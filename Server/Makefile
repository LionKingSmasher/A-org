all: compile

compile:
	if [ ! -d "ebin/" ]; then \
		mkdir ebin/ ;\
	fi

	erlc -pa ebin/ -o ebin/ *.erl

clear:
	rm -rf ebin/