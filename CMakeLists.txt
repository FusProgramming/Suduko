cmake_minimum_required(VERSION 3.14)
project(P2_SQUARE)

set(CMAKE_CXX_STANDARD 14)

add_executable(P2_SQUARE main.cpp Square.cpp Square.hpp tools.cpp tools.hpp game.cpp game.hpp Board.cpp Board.hpp Cluster.cpp Cluster.hpp GameErrors.cpp GameErrors.hpp StreamErrors.cpp StreamErrors.hpp CanView.hpp Viewer.cpp Viewer.hpp Canvas.cpp Canvas.hpp GridChar.cpp GridChar.hpp MixedChar.cpp MixedChar.hpp Stack.hpp Frame.cpp Frame.hpp)