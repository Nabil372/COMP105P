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
include applications/CMakeFiles/final.dir/depend.make

# Include the progress variables for this target.
include applications/CMakeFiles/final.dir/progress.make

# Include the compile flags for this target's objects.
include applications/CMakeFiles/final.dir/flags.make

applications/CMakeFiles/final.dir/final.c.o: applications/CMakeFiles/final.dir/flags.make
applications/CMakeFiles/final.dir/final.c.o: applications/final.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nabil/Documents/COMP105P/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object applications/CMakeFiles/final.dir/final.c.o"
	cd /home/nabil/Documents/COMP105P/Client/applications && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/final.dir/final.c.o   -c /home/nabil/Documents/COMP105P/Client/applications/final.c

applications/CMakeFiles/final.dir/final.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/final.dir/final.c.i"
	cd /home/nabil/Documents/COMP105P/Client/applications && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nabil/Documents/COMP105P/Client/applications/final.c > CMakeFiles/final.dir/final.c.i

applications/CMakeFiles/final.dir/final.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/final.dir/final.c.s"
	cd /home/nabil/Documents/COMP105P/Client/applications && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nabil/Documents/COMP105P/Client/applications/final.c -o CMakeFiles/final.dir/final.c.s

applications/CMakeFiles/final.dir/final.c.o.requires:

.PHONY : applications/CMakeFiles/final.dir/final.c.o.requires

applications/CMakeFiles/final.dir/final.c.o.provides: applications/CMakeFiles/final.dir/final.c.o.requires
	$(MAKE) -f applications/CMakeFiles/final.dir/build.make applications/CMakeFiles/final.dir/final.c.o.provides.build
.PHONY : applications/CMakeFiles/final.dir/final.c.o.provides

applications/CMakeFiles/final.dir/final.c.o.provides.build: applications/CMakeFiles/final.dir/final.c.o


# Object files for target final
final_OBJECTS = \
"CMakeFiles/final.dir/final.c.o"

# External object files for target final
final_EXTERNAL_OBJECTS =

applications/final: applications/CMakeFiles/final.dir/final.c.o
applications/final: applications/CMakeFiles/final.dir/build.make
applications/final: src/libclient.a
applications/final: applications/CMakeFiles/final.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nabil/Documents/COMP105P/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable final"
	cd /home/nabil/Documents/COMP105P/Client/applications && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/final.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
applications/CMakeFiles/final.dir/build: applications/final

.PHONY : applications/CMakeFiles/final.dir/build

applications/CMakeFiles/final.dir/requires: applications/CMakeFiles/final.dir/final.c.o.requires

.PHONY : applications/CMakeFiles/final.dir/requires

applications/CMakeFiles/final.dir/clean:
	cd /home/nabil/Documents/COMP105P/Client/applications && $(CMAKE_COMMAND) -P CMakeFiles/final.dir/cmake_clean.cmake
.PHONY : applications/CMakeFiles/final.dir/clean

applications/CMakeFiles/final.dir/depend:
	cd /home/nabil/Documents/COMP105P/Client && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nabil/Documents/COMP105P/Client /home/nabil/Documents/COMP105P/Client/applications /home/nabil/Documents/COMP105P/Client /home/nabil/Documents/COMP105P/Client/applications /home/nabil/Documents/COMP105P/Client/applications/CMakeFiles/final.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : applications/CMakeFiles/final.dir/depend
