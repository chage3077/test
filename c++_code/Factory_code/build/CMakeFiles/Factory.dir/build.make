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
CMAKE_SOURCE_DIR = F:\huangjiahui\mycode\my_github\Factory_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\huangjiahui\mycode\my_github\Factory_code\build

# Include any dependencies generated for this target.
include CMakeFiles/Factory.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Factory.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Factory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Factory.dir/flags.make

CMakeFiles/Factory.dir/main.cpp.obj: CMakeFiles/Factory.dir/flags.make
CMakeFiles/Factory.dir/main.cpp.obj: CMakeFiles/Factory.dir/includes_CXX.rsp
CMakeFiles/Factory.dir/main.cpp.obj: F:/huangjiahui/mycode/my_github/Factory_code/main.cpp
CMakeFiles/Factory.dir/main.cpp.obj: CMakeFiles/Factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\huangjiahui\mycode\my_github\Factory_code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Factory.dir/main.cpp.obj"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Factory.dir/main.cpp.obj -MF CMakeFiles\Factory.dir\main.cpp.obj.d -o CMakeFiles\Factory.dir\main.cpp.obj -c F:\huangjiahui\mycode\my_github\Factory_code\main.cpp

CMakeFiles/Factory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory.dir/main.cpp.i"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\huangjiahui\mycode\my_github\Factory_code\main.cpp > CMakeFiles\Factory.dir\main.cpp.i

CMakeFiles/Factory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory.dir/main.cpp.s"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\huangjiahui\mycode\my_github\Factory_code\main.cpp -o CMakeFiles\Factory.dir\main.cpp.s

CMakeFiles/Factory.dir/src/Cat.cpp.obj: CMakeFiles/Factory.dir/flags.make
CMakeFiles/Factory.dir/src/Cat.cpp.obj: CMakeFiles/Factory.dir/includes_CXX.rsp
CMakeFiles/Factory.dir/src/Cat.cpp.obj: F:/huangjiahui/mycode/my_github/Factory_code/src/Cat.cpp
CMakeFiles/Factory.dir/src/Cat.cpp.obj: CMakeFiles/Factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\huangjiahui\mycode\my_github\Factory_code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Factory.dir/src/Cat.cpp.obj"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Factory.dir/src/Cat.cpp.obj -MF CMakeFiles\Factory.dir\src\Cat.cpp.obj.d -o CMakeFiles\Factory.dir\src\Cat.cpp.obj -c F:\huangjiahui\mycode\my_github\Factory_code\src\Cat.cpp

CMakeFiles/Factory.dir/src/Cat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory.dir/src/Cat.cpp.i"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\huangjiahui\mycode\my_github\Factory_code\src\Cat.cpp > CMakeFiles\Factory.dir\src\Cat.cpp.i

CMakeFiles/Factory.dir/src/Cat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory.dir/src/Cat.cpp.s"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\huangjiahui\mycode\my_github\Factory_code\src\Cat.cpp -o CMakeFiles\Factory.dir\src\Cat.cpp.s

CMakeFiles/Factory.dir/src/CatFactory.cpp.obj: CMakeFiles/Factory.dir/flags.make
CMakeFiles/Factory.dir/src/CatFactory.cpp.obj: CMakeFiles/Factory.dir/includes_CXX.rsp
CMakeFiles/Factory.dir/src/CatFactory.cpp.obj: F:/huangjiahui/mycode/my_github/Factory_code/src/CatFactory.cpp
CMakeFiles/Factory.dir/src/CatFactory.cpp.obj: CMakeFiles/Factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\huangjiahui\mycode\my_github\Factory_code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Factory.dir/src/CatFactory.cpp.obj"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Factory.dir/src/CatFactory.cpp.obj -MF CMakeFiles\Factory.dir\src\CatFactory.cpp.obj.d -o CMakeFiles\Factory.dir\src\CatFactory.cpp.obj -c F:\huangjiahui\mycode\my_github\Factory_code\src\CatFactory.cpp

