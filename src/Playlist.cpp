#include <iostream>
#include "Playlist.hpp"
#include "ListaEncadeada/List.hpp"
#include "TerminalColors.hpp"

using namespace std;

Playlist::Playlist(string name)
{
   this->musics = new List<Music *>();
   this->name = name;
}

void Playlist::toString()
{
   cout << str_green(this->name) << endl;
}

void Playlist::next()
{
   if (this->currentMusic < this->musics->size)
   {

      this->musics->at(this->currentMusic)->toString();
      this->currentMusic += 1;
   }
   else
   {
      cout << str_red("\nSem músicas para mostrar\n");
   }
}

bool Playlist::displayAllMusics(int index = 0)
{
   if (musics->size > 0)
   {
      if (index < musics->size)
      {
         cout << index + 1 << "º - ";
         musics->at(index)->toString();
         displayAllMusics(++index);
      }
      return true;
   }
   else
   {
      cout << str_red("\nNão existe nenhuma música salva na playlist\n");
      return false;
   }
}