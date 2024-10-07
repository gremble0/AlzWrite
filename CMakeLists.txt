cmake_minimum_required(VERSION 3.10)
project(EmptyQtWindow)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(AlzWrite src/main.cpp)
target_link_libraries(AlzWrite Qt6::Widgets)
