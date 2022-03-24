# CMake generated Testfile for 
# Source directory: /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/opencv/modules/ml
# Build directory: /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/build/modules/ml
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_ml "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/build/bin/opencv_test_ml" "--gtest_output=xml:opencv_test_ml.xml")
set_tests_properties(opencv_test_ml PROPERTIES  LABELS "Main;opencv_ml;Accuracy" WORKING_DIRECTORY "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/opencv/cmake/OpenCVUtils.cmake;1739;add_test;/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/opencv/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/opencv/cmake/OpenCVModule.cmake;1110;ocv_add_accuracy_tests;/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/opencv/modules/ml/CMakeLists.txt;2;ocv_define_module;/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/opencv/modules/ml/CMakeLists.txt;0;")
