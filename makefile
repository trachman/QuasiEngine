UNAME_S = $(shell uname -s)

.PHONY: all

all: hello

hello:
	echo $(UNAME_S)
