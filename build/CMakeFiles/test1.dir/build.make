# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = C:\Users\Jean\CPPSDL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Jean\CPPSDL\build

# Include any dependencies generated for this target.
include CMakeFiles/test1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test1.dir/flags.make

CMakeFiles/test1.dir/test.cc.obj: CMakeFiles/test1.dir/flags.make
CMakeFiles/test1.dir/test.cc.obj: CMakeFiles/test1.dir/includes_CXX.rsp
CMakeFiles/test1.dir/test.cc.obj: C:/Users/Jean/CPPSDL/test.cc
CMakeFiles/test1.dir/test.cc.obj: CMakeFiles/test1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Jean\CPPSDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test1.dir/test.cc.obj"
	C:\MinGW\winlibs-i686-posix-dwarf-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test1.dir/test.cc.obj -MF CMakeFiles\test1.dir\test.cc.obj.d -o CMakeFiles\test1.dir\test.cc.obj -c C:\Users\Jean\CPPSDL\test.cc

CMakeFiles/test1.dir/test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test1.dir/test.cc.i"
	C:\MinGW\winlibs-i686-posix-dwarf-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Jean\CPPSDL\test.cc > CMakeFiles\test1.dir\test.cc.i

CMakeFiles/test1.dir/test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test1.dir/test.cc.s"
	C:\MinGW\winlibs-i686-posix-dwarf-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Jean\CPPSDL\test.cc -o CMakeFiles\test1.dir\test.cc.s

CMakeFiles/test1.dir/src/Score.cpp.obj: CMakeFiles/test1.dir/flags.make
CMakeFiles/test1.dir/src/Score.cpp.obj: CMakeFiles/test1.dir/includes_CXX.rsp
CMakeFiles/test1.dir/src/Score.cpp.obj: C:/Users/Jean/CPPSDL/src/Score.cpp
CMakeFiles/test1.dir/src/Score.cpp.obj: CMakeFiles/test1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Jean\CPPSDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test1.dir/src/Score.cpp.obj"
	C:\MinGW\winlibs-i686-posix-dwarf-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test1.dir/src/Score.cpp.obj -MF CMakeFiles\test1.dir\src\Score.cpp.obj.d -o CMakeFiles\test1.dir\src\Score.cpp.obj -c C:\Users\Jean\CPPSDL\src\Score.cpp

CMakeFiles/test1.dir/src/Score.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test1.dir/src/Score.cpp.i"
	C:\MinGW\winlibs-i686-posix-dwarf-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Jean\CPPSDL\src\Score.cpp > CMakeFiles\test1.dir\src\Score.cpp.i

CMakeFiles/test1.dir/src/Score.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test1.dir/src/Score.cpp.s"
	C:\MinGW\winlibs-i686-posix-dwarf-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Jean\CPPSDL\src\Score.cpp -o CMakeFiles\test1.dir\src\Score.cpp.s

# Object files for target test1
test1_OBJECTS = \
"CMakeFiles/test1.dir/test.cc.obj" \
"CMakeFiles/test1.dir/src/Score.cpp.obj"

# External object files for target test1
test1_EXTERNAL_OBJECTS =

bin/test1.exe: CMakeFiles/test1.dir/test.cc.obj
bin/test1.exe: CMakeFiles/test1.dir/src/Score.cpp.obj
bin/test1.exe: CMakeFiles/test1.dir/build.make
bin/test1.exe: lib/libgtest_main.a
bin/test1.exe: lib/libgtest.a
bin/test1.exe: CMakeFiles/test1.dir/linkLibs.rsp
bin/test1.exe: CMakeFiles/test1.dir/objects1.rsp
bin/test1.exe: CMakeFiles/test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Jean\CPPSDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin\test1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test1.dir\link.txt --verbose=$(VERBOSE)
	"C:\Program Files\CMake\bin\cmake.exe" -D TEST_TARGET=test1 -D TEST_EXECUTABLE=C:/Users/Jean/CPPSDL/build/bin/test1.exe -D TEST_EXECUTOR= -D TEST_WORKING_DIR=C:/Users/Jean/CPPSDL/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=test1_TESTS -D CTEST_FILE=C:/Users/Jean/CPPSDL/build/test1[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P "C:/Program Files/CMake/share/cmake-3.29/Modules/GoogleTestAddTests.cmake"

# Rule to build all files generated by this target.
CMakeFiles/test1.dir/build: bin/test1.exe
.PHONY : CMakeFiles/test1.dir/build

CMakeFiles/test1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test1.dir/clean

CMakeFiles/test1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Jean\CPPSDL C:\Users\Jean\CPPSDL C:\Users\Jean\CPPSDL\build C:\Users\Jean\CPPSDL\build C:\Users\Jean\CPPSDL\build\CMakeFiles\test1.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test1.dir/depend

