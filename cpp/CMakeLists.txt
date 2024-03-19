cmake_minimum_required(VERSION 3.28)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

add_library(cgfs_support
        Canvas.cpp
        Canvas.h
        App.cpp
        App.h
        Color.cpp
        Color.h)

target_include_directories(cgfs_support PRIVATE ${SDL2_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})
target_link_libraries(cgfs_support PRIVATE ${SDL2_LIBRARIES})


add_executable(cgfs Main.cpp)
target_include_directories(cgfs PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(cgfs PRIVATE cgfs_support)

add_executable(rtspheres RTSpheres.cpp)
target_include_directories(rtspheres PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(rtspheres PRIVATE cgfs_support)
