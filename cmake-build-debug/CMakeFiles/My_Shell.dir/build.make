# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/sreejan/Downloads/clion-2021.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sreejan/Downloads/clion-2021.2.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sreejan/CLionProjects/My_Shell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sreejan/CLionProjects/My_Shell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/My_Shell.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/My_Shell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/My_Shell.dir/flags.make

CMakeFiles/My_Shell.dir/main.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/My_Shell.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/main.c.o -c /home/sreejan/CLionProjects/My_Shell/main.c

CMakeFiles/My_Shell.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/main.c > CMakeFiles/My_Shell.dir/main.c.i

CMakeFiles/My_Shell.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/main.c -o CMakeFiles/My_Shell.dir/main.c.s

CMakeFiles/My_Shell.dir/utils/util.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/utils/util.c.o: ../utils/util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/My_Shell.dir/utils/util.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/utils/util.c.o -c /home/sreejan/CLionProjects/My_Shell/utils/util.c

CMakeFiles/My_Shell.dir/utils/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/utils/util.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/utils/util.c > CMakeFiles/My_Shell.dir/utils/util.c.i

CMakeFiles/My_Shell.dir/utils/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/utils/util.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/utils/util.c -o CMakeFiles/My_Shell.dir/utils/util.c.s

CMakeFiles/My_Shell.dir/globals.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/globals.c.o: ../globals.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/My_Shell.dir/globals.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/globals.c.o -c /home/sreejan/CLionProjects/My_Shell/globals.c

CMakeFiles/My_Shell.dir/globals.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/globals.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/globals.c > CMakeFiles/My_Shell.dir/globals.c.i

CMakeFiles/My_Shell.dir/globals.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/globals.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/globals.c -o CMakeFiles/My_Shell.dir/globals.c.s

CMakeFiles/My_Shell.dir/processer/prompt.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/processer/prompt.c.o: ../processer/prompt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/My_Shell.dir/processer/prompt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/processer/prompt.c.o -c /home/sreejan/CLionProjects/My_Shell/processer/prompt.c

CMakeFiles/My_Shell.dir/processer/prompt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/processer/prompt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/processer/prompt.c > CMakeFiles/My_Shell.dir/processer/prompt.c.i

CMakeFiles/My_Shell.dir/processer/prompt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/processer/prompt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/processer/prompt.c -o CMakeFiles/My_Shell.dir/processer/prompt.c.s

CMakeFiles/My_Shell.dir/processer/tokenizer.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/processer/tokenizer.c.o: ../processer/tokenizer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/My_Shell.dir/processer/tokenizer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/processer/tokenizer.c.o -c /home/sreejan/CLionProjects/My_Shell/processer/tokenizer.c

CMakeFiles/My_Shell.dir/processer/tokenizer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/processer/tokenizer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/processer/tokenizer.c > CMakeFiles/My_Shell.dir/processer/tokenizer.c.i

CMakeFiles/My_Shell.dir/processer/tokenizer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/processer/tokenizer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/processer/tokenizer.c -o CMakeFiles/My_Shell.dir/processer/tokenizer.c.s

CMakeFiles/My_Shell.dir/utils/inputmat.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/utils/inputmat.c.o: ../utils/inputmat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/My_Shell.dir/utils/inputmat.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/utils/inputmat.c.o -c /home/sreejan/CLionProjects/My_Shell/utils/inputmat.c

CMakeFiles/My_Shell.dir/utils/inputmat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/utils/inputmat.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/utils/inputmat.c > CMakeFiles/My_Shell.dir/utils/inputmat.c.i

CMakeFiles/My_Shell.dir/utils/inputmat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/utils/inputmat.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/utils/inputmat.c -o CMakeFiles/My_Shell.dir/utils/inputmat.c.s

CMakeFiles/My_Shell.dir/commands/echo.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/commands/echo.c.o: ../commands/echo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/My_Shell.dir/commands/echo.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/commands/echo.c.o -c /home/sreejan/CLionProjects/My_Shell/commands/echo.c

CMakeFiles/My_Shell.dir/commands/echo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/commands/echo.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/commands/echo.c > CMakeFiles/My_Shell.dir/commands/echo.c.i

CMakeFiles/My_Shell.dir/commands/echo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/commands/echo.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/commands/echo.c -o CMakeFiles/My_Shell.dir/commands/echo.c.s

CMakeFiles/My_Shell.dir/commands/pwd.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/commands/pwd.c.o: ../commands/pwd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/My_Shell.dir/commands/pwd.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/commands/pwd.c.o -c /home/sreejan/CLionProjects/My_Shell/commands/pwd.c

CMakeFiles/My_Shell.dir/commands/pwd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/commands/pwd.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/commands/pwd.c > CMakeFiles/My_Shell.dir/commands/pwd.c.i

