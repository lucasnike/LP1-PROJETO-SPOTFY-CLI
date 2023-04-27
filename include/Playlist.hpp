#include <iostream>
#include "Music.hpp"
#include "ListaEncadeada/List.hpp"

using namespace std;

#ifndef PLAYLIST_HPP 
#define PLAYLIST_HPP

class Playlist {
   private:
      string name;
      List<Music*> *musics;
      int currentMusic = 0;
      
   public:
      Playlist(string);
      ~Playlist();
      void addToPlaylist(Music*);
      void removeFromPlaylist(Music*);
      Music next();
      void displayAllMusics();
      string getName() const { return this->name; }
      List<Music*> *getMusics() const { return this->musics; }
      void toString();
};

#endif