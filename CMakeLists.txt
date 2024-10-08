cmake_minimum_required(VERSION 3.30.4)

set(PROJECT_NAME AlzWrite)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp src/widgets/TextBuffer.cpp)
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
