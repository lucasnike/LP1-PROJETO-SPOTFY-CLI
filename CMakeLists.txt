cmake_minimum_required(VERSION 3.16)
project(teste VERSION 0.1 LANGUAGES CXX )

include_directories( include )


add_executable( spotfy_cli 
src/Main.cpp 
src/DisplayMenus.cpp
src/Menu.cpp
src/Music.cpp
src/Playlist.cpp
src/MusicsManager.cpp
src/PlaylistManager.cpp
src/PlaylistMusicsManager.cpp
src/TerminalColors.cpp
src/FileManager.cpp
)