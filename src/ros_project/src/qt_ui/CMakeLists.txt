cmake_minimum_required(VERSION 3.0.2)
project(qt_ui)

# 启用 Qt 自动生成
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 查找 ROS 依赖
find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    actionlib
    std_msgs
    sensor_msgs
    move_base_msgs  # 确保在 catkin 中声明 move_base_msgs
    roslib
    rostime
    roscpp_traits
)
# 查找 Protobuf
find_package(Protobuf REQUIRED)

# 包含路径
include_directories(
    ${catkin_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Protobuf_INCLUDE_DIRS}
    /root/catkin_ws/src/ros_project/src/protobuf_msg/Build  # 添加 Protobuf 生成的头文件路径
)

# 链接路径
link_directories(
    ${Protobuf_LIBRARY_DIRS}
)

# 查找 Qt5
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

# 自动生成 Qt 的 MOC 文件
qt5_wrap_cpp(MOC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/rosFcuntionbase.h
)

# 添加 Protobuf 生成的 .cc 文件
set(PROTO_SRCS
    /root/catkin_ws/src/ros_project/src/protobuf_msg/Build/publish_info.pb.cc
)

# 动态库源文件
add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ros_worker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SignalSlotProxy.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/rosWorkList.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ros_destination.cpp
    ${PROTO_SRCS} # 添加 Protobuf 生成的源文件
    ${MOC_FILES}  # 添加 MOC 文件
)

# 可执行文件
add_executable(${PROJECT_NAME}_test
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# 链接库
target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets 
    Qt5::Core 
    Qt5::Gui
    glog 
    ${catkin_LIBRARIES}  # 确保链接 ROS 库
    ${Protobuf_LIBRARIES}  # 链接 Protobuf 库
)

target_link_libraries(${PROJECT_NAME}_test
    ${PROJECT_NAME}
    ${catkin_LIBRARIES}
)
