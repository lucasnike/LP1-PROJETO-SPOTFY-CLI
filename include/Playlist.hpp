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
      void addToPlaylist(Music* m) const { this->musics->add(m); }
      void removeFromPlaylist(Music* m) const { this->musics->remove(m); }
      void next();
      bool displayAllMusics(int index);
      string getName() const { return this->name; }
      List<Music*> *getMusics() const { return this->musics; }
      void toString();
};

#endif