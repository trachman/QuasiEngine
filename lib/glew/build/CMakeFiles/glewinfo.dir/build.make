# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build

# Include any dependencies generated for this target.
include CMakeFiles/glewinfo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/glewinfo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/glewinfo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glewinfo.dir/flags.make

CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.o: CMakeFiles/glewinfo.dir/flags.make
CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.o: /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c
CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.o: CMakeFiles/glewinfo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.o -MF CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.o.d -o CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.o -c /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c

CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c > CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.i

CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c -o CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.s

# Object files for target glewinfo
glewinfo_OBJECTS = \
"CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.o"

# External object files for target glewinfo
glewinfo_EXTERNAL_OBJECTS =

bin/glewinfo: CMakeFiles/glewinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/glewinfo.c.o
bin/glewinfo: CMakeFiles/glewinfo.dir/build.make
bin/glewinfo: lib/libGLEW.2.1.0.dylib
bin/glewinfo: CMakeFiles/glewinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/glewinfo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glewinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glewinfo.dir/build: bin/glewinfo
.PHONY : CMakeFiles/glewinfo.dir/build

CMakeFiles/glewinfo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/glewinfo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/glewinfo.dir/clean

CMakeFiles/glewinfo.dir/depend:
	cd /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build/cmake /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build/cmake /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build/CMakeFiles/glewinfo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/glewinfo.dir/depend

