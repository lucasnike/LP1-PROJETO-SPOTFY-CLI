#include <iostream>
#include "Music.hpp"
#include "List.hpp"
#include "DisplayMenus.hpp"
#include "Definitions.hpp"
#include "Menu.hpp"

using namespace std;

int main()
{
   cout << "--------------------------------------------------\n";
   List *musicas = new List();
   musicas->add(new Music("Let it be", "Paul"));
   musicas->add(new Music("Please Please me", "The Beatles"));
   musicas->add(new Music("Radio Gaga", "Queen"));
   
   Music *m3 = musicas->at(2);

   musicas->remove(m3);


   start();
   musicas->at(1)->toString();

   return 0;
}