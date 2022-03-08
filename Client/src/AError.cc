#include <A/AError.h>

using namespace A::Exception;

//======================== ConnectFailedException ========================
std::string ConnectFailedException::error_msg() {
    return msg;
}

int ConnectFailedException::error_num(){
    return error_code;
}

ostream& A::Exception::operator<<(ostream& os, ConnectFailedException& except){
    os << "[A.org] ConnectFailedException: " << except.error_msg() << " (" << except.error_num() << ")";
    return os; 
}
//========================================================================

//========================== SendFailedException =========================
std::string SendFailedException::error_msg() {
    return msg;
}

int SendFailedException::error_num(){
    return error_code;
}

ostream& A::Exception::operator<<(ostream& os, SendFailedException& except){
    os << "[A.org] SendFailedException: " << except.error_msg() << " (" << except.error_num() << ")"; 
    return os;
}
//========================================================================

//========================= CloseFailedException =========================
std::string DownloadFailedException::error_msg() {
    return msg;
}

int DownloadFailedException::error_num(){
    return error_code;
}

ostream& A::Exception::operator<<(ostream& os, DownloadFailedException& except){
    os << "[A.org] CloseFailedException: " << except.error_msg() << " (" << except.error_num() << ")"; 
    return os;
}
//========================================================================
