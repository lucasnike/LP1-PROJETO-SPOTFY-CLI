#include <iostream>
#include <ListaEncadeada/List.hpp>
#include <Music.hpp>
#include <Playlist.hpp>

using namespace std;

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

void readData(List<Music*> *musics, List<Playlist*> *playlists, string file);
void writeData(List<Music*> *musics, List<Playlist*> *playlists, string file);

#endif