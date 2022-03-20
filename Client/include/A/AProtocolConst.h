#ifndef __APROTOCOL_CONST_H__
#define __APROTOCOL_CONST_H__

enum AProtocolMode {
    NORMAL_STATE,
    DOWNLOAD_STATE
};

enum AProtocolConst {
    CONNECT_CHECK = 0,
    CONNECT_OK,
    CONNECT_FAIL,
    CONNECT_CLOSE,
    GIVE_FILE = 0x66,
    GIVE_FILE_NAME,
    GIVE_FILE_SIZE,
    SEND_FILE,
    SEND_FILE_NAME,
    SEND_FILE_SIZE
};

enum AProtocolConst4All {
    A_CHECK,
    A_OK,
    A_FAIL
};

#endif