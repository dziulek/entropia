# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/piotr/Dokumenty/myProjects/entropia

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/piotr/Dokumenty/myProjects/entropia/build

# Include any dependencies generated for this target.
include CMakeFiles/Enthropy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Enthropy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Enthropy.dir/flags.make

CMakeFiles/Enthropy.dir/_vector.cpp.o: CMakeFiles/Enthropy.dir/flags.make
CMakeFiles/Enthropy.dir/_vector.cpp.o: ../_vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piotr/Dokumenty/myProjects/entropia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Enthropy.dir/_vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Enthropy.dir/_vector.cpp.o -c /home/piotr/Dokumenty/myProjects/entropia/_vector.cpp

CMakeFiles/Enthropy.dir/_vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Enthropy.dir/_vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piotr/Dokumenty/myProjects/entropia/_vector.cpp > CMakeFiles/Enthropy.dir/_vector.cpp.i

CMakeFiles/Enthropy.dir/_vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Enthropy.dir/_vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piotr/Dokumenty/myProjects/entropia/_vector.cpp -o CMakeFiles/Enthropy.dir/_vector.cpp.s

CMakeFiles/Enthropy.dir/enthropy.cpp.o: CMakeFiles/Enthropy.dir/flags.make
CMakeFiles/Enthropy.dir/enthropy.cpp.o: ../enthropy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piotr/Dokumenty/myProjects/entropia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Enthropy.dir/enthropy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Enthropy.dir/enthropy.cpp.o -c /home/piotr/Dokumenty/myProjects/entropia/enthropy.cpp

CMakeFiles/Enthropy.dir/enthropy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Enthropy.dir/enthropy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piotr/Dokumenty/myProjects/entropia/enthropy.cpp > CMakeFiles/Enthropy.dir/enthropy.cpp.i

CMakeFiles/Enthropy.dir/enthropy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Enthropy.dir/enthropy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piotr/Dokumenty/myProjects/entropia/enthropy.cpp -o CMakeFiles/Enthropy.dir/enthropy.cpp.s

CMakeFiles/Enthropy.dir/main.cpp.o: CMakeFiles/Enthropy.dir/flags.make
CMakeFiles/Enthropy.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piotr/Dokumenty/myProjects/entropia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Enthropy.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Enthropy.dir/main.cpp.o -c /home/piotr/Dokumenty/myProjects/entropia/main.cpp

CMakeFiles/Enthropy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Enthropy.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piotr/Dokumenty/myProjects/entropia/main.cpp > CMakeFiles/Enthropy.dir/main.cpp.i

CMakeFiles/Enthropy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Enthropy.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piotr/Dokumenty/myProjects/entropia/main.cpp -o CMakeFiles/Enthropy.dir/main.cpp.s

CMakeFiles/Enthropy.dir/particle.cpp.o: CMakeFiles/Enthropy.dir/flags.make
CMakeFiles/Enthropy.dir/particle.cpp.o: ../particle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piotr/Dokumenty/myProjects/entropia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Enthropy.dir/particle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Enthropy.dir/particle.cpp.o -c /home/piotr/Dokumenty/myProjects/entropia/particle.cpp

CMakeFiles/Enthropy.dir/particle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Enthropy.dir/particle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piotr/Dokumenty/myProjects/entropia/particle.cpp > CMakeFiles/Enthropy.dir/particle.cpp.i

CMakeFiles/Enthropy.dir/particle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Enthropy.dir/particle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piotr/Dokumenty/myProjects/entropia/particle.cpp -o CMakeFiles/Enthropy.dir/particle.cpp.s

CMakeFiles/Enthropy.dir/plot.cpp.o: CMakeFiles/Enthropy.dir/flags.make
CMakeFiles/Enthropy.dir/plot.cpp.o: ../plot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piotr/Dokumenty/myProjects/entropia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Enthropy.dir/plot.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Enthropy.dir/plot.cpp.o -c /home/piotr/Dokumenty/myProjects/entropia/plot.cpp

CMakeFiles/Enthropy.dir/plot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Enthropy.dir/plot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piotr/Dokumenty/myProjects/entropia/plot.cpp > CMakeFiles/Enthropy.dir/plot.cpp.i

