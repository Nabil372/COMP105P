# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/nabil/Documents/COMP105P/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nabil/Documents/COMP105P/Client

# Include any dependencies generated for this target.
include applications/CMakeFiles/spinLeftRight.dir/depend.make

# Include the progress variables for this target.
include applications/CMakeFiles/spinLeftRight.dir/progress.make

# Include the compile flags for this target's objects.
include applications/CMakeFiles/spinLeftRight.dir/flags.make

applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o: applications/CMakeFiles/spinLeftRight.dir/flags.make
applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o: applications/spinLeftRight.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nabil/Documents/COMP105P/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o"
	cd /home/nabil/Documents/COMP105P/Client/applications && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o   -c /home/nabil/Documents/COMP105P/Client/applications/spinLeftRight.c

applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spinLeftRight.dir/spinLeftRight.c.i"
	cd /home/nabil/Documents/COMP105P/Client/applications && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nabil/Documents/COMP105P/Client/applications/spinLeftRight.c > CMakeFiles/spinLeftRight.dir/spinLeftRight.c.i

applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spinLeftRight.dir/spinLeftRight.c.s"
	cd /home/nabil/Documents/COMP105P/Client/applications && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nabil/Documents/COMP105P/Client/applications/spinLeftRight.c -o CMakeFiles/spinLeftRight.dir/spinLeftRight.c.s

applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o.requires:

.PHONY : applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o.requires

applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o.provides: applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o.requires
	$(MAKE) -f applications/CMakeFiles/spinLeftRight.dir/build.make applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o.provides.build
.PHONY : applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o.provides

applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o.provides.build: applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o


# Object files for target spinLeftRight
spinLeftRight_OBJECTS = \
"CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o"

# External object files for target spinLeftRight
spinLeftRight_EXTERNAL_OBJECTS =

applications/spinLeftRight: applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o
applications/spinLeftRight: applications/CMakeFiles/spinLeftRight.dir/build.make
applications/spinLeftRight: src/libclient.a
applications/spinLeftRight: applications/CMakeFiles/spinLeftRight.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nabil/Documents/COMP105P/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable spinLeftRight"
	cd /home/nabil/Documents/COMP105P/Client/applications && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spinLeftRight.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
applications/CMakeFiles/spinLeftRight.dir/build: applications/spinLeftRight

.PHONY : applications/CMakeFiles/spinLeftRight.dir/build

applications/CMakeFiles/spinLeftRight.dir/requires: applications/CMakeFiles/spinLeftRight.dir/spinLeftRight.c.o.requires

.PHONY : applications/CMakeFiles/spinLeftRight.dir/requires

applications/CMakeFiles/spinLeftRight.dir/clean:
	cd /home/nabil/Documents/COMP105P/Client/applications && $(CMAKE_COMMAND) -P CMakeFiles/spinLeftRight.dir/cmake_clean.cmake
.PHONY : applications/CMakeFiles/spinLeftRight.dir/clean

applications/CMakeFiles/spinLeftRight.dir/depend:
	cd /home/nabil/Documents/COMP105P/Client && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nabil/Documents/COMP105P/Client /home/nabil/Documents/COMP105P/Client/applications /home/nabil/Documents/COMP105P/Client /home/nabil/Documents/COMP105P/Client/applications /home/nabil/Documents/COMP105P/Client/applications/CMakeFiles/spinLeftRight.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : applications/CMakeFiles/spinLeftRight.dir/depend

