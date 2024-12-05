# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "gtest/googlemock/CMakeFiles/gmock_autogen.dir/AutogenUsed.txt"
  "gtest/googlemock/CMakeFiles/gmock_autogen.dir/ParseCache.txt"
  "gtest/googlemock/CMakeFiles/gmock_main_autogen.dir/AutogenUsed.txt"
  "gtest/googlemock/CMakeFiles/gmock_main_autogen.dir/ParseCache.txt"
  "gtest/googlemock/gmock_autogen"
  "gtest/googlemock/gmock_main_autogen"
  "gtest/googletest/CMakeFiles/gtest_autogen.dir/AutogenUsed.txt"
  "gtest/googletest/CMakeFiles/gtest_autogen.dir/ParseCache.txt"
  "gtest/googletest/CMakeFiles/gtest_main_autogen.dir/AutogenUsed.txt"
  "gtest/googletest/CMakeFiles/gtest_main_autogen.dir/ParseCache.txt"
  "gtest/googletest/gtest_autogen"
  "gtest/googletest/gtest_main_autogen"
  "src/qt_ui/CMakeFiles/qt_ui_autogen.dir/AutogenUsed.txt"
  "src/qt_ui/CMakeFiles/qt_ui_autogen.dir/ParseCache.txt"
  "src/qt_ui/CMakeFiles/qt_ui_test_autogen.dir/AutogenUsed.txt"
  "src/qt_ui/CMakeFiles/qt_ui_test_autogen.dir/ParseCache.txt"
  "src/qt_ui/qt_ui_autogen"
  "src/qt_ui/qt_ui_test_autogen"
  )
endif()
