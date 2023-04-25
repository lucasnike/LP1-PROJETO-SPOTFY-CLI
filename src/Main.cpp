#include <iostream>
#include "Music.hpp"
#include "DisplayMenus.hpp"
#include "Definitions.hpp"
#include "Menu.hpp"
#include "ListaEncadeada/List.hpp"

using namespace std;

int main()
{
   List<Music*> *musics = new List<Music*>;
   List<Playlist*> *playlists = new List<Playlist*>;
   
   start(musics, playlists);

   return 0;
}