add_library(gameCtrl
    src/inventory.cpp
    src/mcWindow.cpp
    src/menuCtrl.cpp
    src/moveCtrl.cpp
)


target_include_directories(gameCtrl PUBLIC inc)
target_link_directories(gameCtrl PRIVATE src)

target_include_directories(${PROJECT_NAME} PUBLIC inc)
target_link_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(${PROJECT_NAME} gameCtrl)

target_link_libraries(gameCtrl utils)