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
include CMakeFiles/visualinfo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/visualinfo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/visualinfo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/visualinfo.dir/flags.make

CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.o: CMakeFiles/visualinfo.dir/flags.make
CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.o: /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c
CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.o: CMakeFiles/visualinfo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.o -MF CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.o.d -o CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.o -c /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c

CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c > CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.i

CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c -o CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.s

# Object files for target visualinfo
visualinfo_OBJECTS = \
"CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.o"

# External object files for target visualinfo
visualinfo_EXTERNAL_OBJECTS =

bin/visualinfo: CMakeFiles/visualinfo.dir/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/src/visualinfo.c.o
bin/visualinfo: CMakeFiles/visualinfo.dir/build.make
bin/visualinfo: lib/libGLEW.2.1.0.dylib
bin/visualinfo: CMakeFiles/visualinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/visualinfo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/visualinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/visualinfo.dir/build: bin/visualinfo
.PHONY : CMakeFiles/visualinfo.dir/build

CMakeFiles/visualinfo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/visualinfo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/visualinfo.dir/clean

CMakeFiles/visualinfo.dir/depend:
	cd /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build/cmake /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build/cmake /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build /Users/tristanrachman/Dev/GameEngine/QuasiEngine/lib/glew/build/CMakeFiles/visualinfo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/visualinfo.dir/depend