CMakeFiles/Factory.dir/src/CatFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory.dir/src/CatFactory.cpp.i"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\huangjiahui\mycode\my_github\Factory_code\src\CatFactory.cpp > CMakeFiles\Factory.dir\src\CatFactory.cpp.i

CMakeFiles/Factory.dir/src/CatFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory.dir/src/CatFactory.cpp.s"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\huangjiahui\mycode\my_github\Factory_code\src\CatFactory.cpp -o CMakeFiles\Factory.dir\src\CatFactory.cpp.s

CMakeFiles/Factory.dir/src/Dog.cpp.obj: CMakeFiles/Factory.dir/flags.make
CMakeFiles/Factory.dir/src/Dog.cpp.obj: CMakeFiles/Factory.dir/includes_CXX.rsp
CMakeFiles/Factory.dir/src/Dog.cpp.obj: F:/huangjiahui/mycode/my_github/Factory_code/src/Dog.cpp
CMakeFiles/Factory.dir/src/Dog.cpp.obj: CMakeFiles/Factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\huangjiahui\mycode\my_github\Factory_code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Factory.dir/src/Dog.cpp.obj"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Factory.dir/src/Dog.cpp.obj -MF CMakeFiles\Factory.dir\src\Dog.cpp.obj.d -o CMakeFiles\Factory.dir\src\Dog.cpp.obj -c F:\huangjiahui\mycode\my_github\Factory_code\src\Dog.cpp

CMakeFiles/Factory.dir/src/Dog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory.dir/src/Dog.cpp.i"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\huangjiahui\mycode\my_github\Factory_code\src\Dog.cpp > CMakeFiles\Factory.dir\src\Dog.cpp.i

CMakeFiles/Factory.dir/src/Dog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory.dir/src/Dog.cpp.s"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\huangjiahui\mycode\my_github\Factory_code\src\Dog.cpp -o CMakeFiles\Factory.dir\src\Dog.cpp.s

CMakeFiles/Factory.dir/src/DogFactory.cpp.obj: CMakeFiles/Factory.dir/flags.make
CMakeFiles/Factory.dir/src/DogFactory.cpp.obj: CMakeFiles/Factory.dir/includes_CXX.rsp
CMakeFiles/Factory.dir/src/DogFactory.cpp.obj: F:/huangjiahui/mycode/my_github/Factory_code/src/DogFactory.cpp
CMakeFiles/Factory.dir/src/DogFactory.cpp.obj: CMakeFiles/Factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\huangjiahui\mycode\my_github\Factory_code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Factory.dir/src/DogFactory.cpp.obj"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Factory.dir/src/DogFactory.cpp.obj -MF CMakeFiles\Factory.dir\src\DogFactory.cpp.obj.d -o CMakeFiles\Factory.dir\src\DogFactory.cpp.obj -c F:\huangjiahui\mycode\my_github\Factory_code\src\DogFactory.cpp

CMakeFiles/Factory.dir/src/DogFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory.dir/src/DogFactory.cpp.i"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\huangjiahui\mycode\my_github\Factory_code\src\DogFactory.cpp > CMakeFiles\Factory.dir\src\DogFactory.cpp.i

CMakeFiles/Factory.dir/src/DogFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory.dir/src/DogFactory.cpp.s"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\huangjiahui\mycode\my_github\Factory_code\src\DogFactory.cpp -o CMakeFiles\Factory.dir\src\DogFactory.cpp.s

