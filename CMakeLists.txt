cmake_minimum_required(VERSION 3.25)
set(PROJECT_NAME NamePlaceholder)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp definitions.h)
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
message(${PROJECT_NAME})
