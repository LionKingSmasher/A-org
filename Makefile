SUB_DIR = \
	Client/ \
	Server/ \

all: client server 

client:
	make -C ./Client

server:
	make -C ./Server

clear:
	for i in $(SUB_DIR); do \
		make -C $$i clear;        \
	done

install:
	make -C Client/ install