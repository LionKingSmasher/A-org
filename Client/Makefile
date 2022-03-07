SUB_DIR = \
	src/

OUTPUT_DIR = output/

all: compile

compile:
	for i in $(SUB_DIR); do \
		make -C $$i;        \
	done

clear:
	for i in $(SUB_DIR); do \
		make -C $$i clear;        \
	done
	if [ -d $(OUTPUT_DIR) ]; then \
		mkdir $(OUTPUT_DIR)         ;\
	fi

install:
	if [ ! -d $(OUTPUT_DIR) ]; then \
		mkdir $(OUTPUT_DIR)         ;\
	fi
	ar crv $(OUTPUT_DIR)libA1.a $(shell find . -name '*.o')