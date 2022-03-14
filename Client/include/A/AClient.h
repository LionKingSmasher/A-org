//================ C++ Header ================
#include <string>
#include <type_traits>
//=================== POSIX ==================
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
//================== A-ORG ===================
#include <A/AError.h>
#include <A/AProtocolConst.h>
//=============== Header End =================

#ifndef __ACLIENT_H__
#define __ACLIENT_H__

using namespace A::Exception;

namespace A{
    enum class AUserType {
        AUSER_NONE,
        AUSER_CLIENT,
        AUSER_SERVER
    };

    struct AIPort {
        std::string ip;
        int port;
    };

    template<AUserType = AUserType::AUSER_NONE, typename = void>
    class AClient;

    template<AUserType UserType>
    class AClient<UserType, std::enable_if_t<UserType == AUserType::AUSER_CLIENT>> : private AErrorMsg {
    private:
        bool connectStatus;
        struct sockaddr_in serverAddr;
        int server_fd;
        AFile* afile;
    public:
        AClient(const char* ip, unsigned short port){
            connectStatus = false;
            serverAddr.sin_addr.s_addr = inet_addr(ip);
            serverAddr.sin_port = htons(port);
            serverAddr.sin_family = AF_INET;
            afile = nullptr;
        }

        AClient(std::string ip, unsigned short port) {
            AClient(ip.c_str(), port);
        }

        ~AClient(){
            if(connectStatus)
                close(server_fd);

            if(afile != nullptr)
                delete afile;
        }

        char sendToServer(enum AProtocolConst);
        void connectToServer();
        void closeToServer();
        void giveFile(const char*);
        void giveFile(std::string);

    };
};

#endif