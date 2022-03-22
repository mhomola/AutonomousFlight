# CMake generated Testfile for 
# Source directory: /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/opencv/modules/highgui
# Build directory: /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/build/modules/highgui
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_highgui "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/build/bin/opencv_test_highgui" "--gtest_output=xml:opencv_test_highgui.xml")
set_tests_properties(opencv_test_highgui PROPERTIES  LABELS "Main;opencv_highgui;Accuracy" WORKING_DIRECTORY "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/opencv/cmake/OpenCVUtils.cmake;1739;add_test;/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/opencv/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/opencv/modules/highgui/CMakeLists.txt;294;ocv_add_accuracy_tests;/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/opencv/modules/highgui/CMakeLists.txt;0;")
