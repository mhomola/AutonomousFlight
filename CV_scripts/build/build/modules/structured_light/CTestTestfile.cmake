# CMake generated Testfile for 
# Source directory: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/structured_light
# Build directory: /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/structured_light
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_structured_light "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/bin/opencv_test_structured_light" "--gtest_output=xml:opencv_test_structured_light.xml")
set_tests_properties(opencv_test_structured_light PROPERTIES  LABELS "Extra;opencv_structured_light;Accuracy" WORKING_DIRECTORY "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVUtils.cmake;1739;add_test;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVModule.cmake;1110;ocv_add_accuracy_tests;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/structured_light/CMakeLists.txt;2;ocv_define_module;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/structured_light/CMakeLists.txt;0;")
