cmake_minimum_required(VERSION 3.20.0)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED true)

project(mctools VERSION 0.1)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/steal.cpp
    src/dispatcher.cpp
    src/strListener.cpp
    src/villager.cpp
)

add_subdirectory(utils)
add_subdirectory(gameCtrl)

target_include_directories(${PROJECT_NAME} PUBLIC inc)
target_link_directories(${PROJECT_NAME} PRIVATE src)

