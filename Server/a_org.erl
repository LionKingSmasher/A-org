-module(a_org).
-author("Shin Hyun Kyu").

-export([start_server/0]).
-import(a_org_module, [
	make_dir/0
]).

-include("enum.hrl").

start_server() ->
	init_server(),
	Pid = spawn_link(fun() ->
		{ok, LSocket} = gen_tcp:listen(6666, [binary, {active, false}, {ip, {127,0,0,1}}]),
		spawn(fun() -> acceptState(LSocket) end),
		timer:sleep(infinity)
		end),
	{ok, Pid}.

init_server() ->
	io:format("[A.org] Server Init...."),
	case a_org_module:make_dir(?CLOUD_DIR) of
		{error, Reason} -> 
			io:format("[A.org] Init Failed!");
		true ->
			io:format("[A.org] Init Complete!")
	end,

acceptState(LSocket) ->
	{ok, ASocket} = gen_tcp:accept(LSocket),
	spawn(fun() -> acceptState(LSocket) end),
	handler(ASocket).

handler(ASocket) ->
	inet:setopts(ASocket, [{active, once}]),
	receive
		{tcp, ASocket, <<"s:",Code/binary>>} ->
			if
				Code == <<?ACLIENT_CONNECT_CHECK>>->
					io:format("[A.org] Client Connect!~n"),
					gen_tcp:send(ASocket, <<?A_OK>>),
					handler(ASocket);
				Code == <<?ACLIENT_CONNECT_CLOSE>>->
					io:format("[A.org] Client Close!~n"),
					gen_tcp:close(ASocket);
				Code == <<?ACLIENT_GIVE_FILE>> ->
					io:format("[A.org] Client response download!~n"),
					download_handler(ASocket);
				true ->
					io:format("[A.org] Client Send Unknown Protocol~n")
			end;
		{tcp, ASocket, Message} ->
			io:format("~s ~s~n", ["test:", Message]),
			io:format("Client Connect!~n"),
			gen_tcp:send(ASocket, "test2"),
			handler(ASocket)
	end.

download_state(ASocket) ->
	inet:setopts(ASocket, [{active, once}]).
	receive
		{tcp, ASocket, Filename} ->
			if
				FileName = ?CLOUD_DIR ++ binary_to_list(Filename),
				filelib:is_regular(FileName) == true ->
					download_handler(FileName, ASocket),
					download_state(ASocket);
				true ->
					io:format("[A.org] File is not exist...~n")
			end;
		{tcp, ASocket, <<"a:", Check/binary>>} ->
			if
				Check==<<1>> ->
					io:format("[A.org] File Download Complete!~n");
				true ->
					io:format("[A.org] File Download Failed!~n")
			end
	end.


download_handler(Filename, ASocket) ->
	{ok, Data} = file:read_file(Filename),
	gen_tcp:send(ASocket, Data).
