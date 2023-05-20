cmake_minimum_required(VERSION 3.25)
set(PROJECT_NAME NamePlaceholder)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)

set(IMGUI_PATH "lib/imgui")
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS} ${IMGUI_PATH})

add_library(imgui STATIC
        ${IMGUI_PATH}/imgui.cpp
        )


add_executable(${PROJECT_NAME} src/main.cpp
        include/definitions.h
        )

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES} imgui)
message(${PROJECT_NAME})
