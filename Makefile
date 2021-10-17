UNAME_S = $(shell uname -s)

CC = g++
SRC = $(wildcard src/*.cpp)

.PHONY: all
all: build

build:
	$(CC) $(SRC)

run: build
	./a.out

test: 
	echo $(SRC)

.PHONY: clean
clean:
	rm a.out
