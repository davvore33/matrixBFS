# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/reso.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/reso.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reso.dir/flags.make

CMakeFiles/reso.dir/main.cpp.o: CMakeFiles/reso.dir/flags.make
CMakeFiles/reso.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reso.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reso.dir/main.cpp.o -c /run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS/main.cpp

CMakeFiles/reso.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reso.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS/main.cpp > CMakeFiles/reso.dir/main.cpp.i

CMakeFiles/reso.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reso.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS/main.cpp -o CMakeFiles/reso.dir/main.cpp.s

CMakeFiles/reso.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/reso.dir/main.cpp.o.requires

CMakeFiles/reso.dir/main.cpp.o.provides: CMakeFiles/reso.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/reso.dir/build.make CMakeFiles/reso.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/reso.dir/main.cpp.o.provides

CMakeFiles/reso.dir/main.cpp.o.provides.build: CMakeFiles/reso.dir/main.cpp.o


# Object files for target reso
reso_OBJECTS = \
"CMakeFiles/reso.dir/main.cpp.o"

# External object files for target reso
reso_EXTERNAL_OBJECTS =

reso: CMakeFiles/reso.dir/main.cpp.o
reso: CMakeFiles/reso.dir/build.make
reso: CMakeFiles/reso.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable reso"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reso.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reso.dir/build: reso

.PHONY : CMakeFiles/reso.dir/build

CMakeFiles/reso.dir/requires: CMakeFiles/reso.dir/main.cpp.o.requires

.PHONY : CMakeFiles/reso.dir/requires

CMakeFiles/reso.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reso.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reso.dir/clean

CMakeFiles/reso.dir/depend:
	cd /run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS /run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS /run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS/cmake-build-debug /run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS/cmake-build-debug /run/media/matteo/321AB9C01AB98201/Users/matteo/Documents/matrixBFS/cmake-build-debug/CMakeFiles/reso.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reso.dir/depend

