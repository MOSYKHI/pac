# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/mosy/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/173.3727.114/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/mosy/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/173.3727.114/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mosy/Desktop/96106088/pacman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mosy/Desktop/96106088/pacman

# Include any dependencies generated for this target.
include CMakeFiles/myPacman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myPacman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myPacman.dir/flags.make

CMakeFiles/myPacman.dir/src/game.c.o: CMakeFiles/myPacman.dir/flags.make
CMakeFiles/myPacman.dir/src/game.c.o: src/game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mosy/Desktop/96106088/pacman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/myPacman.dir/src/game.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myPacman.dir/src/game.c.o   -c /home/mosy/Desktop/96106088/pacman/src/game.c

CMakeFiles/myPacman.dir/src/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myPacman.dir/src/game.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mosy/Desktop/96106088/pacman/src/game.c > CMakeFiles/myPacman.dir/src/game.c.i

CMakeFiles/myPacman.dir/src/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myPacman.dir/src/game.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mosy/Desktop/96106088/pacman/src/game.c -o CMakeFiles/myPacman.dir/src/game.c.s

CMakeFiles/myPacman.dir/src/game.c.o.requires:

.PHONY : CMakeFiles/myPacman.dir/src/game.c.o.requires

CMakeFiles/myPacman.dir/src/game.c.o.provides: CMakeFiles/myPacman.dir/src/game.c.o.requires
	$(MAKE) -f CMakeFiles/myPacman.dir/build.make CMakeFiles/myPacman.dir/src/game.c.o.provides.build
.PHONY : CMakeFiles/myPacman.dir/src/game.c.o.provides

CMakeFiles/myPacman.dir/src/game.c.o.provides.build: CMakeFiles/myPacman.dir/src/game.c.o


CMakeFiles/myPacman.dir/src/physics.c.o: CMakeFiles/myPacman.dir/flags.make
CMakeFiles/myPacman.dir/src/physics.c.o: src/physics.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mosy/Desktop/96106088/pacman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/myPacman.dir/src/physics.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myPacman.dir/src/physics.c.o   -c /home/mosy/Desktop/96106088/pacman/src/physics.c

CMakeFiles/myPacman.dir/src/physics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myPacman.dir/src/physics.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mosy/Desktop/96106088/pacman/src/physics.c > CMakeFiles/myPacman.dir/src/physics.c.i

CMakeFiles/myPacman.dir/src/physics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myPacman.dir/src/physics.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mosy/Desktop/96106088/pacman/src/physics.c -o CMakeFiles/myPacman.dir/src/physics.c.s

CMakeFiles/myPacman.dir/src/physics.c.o.requires:

.PHONY : CMakeFiles/myPacman.dir/src/physics.c.o.requires

CMakeFiles/myPacman.dir/src/physics.c.o.provides: CMakeFiles/myPacman.dir/src/physics.c.o.requires
	$(MAKE) -f CMakeFiles/myPacman.dir/build.make CMakeFiles/myPacman.dir/src/physics.c.o.provides.build
.PHONY : CMakeFiles/myPacman.dir/src/physics.c.o.provides

CMakeFiles/myPacman.dir/src/physics.c.o.provides.build: CMakeFiles/myPacman.dir/src/physics.c.o


# Object files for target myPacman
myPacman_OBJECTS = \
"CMakeFiles/myPacman.dir/src/game.c.o" \
"CMakeFiles/myPacman.dir/src/physics.c.o"

# External object files for target myPacman
myPacman_EXTERNAL_OBJECTS =

myPacman: CMakeFiles/myPacman.dir/src/game.c.o
myPacman: CMakeFiles/myPacman.dir/src/physics.c.o
myPacman: CMakeFiles/myPacman.dir/build.make
myPacman: liblib.a
myPacman: CMakeFiles/myPacman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mosy/Desktop/96106088/pacman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable myPacman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myPacman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myPacman.dir/build: myPacman

.PHONY : CMakeFiles/myPacman.dir/build

CMakeFiles/myPacman.dir/requires: CMakeFiles/myPacman.dir/src/game.c.o.requires
CMakeFiles/myPacman.dir/requires: CMakeFiles/myPacman.dir/src/physics.c.o.requires

.PHONY : CMakeFiles/myPacman.dir/requires

CMakeFiles/myPacman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myPacman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myPacman.dir/clean

CMakeFiles/myPacman.dir/depend:
	cd /home/mosy/Desktop/96106088/pacman && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mosy/Desktop/96106088/pacman /home/mosy/Desktop/96106088/pacman /home/mosy/Desktop/96106088/pacman /home/mosy/Desktop/96106088/pacman /home/mosy/Desktop/96106088/pacman/CMakeFiles/myPacman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myPacman.dir/depend
