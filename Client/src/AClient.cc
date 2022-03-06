#include <A/AClient.h>

using namespace A;
using namespace A::Exception;

template<>
void AClient<AUserType::AUSER_CLIENT>::connectToServer(){
    server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(connect(server_fd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) goto error;
    connectStatus = true;
    return;
error:
    AError_msg("Fail to Connect Server!");
    throw ConnectFailedException("Connect Fail!");
}

template<>
void AClient<AUserType::AUSER_CLIENT>::sendToServer(enum AProtocolConst protocol){
    char recieved_msg;
    int err;
    if(connectStatus){
        std::string msg = "s:";
        msg += (char)protocol;
        if((err = write(server_fd, msg.c_str(), 3)) < 0) goto error;
        if(read(server_fd, &recieved_msg, 1) < 0) goto error;
    }
    else goto error;
    return;
error:
    AError_msg("Fail to send message to server!");
    throw SendFailedException("Send Failed");
}

template<>
void AClient<AUserType::AUSER_CLIENT>::closeToServer() {
    if(connectStatus){
        AError_success("Success to close connection!");
        close(server_fd);
    }
    else goto error;
    return;
error:
    AError_msg("Client is not connect to server!");
    throw CloseFailedException("Close Failed");
}