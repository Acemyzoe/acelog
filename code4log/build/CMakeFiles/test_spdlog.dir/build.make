# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ace/下载/log/code4log

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ace/下载/log/code4log/build

# Include any dependencies generated for this target.
include CMakeFiles/test_spdlog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_spdlog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_spdlog.dir/flags.make

CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.o: CMakeFiles/test_spdlog.dir/flags.make
CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.o: ../src/test_spdlog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/下载/log/code4log/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.o -c /home/ace/下载/log/code4log/src/test_spdlog.cpp

CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/下载/log/code4log/src/test_spdlog.cpp > CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.i

CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/下载/log/code4log/src/test_spdlog.cpp -o CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.s

# Object files for target test_spdlog
test_spdlog_OBJECTS = \
"CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.o"

# External object files for target test_spdlog
test_spdlog_EXTERNAL_OBJECTS =

test_spdlog: CMakeFiles/test_spdlog.dir/src/test_spdlog.cpp.o
test_spdlog: CMakeFiles/test_spdlog.dir/build.make
test_spdlog: CMakeFiles/test_spdlog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ace/下载/log/code4log/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_spdlog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_spdlog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_spdlog.dir/build: test_spdlog

.PHONY : CMakeFiles/test_spdlog.dir/build

CMakeFiles/test_spdlog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_spdlog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_spdlog.dir/clean

CMakeFiles/test_spdlog.dir/depend:
	cd /home/ace/下载/log/code4log/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/下载/log/code4log /home/ace/下载/log/code4log /home/ace/下载/log/code4log/build /home/ace/下载/log/code4log/build /home/ace/下载/log/code4log/build/CMakeFiles/test_spdlog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_spdlog.dir/depend

