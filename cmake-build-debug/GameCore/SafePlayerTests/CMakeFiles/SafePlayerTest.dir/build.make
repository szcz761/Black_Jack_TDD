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
include GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/depend.make

# Include the progress variables for this target.
include GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/progress.make

# Include the compile flags for this target's objects.
include GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/flags.make

GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o: GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/flags.make
GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o: ../GameCore/SafePlayerTests/SafePlayerTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/szymon/modernCppTddWorkshop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/GameCore/SafePlayerTests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o -c /home/szymon/modernCppTddWorkshop/GameCore/SafePlayerTests/SafePlayerTests.cpp

GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.i"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/GameCore/SafePlayerTests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/szymon/modernCppTddWorkshop/GameCore/SafePlayerTests/SafePlayerTests.cpp > CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.i

GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.s"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/GameCore/SafePlayerTests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/szymon/modernCppTddWorkshop/GameCore/SafePlayerTests/SafePlayerTests.cpp -o CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.s

GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o.requires:

.PHONY : GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o.requires

GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o.provides: GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o.requires
	$(MAKE) -f GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/build.make GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o.provides.build
.PHONY : GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o.provides

GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o.provides.build: GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o


# Object files for target SafePlayerTest
SafePlayerTest_OBJECTS = \
"CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o"

# External object files for target SafePlayerTest
SafePlayerTest_EXTERNAL_OBJECTS =

GameCore/SafePlayerTests/SafePlayerTest: GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o
GameCore/SafePlayerTests/SafePlayerTest: GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/build.make
GameCore/SafePlayerTests/SafePlayerTest: lib/googlemock/libgmockd.a
GameCore/SafePlayerTests/SafePlayerTest: lib/googlemock/libgmock_maind.a
GameCore/SafePlayerTests/SafePlayerTest: GameCore/libGameCoreLibd.a
GameCore/SafePlayerTests/SafePlayerTest: GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/szymon/modernCppTddWorkshop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SafePlayerTest"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/GameCore/SafePlayerTests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SafePlayerTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/build: GameCore/SafePlayerTests/SafePlayerTest

.PHONY : GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/build

GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/requires: GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/SafePlayerTests.cpp.o.requires

.PHONY : GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/requires

GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/clean:
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/GameCore/SafePlayerTests && $(CMAKE_COMMAND) -P CMakeFiles/SafePlayerTest.dir/cmake_clean.cmake
.PHONY : GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/clean

GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/depend:
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/szymon/modernCppTddWorkshop /home/szymon/modernCppTddWorkshop/GameCore/SafePlayerTests /home/szymon/modernCppTddWorkshop/cmake-build-debug /home/szymon/modernCppTddWorkshop/cmake-build-debug/GameCore/SafePlayerTests /home/szymon/modernCppTddWorkshop/cmake-build-debug/GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : GameCore/SafePlayerTests/CMakeFiles/SafePlayerTest.dir/depend
