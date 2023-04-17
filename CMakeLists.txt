cmake_minimum_required(VERSION 3.22)
project(teste VERSION 0.1 LANGUAGES CXX )

include_directories( include )


add_executable( program 
src/Main.cpp 
src/DisplayMenus.cpp
src/List.cpp
src/Menu.cpp
src/Music.cpp
)