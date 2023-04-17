#include <iostream>
#include "Music.hpp"
#include "List.hpp"

using namespace std;

#ifndef PLAYLIST_HPP 
#define PLAYLIST_HPP

class Playlist {
   private:
      string name;
      List musics;
      int currentMusic = 0;
      
   public:
      Playlist();
      ~Playlist();
      void addToPlaylist(Music*);
      void removeFromPlaylist(Music*);
      Music next();
      void displayAllMusics();
      string getName() const { return this->name; }
};

#endif