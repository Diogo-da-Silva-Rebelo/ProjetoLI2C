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
CMAKE_COMMAND = /home/vortex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/vortex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vortex/CLionProjects/LI2PL7G4/Projeto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RastrosLI2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RastrosLI2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RastrosLI2.dir/flags.make

CMakeFiles/RastrosLI2.dir/main.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RastrosLI2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/main.c.o   -c /home/vortex/CLionProjects/LI2PL7G4/Projeto/main.c

CMakeFiles/RastrosLI2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vortex/CLionProjects/LI2PL7G4/Projeto/main.c > CMakeFiles/RastrosLI2.dir/main.c.i

CMakeFiles/RastrosLI2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vortex/CLionProjects/LI2PL7G4/Projeto/main.c -o CMakeFiles/RastrosLI2.dir/main.c.s

CMakeFiles/RastrosLI2.dir/listas.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/listas.c.o: ../listas.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/RastrosLI2.dir/listas.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/listas.c.o   -c /home/vortex/CLionProjects/LI2PL7G4/Projeto/listas.c

CMakeFiles/RastrosLI2.dir/listas.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/listas.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vortex/CLionProjects/LI2PL7G4/Projeto/listas.c > CMakeFiles/RastrosLI2.dir/listas.c.i

CMakeFiles/RastrosLI2.dir/listas.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/listas.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vortex/CLionProjects/LI2PL7G4/Projeto/listas.c -o CMakeFiles/RastrosLI2.dir/listas.c.s

CMakeFiles/RastrosLI2.dir/io.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/io.c.o: ../io.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/RastrosLI2.dir/io.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/io.c.o   -c /home/vortex/CLionProjects/LI2PL7G4/Projeto/io.c

CMakeFiles/RastrosLI2.dir/io.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/io.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vortex/CLionProjects/LI2PL7G4/Projeto/io.c > CMakeFiles/RastrosLI2.dir/io.c.i

CMakeFiles/RastrosLI2.dir/io.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/io.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vortex/CLionProjects/LI2PL7G4/Projeto/io.c -o CMakeFiles/RastrosLI2.dir/io.c.s

CMakeFiles/RastrosLI2.dir/interface.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/interface.c.o: ../interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/RastrosLI2.dir/interface.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/interface.c.o   -c /home/vortex/CLionProjects/LI2PL7G4/Projeto/interface.c

CMakeFiles/RastrosLI2.dir/interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/interface.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vortex/CLionProjects/LI2PL7G4/Projeto/interface.c > CMakeFiles/RastrosLI2.dir/interface.c.i

CMakeFiles/RastrosLI2.dir/interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/interface.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vortex/CLionProjects/LI2PL7G4/Projeto/interface.c -o CMakeFiles/RastrosLI2.dir/interface.c.s

CMakeFiles/RastrosLI2.dir/logica.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/logica.c.o: ../logica.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/RastrosLI2.dir/logica.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/logica.c.o   -c /home/vortex/CLionProjects/LI2PL7G4/Projeto/logica.c

CMakeFiles/RastrosLI2.dir/logica.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/logica.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vortex/CLionProjects/LI2PL7G4/Projeto/logica.c > CMakeFiles/RastrosLI2.dir/logica.c.i

CMakeFiles/RastrosLI2.dir/logica.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/logica.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vortex/CLionProjects/LI2PL7G4/Projeto/logica.c -o CMakeFiles/RastrosLI2.dir/logica.c.s

CMakeFiles/RastrosLI2.dir/dados.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/dados.c.o: ../dados.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/RastrosLI2.dir/dados.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/dados.c.o   -c /home/vortex/CLionProjects/LI2PL7G4/Projeto/dados.c

CMakeFiles/RastrosLI2.dir/dados.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/dados.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vortex/CLionProjects/LI2PL7G4/Projeto/dados.c > CMakeFiles/RastrosLI2.dir/dados.c.i

CMakeFiles/RastrosLI2.dir/dados.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/dados.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vortex/CLionProjects/LI2PL7G4/Projeto/dados.c -o CMakeFiles/RastrosLI2.dir/dados.c.s

CMakeFiles/RastrosLI2.dir/io_aux.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/io_aux.c.o: ../io_aux.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/RastrosLI2.dir/io_aux.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/io_aux.c.o   -c /home/vortex/CLionProjects/LI2PL7G4/Projeto/io_aux.c

CMakeFiles/RastrosLI2.dir/io_aux.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/io_aux.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vortex/CLionProjects/LI2PL7G4/Projeto/io_aux.c > CMakeFiles/RastrosLI2.dir/io_aux.c.i

CMakeFiles/RastrosLI2.dir/io_aux.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/io_aux.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vortex/CLionProjects/LI2PL7G4/Projeto/io_aux.c -o CMakeFiles/RastrosLI2.dir/io_aux.c.s

# Object files for target RastrosLI2
RastrosLI2_OBJECTS = \
"CMakeFiles/RastrosLI2.dir/main.c.o" \
"CMakeFiles/RastrosLI2.dir/listas.c.o" \
"CMakeFiles/RastrosLI2.dir/io.c.o" \
"CMakeFiles/RastrosLI2.dir/interface.c.o" \
"CMakeFiles/RastrosLI2.dir/logica.c.o" \
"CMakeFiles/RastrosLI2.dir/dados.c.o" \
"CMakeFiles/RastrosLI2.dir/io_aux.c.o"

# External object files for target RastrosLI2
RastrosLI2_EXTERNAL_OBJECTS =

RastrosLI2: CMakeFiles/RastrosLI2.dir/main.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/listas.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/io.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/interface.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/logica.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/dados.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/io_aux.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/build.make
RastrosLI2: CMakeFiles/RastrosLI2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable RastrosLI2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RastrosLI2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RastrosLI2.dir/build: RastrosLI2

.PHONY : CMakeFiles/RastrosLI2.dir/build

CMakeFiles/RastrosLI2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RastrosLI2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RastrosLI2.dir/clean

CMakeFiles/RastrosLI2.dir/depend:
	cd /home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vortex/CLionProjects/LI2PL7G4/Projeto /home/vortex/CLionProjects/LI2PL7G4/Projeto /home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug /home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug /home/vortex/CLionProjects/LI2PL7G4/Projeto/cmake-build-debug/CMakeFiles/RastrosLI2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RastrosLI2.dir/depend
