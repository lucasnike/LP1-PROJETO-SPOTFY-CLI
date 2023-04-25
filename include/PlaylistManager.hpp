#include "Playlist.hpp"
#include "ListaEncadeada/List.hpp"

#ifndef PLAYLISTMANAGER_HPP
#define PLAYLISTMANAGER_HPP

void addPlayList(List<Playlist*> *playlists);
void listAllPlaylists(List<Playlist*> playlists);
void removePlayList(List<Playlist *> *playlists);
void getNextMusic();
Playlist* choosePlaylist(List<Playlist *> *playlists);

#endif