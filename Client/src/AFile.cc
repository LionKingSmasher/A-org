//============ ALIB ============
#include <A/AFile.h>
#include <A/AError.h>
//=========== POSIX ============
#include <fcntl.h>
#include <unistd.h>
//==============================

using namespace A;

AFile::AFile() : open_status(false) {
}

AFile::AFile(const char* filename) : open_status(true) {
    file_fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if(file_fd < 0) {
        open_status = false;
        throw Exception::AFileOpenFailedException("File open failed!");
    }
}

AFile::AFile(std::string filename){
    AFile(filename.c_str());
}

AFile::~AFile(){
    close(file_fd);
}

void AFile::openFile(const char* fileName) {
	file_fd = open(fileName, O_CREAT | O_WRONLY, 0644);
	if(file_fd < 0) {
		open_status = false;
		AERROR_CALL(file_open_error);
	}
	else
		open_status = true;
AERROR_AREA_START(file_open_error)
    AError_msg("File Open Error!");
	throw Exception::AFileOpenFailedException("File Open Error!");	
AERROR_AREA_END
}

void AFile::openFile(std::string&& fileName) {
	openFile(fileName.c_str());
}

void AFile::writeData(u8* arr, size_t size){
    write(file_fd, arr, size);
}

void AFile::writeData(const u8* arr, size_t size){
    writeData((u8*)arr, size);
}

ssize_t AFile::readData(u8* arr, size_t size){
    return read(file_fd, arr, size);
}
