# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "D:\CLion 2022.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2022.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AV2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AV2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AV2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AV2.dir/flags.make

CMakeFiles/AV2.dir/main.c.obj: CMakeFiles/AV2.dir/flags.make
CMakeFiles/AV2.dir/main.c.obj: ../main.c
CMakeFiles/AV2.dir/main.c.obj: CMakeFiles/AV2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AV2.dir/main.c.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/AV2.dir/main.c.obj -MF CMakeFiles\AV2.dir\main.c.obj.d -o CMakeFiles\AV2.dir\main.c.obj -c E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2\main.c

CMakeFiles/AV2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AV2.dir/main.c.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2\main.c > CMakeFiles\AV2.dir\main.c.i

CMakeFiles/AV2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AV2.dir/main.c.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2\main.c -o CMakeFiles\AV2.dir\main.c.s

# Object files for target AV2
AV2_OBJECTS = \
"CMakeFiles/AV2.dir/main.c.obj"

# External object files for target AV2
AV2_EXTERNAL_OBJECTS =

AV2.exe: CMakeFiles/AV2.dir/main.c.obj
AV2.exe: CMakeFiles/AV2.dir/build.make
AV2.exe: CMakeFiles/AV2.dir/linklibs.rsp
AV2.exe: CMakeFiles/AV2.dir/objects1.rsp
AV2.exe: CMakeFiles/AV2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable AV2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AV2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AV2.dir/build: AV2.exe
.PHONY : CMakeFiles/AV2.dir/build

CMakeFiles/AV2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AV2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AV2.dir/clean

CMakeFiles/AV2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2 E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2 E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2\cmake-build-debug E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2\cmake-build-debug E:\Documents\Estudo\Faculdade\SegundoSemestre\Lab-Prog\Projetos\exercicios-valendo-nota\projeto-de-sistema\avalia-o2-main-corrigido\avalia-o2-main\AV2\cmake-build-debug\CMakeFiles\AV2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AV2.dir/depend

