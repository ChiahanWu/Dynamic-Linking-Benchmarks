# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++/build

# Include any dependencies generated for this target.
include CMakeFiles/modA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/modA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/modA.dir/flags.make

CMakeFiles/modA.dir/modA.cpp.o: CMakeFiles/modA.dir/flags.make
CMakeFiles/modA.dir/modA.cpp.o: ../modA.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/modA.dir/modA.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/modA.dir/modA.cpp.o -c /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++/modA.cpp

CMakeFiles/modA.dir/modA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modA.dir/modA.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++/modA.cpp > CMakeFiles/modA.dir/modA.cpp.i

CMakeFiles/modA.dir/modA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modA.dir/modA.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++/modA.cpp -o CMakeFiles/modA.dir/modA.cpp.s

CMakeFiles/modA.dir/modA.cpp.o.requires:
.PHONY : CMakeFiles/modA.dir/modA.cpp.o.requires

CMakeFiles/modA.dir/modA.cpp.o.provides: CMakeFiles/modA.dir/modA.cpp.o.requires
	$(MAKE) -f CMakeFiles/modA.dir/build.make CMakeFiles/modA.dir/modA.cpp.o.provides.build
.PHONY : CMakeFiles/modA.dir/modA.cpp.o.provides

CMakeFiles/modA.dir/modA.cpp.o.provides.build: CMakeFiles/modA.dir/modA.cpp.o

# Object files for target modA
modA_OBJECTS = \
"CMakeFiles/modA.dir/modA.cpp.o"

# External object files for target modA
modA_EXTERNAL_OBJECTS =

libmodA.so: CMakeFiles/modA.dir/modA.cpp.o
libmodA.so: CMakeFiles/modA.dir/build.make
libmodA.so: CMakeFiles/modA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libmodA.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/modA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/modA.dir/build: libmodA.so
.PHONY : CMakeFiles/modA.dir/build

CMakeFiles/modA.dir/requires: CMakeFiles/modA.dir/modA.cpp.o.requires
.PHONY : CMakeFiles/modA.dir/requires

CMakeFiles/modA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/modA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/modA.dir/clean

CMakeFiles/modA.dir/depend:
	cd /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++ /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++ /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++/build /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++/build /home/chiahan/DLK-Benchmarks/06-Dlk_in_C++/build/CMakeFiles/modA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/modA.dir/depend

