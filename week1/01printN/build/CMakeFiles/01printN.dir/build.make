# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\ProgramFiles\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\ProgramFiles\CMake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Work\Mooc\week1\01printN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Work\Mooc\week1\01printN\build

# Include any dependencies generated for this target.
include CMakeFiles/01printN.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/01printN.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/01printN.dir/flags.make

CMakeFiles/01printN.dir/main.cpp.obj: CMakeFiles/01printN.dir/flags.make
CMakeFiles/01printN.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Work\Mooc\week1\01printN\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/01printN.dir/main.cpp.obj"
	D:\ProgramFiles\Qt\Tools\mingw530_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\01printN.dir\main.cpp.obj -c D:\Work\Mooc\week1\01printN\main.cpp

CMakeFiles/01printN.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/01printN.dir/main.cpp.i"
	D:\ProgramFiles\Qt\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Work\Mooc\week1\01printN\main.cpp > CMakeFiles\01printN.dir\main.cpp.i

CMakeFiles/01printN.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/01printN.dir/main.cpp.s"
	D:\ProgramFiles\Qt\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Work\Mooc\week1\01printN\main.cpp -o CMakeFiles\01printN.dir\main.cpp.s

# Object files for target 01printN
01printN_OBJECTS = \
"CMakeFiles/01printN.dir/main.cpp.obj"

# External object files for target 01printN
01printN_EXTERNAL_OBJECTS =

01printN.exe: CMakeFiles/01printN.dir/main.cpp.obj
01printN.exe: CMakeFiles/01printN.dir/build.make
01printN.exe: CMakeFiles/01printN.dir/linklibs.rsp
01printN.exe: CMakeFiles/01printN.dir/objects1.rsp
01printN.exe: CMakeFiles/01printN.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Work\Mooc\week1\01printN\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 01printN.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\01printN.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/01printN.dir/build: 01printN.exe

.PHONY : CMakeFiles/01printN.dir/build

CMakeFiles/01printN.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\01printN.dir\cmake_clean.cmake
.PHONY : CMakeFiles/01printN.dir/clean

CMakeFiles/01printN.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Work\Mooc\week1\01printN D:\Work\Mooc\week1\01printN D:\Work\Mooc\week1\01printN\build D:\Work\Mooc\week1\01printN\build D:\Work\Mooc\week1\01printN\build\CMakeFiles\01printN.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/01printN.dir/depend

