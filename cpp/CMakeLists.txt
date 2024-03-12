cmake_minimum_required(VERSION 3.28)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

add_executable(cgfs Main.cpp
        Canvas.cpp
        Canvas.h
        App.cpp
        App.h
        Color.cpp
        Color.h)
target_include_directories(cgfs PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(cgfs PRIVATE ${SDL2_LIBRARIES})
