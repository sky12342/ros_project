cmake_minimum_required(VERSION 3.10)
project(vsomeip_example)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
# 设置 vsomeip3 配置文件的路径
set(vsomeip_DIR "/usr/local/lib/cmake/vsomeip3")

# 查找 vsomeip 库
find_package(vsomeip3 REQUIRED)

# 使用 vsomeip 库

# 寻找 vsomeip 库

# 包含 vsomeip 的头文件
include_directories(${VSOMEIP_INCLUDE_DIRS})

# 添加可执行文件：客户端
add_executable(client testclient.cpp)

# 添加可执行文件：服务端
add_executable(server testclient.cpp)

# 链接 vsomeip 库到可执行文件
target_link_libraries(client PRIVATE vsomeip3)
target_link_libraries(server PRIVATE vsomeip3)
# 安装目标（如果需要）
install(TARGETS client server DESTINATION /usr/local/bin)
