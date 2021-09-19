cmake_minimum_required(VERSION 3.20.0)


project(mcTools VERSION 0.1)

add_executable(${PROJECT_NAME} main.cpp)


add_subdirectory(utils)
target_include_directories(${PROJECT_NAME} PUBLIC utils)
target_link_libraries(${PROJECT_NAME} utils)