CMakeFiles/My_Shell.dir/commands/pwd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/commands/pwd.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/commands/pwd.c -o CMakeFiles/My_Shell.dir/commands/pwd.c.s

CMakeFiles/My_Shell.dir/commands/cd.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/commands/cd.c.o: ../commands/cd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/My_Shell.dir/commands/cd.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/commands/cd.c.o -c /home/sreejan/CLionProjects/My_Shell/commands/cd.c

CMakeFiles/My_Shell.dir/commands/cd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/commands/cd.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/commands/cd.c > CMakeFiles/My_Shell.dir/commands/cd.c.i

CMakeFiles/My_Shell.dir/commands/cd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/commands/cd.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/commands/cd.c -o CMakeFiles/My_Shell.dir/commands/cd.c.s

CMakeFiles/My_Shell.dir/commands/ls.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/commands/ls.c.o: ../commands/ls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/My_Shell.dir/commands/ls.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/commands/ls.c.o -c /home/sreejan/CLionProjects/My_Shell/commands/ls.c

CMakeFiles/My_Shell.dir/commands/ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/commands/ls.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/commands/ls.c > CMakeFiles/My_Shell.dir/commands/ls.c.i

CMakeFiles/My_Shell.dir/commands/ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/commands/ls.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/commands/ls.c -o CMakeFiles/My_Shell.dir/commands/ls.c.s

CMakeFiles/My_Shell.dir/processer/bgprocess.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/processer/bgprocess.c.o: ../processer/bgprocess.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/My_Shell.dir/processer/bgprocess.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/processer/bgprocess.c.o -c /home/sreejan/CLionProjects/My_Shell/processer/bgprocess.c

CMakeFiles/My_Shell.dir/processer/bgprocess.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/processer/bgprocess.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/processer/bgprocess.c > CMakeFiles/My_Shell.dir/processer/bgprocess.c.i

CMakeFiles/My_Shell.dir/processer/bgprocess.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/processer/bgprocess.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/processer/bgprocess.c -o CMakeFiles/My_Shell.dir/processer/bgprocess.c.s

CMakeFiles/My_Shell.dir/commands/execvp.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/commands/execvp.c.o: ../commands/execvp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/My_Shell.dir/commands/execvp.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/commands/execvp.c.o -c /home/sreejan/CLionProjects/My_Shell/commands/execvp.c

CMakeFiles/My_Shell.dir/commands/execvp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/commands/execvp.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/commands/execvp.c > CMakeFiles/My_Shell.dir/commands/execvp.c.i

CMakeFiles/My_Shell.dir/commands/execvp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/commands/execvp.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/commands/execvp.c -o CMakeFiles/My_Shell.dir/commands/execvp.c.s

CMakeFiles/My_Shell.dir/commands/pinfo.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/commands/pinfo.c.o: ../commands/pinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/My_Shell.dir/commands/pinfo.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/commands/pinfo.c.o -c /home/sreejan/CLionProjects/My_Shell/commands/pinfo.c

CMakeFiles/My_Shell.dir/commands/pinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/commands/pinfo.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/commands/pinfo.c > CMakeFiles/My_Shell.dir/commands/pinfo.c.i

CMakeFiles/My_Shell.dir/commands/pinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/commands/pinfo.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/commands/pinfo.c -o CMakeFiles/My_Shell.dir/commands/pinfo.c.s

CMakeFiles/My_Shell.dir/utils/processmat.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/utils/processmat.c.o: ../utils/processmat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/My_Shell.dir/utils/processmat.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/utils/processmat.c.o -c /home/sreejan/CLionProjects/My_Shell/utils/processmat.c

CMakeFiles/My_Shell.dir/utils/processmat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/utils/processmat.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/utils/processmat.c > CMakeFiles/My_Shell.dir/utils/processmat.c.i

CMakeFiles/My_Shell.dir/utils/processmat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/utils/processmat.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/utils/processmat.c -o CMakeFiles/My_Shell.dir/utils/processmat.c.s

CMakeFiles/My_Shell.dir/processer/redirections.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/processer/redirections.c.o: ../processer/redirections.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/My_Shell.dir/processer/redirections.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/processer/redirections.c.o -c /home/sreejan/CLionProjects/My_Shell/processer/redirections.c

CMakeFiles/My_Shell.dir/processer/redirections.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/processer/redirections.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/processer/redirections.c > CMakeFiles/My_Shell.dir/processer/redirections.c.i

CMakeFiles/My_Shell.dir/processer/redirections.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/processer/redirections.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/processer/redirections.c -o CMakeFiles/My_Shell.dir/processer/redirections.c.s

CMakeFiles/My_Shell.dir/processer/pipeline.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/processer/pipeline.c.o: ../processer/pipeline.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/My_Shell.dir/processer/pipeline.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/processer/pipeline.c.o -c /home/sreejan/CLionProjects/My_Shell/processer/pipeline.c

