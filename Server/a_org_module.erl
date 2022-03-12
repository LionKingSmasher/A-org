-module(a_org_module).
-author("Shin Hyun Kyu").

-export([make_dir/1]).

make_dir(Dir) -> 
    case file:make_dir(Dir) of
        ok -> ok;
        {error, eexist} -> ok;
        {error, Reason} -> {error, Reason}
    end.