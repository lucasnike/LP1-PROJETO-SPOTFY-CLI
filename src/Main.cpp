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
   start(musicas);

   return 0;
}