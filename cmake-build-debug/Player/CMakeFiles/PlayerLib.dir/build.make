# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/szymon/Pulpit/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/szymon/Pulpit/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/szymon/modernCppTddWorkshop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/szymon/modernCppTddWorkshop/cmake-build-debug

# Include any dependencies generated for this target.
include Player/CMakeFiles/PlayerLib.dir/depend.make

# Include the progress variables for this target.
include Player/CMakeFiles/PlayerLib.dir/progress.make

# Include the compile flags for this target's objects.
include Player/CMakeFiles/PlayerLib.dir/flags.make

Player/CMakeFiles/PlayerLib.dir/Player.cpp.o: Player/CMakeFiles/PlayerLib.dir/flags.make
Player/CMakeFiles/PlayerLib.dir/Player.cpp.o: ../Player/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/szymon/modernCppTddWorkshop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Player/CMakeFiles/PlayerLib.dir/Player.cpp.o"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/Player && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PlayerLib.dir/Player.cpp.o -c /home/szymon/modernCppTddWorkshop/Player/Player.cpp

Player/CMakeFiles/PlayerLib.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PlayerLib.dir/Player.cpp.i"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/Player && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/szymon/modernCppTddWorkshop/Player/Player.cpp > CMakeFiles/PlayerLib.dir/Player.cpp.i

Player/CMakeFiles/PlayerLib.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PlayerLib.dir/Player.cpp.s"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/Player && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/szymon/modernCppTddWorkshop/Player/Player.cpp -o CMakeFiles/PlayerLib.dir/Player.cpp.s

Player/CMakeFiles/PlayerLib.dir/Player.cpp.o.requires:

.PHONY : Player/CMakeFiles/PlayerLib.dir/Player.cpp.o.requires

Player/CMakeFiles/PlayerLib.dir/Player.cpp.o.provides: Player/CMakeFiles/PlayerLib.dir/Player.cpp.o.requires
	$(MAKE) -f Player/CMakeFiles/PlayerLib.dir/build.make Player/CMakeFiles/PlayerLib.dir/Player.cpp.o.provides.build
.PHONY : Player/CMakeFiles/PlayerLib.dir/Player.cpp.o.provides

Player/CMakeFiles/PlayerLib.dir/Player.cpp.o.provides.build: Player/CMakeFiles/PlayerLib.dir/Player.cpp.o


# Object files for target PlayerLib
PlayerLib_OBJECTS = \
"CMakeFiles/PlayerLib.dir/Player.cpp.o"

# External object files for target PlayerLib
PlayerLib_EXTERNAL_OBJECTS =

Player/libPlayerLibd.a: Player/CMakeFiles/PlayerLib.dir/Player.cpp.o
Player/libPlayerLibd.a: Player/CMakeFiles/PlayerLib.dir/build.make
Player/libPlayerLibd.a: Player/CMakeFiles/PlayerLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/szymon/modernCppTddWorkshop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libPlayerLibd.a"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/Player && $(CMAKE_COMMAND) -P CMakeFiles/PlayerLib.dir/cmake_clean_target.cmake
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/Player && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PlayerLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Player/CMakeFiles/PlayerLib.dir/build: Player/libPlayerLibd.a

.PHONY : Player/CMakeFiles/PlayerLib.dir/build

Player/CMakeFiles/PlayerLib.dir/requires: Player/CMakeFiles/PlayerLib.dir/Player.cpp.o.requires

.PHONY : Player/CMakeFiles/PlayerLib.dir/requires

Player/CMakeFiles/PlayerLib.dir/clean:
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/Player && $(CMAKE_COMMAND) -P CMakeFiles/PlayerLib.dir/cmake_clean.cmake
.PHONY : Player/CMakeFiles/PlayerLib.dir/clean

Player/CMakeFiles/PlayerLib.dir/depend:
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/szymon/modernCppTddWorkshop /home/szymon/modernCppTddWorkshop/Player /home/szymon/modernCppTddWorkshop/cmake-build-debug /home/szymon/modernCppTddWorkshop/cmake-build-debug/Player /home/szymon/modernCppTddWorkshop/cmake-build-debug/Player/CMakeFiles/PlayerLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Player/CMakeFiles/PlayerLib.dir/depend

