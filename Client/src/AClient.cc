#include <A/AClient.h>
#include <A/AFile.h>

using namespace A;
using namespace A::Exception;

static inline ssize_t read_file_section(AFile* file, int fd){
    u8 arr[1024] = {0,};
    ssize_t size;
	while((size = read(fd, arr, 1024)) > 0)
        file->writeData(arr, size);
    return size;
}

static inline std::string check_AProtocol_section(enum AProtocolMode mode){
    switch(mode){
    case NORMAL_STATE:
        return "s";
    case DOWNLOAD_STATE:
        return "a";
    }
}

template<>
char AClient<AUserType::AUSER_CLIENT>::sendToServer(enum AProtocolConst protocol, enum AProtocolMode mode){
    char received_msg[3];
    int err;
    if(connectStatus){
        std::string msg = check_AProtocol_section(mode) + ":";
        msg += (char)protocol;
        std::cout << "Write....\n";
        if((err = write(server_fd, msg.c_str(), 3)) < 0) AERROR_CALL(error);
        std::cout << "Read....\n";
        if(read(server_fd, received_msg, 3) < 0) AERROR_CALL(error);
        return received_msg[0];
    }
    else AERROR_CALL(not_connected_error);
    
error:
    AError_msg("Fail to send message to server!");
    throw SendFailedException("Send Failed");

not_connected_error:
    AError_msg("You don't connect server!");
    throw SendFailedException("Not to connect server!");
}

template<>
void AClient<AUserType::AUSER_CLIENT>::connectToServer(){
    char recv;
    server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(connect(server_fd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) AERROR_CALL(error);
    recv = sendToServer(AProtocolConst::CONNECT_CHECK);
    if(!recv) goto error;
    AError_success("Server Connect Complete!");
    connectStatus = true;
AERROR_AREA_START(error)
    AError_msg("Fail to Connect Server!");
    throw ConnectFailedException("Connect Fail!");
AERROR_AREA_END
}

template<>
void AClient<AUserType::AUSER_CLIENT>::closeToServer() {
    if(connectStatus){
        AError_success("Success to close connection!");
        sendToServer(AProtocolConst::CONNECT_CLOSE);
        close(server_fd);
        connectStatus = false;
    }
AERROR_AREA_START(error)
    AError_msg("Client is not connect to server!");
    throw CloseFailedException("Close Failed");
AERROR_AREA_END
}

template<>
void AClient<AUserType::AUSER_CLIENT>::giveFile(const char* file_name){
    unsigned char buffer[1024];
    std::string msg = std::string(file_name);
    char recv = sendToServer(AProtocolConst::GIVE_FILE);
    if(recv != 1) goto error;
    write(server_fd, msg.c_str(), msg.size() - 1);
    afile = new AFile(msg);
    if(read_file_section(afile, server_fd) < 0) AERROR_CALL(error);
    if(sendToServer((enum AProtocolConst)A_OK, DOWNLOAD_STATE) != 1) AERROR_CALL(error);
    afile->closeFile();
    delete afile;
AERROR_AREA_START(error)
    AError_msg("Client is failed to download file!");
    throw DownloadFailedException("Dwonload Failed!");
AERROR_AREA_END
}

template<>
void AClient<AUserType::AUSER_CLIENT>::giveFile(std::string file_name){
    giveFile(file_name.c_str());
}
