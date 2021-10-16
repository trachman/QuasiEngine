UNAME_S = $(shell uname -s)

.PHONY: all

all: run

hello:
	echo $(UNAME_S)

run: hello
	echo "we running"
