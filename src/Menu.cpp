#include <iostream>
#include "Definitions.hpp"
#include "Menu.hpp"
#include "DisplayMenus.hpp"

using namespace std;

void start()
{
   bool loop = true;
   int choice;

   while (loop)
   {
      displayMainMenu();

      cout << "Escolha: ";
      cin >> choice;

      switch (choice)
      {
      case (int)MainMenu::musics:
         startMusicsMenu();
         break;
      case (int)MainMenu::playlists:

         break;
      case (int)MainMenu::end:
         loop = false;
         exit(0);
         break;
      default:
         cout << "Escolha uma opção válida\n";
         break;
      }

   }
}

void startMusicsMenu()
{
   bool loop = true;
   int choice;

   while (loop)
   {
      displayMusicsMenu();

      cout << "Escolha: ";
      cin >> choice;
      switch (choice)
      {
      case (int)MusicsMenu::add :
         break;
      case (int)MusicsMenu::remove :

         break;
      case (int)MusicsMenu::list :
         break;

      case (int)MusicsMenu::main:
         loop = false;
         break;
      default:
         cout << "Escolha uma opção válida\n";
         break;
      }

   }
}