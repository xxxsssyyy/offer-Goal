# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xingsiyuan/PycharmProjects/offer-Goal/C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xingsiyuan/PycharmProjects/offer-Goal/C++/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/JZ63.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/JZ63.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JZ63.dir/flags.make

CMakeFiles/JZ63.dir/JZ63.cpp.o: CMakeFiles/JZ63.dir/flags.make
CMakeFiles/JZ63.dir/JZ63.cpp.o: ../JZ63.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xingsiyuan/PycharmProjects/offer-Goal/C++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/JZ63.dir/JZ63.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JZ63.dir/JZ63.cpp.o -c /Users/xingsiyuan/PycharmProjects/offer-Goal/C++/JZ63.cpp

CMakeFiles/JZ63.dir/JZ63.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JZ63.dir/JZ63.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xingsiyuan/PycharmProjects/offer-Goal/C++/JZ63.cpp > CMakeFiles/JZ63.dir/JZ63.cpp.i

CMakeFiles/JZ63.dir/JZ63.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JZ63.dir/JZ63.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xingsiyuan/PycharmProjects/offer-Goal/C++/JZ63.cpp -o CMakeFiles/JZ63.dir/JZ63.cpp.s

# Object files for target JZ63
JZ63_OBJECTS = \
"CMakeFiles/JZ63.dir/JZ63.cpp.o"

# External object files for target JZ63
JZ63_EXTERNAL_OBJECTS =

JZ63: CMakeFiles/JZ63.dir/JZ63.cpp.o
JZ63: CMakeFiles/JZ63.dir/build.make
JZ63: CMakeFiles/JZ63.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xingsiyuan/PycharmProjects/offer-Goal/C++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable JZ63"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JZ63.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JZ63.dir/build: JZ63

.PHONY : CMakeFiles/JZ63.dir/build

CMakeFiles/JZ63.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/JZ63.dir/cmake_clean.cmake
.PHONY : CMakeFiles/JZ63.dir/clean

CMakeFiles/JZ63.dir/depend:
	cd /Users/xingsiyuan/PycharmProjects/offer-Goal/C++/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xingsiyuan/PycharmProjects/offer-Goal/C++ /Users/xingsiyuan/PycharmProjects/offer-Goal/C++ /Users/xingsiyuan/PycharmProjects/offer-Goal/C++/cmake-build-debug /Users/xingsiyuan/PycharmProjects/offer-Goal/C++/cmake-build-debug /Users/xingsiyuan/PycharmProjects/offer-Goal/C++/cmake-build-debug/CMakeFiles/JZ63.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JZ63.dir/depend
