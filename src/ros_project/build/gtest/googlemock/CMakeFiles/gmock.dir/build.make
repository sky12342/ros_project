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
include gtest/googlemock/CMakeFiles/gmock.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include gtest/googlemock/CMakeFiles/gmock.dir/compiler_depend.make

# Include the progress variables for this target.
include gtest/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include gtest/googlemock/CMakeFiles/gmock.dir/flags.make

gtest/googlemock/CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.o: gtest/googlemock/CMakeFiles/gmock.dir/flags.make
gtest/googlemock/CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.o: gtest/googlemock/gmock_autogen/mocs_compilation.cpp
gtest/googlemock/CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.o: gtest/googlemock/CMakeFiles/gmock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/book/ros_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gtest/googlemock/CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.o"
	cd /home/book/ros_project/build/gtest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT gtest/googlemock/CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.o -MF CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.o -c /home/book/ros_project/build/gtest/googlemock/gmock_autogen/mocs_compilation.cpp

gtest/googlemock/CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.i"
	cd /home/book/ros_project/build/gtest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/book/ros_project/build/gtest/googlemock/gmock_autogen/mocs_compilation.cpp > CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.i

gtest/googlemock/CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.s"
	cd /home/book/ros_project/build/gtest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/book/ros_project/build/gtest/googlemock/gmock_autogen/mocs_compilation.cpp -o CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.s

gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: gtest/googlemock/CMakeFiles/gmock.dir/flags.make
gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: /usr/src/googletest/googlemock/src/gmock-all.cc
gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: gtest/googlemock/CMakeFiles/gmock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/book/ros_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /home/book/ros_project/build/gtest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o -MF CMakeFiles/gmock.dir/src/gmock-all.cc.o.d -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /usr/src/googletest/googlemock/src/gmock-all.cc

gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /home/book/ros_project/build/gtest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/src/googletest/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /home/book/ros_project/build/gtest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/src/googletest/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

gtest/lib/libgmock.so.1.11.0: gtest/googlemock/CMakeFiles/gmock.dir/gmock_autogen/mocs_compilation.cpp.o
gtest/lib/libgmock.so.1.11.0: gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
gtest/lib/libgmock.so.1.11.0: gtest/googlemock/CMakeFiles/gmock.dir/build.make
gtest/lib/libgmock.so.1.11.0: gtest/lib/libgtest.so.1.11.0
gtest/lib/libgmock.so.1.11.0: gtest/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/book/ros_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../lib/libgmock.so"
	cd /home/book/ros_project/build/gtest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)
	cd /home/book/ros_project/build/gtest/googlemock && $(CMAKE_COMMAND) -E cmake_symlink_library ../lib/libgmock.so.1.11.0 ../lib/libgmock.so.1.11.0 ../lib/libgmock.so

gtest/lib/libgmock.so: gtest/lib/libgmock.so.1.11.0
	@$(CMAKE_COMMAND) -E touch_nocreate gtest/lib/libgmock.so

# Rule to build all files generated by this target.
gtest/googlemock/CMakeFiles/gmock.dir/build: gtest/lib/libgmock.so
.PHONY : gtest/googlemock/CMakeFiles/gmock.dir/build

gtest/googlemock/CMakeFiles/gmock.dir/clean:
	cd /home/book/ros_project/build/gtest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : gtest/googlemock/CMakeFiles/gmock.dir/clean

gtest/googlemock/CMakeFiles/gmock.dir/depend:
	cd /home/book/ros_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/book/ros_project /usr/src/googletest/googlemock /home/book/ros_project/build /home/book/ros_project/build/gtest/googlemock /home/book/ros_project/build/gtest/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gtest/googlemock/CMakeFiles/gmock.dir/depend

