cmake_minimum_required(VERSION 3.10)

# 项目名称
project(dds_error LANGUAGES CXX)

# C++ 标准设置
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含路径
include_directories(
    /usr/local/include
    /usr/local/include/eProsima
    ${CMAKE_CURRENT_SOURCE_DIR}/../xtypes
)

# 库文件路径
link_directories(
    /usr/local/lib
)

# 源文件列表
set(SOURCES_RECEIVE
    server.cpp               # 订阅者的 main 函数
    ../xtypes/ErrorServicePubSubTypes.cxx # fastddsgen 生成的序列化代码
    ../xtypes/ErrorServiceTypeObjectSupport.cxx  # 添加此文件
)

set(SOURCES_SEND
    testClient.cpp               # 发布者的 main 函数
    ../xtypes/ErrorServicePubSubTypes.cxx # fastddsgen 生成的序列化代码
    ../xtypes/ErrorServiceTypeObjectSupport.cxx  # 添加此文件
)


# 定义订阅者可执行文件
add_executable(server ${SOURCES_RECEIVE})

# 定义发布者可执行文件
# add_executable(testClient ${SOURCES_SEND})

# 手动指定 Fast DDS 和 Fast RTPS 的库文件路径
target_link_libraries(server
    /usr/local/lib/libfastdds.so
    /usr/local/lib/libfastrtps.so
    /usr/local/lib/libfastcdr.so
)

# 为发布者添加链接库
# target_link_libraries(testClient
#     /usr/local/lib/libfastdds.so
#     /usr/local/lib/libfastrtps.so
#     /usr/local/lib/libfastcdr.so
# )
