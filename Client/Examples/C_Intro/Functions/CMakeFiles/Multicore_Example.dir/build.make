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
include Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/depend.make

# Include the progress variables for this target.
include Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/progress.make

# Include the compile flags for this target's objects.
include Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/flags.make

Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o: Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/flags.make
Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o: Examples/C_Intro/Functions/Multicore_Example.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nabil/Documents/COMP105P/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o"
	cd /home/nabil/Documents/COMP105P/Client/Examples/C_Intro/Functions && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o   -c /home/nabil/Documents/COMP105P/Client/Examples/C_Intro/Functions/Multicore_Example.c

Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Multicore_Example.dir/Multicore_Example.c.i"
	cd /home/nabil/Documents/COMP105P/Client/Examples/C_Intro/Functions && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nabil/Documents/COMP105P/Client/Examples/C_Intro/Functions/Multicore_Example.c > CMakeFiles/Multicore_Example.dir/Multicore_Example.c.i

Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Multicore_Example.dir/Multicore_Example.c.s"
	cd /home/nabil/Documents/COMP105P/Client/Examples/C_Intro/Functions && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nabil/Documents/COMP105P/Client/Examples/C_Intro/Functions/Multicore_Example.c -o CMakeFiles/Multicore_Example.dir/Multicore_Example.c.s

Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o.requires:

.PHONY : Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o.requires

Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o.provides: Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o.requires
	$(MAKE) -f Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/build.make Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o.provides.build
.PHONY : Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o.provides

Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o.provides.build: Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o


# Object files for target Multicore_Example
Multicore_Example_OBJECTS = \
"CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o"

# External object files for target Multicore_Example
Multicore_Example_EXTERNAL_OBJECTS =

Examples/C_Intro/Functions/Multicore_Example: Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o
Examples/C_Intro/Functions/Multicore_Example: Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/build.make
Examples/C_Intro/Functions/Multicore_Example: src/libclient.a
Examples/C_Intro/Functions/Multicore_Example: Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nabil/Documents/COMP105P/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Multicore_Example"
	cd /home/nabil/Documents/COMP105P/Client/Examples/C_Intro/Functions && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Multicore_Example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/build: Examples/C_Intro/Functions/Multicore_Example

.PHONY : Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/build

Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/requires: Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/Multicore_Example.c.o.requires

.PHONY : Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/requires

Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/clean:
	cd /home/nabil/Documents/COMP105P/Client/Examples/C_Intro/Functions && $(CMAKE_COMMAND) -P CMakeFiles/Multicore_Example.dir/cmake_clean.cmake
.PHONY : Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/clean

Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/depend:
	cd /home/nabil/Documents/COMP105P/Client && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nabil/Documents/COMP105P/Client /home/nabil/Documents/COMP105P/Client/Examples/C_Intro/Functions /home/nabil/Documents/COMP105P/Client /home/nabil/Documents/COMP105P/Client/Examples/C_Intro/Functions /home/nabil/Documents/COMP105P/Client/Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Examples/C_Intro/Functions/CMakeFiles/Multicore_Example.dir/depend
