cmake_minimum_required(VERSION 3.13)
project(Labyrinthe)

set(CMAKE_CXX_STANDARD 14)

include_directories(hdr)

add_executable(Labyrinthe
        hdr/robot.h
        main.cpp
        src/robot.cpp src/robotAvance.cpp hdr/robotAvance.h)
