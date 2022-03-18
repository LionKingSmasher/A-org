#ifndef __AFILE_H__
#define __AFILE_H__

typedef unsigned char u8;

#include <string>

namespace A{
    class AFile : private AErrorMsg{
private:
    int file_fd;
    bool open_status;
public:
	AFile();
    AFile(const char*);
    AFile(std::string);
    ~AFile();

	void openFile(const char*);
	void openFile(std::string&&);
    void writeData(u8*, size_t);
    void writeData(const u8*, size_t);
    ssize_t readData(u8*, size_t);
    };
};

#endif
