# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_.dir/flags.make

CMakeFiles/_.dir/main.cpp.o: CMakeFiles/_.dir/flags.make
CMakeFiles/_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/_.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/_.dir/main.cpp.o -c "/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка/main.cpp"

CMakeFiles/_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка/main.cpp" > CMakeFiles/_.dir/main.cpp.i

CMakeFiles/_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка/main.cpp" -o CMakeFiles/_.dir/main.cpp.s

# Object files for target _
__OBJECTS = \
"CMakeFiles/_.dir/main.cpp.o"

# External object files for target _
__EXTERNAL_OBJECTS =

_ : CMakeFiles/_.dir/main.cpp.o
_ : CMakeFiles/_.dir/build.make
_ : CMakeFiles/_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable _"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_.dir/build: _

.PHONY : CMakeFiles/_.dir/build

CMakeFiles/_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/_.dir/clean

CMakeFiles/_.dir/depend:
	cd "/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка" "/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка" "/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка/cmake-build-debug" "/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка/cmake-build-debug" "/Users/maksimeliseev/Documents/Python/Git_hub/Coursera/С++/белый пояс/Новая папка/cmake-build-debug/CMakeFiles/_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/_.dir/depend

