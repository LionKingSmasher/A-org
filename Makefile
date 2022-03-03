all: compile

client:
	make -C ./Client

server:
	make -C ./Server
