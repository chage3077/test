# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = F:\huangjiahui\software\CMake\bin\cmake.exe

# The command to remove a file.
RM = F:\huangjiahui\software\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\huangjiahui\mycode\my_github\c++_code\SharePattren

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\huangjiahui\mycode\my_github\c++_code\SharePattren\build

# Include any dependencies generated for this target.
include CMakeFiles/SharedPattern.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SharedPattern.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SharedPattern.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SharedPattern.dir/flags.make

CMakeFiles/SharedPattern.dir/main.cpp.obj: CMakeFiles/SharedPattern.dir/flags.make
CMakeFiles/SharedPattern.dir/main.cpp.obj: CMakeFiles/SharedPattern.dir/includes_CXX.rsp
CMakeFiles/SharedPattern.dir/main.cpp.obj: F:/huangjiahui/mycode/my_github/c++_code/SharePattren/main.cpp
CMakeFiles/SharedPattern.dir/main.cpp.obj: CMakeFiles/SharedPattern.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\huangjiahui\mycode\my_github\c++_code\SharePattren\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SharedPattern.dir/main.cpp.obj"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SharedPattern.dir/main.cpp.obj -MF CMakeFiles\SharedPattern.dir\main.cpp.obj.d -o CMakeFiles\SharedPattern.dir\main.cpp.obj -c F:\huangjiahui\mycode\my_github\c++_code\SharePattren\main.cpp

CMakeFiles/SharedPattern.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedPattern.dir/main.cpp.i"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\huangjiahui\mycode\my_github\c++_code\SharePattren\main.cpp > CMakeFiles\SharedPattern.dir\main.cpp.i

CMakeFiles/SharedPattern.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedPattern.dir/main.cpp.s"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\huangjiahui\mycode\my_github\c++_code\SharePattren\main.cpp -o CMakeFiles\SharedPattern.dir\main.cpp.s

CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.obj: CMakeFiles/SharedPattern.dir/flags.make
CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.obj: CMakeFiles/SharedPattern.dir/includes_CXX.rsp
CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.obj: F:/huangjiahui/mycode/my_github/c++_code/SharePattren/src/BoomBodyFactory.cpp
CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.obj: CMakeFiles/SharedPattern.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\huangjiahui\mycode\my_github\c++_code\SharePattren\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.obj"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.obj -MF CMakeFiles\SharedPattern.dir\src\BoomBodyFactory.cpp.obj.d -o CMakeFiles\SharedPattern.dir\src\BoomBodyFactory.cpp.obj -c F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\BoomBodyFactory.cpp

CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.i"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\BoomBodyFactory.cpp > CMakeFiles\SharedPattern.dir\src\BoomBodyFactory.cpp.i

CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.s"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\BoomBodyFactory.cpp -o CMakeFiles\SharedPattern.dir\src\BoomBodyFactory.cpp.s

CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.obj: CMakeFiles/SharedPattern.dir/flags.make
CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.obj: CMakeFiles/SharedPattern.dir/includes_CXX.rsp
CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.obj: F:/huangjiahui/mycode/my_github/c++_code/SharePattren/src/LunchBoom.cpp
CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.obj: CMakeFiles/SharedPattern.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\huangjiahui\mycode\my_github\c++_code\SharePattren\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.obj"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.obj -MF CMakeFiles\SharedPattern.dir\src\LunchBoom.cpp.obj.d -o CMakeFiles\SharedPattern.dir\src\LunchBoom.cpp.obj -c F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\LunchBoom.cpp

CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.i"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\LunchBoom.cpp > CMakeFiles\SharedPattern.dir\src\LunchBoom.cpp.i

CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.s"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\LunchBoom.cpp -o CMakeFiles\SharedPattern.dir\src\LunchBoom.cpp.s

CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.obj: CMakeFiles/SharedPattern.dir/flags.make
CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.obj: CMakeFiles/SharedPattern.dir/includes_CXX.rsp
CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.obj: F:/huangjiahui/mycode/my_github/c++_code/SharePattren/src/SharedBoomBody.cpp
CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.obj: CMakeFiles/SharedPattern.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\huangjiahui\mycode\my_github\c++_code\SharePattren\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.obj"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.obj -MF CMakeFiles\SharedPattern.dir\src\SharedBoomBody.cpp.obj.d -o CMakeFiles\SharedPattern.dir\src\SharedBoomBody.cpp.obj -c F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\SharedBoomBody.cpp

CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.i"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\SharedBoomBody.cpp > CMakeFiles\SharedPattern.dir\src\SharedBoomBody.cpp.i

CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.s"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\SharedBoomBody.cpp -o CMakeFiles\SharedPattern.dir\src\SharedBoomBody.cpp.s

CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.obj: CMakeFiles/SharedPattern.dir/flags.make
CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.obj: CMakeFiles/SharedPattern.dir/includes_CXX.rsp
CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.obj: F:/huangjiahui/mycode/my_github/c++_code/SharePattren/src/UniqueBoomBody.cpp
CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.obj: CMakeFiles/SharedPattern.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\huangjiahui\mycode\my_github\c++_code\SharePattren\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.obj"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.obj -MF CMakeFiles\SharedPattern.dir\src\UniqueBoomBody.cpp.obj.d -o CMakeFiles\SharedPattern.dir\src\UniqueBoomBody.cpp.obj -c F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\UniqueBoomBody.cpp

CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.i"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\UniqueBoomBody.cpp > CMakeFiles\SharedPattern.dir\src\UniqueBoomBody.cpp.i

CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.s"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\huangjiahui\mycode\my_github\c++_code\SharePattren\src\UniqueBoomBody.cpp -o CMakeFiles\SharedPattern.dir\src\UniqueBoomBody.cpp.s

# Object files for target SharedPattern
SharedPattern_OBJECTS = \
"CMakeFiles/SharedPattern.dir/main.cpp.obj" \
"CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.obj" \
"CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.obj" \
"CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.obj" \
"CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.obj"

# External object files for target SharedPattern
SharedPattern_EXTERNAL_OBJECTS =

F:/huangjiahui/mycode/my_github/c++_code/SharePattren/exe/SharedPattern.exe: CMakeFiles/SharedPattern.dir/main.cpp.obj
F:/huangjiahui/mycode/my_github/c++_code/SharePattren/exe/SharedPattern.exe: CMakeFiles/SharedPattern.dir/src/BoomBodyFactory.cpp.obj
F:/huangjiahui/mycode/my_github/c++_code/SharePattren/exe/SharedPattern.exe: CMakeFiles/SharedPattern.dir/src/LunchBoom.cpp.obj
F:/huangjiahui/mycode/my_github/c++_code/SharePattren/exe/SharedPattern.exe: CMakeFiles/SharedPattern.dir/src/SharedBoomBody.cpp.obj
F:/huangjiahui/mycode/my_github/c++_code/SharePattren/exe/SharedPattern.exe: CMakeFiles/SharedPattern.dir/src/UniqueBoomBody.cpp.obj
F:/huangjiahui/mycode/my_github/c++_code/SharePattren/exe/SharedPattern.exe: CMakeFiles/SharedPattern.dir/build.make
F:/huangjiahui/mycode/my_github/c++_code/SharePattren/exe/SharedPattern.exe: CMakeFiles/SharedPattern.dir/linkLibs.rsp
F:/huangjiahui/mycode/my_github/c++_code/SharePattren/exe/SharedPattern.exe: CMakeFiles/SharedPattern.dir/objects1.rsp
F:/huangjiahui/mycode/my_github/c++_code/SharePattren/exe/SharedPattern.exe: CMakeFiles/SharedPattern.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\huangjiahui\mycode\my_github\c++_code\SharePattren\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable F:\huangjiahui\mycode\my_github\c++_code\SharePattren\exe\SharedPattern.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SharedPattern.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SharedPattern.dir/build: F:/huangjiahui/mycode/my_github/c++_code/SharePattren/exe/SharedPattern.exe
.PHONY : CMakeFiles/SharedPattern.dir/build

CMakeFiles/SharedPattern.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SharedPattern.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SharedPattern.dir/clean

CMakeFiles/SharedPattern.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\huangjiahui\mycode\my_github\c++_code\SharePattren F:\huangjiahui\mycode\my_github\c++_code\SharePattren F:\huangjiahui\mycode\my_github\c++_code\SharePattren\build F:\huangjiahui\mycode\my_github\c++_code\SharePattren\build F:\huangjiahui\mycode\my_github\c++_code\SharePattren\build\CMakeFiles\SharedPattern.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SharedPattern.dir/depend

