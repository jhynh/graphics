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
CMAKE_SOURCE_DIR = /home/jan/Documents/sdl/project_01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jan/Documents/sdl/project_01/build

# Include any dependencies generated for this target.
include SDL2_image-2.6.2/CMakeFiles/showimage.dir/depend.make

# Include the progress variables for this target.
include SDL2_image-2.6.2/CMakeFiles/showimage.dir/progress.make

# Include the compile flags for this target's objects.
include SDL2_image-2.6.2/CMakeFiles/showimage.dir/flags.make

SDL2_image-2.6.2/CMakeFiles/showimage.dir/showimage.c.o: SDL2_image-2.6.2/CMakeFiles/showimage.dir/flags.make
SDL2_image-2.6.2/CMakeFiles/showimage.dir/showimage.c.o: ../SDL2_image-2.6.2/showimage.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jan/Documents/sdl/project_01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object SDL2_image-2.6.2/CMakeFiles/showimage.dir/showimage.c.o"
	cd /home/jan/Documents/sdl/project_01/build/SDL2_image-2.6.2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/showimage.dir/showimage.c.o -c /home/jan/Documents/sdl/project_01/SDL2_image-2.6.2/showimage.c

SDL2_image-2.6.2/CMakeFiles/showimage.dir/showimage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/showimage.dir/showimage.c.i"
	cd /home/jan/Documents/sdl/project_01/build/SDL2_image-2.6.2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jan/Documents/sdl/project_01/SDL2_image-2.6.2/showimage.c > CMakeFiles/showimage.dir/showimage.c.i

SDL2_image-2.6.2/CMakeFiles/showimage.dir/showimage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/showimage.dir/showimage.c.s"
	cd /home/jan/Documents/sdl/project_01/build/SDL2_image-2.6.2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jan/Documents/sdl/project_01/SDL2_image-2.6.2/showimage.c -o CMakeFiles/showimage.dir/showimage.c.s

# Object files for target showimage
showimage_OBJECTS = \
"CMakeFiles/showimage.dir/showimage.c.o"

# External object files for target showimage
showimage_EXTERNAL_OBJECTS =

SDL2_image-2.6.2/showimage: SDL2_image-2.6.2/CMakeFiles/showimage.dir/showimage.c.o
SDL2_image-2.6.2/showimage: SDL2_image-2.6.2/CMakeFiles/showimage.dir/build.make
SDL2_image-2.6.2/showimage: SDL2_image-2.6.2/libSDL2_image-2.0d.so.0.600.2
SDL2_image-2.6.2/showimage: /usr/lib/x86_64-linux-gnu/libSDL2main.a
SDL2_image-2.6.2/showimage: /usr/lib/x86_64-linux-gnu/libSDL2.so
SDL2_image-2.6.2/showimage: SDL2_image-2.6.2/CMakeFiles/showimage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jan/Documents/sdl/project_01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable showimage"
	cd /home/jan/Documents/sdl/project_01/build/SDL2_image-2.6.2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/showimage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
SDL2_image-2.6.2/CMakeFiles/showimage.dir/build: SDL2_image-2.6.2/showimage

.PHONY : SDL2_image-2.6.2/CMakeFiles/showimage.dir/build

SDL2_image-2.6.2/CMakeFiles/showimage.dir/clean:
	cd /home/jan/Documents/sdl/project_01/build/SDL2_image-2.6.2 && $(CMAKE_COMMAND) -P CMakeFiles/showimage.dir/cmake_clean.cmake
.PHONY : SDL2_image-2.6.2/CMakeFiles/showimage.dir/clean

SDL2_image-2.6.2/CMakeFiles/showimage.dir/depend:
	cd /home/jan/Documents/sdl/project_01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jan/Documents/sdl/project_01 /home/jan/Documents/sdl/project_01/SDL2_image-2.6.2 /home/jan/Documents/sdl/project_01/build /home/jan/Documents/sdl/project_01/build/SDL2_image-2.6.2 /home/jan/Documents/sdl/project_01/build/SDL2_image-2.6.2/CMakeFiles/showimage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SDL2_image-2.6.2/CMakeFiles/showimage.dir/depend

