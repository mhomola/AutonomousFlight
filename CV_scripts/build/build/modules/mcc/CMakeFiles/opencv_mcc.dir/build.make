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
CMAKE_SOURCE_DIR = /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marek/Documents/AutonomousFlight/CV_scripts/build/build

# Include any dependencies generated for this target.
include modules/mcc/CMakeFiles/opencv_mcc.dir/depend.make

# Include the progress variables for this target.
include modules/mcc/CMakeFiles/opencv_mcc.dir/progress.make

# Include the compile flags for this target's objects.
include modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make

modules/mcc/CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/bound_min.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/bound_min.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/bound_min.cpp > CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/bound_min.cpp -o CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/ccm.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/ccm.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/ccm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/ccm.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/ccm.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/ccm.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/ccm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/ccm.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/ccm.cpp > CMakeFiles/opencv_mcc.dir/src/ccm.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/ccm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/ccm.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/ccm.cpp -o CMakeFiles/opencv_mcc.dir/src/ccm.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/charts.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/charts.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/charts.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/charts.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/charts.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/charts.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/charts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/charts.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/charts.cpp > CMakeFiles/opencv_mcc.dir/src/charts.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/charts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/charts.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/charts.cpp -o CMakeFiles/opencv_mcc.dir/src/charts.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/checker_detector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/checker_detector.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/checker_detector.cpp > CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/checker_detector.cpp -o CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/checker_model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/checker_model.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/checker_model.cpp > CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/checker_model.cpp -o CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/color.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/color.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/color.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/color.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/color.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/color.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/color.cpp > CMakeFiles/opencv_mcc.dir/src/color.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/color.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/color.cpp -o CMakeFiles/opencv_mcc.dir/src/color.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/colorspace.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/colorspace.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/colorspace.cpp > CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/colorspace.cpp -o CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/common.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/common.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/common.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/common.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/common.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/common.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/common.cpp > CMakeFiles/opencv_mcc.dir/src/common.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/common.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/common.cpp -o CMakeFiles/opencv_mcc.dir/src/common.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/debug.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/debug.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/debug.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/debug.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/debug.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/debug.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/debug.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/debug.cpp > CMakeFiles/opencv_mcc.dir/src/debug.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/debug.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/debug.cpp -o CMakeFiles/opencv_mcc.dir/src/debug.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/distance.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/distance.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/distance.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/distance.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/distance.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/distance.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/distance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/distance.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/distance.cpp > CMakeFiles/opencv_mcc.dir/src/distance.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/distance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/distance.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/distance.cpp -o CMakeFiles/opencv_mcc.dir/src/distance.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/graph_cluster.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/graph_cluster.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/graph_cluster.cpp > CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/graph_cluster.cpp -o CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/io.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/io.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/io.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/io.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/io.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/io.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/io.cpp > CMakeFiles/opencv_mcc.dir/src/io.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/io.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/io.cpp -o CMakeFiles/opencv_mcc.dir/src/io.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/linearize.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/linearize.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/linearize.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/linearize.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/linearize.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/linearize.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/linearize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/linearize.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/linearize.cpp > CMakeFiles/opencv_mcc.dir/src/linearize.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/linearize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/linearize.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/linearize.cpp -o CMakeFiles/opencv_mcc.dir/src/linearize.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/mcc.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/mcc.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/mcc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/mcc.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/mcc.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/mcc.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/mcc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/mcc.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/mcc.cpp > CMakeFiles/opencv_mcc.dir/src/mcc.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/mcc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/mcc.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/mcc.cpp -o CMakeFiles/opencv_mcc.dir/src/mcc.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/operations.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/operations.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/operations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/operations.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/operations.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/operations.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/operations.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/operations.cpp > CMakeFiles/opencv_mcc.dir/src/operations.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/operations.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/operations.cpp -o CMakeFiles/opencv_mcc.dir/src/operations.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/utils.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/utils.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/utils.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/utils.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/utils.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/utils.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/utils.cpp > CMakeFiles/opencv_mcc.dir/src/utils.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/utils.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/utils.cpp -o CMakeFiles/opencv_mcc.dir/src/utils.cpp.s

modules/mcc/CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.o: modules/mcc/CMakeFiles/opencv_mcc.dir/flags.make
modules/mcc/CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/wiener_filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object modules/mcc/CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/wiener_filter.cpp

modules/mcc/CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/wiener_filter.cpp > CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.i

modules/mcc/CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc/src/wiener_filter.cpp -o CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.s

# Object files for target opencv_mcc
opencv_mcc_OBJECTS = \
"CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/ccm.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/charts.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/color.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/common.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/debug.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/distance.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/io.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/linearize.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/mcc.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/operations.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/utils.cpp.o" \
"CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.o"

# External object files for target opencv_mcc
opencv_mcc_EXTERNAL_OBJECTS =

lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/bound_min.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/ccm.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/charts.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_detector.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/checker_model.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/color.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/colorspace.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/common.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/debug.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/distance.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/graph_cluster.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/io.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/linearize.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/mcc.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/operations.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/utils.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/src/wiener_filter.cpp.o
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/build.make
lib/libopencv_mcc.so.4.5.5: lib/libopencv_dnn.so.4.5.5
lib/libopencv_mcc.so.4.5.5: lib/libopencv_calib3d.so.4.5.5
lib/libopencv_mcc.so.4.5.5: 3rdparty/lib/libippiw.a
lib/libopencv_mcc.so.4.5.5: 3rdparty/ippicv/ippicv_lnx/icv/lib/intel64/libippicv.a
lib/libopencv_mcc.so.4.5.5: lib/libopencv_features2d.so.4.5.5
lib/libopencv_mcc.so.4.5.5: lib/libopencv_flann.so.4.5.5
lib/libopencv_mcc.so.4.5.5: lib/libopencv_imgproc.so.4.5.5
lib/libopencv_mcc.so.4.5.5: lib/libopencv_core.so.4.5.5
lib/libopencv_mcc.so.4.5.5: modules/mcc/CMakeFiles/opencv_mcc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX shared library ../../lib/libopencv_mcc.so"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_mcc.dir/link.txt --verbose=$(VERBOSE)
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libopencv_mcc.so.4.5.5 ../../lib/libopencv_mcc.so.405 ../../lib/libopencv_mcc.so

lib/libopencv_mcc.so.405: lib/libopencv_mcc.so.4.5.5
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libopencv_mcc.so.405

lib/libopencv_mcc.so: lib/libopencv_mcc.so.4.5.5
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libopencv_mcc.so

# Rule to build all files generated by this target.
modules/mcc/CMakeFiles/opencv_mcc.dir/build: lib/libopencv_mcc.so

.PHONY : modules/mcc/CMakeFiles/opencv_mcc.dir/build

modules/mcc/CMakeFiles/opencv_mcc.dir/clean:
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc && $(CMAKE_COMMAND) -P CMakeFiles/opencv_mcc.dir/cmake_clean.cmake
.PHONY : modules/mcc/CMakeFiles/opencv_mcc.dir/clean

modules/mcc/CMakeFiles/opencv_mcc.dir/depend:
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/mcc /home/marek/Documents/AutonomousFlight/CV_scripts/build/build /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/mcc/CMakeFiles/opencv_mcc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/mcc/CMakeFiles/opencv_mcc.dir/depend

