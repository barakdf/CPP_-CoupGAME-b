cmake_minimum_required(VERSION 3.16)
project(CPP__CoupGAME_b)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPP__CoupGAME_b sources/main.cpp sources/Game.cpp sources/Player.hpp sources/Player.cpp sources/Assassin.cpp sources/Duke.cpp sources/Captain.cpp sources/Ambassador.cpp sources/Contessa.cpp)
