# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "F:\install\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "F:\install\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\recatu\Documents\Library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\recatu\Documents\Library\cmake-build-debug

# Utility rule file for Library_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/Library_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Library_autogen.dir/progress.make

CMakeFiles/Library_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\recatu\Documents\Library\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target Library"
	"F:\install\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E cmake_autogen C:/Users/recatu/Documents/Library/cmake-build-debug/CMakeFiles/Library_autogen.dir/AutogenInfo.json Debug

Library_autogen: CMakeFiles/Library_autogen
Library_autogen: CMakeFiles/Library_autogen.dir/build.make
.PHONY : Library_autogen

# Rule to build all files generated by this target.
CMakeFiles/Library_autogen.dir/build: Library_autogen
.PHONY : CMakeFiles/Library_autogen.dir/build

CMakeFiles/Library_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Library_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Library_autogen.dir/clean

CMakeFiles/Library_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\recatu\Documents\Library C:\Users\recatu\Documents\Library C:\Users\recatu\Documents\Library\cmake-build-debug C:\Users\recatu\Documents\Library\cmake-build-debug C:\Users\recatu\Documents\Library\cmake-build-debug\CMakeFiles\Library_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Library_autogen.dir/depend
