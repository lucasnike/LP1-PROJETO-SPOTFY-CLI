#include <iostream>
#include "Music.hpp"
#include "DisplayMenus.hpp"
#include "Definitions.hpp"
#include "Menu.hpp"
#include "ListaEncadeada/List.hpp"
#include "FileManager.hpp"
using namespace std;

int main(int argc, char **argv)
{
   List<Music *> musics;
   List<Playlist *> playlists;

   if (argc < 2)
   {
      cout << str_red("Arquivo não informado\n");
      abort();
   }

   string fileName = argv[1];

   readData(&musics, &playlists, fileName);
   start(&musics, &playlists);
   writeData(&musics, &playlists, fileName);

   return 0;
}