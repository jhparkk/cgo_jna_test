# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c

# Include any dependencies generated for this target.
include CMakeFiles/runclib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/runclib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/runclib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runclib.dir/flags.make

CMakeFiles/runclib.dir/main.cpp.obj: CMakeFiles/runclib.dir/flags.make
CMakeFiles/runclib.dir/main.cpp.obj: CMakeFiles/runclib.dir/includes_CXX.rsp
CMakeFiles/runclib.dir/main.cpp.obj: main.cpp
CMakeFiles/runclib.dir/main.cpp.obj: CMakeFiles/runclib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runclib.dir/main.cpp.obj"
	C:\Users\dbmas\AppData\Local\Programs\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runclib.dir/main.cpp.obj -MF CMakeFiles\runclib.dir\main.cpp.obj.d -o CMakeFiles\runclib.dir\main.cpp.obj -c C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c\main.cpp

CMakeFiles/runclib.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runclib.dir/main.cpp.i"
	C:\Users\dbmas\AppData\Local\Programs\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c\main.cpp > CMakeFiles\runclib.dir\main.cpp.i

CMakeFiles/runclib.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runclib.dir/main.cpp.s"
	C:\Users\dbmas\AppData\Local\Programs\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c\main.cpp -o CMakeFiles\runclib.dir\main.cpp.s

# Object files for target runclib
runclib_OBJECTS = \
"CMakeFiles/runclib.dir/main.cpp.obj"

# External object files for target runclib
runclib_EXTERNAL_OBJECTS =

runclib.exe: CMakeFiles/runclib.dir/main.cpp.obj
runclib.exe: CMakeFiles/runclib.dir/build.make
runclib.exe: CMakeFiles/runclib.dir/linklibs.rsp
runclib.exe: CMakeFiles/runclib.dir/objects1.rsp
runclib.exe: CMakeFiles/runclib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runclib.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\runclib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runclib.dir/build: runclib.exe
.PHONY : CMakeFiles/runclib.dir/build

CMakeFiles/runclib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\runclib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/runclib.dir/clean

CMakeFiles/runclib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c C:\Users\dbmas\workspace\c_c++\cgo_jni_test\run_c\CMakeFiles\runclib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runclib.dir/depend

