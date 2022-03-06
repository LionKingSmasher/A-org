all: client server 

client:
	make -C ./Client

server:
	make -C ./Server
