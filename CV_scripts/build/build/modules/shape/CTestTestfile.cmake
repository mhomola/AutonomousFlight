# CMake generated Testfile for 
# Source directory: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/shape
# Build directory: /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/shape
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_shape "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/bin/opencv_test_shape" "--gtest_output=xml:opencv_test_shape.xml")
set_tests_properties(opencv_test_shape PROPERTIES  LABELS "Extra;opencv_shape;Accuracy" WORKING_DIRECTORY "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVUtils.cmake;1739;add_test;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVModule.cmake;1110;ocv_add_accuracy_tests;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/shape/CMakeLists.txt;2;ocv_define_module;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/shape/CMakeLists.txt;0;")
