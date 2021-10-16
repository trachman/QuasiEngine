UNAME_S = $(shell uname -s)

.PHONY: all
all: run clean

build:
	g++ quasi.cpp

run: build
	./a.out

.PHONY: clean
clean:
	rm a.out
