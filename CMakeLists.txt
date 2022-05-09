cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(gameoflife src/GameBoardBasic.cpp src/AlwaysNextTurn.cpp src/UserCommands.cpp src/GameBoardCylinder.cpp src/GameBoardTorus.cpp src/BoardSource.cpp src/main.cpp)

include_directories(include)