CMakeFiles/Factory.dir/src/Factory.cpp.obj: CMakeFiles/Factory.dir/flags.make
CMakeFiles/Factory.dir/src/Factory.cpp.obj: CMakeFiles/Factory.dir/includes_CXX.rsp
CMakeFiles/Factory.dir/src/Factory.cpp.obj: F:/huangjiahui/mycode/my_github/Factory_code/src/Factory.cpp
CMakeFiles/Factory.dir/src/Factory.cpp.obj: CMakeFiles/Factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\huangjiahui\mycode\my_github\Factory_code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Factory.dir/src/Factory.cpp.obj"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Factory.dir/src/Factory.cpp.obj -MF CMakeFiles\Factory.dir\src\Factory.cpp.obj.d -o CMakeFiles\Factory.dir\src\Factory.cpp.obj -c F:\huangjiahui\mycode\my_github\Factory_code\src\Factory.cpp

CMakeFiles/Factory.dir/src/Factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory.dir/src/Factory.cpp.i"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\huangjiahui\mycode\my_github\Factory_code\src\Factory.cpp > CMakeFiles\Factory.dir\src\Factory.cpp.i

CMakeFiles/Factory.dir/src/Factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory.dir/src/Factory.cpp.s"
	F:\huangjiahui\software\MinGW\w64devkit-1.19.0\w64devkit\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\huangjiahui\mycode\my_github\Factory_code\src\Factory.cpp -o CMakeFiles\Factory.dir\src\Factory.cpp.s

# Object files for target Factory
Factory_OBJECTS = \
"CMakeFiles/Factory.dir/main.cpp.obj" \
"CMakeFiles/Factory.dir/src/Cat.cpp.obj" \
"CMakeFiles/Factory.dir/src/CatFactory.cpp.obj" \
"CMakeFiles/Factory.dir/src/Dog.cpp.obj" \
"CMakeFiles/Factory.dir/src/DogFactory.cpp.obj" \
"CMakeFiles/Factory.dir/src/Factory.cpp.obj"

# External object files for target Factory
Factory_EXTERNAL_OBJECTS =

F:/huangjiahui/mycode/my_github/Factory_code/exe/Factory.exe: CMakeFiles/Factory.dir/main.cpp.obj
F:/huangjiahui/mycode/my_github/Factory_code/exe/Factory.exe: CMakeFiles/Factory.dir/src/Cat.cpp.obj
F:/huangjiahui/mycode/my_github/Factory_code/exe/Factory.exe: CMakeFiles/Factory.dir/src/CatFactory.cpp.obj
F:/huangjiahui/mycode/my_github/Factory_code/exe/Factory.exe: CMakeFiles/Factory.dir/src/Dog.cpp.obj
F:/huangjiahui/mycode/my_github/Factory_code/exe/Factory.exe: CMakeFiles/Factory.dir/src/DogFactory.cpp.obj
F:/huangjiahui/mycode/my_github/Factory_code/exe/Factory.exe: CMakeFiles/Factory.dir/src/Factory.cpp.obj
F:/huangjiahui/mycode/my_github/Factory_code/exe/Factory.exe: CMakeFiles/Factory.dir/build.make
F:/huangjiahui/mycode/my_github/Factory_code/exe/Factory.exe: CMakeFiles/Factory.dir/linkLibs.rsp
F:/huangjiahui/mycode/my_github/Factory_code/exe/Factory.exe: CMakeFiles/Factory.dir/objects1.rsp
F:/huangjiahui/mycode/my_github/Factory_code/exe/Factory.exe: CMakeFiles/Factory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\huangjiahui\mycode\my_github\Factory_code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable F:\huangjiahui\mycode\my_github\Factory_code\exe\Factory.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Factory.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Factory.dir/build: F:/huangjiahui/mycode/my_github/Factory_code/exe/Factory.exe
.PHONY : CMakeFiles/Factory.dir/build

CMakeFiles/Factory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Factory.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Factory.dir/clean

CMakeFiles/Factory.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\huangjiahui\mycode\my_github\Factory_code F:\huangjiahui\mycode\my_github\Factory_code F:\huangjiahui\mycode\my_github\Factory_code\build F:\huangjiahui\mycode\my_github\Factory_code\build F:\huangjiahui\mycode\my_github\Factory_code\build\CMakeFiles\Factory.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Factory.dir/depend
