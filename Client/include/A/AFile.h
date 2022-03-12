#ifndef __AFILE_H__
#define __AFILE_H__

typedef unsigned char u8;

#include <string>

namespace A{
    class AFile {
    private:
        int file_fd;
        bool open_status;
    public:
        AFile(const char*);
        AFile(std::string);
        ~AFile();

        void writeData(u8*, size_t);
        void writeData(const u8*, size_t);
    };
};

#endif