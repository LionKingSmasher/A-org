//============ ALIB ============
#include <A/AFile.h>
#include <A/AError.h>
//=========== POSIX ============
#include <fcntl.h>
#include <unistd.h>
//==============================

using namespace A;

AFile::AFile(const char* filename) : open_status(true) {
    file_fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if(file_fd < 0){

    }
}

AFile::AFile(std::string filename){
    AFile(filename.c_str());
}

AFile::~AFile(){
    close(file_fd);
}

void AFile::writeData(u8* arr, size_t size){
    write(file_fd, arr, size);
}

void AFile::writeData(const u8* arr, size_t size){
    writeData((u8*)arr, size);
}