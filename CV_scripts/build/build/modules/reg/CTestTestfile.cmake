# CMake generated Testfile for 
# Source directory: /home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/reg
# Build directory: /home/marek/Documents/AutonomousFlight/CV_scripts/build/build/modules/reg
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_reg "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/bin/opencv_test_reg" "--gtest_output=xml:opencv_test_reg.xml")
set_tests_properties(opencv_test_reg PROPERTIES  LABELS "Extra;opencv_reg;Accuracy" WORKING_DIRECTORY "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVUtils.cmake;1739;add_test;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVModule.cmake;1110;ocv_add_accuracy_tests;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/reg/CMakeLists.txt;2;ocv_define_module;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/reg/CMakeLists.txt;0;")
add_test(opencv_perf_reg "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/bin/opencv_perf_reg" "--gtest_output=xml:opencv_perf_reg.xml")
set_tests_properties(opencv_perf_reg PROPERTIES  LABELS "Extra;opencv_reg;Performance" WORKING_DIRECTORY "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/test-reports/performance" _BACKTRACE_TRIPLES "/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVUtils.cmake;1739;add_test;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVModule.cmake;1251;ocv_add_test_from_target;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVModule.cmake;1111;ocv_add_perf_tests;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/reg/CMakeLists.txt;2;ocv_define_module;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/reg/CMakeLists.txt;0;")
add_test(opencv_sanity_reg "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/bin/opencv_perf_reg" "--gtest_output=xml:opencv_perf_reg.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_reg PROPERTIES  LABELS "Extra;opencv_reg;Sanity" WORKING_DIRECTORY "/home/marek/Documents/AutonomousFlight/CV_scripts/build/build/test-reports/sanity" _BACKTRACE_TRIPLES "/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVUtils.cmake;1739;add_test;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVModule.cmake;1252;ocv_add_test_from_target;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv-4.x/cmake/OpenCVModule.cmake;1111;ocv_add_perf_tests;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/reg/CMakeLists.txt;2;ocv_define_module;/home/marek/Documents/AutonomousFlight/CV_scripts/build/opencv_contrib-4.x/modules/reg/CMakeLists.txt;0;")