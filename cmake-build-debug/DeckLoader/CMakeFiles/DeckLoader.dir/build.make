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
include DeckLoader/CMakeFiles/DeckLoader.dir/depend.make

# Include the progress variables for this target.
include DeckLoader/CMakeFiles/DeckLoader.dir/progress.make

# Include the compile flags for this target's objects.
include DeckLoader/CMakeFiles/DeckLoader.dir/flags.make

DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o: DeckLoader/CMakeFiles/DeckLoader.dir/flags.make
DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o: ../DeckLoader/TextDeckLoader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/szymon/modernCppTddWorkshop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/DeckLoader && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o -c /home/szymon/modernCppTddWorkshop/DeckLoader/TextDeckLoader.cpp

DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.i"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/DeckLoader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/szymon/modernCppTddWorkshop/DeckLoader/TextDeckLoader.cpp > CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.i

DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.s"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/DeckLoader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/szymon/modernCppTddWorkshop/DeckLoader/TextDeckLoader.cpp -o CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.s

DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o.requires:

.PHONY : DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o.requires

DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o.provides: DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o.requires
	$(MAKE) -f DeckLoader/CMakeFiles/DeckLoader.dir/build.make DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o.provides.build
.PHONY : DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o.provides

DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o.provides.build: DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o


# Object files for target DeckLoader
DeckLoader_OBJECTS = \
"CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o"

# External object files for target DeckLoader
DeckLoader_EXTERNAL_OBJECTS =

DeckLoader/libDeckLoaderd.a: DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o
DeckLoader/libDeckLoaderd.a: DeckLoader/CMakeFiles/DeckLoader.dir/build.make
DeckLoader/libDeckLoaderd.a: DeckLoader/CMakeFiles/DeckLoader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/szymon/modernCppTddWorkshop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libDeckLoaderd.a"
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/DeckLoader && $(CMAKE_COMMAND) -P CMakeFiles/DeckLoader.dir/cmake_clean_target.cmake
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/DeckLoader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DeckLoader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DeckLoader/CMakeFiles/DeckLoader.dir/build: DeckLoader/libDeckLoaderd.a

.PHONY : DeckLoader/CMakeFiles/DeckLoader.dir/build

DeckLoader/CMakeFiles/DeckLoader.dir/requires: DeckLoader/CMakeFiles/DeckLoader.dir/TextDeckLoader.cpp.o.requires

.PHONY : DeckLoader/CMakeFiles/DeckLoader.dir/requires

DeckLoader/CMakeFiles/DeckLoader.dir/clean:
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug/DeckLoader && $(CMAKE_COMMAND) -P CMakeFiles/DeckLoader.dir/cmake_clean.cmake
.PHONY : DeckLoader/CMakeFiles/DeckLoader.dir/clean

DeckLoader/CMakeFiles/DeckLoader.dir/depend:
	cd /home/szymon/modernCppTddWorkshop/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/szymon/modernCppTddWorkshop /home/szymon/modernCppTddWorkshop/DeckLoader /home/szymon/modernCppTddWorkshop/cmake-build-debug /home/szymon/modernCppTddWorkshop/cmake-build-debug/DeckLoader /home/szymon/modernCppTddWorkshop/cmake-build-debug/DeckLoader/CMakeFiles/DeckLoader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DeckLoader/CMakeFiles/DeckLoader.dir/depend
