cmake_minimum_required(VERSION 3.12)
project(Labyrinthe)

set(CMAKE_CXX_STANDARD 14)

include_directories(hdr)

add_executable(Labyrinthe
        hdr/Cases.h
        hdr/Game.h
        hdr/graphics.h
        hdr/Map.h
        hdr/Robot.h
        hdr/RobotAvance.h
        src/Cases.cpp
        src/Game.cpp
        src/Map.cpp
        src/Robot.cpp
        src/RobotAvance.cpp
        src/winbgi.cpp
        Labyrinthe.cpp)
