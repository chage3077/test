# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = F:/software/cmake/bin/cmake.exe

# The command to remove a file.
RM = F:/software/cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:/mycode/design_model_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:/mycode/design_model_code/build

# Include any dependencies generated for this target.
include CMakeFiles/Mytest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Mytest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Mytest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Mytest.dir/flags.make

CMakeFiles/Mytest.dir/main.cpp.obj: CMakeFiles/Mytest.dir/flags.make
CMakeFiles/Mytest.dir/main.cpp.obj: CMakeFiles/Mytest.dir/includes_CXX.rsp
CMakeFiles/Mytest.dir/main.cpp.obj: F:/mycode/design_model_code/main.cpp
CMakeFiles/Mytest.dir/main.cpp.obj: CMakeFiles/Mytest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:/mycode/design_model_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Mytest.dir/main.cpp.obj"
	F:/software/mingw-w64/w64devkit-1.19.0/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mytest.dir/main.cpp.obj -MF CMakeFiles/Mytest.dir/main.cpp.obj.d -o CMakeFiles/Mytest.dir/main.cpp.obj -c F:/mycode/design_model_code/main.cpp

CMakeFiles/Mytest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Mytest.dir/main.cpp.i"
	F:/software/mingw-w64/w64devkit-1.19.0/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:/mycode/design_model_code/main.cpp > CMakeFiles/Mytest.dir/main.cpp.i

CMakeFiles/Mytest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Mytest.dir/main.cpp.s"
	F:/software/mingw-w64/w64devkit-1.19.0/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:/mycode/design_model_code/main.cpp -o CMakeFiles/Mytest.dir/main.cpp.s

CMakeFiles/Mytest.dir/src/Association.cpp.obj: CMakeFiles/Mytest.dir/flags.make
CMakeFiles/Mytest.dir/src/Association.cpp.obj: CMakeFiles/Mytest.dir/includes_CXX.rsp
CMakeFiles/Mytest.dir/src/Association.cpp.obj: F:/mycode/design_model_code/src/Association.cpp
CMakeFiles/Mytest.dir/src/Association.cpp.obj: CMakeFiles/Mytest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:/mycode/design_model_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Mytest.dir/src/Association.cpp.obj"
	F:/software/mingw-w64/w64devkit-1.19.0/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mytest.dir/src/Association.cpp.obj -MF CMakeFiles/Mytest.dir/src/Association.cpp.obj.d -o CMakeFiles/Mytest.dir/src/Association.cpp.obj -c F:/mycode/design_model_code/src/Association.cpp

CMakeFiles/Mytest.dir/src/Association.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Mytest.dir/src/Association.cpp.i"
	F:/software/mingw-w64/w64devkit-1.19.0/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:/mycode/design_model_code/src/Association.cpp > CMakeFiles/Mytest.dir/src/Association.cpp.i

CMakeFiles/Mytest.dir/src/Association.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Mytest.dir/src/Association.cpp.s"
	F:/software/mingw-w64/w64devkit-1.19.0/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:/mycode/design_model_code/src/Association.cpp -o CMakeFiles/Mytest.dir/src/Association.cpp.s

CMakeFiles/Mytest.dir/src/Generalization.cpp.obj: CMakeFiles/Mytest.dir/flags.make
CMakeFiles/Mytest.dir/src/Generalization.cpp.obj: CMakeFiles/Mytest.dir/includes_CXX.rsp
CMakeFiles/Mytest.dir/src/Generalization.cpp.obj: F:/mycode/design_model_code/src/Generalization.cpp
CMakeFiles/Mytest.dir/src/Generalization.cpp.obj: CMakeFiles/Mytest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:/mycode/design_model_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Mytest.dir/src/Generalization.cpp.obj"
	F:/software/mingw-w64/w64devkit-1.19.0/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mytest.dir/src/Generalization.cpp.obj -MF CMakeFiles/Mytest.dir/src/Generalization.cpp.obj.d -o CMakeFiles/Mytest.dir/src/Generalization.cpp.obj -c F:/mycode/design_model_code/src/Generalization.cpp

CMakeFiles/Mytest.dir/src/Generalization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Mytest.dir/src/Generalization.cpp.i"
	F:/software/mingw-w64/w64devkit-1.19.0/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:/mycode/design_model_code/src/Generalization.cpp > CMakeFiles/Mytest.dir/src/Generalization.cpp.i

CMakeFiles/Mytest.dir/src/Generalization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Mytest.dir/src/Generalization.cpp.s"
	F:/software/mingw-w64/w64devkit-1.19.0/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:/mycode/design_model_code/src/Generalization.cpp -o CMakeFiles/Mytest.dir/src/Generalization.cpp.s

# Object files for target Mytest
Mytest_OBJECTS = \
"CMakeFiles/Mytest.dir/main.cpp.obj" \
"CMakeFiles/Mytest.dir/src/Association.cpp.obj" \
"CMakeFiles/Mytest.dir/src/Generalization.cpp.obj"

# External object files for target Mytest
Mytest_EXTERNAL_OBJECTS =

Mytest.exe: CMakeFiles/Mytest.dir/main.cpp.obj
Mytest.exe: CMakeFiles/Mytest.dir/src/Association.cpp.obj
Mytest.exe: CMakeFiles/Mytest.dir/src/Generalization.cpp.obj
Mytest.exe: CMakeFiles/Mytest.dir/build.make
Mytest.exe: CMakeFiles/Mytest.dir/linkLibs.rsp
Mytest.exe: CMakeFiles/Mytest.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:/mycode/design_model_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Mytest.exe"
	F:/software/cmake/bin/cmake.exe -E rm -f CMakeFiles/Mytest.dir/objects.a
	F:/software/mingw-w64/w64devkit-1.19.0/w64devkit/bin/ar.exe qc CMakeFiles/Mytest.dir/objects.a @CMakeFiles/Mytest.dir/objects1.rsp
	F:/software/mingw-w64/w64devkit-1.19.0/w64devkit/bin/c++.exe -g -Wl,--whole-archive CMakeFiles/Mytest.dir/objects.a -Wl,--no-whole-archive -o Mytest.exe -Wl,--out-implib,libMytest.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/Mytest.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/Mytest.dir/build: Mytest.exe
.PHONY : CMakeFiles/Mytest.dir/build

CMakeFiles/Mytest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Mytest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Mytest.dir/clean

CMakeFiles/Mytest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" F:/mycode/design_model_code F:/mycode/design_model_code F:/mycode/design_model_code/build F:/mycode/design_model_code/build F:/mycode/design_model_code/build/CMakeFiles/Mytest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Mytest.dir/depend
