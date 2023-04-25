#include <iostream>
#include "Playlist.hpp"
#include "ListaEncadeada/List.hpp"

using namespace std;

Playlist::Playlist(string name)
{
   this->musics = new List<Music *>();
   this->name = name;
}

Playlist::~Playlist()
{
}

void Playlist::toString()
{
   cout << "\033[1;32m" << this->name << "\033[0m\n";
}

Music Playlist::next()
{
   if (this->musics->size > 0)
   {
      if (this->currentMusic <= this->musics->size)
      {
         return *this->musics->at(currentMusic);
         this->currentMusic += 1;
      }
      else
      {
         return Music("", "");   
      }
      
   }
   else
   {
      return Music("", "");
   }
   
}

void Playlist::displayAllMusics()
{
   List<Music *> *musics = this->musics;
   if (musics->size > 0)
   {
      if (musics->head->value)
      {
         displayAllMusics();
      }
   }
}