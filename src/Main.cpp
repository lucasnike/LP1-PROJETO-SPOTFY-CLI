#include <iostream>
#include "Music.hpp"
#include "List.hpp"
#include "DisplayMenus.hpp"
#include "Definitions.hpp"
#include "Menu.hpp"
#include "ListaEncadeada/Lists.hpp"

using namespace std;

int main()
{
   cout << "--------------------------------------------------\n";
   // List *musicas = new List();
   // start(musicas);

   Lists<Music*> *musics = new Lists<Music*>;

   Music *m1 = new Music("Bohemian Rhapsody", "Queen");
   Music *m2 = new Music("Stairway to heaven", "Led Zeplin");
   Music *m3 = new Music("Vampiro espacial", "Marilia Mendonça");
   Music *m4 = new Music("1981", "Flamengo");
   Music *m5 = new Music("Água de coco", "MC Naldo Benner");
   Music *m6 = new Music("Please Please Me", "The Beatles");

   musics->add(m1);
   musics->add(m2);
   musics->add(m3);
   musics->add(m4);
   musics->add(m5);
   musics->add(m6);

   musics->at(0)->toString();
   musics->at(1)->toString();
   musics->at(2)->toString();
   musics->at(3)->toString();
   musics->at(4)->toString();
   musics->at(5)->toString();


   return 0;
}