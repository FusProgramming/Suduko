cmake_minimum_required(VERSION 3.14)
project(P2_SQUARE)

set(CMAKE_CXX_STANDARD 14)

add_executable(P2_SQUARE main.cpp Square.cpp Square.hpp tools.cpp tools.hpp game.cpp game.hpp)