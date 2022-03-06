SUB_DIR = \
	src/

all: compile

compile:
	for i in $(SUB_DIR); do \
		make -C $$i;        \
	done

clear:
	for i in $(SUB_DIR); do \
		make -C $$i clear;        \
	done