CMakeFiles/My_Shell.dir/processer/pipeline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/processer/pipeline.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/processer/pipeline.c > CMakeFiles/My_Shell.dir/processer/pipeline.c.i

CMakeFiles/My_Shell.dir/processer/pipeline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/processer/pipeline.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/processer/pipeline.c -o CMakeFiles/My_Shell.dir/processer/pipeline.c.s

CMakeFiles/My_Shell.dir/commands/jobs.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/commands/jobs.c.o: ../commands/jobs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/My_Shell.dir/commands/jobs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/commands/jobs.c.o -c /home/sreejan/CLionProjects/My_Shell/commands/jobs.c

CMakeFiles/My_Shell.dir/commands/jobs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/commands/jobs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/commands/jobs.c > CMakeFiles/My_Shell.dir/commands/jobs.c.i

CMakeFiles/My_Shell.dir/commands/jobs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/commands/jobs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/commands/jobs.c -o CMakeFiles/My_Shell.dir/commands/jobs.c.s

CMakeFiles/My_Shell.dir/commands/sig.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/commands/sig.c.o: ../commands/sig.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/My_Shell.dir/commands/sig.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/commands/sig.c.o -c /home/sreejan/CLionProjects/My_Shell/commands/sig.c

CMakeFiles/My_Shell.dir/commands/sig.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/commands/sig.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/commands/sig.c > CMakeFiles/My_Shell.dir/commands/sig.c.i

CMakeFiles/My_Shell.dir/commands/sig.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/commands/sig.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/commands/sig.c -o CMakeFiles/My_Shell.dir/commands/sig.c.s

CMakeFiles/My_Shell.dir/commands/fg.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/commands/fg.c.o: ../commands/fg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/My_Shell.dir/commands/fg.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/commands/fg.c.o -c /home/sreejan/CLionProjects/My_Shell/commands/fg.c

CMakeFiles/My_Shell.dir/commands/fg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/commands/fg.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/commands/fg.c > CMakeFiles/My_Shell.dir/commands/fg.c.i

CMakeFiles/My_Shell.dir/commands/fg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/commands/fg.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/commands/fg.c -o CMakeFiles/My_Shell.dir/commands/fg.c.s

CMakeFiles/My_Shell.dir/processer/signals.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/processer/signals.c.o: ../processer/signals.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building C object CMakeFiles/My_Shell.dir/processer/signals.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/processer/signals.c.o -c /home/sreejan/CLionProjects/My_Shell/processer/signals.c

CMakeFiles/My_Shell.dir/processer/signals.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/processer/signals.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/processer/signals.c > CMakeFiles/My_Shell.dir/processer/signals.c.i

CMakeFiles/My_Shell.dir/processer/signals.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/processer/signals.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/processer/signals.c -o CMakeFiles/My_Shell.dir/processer/signals.c.s

CMakeFiles/My_Shell.dir/commands/bg.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/commands/bg.c.o: ../commands/bg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building C object CMakeFiles/My_Shell.dir/commands/bg.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/commands/bg.c.o -c /home/sreejan/CLionProjects/My_Shell/commands/bg.c

CMakeFiles/My_Shell.dir/commands/bg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/commands/bg.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/commands/bg.c > CMakeFiles/My_Shell.dir/commands/bg.c.i

CMakeFiles/My_Shell.dir/commands/bg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/commands/bg.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/commands/bg.c -o CMakeFiles/My_Shell.dir/commands/bg.c.s

CMakeFiles/My_Shell.dir/utils/process.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/utils/process.c.o: ../utils/process.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building C object CMakeFiles/My_Shell.dir/utils/process.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/utils/process.c.o -c /home/sreejan/CLionProjects/My_Shell/utils/process.c

CMakeFiles/My_Shell.dir/utils/process.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/utils/process.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/utils/process.c > CMakeFiles/My_Shell.dir/utils/process.c.i

CMakeFiles/My_Shell.dir/utils/process.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/utils/process.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/utils/process.c -o CMakeFiles/My_Shell.dir/utils/process.c.s

CMakeFiles/My_Shell.dir/utils/print.c.o: CMakeFiles/My_Shell.dir/flags.make
CMakeFiles/My_Shell.dir/utils/print.c.o: ../utils/print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Building C object CMakeFiles/My_Shell.dir/utils/print.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/My_Shell.dir/utils/print.c.o -c /home/sreejan/CLionProjects/My_Shell/utils/print.c

CMakeFiles/My_Shell.dir/utils/print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Shell.dir/utils/print.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sreejan/CLionProjects/My_Shell/utils/print.c > CMakeFiles/My_Shell.dir/utils/print.c.i

