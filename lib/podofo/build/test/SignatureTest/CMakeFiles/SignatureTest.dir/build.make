# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lorenzo/CLionProjects/PdfManagement/lib/podofo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build

# Include any dependencies generated for this target.
include test/SignatureTest/CMakeFiles/SignatureTest.dir/depend.make

# Include the progress variables for this target.
include test/SignatureTest/CMakeFiles/SignatureTest.dir/progress.make

# Include the compile flags for this target's objects.
include test/SignatureTest/CMakeFiles/SignatureTest.dir/flags.make

test/SignatureTest/CMakeFiles/SignatureTest.dir/SignTest.cpp.o: test/SignatureTest/CMakeFiles/SignatureTest.dir/flags.make
test/SignatureTest/CMakeFiles/SignatureTest.dir/SignTest.cpp.o: ../test/SignatureTest/SignTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/SignatureTest/CMakeFiles/SignatureTest.dir/SignTest.cpp.o"
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/test/SignatureTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SignatureTest.dir/SignTest.cpp.o -c /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/test/SignatureTest/SignTest.cpp

test/SignatureTest/CMakeFiles/SignatureTest.dir/SignTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SignatureTest.dir/SignTest.cpp.i"
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/test/SignatureTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/test/SignatureTest/SignTest.cpp > CMakeFiles/SignatureTest.dir/SignTest.cpp.i

test/SignatureTest/CMakeFiles/SignatureTest.dir/SignTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SignatureTest.dir/SignTest.cpp.s"
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/test/SignatureTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/test/SignatureTest/SignTest.cpp -o CMakeFiles/SignatureTest.dir/SignTest.cpp.s

# Object files for target SignatureTest
SignatureTest_OBJECTS = \
"CMakeFiles/SignatureTest.dir/SignTest.cpp.o"

# External object files for target SignatureTest
SignatureTest_EXTERNAL_OBJECTS =

test/SignatureTest/SignatureTest: test/SignatureTest/CMakeFiles/SignatureTest.dir/SignTest.cpp.o
test/SignatureTest/SignatureTest: test/SignatureTest/CMakeFiles/SignatureTest.dir/build.make
test/SignatureTest/SignatureTest: /usr/local/lib/libz.so
test/SignatureTest/SignatureTest: /usr/lib/x86_64-linux-gnu/libcrypto.so
test/SignatureTest/SignatureTest: /usr/lib/x86_64-linux-gnu/libssl.so
test/SignatureTest/SignatureTest: /usr/lib/x86_64-linux-gnu/libjpeg.so
test/SignatureTest/SignatureTest: /usr/local/lib/libfreetype.so
test/SignatureTest/SignatureTest: /usr/lib/x86_64-linux-gnu/libpng.so
test/SignatureTest/SignatureTest: /usr/local/lib/libz.so
test/SignatureTest/SignatureTest: /usr/lib/x86_64-linux-gnu/libtiff.so
test/SignatureTest/SignatureTest: /usr/lib/x86_64-linux-gnu/libcrypto.so
test/SignatureTest/SignatureTest: /usr/lib/x86_64-linux-gnu/libssl.so
test/SignatureTest/SignatureTest: /usr/lib/x86_64-linux-gnu/libjpeg.so
test/SignatureTest/SignatureTest: /usr/local/lib/libfreetype.so
test/SignatureTest/SignatureTest: /usr/lib/x86_64-linux-gnu/libpng.so
test/SignatureTest/SignatureTest: /usr/lib/x86_64-linux-gnu/libtiff.so
test/SignatureTest/SignatureTest: test/SignatureTest/CMakeFiles/SignatureTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SignatureTest"
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/test/SignatureTest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SignatureTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/SignatureTest/CMakeFiles/SignatureTest.dir/build: test/SignatureTest/SignatureTest

.PHONY : test/SignatureTest/CMakeFiles/SignatureTest.dir/build

test/SignatureTest/CMakeFiles/SignatureTest.dir/clean:
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/test/SignatureTest && $(CMAKE_COMMAND) -P CMakeFiles/SignatureTest.dir/cmake_clean.cmake
.PHONY : test/SignatureTest/CMakeFiles/SignatureTest.dir/clean

test/SignatureTest/CMakeFiles/SignatureTest.dir/depend:
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lorenzo/CLionProjects/PdfManagement/lib/podofo /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/test/SignatureTest /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/test/SignatureTest /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/test/SignatureTest/CMakeFiles/SignatureTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/SignatureTest/CMakeFiles/SignatureTest.dir/depend
