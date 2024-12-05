project(common)
target_link_libraries(common PRIVATE glog pthread)

include_directories("/usr/include/glog")
link_directories("/usr/lib/x86_64-linux-gnu")

find_package(glog REQUIRED)
add_library(${PROJECT_NAME} SHARED common.cpp Log.cpp)
target_link_libraries(${PROJECT_NAME} glog)


add_executable(test test.cpp)
target_link_libraries(test PRIVATE common glog)