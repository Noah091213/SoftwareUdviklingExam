cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(adventureGame)
set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/include)
link_directories(/usr/lib)

add_executable(main.cpp MainMenu.hpp MainMenu.cpp Hero.hpp Hero.cpp Enemy.hpp Enemy.cpp)


