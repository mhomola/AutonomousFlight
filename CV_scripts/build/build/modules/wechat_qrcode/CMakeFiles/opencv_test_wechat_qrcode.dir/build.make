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
include modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/depend.make

# Include the progress variables for this target.
include modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/progress.make

# Include the compile flags for this target's objects.
include modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/flags.make

modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.o: modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/flags.make
modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/wechat_qrcode/test/test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/wechat_qrcode && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/wechat_qrcode/test/test_main.cpp

modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/wechat_qrcode && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/wechat_qrcode/test/test_main.cpp > CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.i

modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/wechat_qrcode && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/wechat_qrcode/test/test_main.cpp -o CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.s

modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.o: modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/flags.make
modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.o: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/wechat_qrcode/test/test_qrcode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.o"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/wechat_qrcode && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.o -c /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/wechat_qrcode/test/test_qrcode.cpp

modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.i"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/wechat_qrcode && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/wechat_qrcode/test/test_qrcode.cpp > CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.i

modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.s"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/wechat_qrcode && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/wechat_qrcode/test/test_qrcode.cpp -o CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.s

# Object files for target opencv_test_wechat_qrcode
opencv_test_wechat_qrcode_OBJECTS = \
"CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.o" \
"CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.o"

# External object files for target opencv_test_wechat_qrcode
opencv_test_wechat_qrcode_EXTERNAL_OBJECTS =

bin/opencv_test_wechat_qrcode: modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_main.cpp.o
bin/opencv_test_wechat_qrcode: modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/test/test_qrcode.cpp.o
bin/opencv_test_wechat_qrcode: modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/build.make
bin/opencv_test_wechat_qrcode: lib/libopencv_ts.a
bin/opencv_test_wechat_qrcode: lib/libopencv_wechat_qrcode.so.4.5.5
bin/opencv_test_wechat_qrcode: lib/libopencv_highgui.so.4.5.5
bin/opencv_test_wechat_qrcode: lib/libopencv_dnn.so.4.5.5
bin/opencv_test_wechat_qrcode: 3rdparty/lib/libippiw.a
bin/opencv_test_wechat_qrcode: 3rdparty/ippicv/ippicv_lnx/icv/lib/intel64/libippicv.a
bin/opencv_test_wechat_qrcode: lib/libopencv_videoio.so.4.5.5
bin/opencv_test_wechat_qrcode: lib/libopencv_imgcodecs.so.4.5.5
bin/opencv_test_wechat_qrcode: lib/libopencv_imgproc.so.4.5.5
bin/opencv_test_wechat_qrcode: lib/libopencv_core.so.4.5.5
bin/opencv_test_wechat_qrcode: modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/opencv_test_wechat_qrcode"
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/wechat_qrcode && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_test_wechat_qrcode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/build: bin/opencv_test_wechat_qrcode

.PHONY : modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/build

modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/clean:
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/wechat_qrcode && $(CMAKE_COMMAND) -P CMakeFiles/opencv_test_wechat_qrcode.dir/cmake_clean.cmake
.PHONY : modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/clean

modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/depend:
	cd /home/marek/Documents/AutonomousFlight/CV_scripts/build/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/wechat_qrcode /home/marek/Documents/AutonomousFlight/CV_scripts/build/build /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/wechat_qrcode /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/wechat_qrcode/CMakeFiles/opencv_test_wechat_qrcode.dir/depend

