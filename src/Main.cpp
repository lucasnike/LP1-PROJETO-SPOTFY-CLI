#include <iostream>
#include "Music.hpp"
#include "DisplayMenus.hpp"
#include "Definitions.hpp"
#include "Menu.hpp"
#include "ListaEncadeada/List.hpp"

using namespace std;

int main()
{
   List<Music*> musics;
   List<Playlist*> playlists;
   
   start(&musics, &playlists);

   return 0;
}