# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61"

# Include any dependencies generated for this target.
include CMakeFiles/unittests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/unittests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/unittests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unittests.dir/flags.make

CMakeFiles/unittests.dir/unittests.cpp.o: CMakeFiles/unittests.dir/flags.make
CMakeFiles/unittests.dir/unittests.cpp.o: unittests.cpp
CMakeFiles/unittests.dir/unittests.cpp.o: CMakeFiles/unittests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unittests.dir/unittests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/unittests.dir/unittests.cpp.o -MF CMakeFiles/unittests.dir/unittests.cpp.o.d -o CMakeFiles/unittests.dir/unittests.cpp.o -c "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61/unittests.cpp"

CMakeFiles/unittests.dir/unittests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittests.dir/unittests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61/unittests.cpp" > CMakeFiles/unittests.dir/unittests.cpp.i

CMakeFiles/unittests.dir/unittests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittests.dir/unittests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61/unittests.cpp" -o CMakeFiles/unittests.dir/unittests.cpp.s

CMakeFiles/unittests.dir/test_cqsort.cpp.o: CMakeFiles/unittests.dir/flags.make
CMakeFiles/unittests.dir/test_cqsort.cpp.o: test_cqsort.cpp
CMakeFiles/unittests.dir/test_cqsort.cpp.o: CMakeFiles/unittests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/unittests.dir/test_cqsort.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/unittests.dir/test_cqsort.cpp.o -MF CMakeFiles/unittests.dir/test_cqsort.cpp.o.d -o CMakeFiles/unittests.dir/test_cqsort.cpp.o -c "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61/test_cqsort.cpp"

CMakeFiles/unittests.dir/test_cqsort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittests.dir/test_cqsort.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61/test_cqsort.cpp" > CMakeFiles/unittests.dir/test_cqsort.cpp.i

CMakeFiles/unittests.dir/test_cqsort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittests.dir/test_cqsort.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61/test_cqsort.cpp" -o CMakeFiles/unittests.dir/test_cqsort.cpp.s

# Object files for target unittests
unittests_OBJECTS = \
"CMakeFiles/unittests.dir/unittests.cpp.o" \
"CMakeFiles/unittests.dir/test_cqsort.cpp.o"

# External object files for target unittests
unittests_EXTERNAL_OBJECTS =

unittests: CMakeFiles/unittests.dir/unittests.cpp.o
unittests: CMakeFiles/unittests.dir/test_cqsort.cpp.o
unittests: CMakeFiles/unittests.dir/build.make
unittests: CMakeFiles/unittests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable unittests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unittests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unittests.dir/build: unittests
.PHONY : CMakeFiles/unittests.dir/build

CMakeFiles/unittests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unittests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unittests.dir/clean

CMakeFiles/unittests.dir/depend:
	cd "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61" "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61" "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61" "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61" "/Users/yichenliu/Library/CloudStorage/OneDrive-VirginiaTech/ECE3574 NEW/ece3574-sp22-proj4-yichenl61/CMakeFiles/unittests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/unittests.dir/depend

