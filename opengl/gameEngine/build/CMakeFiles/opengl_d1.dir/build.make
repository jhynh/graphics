# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/jan/Documents/opengl/salsaDip

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jan/Documents/opengl/salsaDip/build

# Include any dependencies generated for this target.
include CMakeFiles/opengl_d1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opengl_d1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opengl_d1.dir/flags.make

CMakeFiles/opengl_d1.dir/Application.cpp.o: CMakeFiles/opengl_d1.dir/flags.make
CMakeFiles/opengl_d1.dir/Application.cpp.o: ../Application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jan/Documents/opengl/salsaDip/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opengl_d1.dir/Application.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_d1.dir/Application.cpp.o -c /home/jan/Documents/opengl/salsaDip/Application.cpp

CMakeFiles/opengl_d1.dir/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_d1.dir/Application.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jan/Documents/opengl/salsaDip/Application.cpp > CMakeFiles/opengl_d1.dir/Application.cpp.i

CMakeFiles/opengl_d1.dir/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_d1.dir/Application.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jan/Documents/opengl/salsaDip/Application.cpp -o CMakeFiles/opengl_d1.dir/Application.cpp.s

# Object files for target opengl_d1
opengl_d1_OBJECTS = \
"CMakeFiles/opengl_d1.dir/Application.cpp.o"

# External object files for target opengl_d1
opengl_d1_EXTERNAL_OBJECTS =

opengl_d1: CMakeFiles/opengl_d1.dir/Application.cpp.o
opengl_d1: CMakeFiles/opengl_d1.dir/build.make
opengl_d1: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
opengl_d1: /usr/lib/x86_64-linux-gnu/libGL.so
opengl_d1: /usr/lib/x86_64-linux-gnu/libGLU.so
opengl_d1: CMakeFiles/opengl_d1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jan/Documents/opengl/salsaDip/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opengl_d1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl_d1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opengl_d1.dir/build: opengl_d1

.PHONY : CMakeFiles/opengl_d1.dir/build

CMakeFiles/opengl_d1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opengl_d1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opengl_d1.dir/clean

CMakeFiles/opengl_d1.dir/depend:
	cd /home/jan/Documents/opengl/salsaDip/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jan/Documents/opengl/salsaDip /home/jan/Documents/opengl/salsaDip /home/jan/Documents/opengl/salsaDip/build /home/jan/Documents/opengl/salsaDip/build /home/jan/Documents/opengl/salsaDip/build/CMakeFiles/opengl_d1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opengl_d1.dir/depend

