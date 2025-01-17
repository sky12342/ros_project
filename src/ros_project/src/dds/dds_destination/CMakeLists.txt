cmake_minimum_required(VERSION 3.10)

# 项目名称
project(dds_destination LANGUAGES CXX)

# C++ 标准设置
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含路径
include_directories(
    /usr/local/include
    /usr/local/include/eProsima
    ${CMAKE_CURRENT_SOURCE_DIR}/../dds_xtypes/destination
)

# 库文件路径
link_directories(
    /usr/local/lib
)

# 源文件列表
set(SOURCES_RECEIVE
    sub_test.cpp               # 订阅者的 main 函数
    destination_recive.cpp     # 订阅者类实现
    ../dds_xtypes/destination/destinationPubSubTypes.cxx # fastddsgen 生成的序列化代码
    ../dds_xtypes/destination/destinationTypeObjectSupport.cxx  # 添加此文件
)

set(SOURCES_SEND
    pub_test.cpp               # 发布者的 main 函数
    ../dds_xtypes/destination/destinationPubSubTypes.cxx # fastddsgen 生成的序列化代码
    ../dds_xtypes/destination/destinationTypeObjectSupport.cxx  # 添加此文件
)


# 定义订阅者可执行文件
add_executable(sub_test ${SOURCES_RECEIVE})

# 定义发布者可执行文件
add_executable(pub_test ${SOURCES_SEND})

# 手动指定 Fast DDS 和 Fast RTPS 的库文件路径
target_link_libraries(sub_test
    /usr/local/lib/libfastdds.so
    /usr/local/lib/libfastrtps.so
    /usr/local/lib/libfastcdr.so
)

# 为发布者添加链接库
target_link_libraries(pub_test
    /usr/local/lib/libfastdds.so
    /usr/local/lib/libfastrtps.so
    /usr/local/lib/libfastcdr.so
)
