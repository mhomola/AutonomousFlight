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
include modules/aruco/CMakeFiles/opencv_aruco.dir/depend.make

# Include the progress variables for this target.
include modules/aruco/CMakeFiles/opencv_aruco.dir/progress.make

# Include the compile flags for this target's objects.
include modules/aruco/CMakeFiles/opencv_aruco.dir/flags.make

modules/aruco/CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.o: modules/aruco/CMakeFiles/opencv_aruco.dir/flags.make
modules/aruco/CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/apriltag_quad_thresh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/aruco/CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/apriltag_quad_thresh.cpp

modules/aruco/CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/apriltag_quad_thresh.cpp > CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.i

modules/aruco/CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/apriltag_quad_thresh.cpp -o CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.s

modules/aruco/CMakeFiles/opencv_aruco.dir/src/aruco.cpp.o: modules/aruco/CMakeFiles/opencv_aruco.dir/flags.make
modules/aruco/CMakeFiles/opencv_aruco.dir/src/aruco.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/aruco.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/aruco/CMakeFiles/opencv_aruco.dir/src/aruco.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_aruco.dir/src/aruco.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/aruco.cpp

modules/aruco/CMakeFiles/opencv_aruco.dir/src/aruco.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_aruco.dir/src/aruco.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/aruco.cpp > CMakeFiles/opencv_aruco.dir/src/aruco.cpp.i

modules/aruco/CMakeFiles/opencv_aruco.dir/src/aruco.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_aruco.dir/src/aruco.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/aruco.cpp -o CMakeFiles/opencv_aruco.dir/src/aruco.cpp.s

modules/aruco/CMakeFiles/opencv_aruco.dir/src/charuco.cpp.o: modules/aruco/CMakeFiles/opencv_aruco.dir/flags.make
modules/aruco/CMakeFiles/opencv_aruco.dir/src/charuco.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/charuco.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object modules/aruco/CMakeFiles/opencv_aruco.dir/src/charuco.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_aruco.dir/src/charuco.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/charuco.cpp

modules/aruco/CMakeFiles/opencv_aruco.dir/src/charuco.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_aruco.dir/src/charuco.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/charuco.cpp > CMakeFiles/opencv_aruco.dir/src/charuco.cpp.i

modules/aruco/CMakeFiles/opencv_aruco.dir/src/charuco.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_aruco.dir/src/charuco.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/charuco.cpp -o CMakeFiles/opencv_aruco.dir/src/charuco.cpp.s

modules/aruco/CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.o: modules/aruco/CMakeFiles/opencv_aruco.dir/flags.make
modules/aruco/CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/dictionary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object modules/aruco/CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/dictionary.cpp

modules/aruco/CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/dictionary.cpp > CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.i

modules/aruco/CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/dictionary.cpp -o CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.s

modules/aruco/CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.o: modules/aruco/CMakeFiles/opencv_aruco.dir/flags.make
modules/aruco/CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/zmaxheap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object modules/aruco/CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/zmaxheap.cpp

modules/aruco/CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/zmaxheap.cpp > CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.i

modules/aruco/CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco/src/zmaxheap.cpp -o CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.s

# Object files for target opencv_aruco
opencv_aruco_OBJECTS = \
"CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.o" \
"CMakeFiles/opencv_aruco.dir/src/aruco.cpp.o" \
"CMakeFiles/opencv_aruco.dir/src/charuco.cpp.o" \
"CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.o" \
"CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.o"

# External object files for target opencv_aruco
opencv_aruco_EXTERNAL_OBJECTS =

lib/libopencv_aruco.so.4.5.5: modules/aruco/CMakeFiles/opencv_aruco.dir/src/apriltag_quad_thresh.cpp.o
lib/libopencv_aruco.so.4.5.5: modules/aruco/CMakeFiles/opencv_aruco.dir/src/aruco.cpp.o
lib/libopencv_aruco.so.4.5.5: modules/aruco/CMakeFiles/opencv_aruco.dir/src/charuco.cpp.o
lib/libopencv_aruco.so.4.5.5: modules/aruco/CMakeFiles/opencv_aruco.dir/src/dictionary.cpp.o
lib/libopencv_aruco.so.4.5.5: modules/aruco/CMakeFiles/opencv_aruco.dir/src/zmaxheap.cpp.o
lib/libopencv_aruco.so.4.5.5: modules/aruco/CMakeFiles/opencv_aruco.dir/build.make
lib/libopencv_aruco.so.4.5.5: lib/libopencv_calib3d.so.4.5.5
lib/libopencv_aruco.so.4.5.5: 3rdparty/lib/libippiw.a
lib/libopencv_aruco.so.4.5.5: 3rdparty/ippicv/ippicv_lnx/icv/lib/intel64/libippicv.a
lib/libopencv_aruco.so.4.5.5: lib/libopencv_features2d.so.4.5.5
lib/libopencv_aruco.so.4.5.5: lib/libopencv_flann.so.4.5.5
lib/libopencv_aruco.so.4.5.5: lib/libopencv_imgproc.so.4.5.5
lib/libopencv_aruco.so.4.5.5: lib/libopencv_core.so.4.5.5
lib/libopencv_aruco.so.4.5.5: modules/aruco/CMakeFiles/opencv_aruco.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library ../../lib/libopencv_aruco.so"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_aruco.dir/link.txt --verbose=$(VERBOSE)
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libopencv_aruco.so.4.5.5 ../../lib/libopencv_aruco.so.405 ../../lib/libopencv_aruco.so

lib/libopencv_aruco.so.405: lib/libopencv_aruco.so.4.5.5
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libopencv_aruco.so.405

lib/libopencv_aruco.so: lib/libopencv_aruco.so.4.5.5
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libopencv_aruco.so

# Rule to build all files generated by this target.
modules/aruco/CMakeFiles/opencv_aruco.dir/build: lib/libopencv_aruco.so

.PHONY : modules/aruco/CMakeFiles/opencv_aruco.dir/build

modules/aruco/CMakeFiles/opencv_aruco.dir/clean:
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco && $(CMAKE_COMMAND) -P CMakeFiles/opencv_aruco.dir/cmake_clean.cmake
.PHONY : modules/aruco/CMakeFiles/opencv_aruco.dir/clean

modules/aruco/CMakeFiles/opencv_aruco.dir/depend:
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/aruco /home/marek/Documents/AutonomousFlight/CV_scripts/build/build /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/aruco/CMakeFiles/opencv_aruco.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/aruco/CMakeFiles/opencv_aruco.dir/depend

