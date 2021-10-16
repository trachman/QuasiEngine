UNAME_S = $(shell uname -s)

.PHONY: all

all: run

build:
	g++ quasi.cpp

run: build
	./a.out

clean:
	rm a.out
