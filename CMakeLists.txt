cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(adventureGame)
set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/include)
link_directories(/usr/lib)

add_executable(Functions.hpp Functions.cpp Hero.hpp Hero.cpp Enemy.hpp Enemy.cpp Tournament.hpp Tournament.cpp main.cpp)