CMakeFiles/My_Shell.dir/utils/print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Shell.dir/utils/print.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sreejan/CLionProjects/My_Shell/utils/print.c -o CMakeFiles/My_Shell.dir/utils/print.c.s

# Object files for target My_Shell
My_Shell_OBJECTS = \
"CMakeFiles/My_Shell.dir/main.c.o" \
"CMakeFiles/My_Shell.dir/utils/util.c.o" \
"CMakeFiles/My_Shell.dir/globals.c.o" \
"CMakeFiles/My_Shell.dir/processer/prompt.c.o" \
"CMakeFiles/My_Shell.dir/processer/tokenizer.c.o" \
"CMakeFiles/My_Shell.dir/utils/inputmat.c.o" \
"CMakeFiles/My_Shell.dir/commands/echo.c.o" \
"CMakeFiles/My_Shell.dir/commands/pwd.c.o" \
"CMakeFiles/My_Shell.dir/commands/cd.c.o" \
"CMakeFiles/My_Shell.dir/commands/ls.c.o" \
"CMakeFiles/My_Shell.dir/processer/bgprocess.c.o" \
"CMakeFiles/My_Shell.dir/commands/execvp.c.o" \
"CMakeFiles/My_Shell.dir/commands/pinfo.c.o" \
"CMakeFiles/My_Shell.dir/utils/processmat.c.o" \
"CMakeFiles/My_Shell.dir/processer/redirections.c.o" \
"CMakeFiles/My_Shell.dir/processer/pipeline.c.o" \
"CMakeFiles/My_Shell.dir/commands/jobs.c.o" \
"CMakeFiles/My_Shell.dir/commands/sig.c.o" \
"CMakeFiles/My_Shell.dir/commands/fg.c.o" \
"CMakeFiles/My_Shell.dir/processer/signals.c.o" \
"CMakeFiles/My_Shell.dir/commands/bg.c.o" \
"CMakeFiles/My_Shell.dir/utils/process.c.o" \
"CMakeFiles/My_Shell.dir/utils/print.c.o"

# External object files for target My_Shell
My_Shell_EXTERNAL_OBJECTS =

My_Shell: CMakeFiles/My_Shell.dir/main.c.o
My_Shell: CMakeFiles/My_Shell.dir/utils/util.c.o
My_Shell: CMakeFiles/My_Shell.dir/globals.c.o
My_Shell: CMakeFiles/My_Shell.dir/processer/prompt.c.o
My_Shell: CMakeFiles/My_Shell.dir/processer/tokenizer.c.o
My_Shell: CMakeFiles/My_Shell.dir/utils/inputmat.c.o
My_Shell: CMakeFiles/My_Shell.dir/commands/echo.c.o
My_Shell: CMakeFiles/My_Shell.dir/commands/pwd.c.o
My_Shell: CMakeFiles/My_Shell.dir/commands/cd.c.o
My_Shell: CMakeFiles/My_Shell.dir/commands/ls.c.o
My_Shell: CMakeFiles/My_Shell.dir/processer/bgprocess.c.o
My_Shell: CMakeFiles/My_Shell.dir/commands/execvp.c.o
My_Shell: CMakeFiles/My_Shell.dir/commands/pinfo.c.o
My_Shell: CMakeFiles/My_Shell.dir/utils/processmat.c.o
My_Shell: CMakeFiles/My_Shell.dir/processer/redirections.c.o
My_Shell: CMakeFiles/My_Shell.dir/processer/pipeline.c.o
My_Shell: CMakeFiles/My_Shell.dir/commands/jobs.c.o
My_Shell: CMakeFiles/My_Shell.dir/commands/sig.c.o
My_Shell: CMakeFiles/My_Shell.dir/commands/fg.c.o
My_Shell: CMakeFiles/My_Shell.dir/processer/signals.c.o
My_Shell: CMakeFiles/My_Shell.dir/commands/bg.c.o
My_Shell: CMakeFiles/My_Shell.dir/utils/process.c.o
My_Shell: CMakeFiles/My_Shell.dir/utils/print.c.o
My_Shell: CMakeFiles/My_Shell.dir/build.make
My_Shell: CMakeFiles/My_Shell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_24) "Linking C executable My_Shell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/My_Shell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/My_Shell.dir/build: My_Shell
.PHONY : CMakeFiles/My_Shell.dir/build

CMakeFiles/My_Shell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/My_Shell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/My_Shell.dir/clean

CMakeFiles/My_Shell.dir/depend:
	cd /home/sreejan/CLionProjects/My_Shell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sreejan/CLionProjects/My_Shell /home/sreejan/CLionProjects/My_Shell /home/sreejan/CLionProjects/My_Shell/cmake-build-debug /home/sreejan/CLionProjects/My_Shell/cmake-build-debug /home/sreejan/CLionProjects/My_Shell/cmake-build-debug/CMakeFiles/My_Shell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/My_Shell.dir/depend

