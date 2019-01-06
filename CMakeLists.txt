cmake_minimum_required(VERSION 3.12)
project(Labyrinthe)

set(CMAKE_CXX_STANDARD 14)

include_directories(hdr)

add_executable(Labyrinthe
        hdr/Game.h
        hdr/graphics.h
        hdr/Robot.h
        hdr/RobotAvance.h
        hdr/Terrain.h
        src/Game.cpp
        src/Robot.cpp
        src/RobotAvance.cpp
        src/Terrain.cpp
        src/winbgi.cpp
        Labyrinthe.cpp)
