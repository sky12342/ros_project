
cmake_minimum_required(VERSION 3.20)

project("generated_code")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps 2.12 REQUIRED)


message(STATUS "Configuring state_error...")
add_library(state_error_lib state_error.cxx)
target_link_libraries(state_error_lib fastcdr fastrtps)

add_executable(state_error state_errorPubSubTypes.cxx state_errorPublisher.cxx state_errorSubscriber.cxx state_errorPubSubMain.cxx)
target_link_libraries(state_error fastcdr fastrtps
        state_error_lib )


