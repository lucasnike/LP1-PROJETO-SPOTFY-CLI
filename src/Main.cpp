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

   // if (argc < 2)
   // {
   //    cout << str_red("Arquivo não informado\n");
   //    abort();
   // }

   // string fileName = argv[1];

   // readData(&musics, &playlists, fileName);
   // start(&musics, &playlists);
   // writeData(&musics, &playlists, fileName);

   List<int*> l1;
   List<int*> l2;

   l1.add(new int(2));
   l1.add(new int(4));
   l1.add(new int(5));
   l1.add(new int(6));

   l2.add(new int(58));
   l2.add(new int(56));
   l2.add(new int(32));
   l2.add(new int(99));

   l1.extend(&l2);
   
   for (int i = 0; i < l1.size; i++)
   {
      cout << *l1.at(i) << endl;
   }

   l1.remove(&l2);

   for (int i = 0; i < l1.size; i++)
   {
      cout << *l1.at(i) << endl;
   }
   
   return 0;
}