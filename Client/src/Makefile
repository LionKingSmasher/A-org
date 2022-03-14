SOURCE_FILE =  \
	AClient.cc \
	AError.cc  \
	AFile.cc   \

CC=gcc

all: $(SOURCE_FILE:.cc=.o)

%.o: %.cc
	$(CC) -std=c++20 -g -c $^ -I../include

clear:
	rm *.o