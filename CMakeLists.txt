cmake_minimum_required(VERSION 3.13)
project(Labyrinthe)

set(CMAKE_CXX_STANDARD 14)

include_directories(hdr)

add_executable(Labyrinthe
        Labyrinthe.cpp
        src/Game.cpp hdr/Game.h
        src/winbgi.cpp hdr/graphics.h
        src/Robot.cpp hdr/Robot.h
        src/RobotAvance.cpp hdr/RobotAvance.h
        src/Terrain.cpp hdr/Terrain.h
        )
