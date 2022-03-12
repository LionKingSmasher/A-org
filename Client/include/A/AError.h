#ifndef __AERROR_H__
#define __AERROR_H__
#include <iostream>

#define DECLARE_EXCEPTION_NORMAL(ExceptionName)                      \
    class ExceptionName : public SuperException {                    \
    private:                                                         \
    public:                                                          \
        ExceptionName(const char* msg, int error_code = 0) {       \
            this->msg = msg;                                         \
            this->error_code = error_code;                           \
        }                                                            \
                                                                     \
        std::string error_msg() override;                            \
        int error_num() override;                                    \
        friend ostream& operator<<(std::ostream&, ExceptionName&); \
    }

using namespace std;

namespace A {
    class AErrorMsg {
    public:
        inline void AError_success(std::string msg){
            std::cout << "[A.org] " << msg << "\n";
        }

        inline void AError_success(const char* msg){
            AError_success(std::string(msg));
        }

        inline void AError_msg(std::string msg) {
            std::cout << "[A.org] Error: " << msg << "\n";
        }

        inline void AError_msg(const char* msg) {
            AError_msg(std::string(msg));
        }
    };

    namespace Exception {
        class SuperException {
        protected:
            std::string msg;
            int error_code;
        public:
            virtual std::string error_msg() = 0;
            virtual int error_num() = 0;
        };

        DECLARE_EXCEPTION_NORMAL(ConnectFailedException);
        DECLARE_EXCEPTION_NORMAL(SendFailedException);
        DECLARE_EXCEPTION_NORMAL(CloseFailedException);
        DECLARE_EXCEPTION_NORMAL(DownloadFailedException);
        DECLARE_EXCEPTION_NORMAL(AFileOpenFailedException);
    };
};
#endif