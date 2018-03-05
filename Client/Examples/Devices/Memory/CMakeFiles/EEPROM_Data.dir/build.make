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
include Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/depend.make

# Include the progress variables for this target.
include Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/progress.make

# Include the compile flags for this target's objects.
include Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/flags.make

Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o: Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/flags.make
Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o: Examples/Devices/Memory/EEPROM_Data.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nabil/Documents/COMP105P/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o"
	cd /home/nabil/Documents/COMP105P/Client/Examples/Devices/Memory && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o   -c /home/nabil/Documents/COMP105P/Client/Examples/Devices/Memory/EEPROM_Data.c

Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.i"
	cd /home/nabil/Documents/COMP105P/Client/Examples/Devices/Memory && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nabil/Documents/COMP105P/Client/Examples/Devices/Memory/EEPROM_Data.c > CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.i

Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.s"
	cd /home/nabil/Documents/COMP105P/Client/Examples/Devices/Memory && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nabil/Documents/COMP105P/Client/Examples/Devices/Memory/EEPROM_Data.c -o CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.s

Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o.requires:

.PHONY : Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o.requires

Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o.provides: Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o.requires
	$(MAKE) -f Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/build.make Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o.provides.build
.PHONY : Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o.provides

Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o.provides.build: Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o


# Object files for target EEPROM_Data
EEPROM_Data_OBJECTS = \
"CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o"

# External object files for target EEPROM_Data
EEPROM_Data_EXTERNAL_OBJECTS =

Examples/Devices/Memory/EEPROM_Data: Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o
Examples/Devices/Memory/EEPROM_Data: Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/build.make
Examples/Devices/Memory/EEPROM_Data: src/libclient.a
Examples/Devices/Memory/EEPROM_Data: Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nabil/Documents/COMP105P/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable EEPROM_Data"
	cd /home/nabil/Documents/COMP105P/Client/Examples/Devices/Memory && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EEPROM_Data.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/build: Examples/Devices/Memory/EEPROM_Data

.PHONY : Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/build

Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/requires: Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/EEPROM_Data.c.o.requires

.PHONY : Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/requires

Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/clean:
	cd /home/nabil/Documents/COMP105P/Client/Examples/Devices/Memory && $(CMAKE_COMMAND) -P CMakeFiles/EEPROM_Data.dir/cmake_clean.cmake
.PHONY : Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/clean

Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/depend:
	cd /home/nabil/Documents/COMP105P/Client && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nabil/Documents/COMP105P/Client /home/nabil/Documents/COMP105P/Client/Examples/Devices/Memory /home/nabil/Documents/COMP105P/Client /home/nabil/Documents/COMP105P/Client/Examples/Devices/Memory /home/nabil/Documents/COMP105P/Client/Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Examples/Devices/Memory/CMakeFiles/EEPROM_Data.dir/depend
