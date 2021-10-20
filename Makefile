# operating system
UNAME_S = $(shell uname -s)

# variables
CC = g++
BIN = bin
ENGINE = engine
SRC = $(wildcard src/*.cpp)
OBJ  = $(SRC:.cpp=.o)

CPPFLAGS = -std=c++17 -Ilib/glew/include -Ilib/glfw/include -Wno-int-to-void-pointer-cast
# -lm to ldflags was removed, also lib/glew/lib/glew.a file was removed
LDFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo lib/glew/lib/libGLEW.a lib/glfw/src/libglfw3.a 

# targets
.PHONY: all testing clean

# libs
all: dirs build run clean

dirs: 
	mkdir -p ./$(BIN)

libs:
	cd lib/glew/auto && make all && cd ../ && make all
	cd lib/glfw && cmake . && make	

build: $(OBJ)
	$(CC) -o $(BIN)/$(ENGINE) $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CPPFLAGS)

run:
	$(BIN)/$(ENGINE)

testing: 
	echo $(SRC)
	echo $(OBJ)
	echo $^
	echo $<
	echo $@

clean:
	rm -rf $(BIN) $(OBJ)
