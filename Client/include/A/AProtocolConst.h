#ifndef __APROTOCOL_CONST_H__
#define __APROTOCOL_CONST_H__

enum AProtocolConst {
    CONNECT_CHECK = 0,
    CONNECT_OK,
    CONNECT_FAIL,
    GIVE_FILE = 0x66,
    GIVE_FILE_NAME,
    GIVE_FILE_SIZE,
    SEND_FILE,
    SEND_FILE_NAME,
    SEND_FILE_SIZE
};

#endif