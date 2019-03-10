cmake_minimum_required(VERSION 3.13)
project(simulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(simulation main.cpp Board_Class.cpp Board_Class.h Circle_Class.cpp Circle_Class.h Goal_Class.h Line_Class.h passing_structures.h Puck_Class.cpp Puck_Class.h Striker_Class.h Wall_Class.h)