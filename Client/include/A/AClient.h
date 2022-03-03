#include <string>
#include <type_traits>

#ifndef __ACLIENT_H__
#define __ACLIENT_H__

enum class AUserType {
    AUSER_NONE,
    AUSER_CLIENT,
    AUSER_SERVER,
};

struct AIPort {
    std::string ip;
    int port;
};

template<AUserType = AUsterType::AUSER_NONE, typename = void>
class AClient;

template<AUserType UserType>
class AClient<UserType, std::enable_if_t<UserType == UserType::AUSER_CLIENT>> {
private:
    AIPort iport;
    int server_fd;
public:
    AClient(std::string ip, int port) {
        this->iport.ip = ip;
        this->iport.port = port;
    }

    void connect();
}

#endif