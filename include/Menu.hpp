#include "Playlist.hpp"
#include "ListaEncadeada/List.hpp"

#ifndef MENU_HPP
#define MENU_HPP

void start(List<Music*>*, List<Playlist*>*);
void startMusicsMenu(List<Music *> *, List<Playlist *> *);
void startPlaylistMenu(List<Music*> *musics, List<Playlist*> *playlists);
void startPlaylistMusicsMenu(Playlist*, List<Music *> *);
#endif