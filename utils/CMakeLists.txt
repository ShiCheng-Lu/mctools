add_library(utils
    src/coord.cpp
    src/delay.cpp
    src/keyboard.cpp
    src/mouse.cpp
    src/screen.cpp
)

target_include_directories(utils PUBLIC inc)
target_link_directories(utils PRIVATE src)

target_include_directories(${PROJECT_NAME} PUBLIC inc)
target_link_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(${PROJECT_NAME} utils)
