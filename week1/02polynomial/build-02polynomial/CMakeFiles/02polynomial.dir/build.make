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
CMAKE_SOURCE_DIR = D:\Work\Mooc\week1\02polynomial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Work\Mooc\week1\02polynomial\build-02polynomial

# Include any dependencies generated for this target.
include CMakeFiles/02polynomial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/02polynomial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/02polynomial.dir/flags.make

CMakeFiles/02polynomial.dir/main.cpp.obj: CMakeFiles/02polynomial.dir/flags.make
CMakeFiles/02polynomial.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Work\Mooc\week1\02polynomial\build-02polynomial\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/02polynomial.dir/main.cpp.obj"
	D:\ProgramFiles\Qt\Tools\mingw530_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\02polynomial.dir\main.cpp.obj -c D:\Work\Mooc\week1\02polynomial\main.cpp

CMakeFiles/02polynomial.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/02polynomial.dir/main.cpp.i"
	D:\ProgramFiles\Qt\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Work\Mooc\week1\02polynomial\main.cpp > CMakeFiles\02polynomial.dir\main.cpp.i

CMakeFiles/02polynomial.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/02polynomial.dir/main.cpp.s"
	D:\ProgramFiles\Qt\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Work\Mooc\week1\02polynomial\main.cpp -o CMakeFiles\02polynomial.dir\main.cpp.s

# Object files for target 02polynomial
02polynomial_OBJECTS = \
"CMakeFiles/02polynomial.dir/main.cpp.obj"

# External object files for target 02polynomial
02polynomial_EXTERNAL_OBJECTS =

02polynomial.exe: CMakeFiles/02polynomial.dir/main.cpp.obj
02polynomial.exe: CMakeFiles/02polynomial.dir/build.make
02polynomial.exe: CMakeFiles/02polynomial.dir/linklibs.rsp
02polynomial.exe: CMakeFiles/02polynomial.dir/objects1.rsp
02polynomial.exe: CMakeFiles/02polynomial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Work\Mooc\week1\02polynomial\build-02polynomial\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 02polynomial.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\02polynomial.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/02polynomial.dir/build: 02polynomial.exe

.PHONY : CMakeFiles/02polynomial.dir/build

CMakeFiles/02polynomial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\02polynomial.dir\cmake_clean.cmake
.PHONY : CMakeFiles/02polynomial.dir/clean

CMakeFiles/02polynomial.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Work\Mooc\week1\02polynomial D:\Work\Mooc\week1\02polynomial D:\Work\Mooc\week1\02polynomial\build-02polynomial D:\Work\Mooc\week1\02polynomial\build-02polynomial D:\Work\Mooc\week1\02polynomial\build-02polynomial\CMakeFiles\02polynomial.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/02polynomial.dir/depend

