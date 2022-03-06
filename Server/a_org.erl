-module(a_org).
-author("Shin Hyun Kyu").

-export([start_server/0]).

-include("enum.hrl").

start_server() ->
	Pid = spawn_link(fun() ->
		{ok, LSocket} = gen_tcp:listen(6666, [binary, {active, false}, {ip, {127,0,0,1}}]),
		spawn(fun() -> acceptState(LSocket) end),
		timer:sleep(infinity)
		end),
	{ok, Pid}.

acceptState(LSocket) ->
	{ok, ASocket} = gen_tcp:accept(LSocket),
	spawn(fun() -> acceptState(ASocket) end),
	handler(ASocket).

handler(ASocket) ->
	inet:setopts(ASocket, [{active, once}]),
	receive
		{tcp, ASocket, <<"s:",Code/binary>>} ->
			if
				Code == <<"">>->
					io:format("TO-DO~n");
				true ->
					io:format("TO-DO~n")
			end
	end.
