#include "Playlist.hpp"
#include "ListaEncadeada/List.hpp"

#ifndef MUSICMANAGER_HPP
#define MUSICMANAGER_HPP

void addMusic(List<Music*> *musicas);
void removeMusic(List<Music *> *musics);
void listAllMusic(List<Music *> musics);

#endif