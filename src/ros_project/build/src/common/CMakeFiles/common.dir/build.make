# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/book/ros_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/book/ros_project/build

# Include any dependencies generated for this target.
include src/common/CMakeFiles/common.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/common/CMakeFiles/common.dir/compiler_depend.make

# Include the progress variables for this target.
include src/common/CMakeFiles/common.dir/progress.make

# Include the compile flags for this target's objects.
include src/common/CMakeFiles/common.dir/flags.make

src/common/CMakeFiles/common.dir/common.cpp.o: src/common/CMakeFiles/common.dir/flags.make
src/common/CMakeFiles/common.dir/common.cpp.o: ../src/common/common.cpp
src/common/CMakeFiles/common.dir/common.cpp.o: src/common/CMakeFiles/common.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/book/ros_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/common/CMakeFiles/common.dir/common.cpp.o"
	cd /home/book/ros_project/build/src/common && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/common/CMakeFiles/common.dir/common.cpp.o -MF CMakeFiles/common.dir/common.cpp.o.d -o CMakeFiles/common.dir/common.cpp.o -c /home/book/ros_project/src/common/common.cpp

src/common/CMakeFiles/common.dir/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common.cpp.i"
	cd /home/book/ros_project/build/src/common && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/book/ros_project/src/common/common.cpp > CMakeFiles/common.dir/common.cpp.i

src/common/CMakeFiles/common.dir/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common.cpp.s"
	cd /home/book/ros_project/build/src/common && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/book/ros_project/src/common/common.cpp -o CMakeFiles/common.dir/common.cpp.s

src/common/CMakeFiles/common.dir/Log.cpp.o: src/common/CMakeFiles/common.dir/flags.make
src/common/CMakeFiles/common.dir/Log.cpp.o: ../src/common/Log.cpp
src/common/CMakeFiles/common.dir/Log.cpp.o: src/common/CMakeFiles/common.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/book/ros_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/common/CMakeFiles/common.dir/Log.cpp.o"
	cd /home/book/ros_project/build/src/common && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/common/CMakeFiles/common.dir/Log.cpp.o -MF CMakeFiles/common.dir/Log.cpp.o.d -o CMakeFiles/common.dir/Log.cpp.o -c /home/book/ros_project/src/common/Log.cpp

src/common/CMakeFiles/common.dir/Log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/Log.cpp.i"
	cd /home/book/ros_project/build/src/common && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/book/ros_project/src/common/Log.cpp > CMakeFiles/common.dir/Log.cpp.i

src/common/CMakeFiles/common.dir/Log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/Log.cpp.s"
	cd /home/book/ros_project/build/src/common && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/book/ros_project/src/common/Log.cpp -o CMakeFiles/common.dir/Log.cpp.s

# Object files for target common
common_OBJECTS = \
"CMakeFiles/common.dir/common.cpp.o" \
"CMakeFiles/common.dir/Log.cpp.o"

# External object files for target common
common_EXTERNAL_OBJECTS =

../lib/libcommon.so: src/common/CMakeFiles/common.dir/common.cpp.o
../lib/libcommon.so: src/common/CMakeFiles/common.dir/Log.cpp.o
../lib/libcommon.so: src/common/CMakeFiles/common.dir/build.make
../lib/libcommon.so: src/common/CMakeFiles/common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/book/ros_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../../lib/libcommon.so"
	cd /home/book/ros_project/build/src/common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/common/CMakeFiles/common.dir/build: ../lib/libcommon.so
.PHONY : src/common/CMakeFiles/common.dir/build

src/common/CMakeFiles/common.dir/clean:
	cd /home/book/ros_project/build/src/common && $(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean.cmake
.PHONY : src/common/CMakeFiles/common.dir/clean

src/common/CMakeFiles/common.dir/depend:
	cd /home/book/ros_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/book/ros_project /home/book/ros_project/src/common /home/book/ros_project/build /home/book/ros_project/build/src/common /home/book/ros_project/build/src/common/CMakeFiles/common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/common/CMakeFiles/common.dir/depend

