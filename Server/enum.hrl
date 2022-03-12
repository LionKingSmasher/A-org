%
%               enum.hrl
%
%   Description: This file is header file of A.org protocol const number. 
%
%
%   Copyright (C) 2022 Shin Hyun Kyu all rights reserved.
%

% For Client
-define(ACLIENT_CONNECT_CHECK, 0).
-define(ACLIENT_CONNECT_OK, 1).
-define(ACLIENT_CONNECT_FAIL, 2).
-define(ACLIENT_CONNECT_CLOSE, 3).
-define(ACLIENT_GIVE_FILE, 102).
-define(ACLIENT_GIVE_FILE_NAME, 103).
-define(ACLIENT_GIVE_FILE_SIZE, 104).
-define(ACLIENT_SEND_FILE, 105).
-define(ACLIENT_SEND_FILE_NAME, 106).
-define(ACLIENT_SEND_FILE_SIZE, 107).

% For Server
-define(A_OK, 1).
-define(A_FAILED, 2).
-define(A_DONE, 3).

-define(CLOUD_DIR, "./Cloud/").