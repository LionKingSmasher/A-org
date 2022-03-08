#ifndef __AERROR_H__
#define __AERROR_H__
#include <iostream>

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

        class ConnectFailedException : public SuperException {
        private:
        public:
            ConnectFailedException(const char* msg, int error_code = 0) {
                this->msg = msg;
                this->error_code = error_code;
            }

            std::string error_msg() override;
            int error_num() override;
            friend ostream& operator<<(std::ostream&, ConnectFailedException&);
        };

        class SendFailedException : public SuperException {
        private:
        public:
            SendFailedException(const char* msg, int error_code = 0) {
                this->msg = msg;
                this->error_code = error_code;
            }

            std::string error_msg() override;
            int error_num() override;
            friend ostream& operator<<(std::ostream&, SendFailedException&);
        };

        class CloseFailedException : public SuperException {
        private:
        public:
            CloseFailedException(const char* msg, int error_code = 0) {
                this->msg = msg;
                this->error_code = error_code;
            }

            std::string error_msg() override;
            int error_num() override;
            friend ostream& operator<<(std::ostream&, CloseFailedException&);
        };

        class DownloadFailedException : public SuperException {
        private:
        public:
            DownloadFailedException(const char* msg, int error_code = 0) {
                this->msg = msg;
                this->error_code = error_code;
            }

            std::string error_msg() override;
            int error_num() override;
            friend ostream& operator<<(std::ostream&, DownloadFailedException&);
        };
    };
};
#endif