CMakeFiles/Enthropy.dir/plot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Enthropy.dir/plot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piotr/Dokumenty/myProjects/entropia/plot.cpp -o CMakeFiles/Enthropy.dir/plot.cpp.s

CMakeFiles/Enthropy.dir/renderer.cpp.o: CMakeFiles/Enthropy.dir/flags.make
CMakeFiles/Enthropy.dir/renderer.cpp.o: ../renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piotr/Dokumenty/myProjects/entropia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Enthropy.dir/renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Enthropy.dir/renderer.cpp.o -c /home/piotr/Dokumenty/myProjects/entropia/renderer.cpp

CMakeFiles/Enthropy.dir/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Enthropy.dir/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piotr/Dokumenty/myProjects/entropia/renderer.cpp > CMakeFiles/Enthropy.dir/renderer.cpp.i

CMakeFiles/Enthropy.dir/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Enthropy.dir/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piotr/Dokumenty/myProjects/entropia/renderer.cpp -o CMakeFiles/Enthropy.dir/renderer.cpp.s

CMakeFiles/Enthropy.dir/simulation.cpp.o: CMakeFiles/Enthropy.dir/flags.make
CMakeFiles/Enthropy.dir/simulation.cpp.o: ../simulation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piotr/Dokumenty/myProjects/entropia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Enthropy.dir/simulation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Enthropy.dir/simulation.cpp.o -c /home/piotr/Dokumenty/myProjects/entropia/simulation.cpp

CMakeFiles/Enthropy.dir/simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Enthropy.dir/simulation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piotr/Dokumenty/myProjects/entropia/simulation.cpp > CMakeFiles/Enthropy.dir/simulation.cpp.i

CMakeFiles/Enthropy.dir/simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Enthropy.dir/simulation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piotr/Dokumenty/myProjects/entropia/simulation.cpp -o CMakeFiles/Enthropy.dir/simulation.cpp.s

# Object files for target Enthropy
Enthropy_OBJECTS = \
"CMakeFiles/Enthropy.dir/_vector.cpp.o" \
"CMakeFiles/Enthropy.dir/enthropy.cpp.o" \
"CMakeFiles/Enthropy.dir/main.cpp.o" \
"CMakeFiles/Enthropy.dir/particle.cpp.o" \
"CMakeFiles/Enthropy.dir/plot.cpp.o" \
"CMakeFiles/Enthropy.dir/renderer.cpp.o" \
"CMakeFiles/Enthropy.dir/simulation.cpp.o"

# External object files for target Enthropy
Enthropy_EXTERNAL_OBJECTS =

Enthropy: CMakeFiles/Enthropy.dir/_vector.cpp.o
Enthropy: CMakeFiles/Enthropy.dir/enthropy.cpp.o
Enthropy: CMakeFiles/Enthropy.dir/main.cpp.o
Enthropy: CMakeFiles/Enthropy.dir/particle.cpp.o
Enthropy: CMakeFiles/Enthropy.dir/plot.cpp.o
Enthropy: CMakeFiles/Enthropy.dir/renderer.cpp.o
Enthropy: CMakeFiles/Enthropy.dir/simulation.cpp.o
Enthropy: CMakeFiles/Enthropy.dir/build.make
Enthropy: CMakeFiles/Enthropy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/piotr/Dokumenty/myProjects/entropia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Enthropy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Enthropy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Enthropy.dir/build: Enthropy

.PHONY : CMakeFiles/Enthropy.dir/build

CMakeFiles/Enthropy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Enthropy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Enthropy.dir/clean

CMakeFiles/Enthropy.dir/depend:
	cd /home/piotr/Dokumenty/myProjects/entropia/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/piotr/Dokumenty/myProjects/entropia /home/piotr/Dokumenty/myProjects/entropia /home/piotr/Dokumenty/myProjects/entropia/build /home/piotr/Dokumenty/myProjects/entropia/build /home/piotr/Dokumenty/myProjects/entropia/build/CMakeFiles/Enthropy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Enthropy.dir/depend

