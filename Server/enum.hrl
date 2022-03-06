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
-define(ACLIENT_GIVE_FILE, 0x66).
-define(ACLIENT_GIVE_FILE_NAME, 0x67).
-define(ACLIENT_GIVE_FILE_SIZE, 0x68).
-define(ACLIENT_SEND_FILE, 0x69).
-define(ACLIENT_SEND_FILE_NAME, 0x70).
-define(ACLIENT_SEND_FILE_SIZE, 0x71).

% For Server
-define(A_OK, 1).
-define(A_FAILED, 2).
-define(A_DONE, 3).