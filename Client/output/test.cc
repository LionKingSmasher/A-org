#include <A/Alib.h>

using namespace A;
using namespace A::Exception;

int main(int argc, char **argv){
    AClient<AUserType::AUSER_CLIENT> client("127.0.0.1", 6666);
    try {
        client.connectToServer();
        client.closeToServer();
    }
    catch(ConnectFailedException e){
        std::cout << e << std::endl;
    }
    catch(CloseFailedException e){
        std::cout << e << std::endl;
    }
}