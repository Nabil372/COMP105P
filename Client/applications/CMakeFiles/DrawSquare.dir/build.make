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
include applications/CMakeFiles/DrawSquare.dir/depend.make

# Include the progress variables for this target.
include applications/CMakeFiles/DrawSquare.dir/progress.make

# Include the compile flags for this target's objects.
include applications/CMakeFiles/DrawSquare.dir/flags.make

# Object files for target DrawSquare
DrawSquare_OBJECTS =

# External object files for target DrawSquare
DrawSquare_EXTERNAL_OBJECTS =

applications/DrawSquare: applications/CMakeFiles/DrawSquare.dir/build.make
applications/DrawSquare: src/libclient.a
applications/DrawSquare: applications/CMakeFiles/DrawSquare.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nabil/Documents/COMP105P/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX executable DrawSquare"
	cd /home/nabil/Documents/COMP105P/Client/applications && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DrawSquare.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
applications/CMakeFiles/DrawSquare.dir/build: applications/DrawSquare

.PHONY : applications/CMakeFiles/DrawSquare.dir/build

applications/CMakeFiles/DrawSquare.dir/requires:

.PHONY : applications/CMakeFiles/DrawSquare.dir/requires

applications/CMakeFiles/DrawSquare.dir/clean:
	cd /home/nabil/Documents/COMP105P/Client/applications && $(CMAKE_COMMAND) -P CMakeFiles/DrawSquare.dir/cmake_clean.cmake
.PHONY : applications/CMakeFiles/DrawSquare.dir/clean

applications/CMakeFiles/DrawSquare.dir/depend:
	cd /home/nabil/Documents/COMP105P/Client && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nabil/Documents/COMP105P/Client /home/nabil/Documents/COMP105P/Client/applications /home/nabil/Documents/COMP105P/Client /home/nabil/Documents/COMP105P/Client/applications /home/nabil/Documents/COMP105P/Client/applications/CMakeFiles/DrawSquare.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : applications/CMakeFiles/DrawSquare.dir/depend

