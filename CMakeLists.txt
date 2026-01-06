cmake_minimum_required(VERSION 3.18.1)
set(CMAKE_CXX_STANDARD 11)

project(follower VERSION 1.0)

add_executable(${PROJECT_NAME} src/follower.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw GL)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/struct)