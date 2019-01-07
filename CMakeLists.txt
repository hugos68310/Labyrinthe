cmake_minimum_required(VERSION 3.13)
project(Labyrinthe)

set(CMAKE_CXX_STANDARD 14)

find_package(libbgi)
include_directories(hdr)

add_executable(Labyrinthe
        hdr/Game.h
        hdr/graphics.h
        hdr/Map.h
        hdr/Robot.h
        hdr/RobotAvance.h
        hdr/winbgim.h
        src/Game.cpp
        src/Map.cpp
        src/Robot.cpp
        src/RobotAvance.cpp
        Labyrinthe.cpp)
