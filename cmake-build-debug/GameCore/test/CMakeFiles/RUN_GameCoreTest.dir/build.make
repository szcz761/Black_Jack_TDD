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

# Utility rule file for RUN_GameCoreTest.

# Include the progress variables for this target.
include GameCore/test/CMakeFiles/RUN_GameCoreTest.dir/progress.make

GameCore/test/CMakeFiles/RUN_GameCoreTest:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/szymon/modernCppTddWorkshop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) GameCoreTest
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/GameCore/test && ./GameCoreTest

RUN_GameCoreTest: GameCore/test/CMakeFiles/RUN_GameCoreTest
RUN_GameCoreTest: GameCore/test/CMakeFiles/RUN_GameCoreTest.dir/build.make

.PHONY : RUN_GameCoreTest

# Rule to build all files generated by this target.
GameCore/test/CMakeFiles/RUN_GameCoreTest.dir/build: RUN_GameCoreTest

.PHONY : GameCore/test/CMakeFiles/RUN_GameCoreTest.dir/build

GameCore/test/CMakeFiles/RUN_GameCoreTest.dir/clean:
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/GameCore/test && $(CMAKE_COMMAND) -P CMakeFiles/RUN_GameCoreTest.dir/cmake_clean.cmake
.PHONY : GameCore/test/CMakeFiles/RUN_GameCoreTest.dir/clean

GameCore/test/CMakeFiles/RUN_GameCoreTest.dir/depend:
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/szymon/modernCppTddWorkshop /home/szymon/modernCppTddWorkshop/GameCore/test /home/szymon/modernCppTddWorkshop/cmake-build-debug /home/szymon/modernCppTddWorkshop/cmake-build-debug/GameCore/test /home/szymon/modernCppTddWorkshop/cmake-build-debug/GameCore/test/CMakeFiles/RUN_GameCoreTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : GameCore/test/CMakeFiles/RUN_GameCoreTest.dir/depend

