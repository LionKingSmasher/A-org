#include <A/AError.h>

#define DECLARE_EXCEPTION_FUNCTION(ExceptionName)                                                            \
    std::string ExceptionName::error_msg() {                                                               \
        return msg;                                                                                          \
    }                                                                                                        \ 
                                                                                                             \
    int ExceptionName::error_num(){                                                                        \
        return error_code;                                                                                   \
    }                                                                                                        \
                                                                                                             \
    ostream& A::Exception::operator<<(ostream& os, ExceptionName& except){                                 \
        os << "[A.org]" #ExceptionName ": " << except.error_msg() << " (" << except.error_num() << ")"; \
        return os;                                                                                           \
    }

using namespace A::Exception;

//======================== ConnectFailedException ========================
DECLARE_EXCEPTION_FUNCTION(ConnectFailedException)
//========================================================================

//========================== SendFailedException =========================
DECLARE_EXCEPTION_FUNCTION(SendFailedException)
//========================================================================

//========================= CloseFailedException =========================
DECLARE_EXCEPTION_FUNCTION(CloseFailedException)
//========================================================================

//======================= DownloadFailedException ========================
DECLARE_EXCEPTION_FUNCTION(DownloadFailedException)
//========================================================================

//====================== AFileOpenFailedException ========================
DECLARE_EXCEPTION_FUNCTION(AFileOpenFailedException)
//========================================================================

//======================= AFileCloseFailedException ======================
DECLARE_EXCEPTION_FUNCTION(AFileCloseFailedException)
//========================================================================
