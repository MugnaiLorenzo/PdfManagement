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
include tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/depend.make

# Include the progress variables for this target.
include tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/progress.make

# Include the compile flags for this target's objects.
include tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/flags.make

tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.o: tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/flags.make
tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.o: ../tools/podofotxtextract/TextExtractor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.o"
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/tools/podofotxtextract && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.o -c /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/tools/podofotxtextract/TextExtractor.cpp

tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.i"
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/tools/podofotxtextract && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/tools/podofotxtextract/TextExtractor.cpp > CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.i

tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.s"
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/tools/podofotxtextract && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/tools/podofotxtextract/TextExtractor.cpp -o CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.s

tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.o: tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/flags.make
tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.o: ../tools/podofotxtextract/podofotxtextract.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.o"
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/tools/podofotxtextract && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.o -c /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/tools/podofotxtextract/podofotxtextract.cpp

tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.i"
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/tools/podofotxtextract && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/tools/podofotxtextract/podofotxtextract.cpp > CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.i

tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.s"
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/tools/podofotxtextract && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/tools/podofotxtextract/podofotxtextract.cpp -o CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.s

# Object files for target podofotxtextract
podofotxtextract_OBJECTS = \
"CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.o" \
"CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.o"

# External object files for target podofotxtextract
podofotxtextract_EXTERNAL_OBJECTS =

tools/podofotxtextract/podofotxtextract: tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/TextExtractor.cpp.o
tools/podofotxtextract/podofotxtextract: tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/podofotxtextract.cpp.o
tools/podofotxtextract/podofotxtextract: tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/build.make
tools/podofotxtextract/podofotxtextract: tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable podofotxtextract"
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/tools/podofotxtextract && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/podofotxtextract.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/build: tools/podofotxtextract/podofotxtextract

.PHONY : tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/build

tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/clean:
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/tools/podofotxtextract && $(CMAKE_COMMAND) -P CMakeFiles/podofotxtextract.dir/cmake_clean.cmake
.PHONY : tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/clean

tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/depend:
	cd /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lorenzo/CLionProjects/PdfManagement/lib/podofo /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/tools/podofotxtextract /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/tools/podofotxtextract /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/podofotxtextract/CMakeFiles/podofotxtextract.dir/depend

