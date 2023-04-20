#include <iostream>
#include "Definitions.hpp"
#include "Menu.hpp"
#include "DisplayMenus.hpp"
#include "MusicManager.hpp"

using namespace std;

void start(List *musics)
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
         startMusicsMenu(musics);
         break;
      case (int)MainMenu::playlists:
         startPlaylistMenu();
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

void startMusicsMenu(List *musics)
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
      case (int)MusicsMenu::add:
         addMusic(musics);
         musics->at(0)->toString();
         break;
      case (int)MusicsMenu::remove:

         break;
      case (int)MusicsMenu::list:
         break;

      case (int)MusicsMenu::main:
         loop = false;
         break;
      case (int)MusicsMenu::end:
         exit(0);
         break;
      default:
         cout << "Escolha uma opção válida\n";
         break;
      }
   }
}

void startPlaylistMenu()
{
   bool loop = true;
   int choice;

   while (loop)
   {
      displayPlaylistsMenu();

      cout << "Escolha: ";
      cin >> choice;
      switch (choice)
      {
      case (int)PlayListMenu::manage:
         startPlaylistMusicsMenu(new Playlist("Favoritas"));
         break;
      case (int)PlayListMenu::add:
         break;
      case (int)PlayListMenu::remove:

         break;
      case (int)PlayListMenu::list:
         break;

      case (int)PlayListMenu::next:
         break;
      case (int)PlayListMenu::main:
         loop = false;
         break;
      case (int)PlayListMenu::end:
         exit(0);
         break;
      default:
         cout << "Escolha uma opção válida\n";
         break;
      }
   }
}

void startPlaylistMusicsMenu(Playlist *pl)
{
   bool loop = true;
   int choice;

   while (loop)
   {
      displayPlaylistsMusicsMenu(*pl);

      cout << "Escolha: ";
      cin >> choice;
      switch (choice)
      {
      case (int)PlayListMusicsMenu::add:
         break;
      case (int)PlayListMusicsMenu::remove:

         break;
      case (int)PlayListMusicsMenu::list:
         break;

      case (int)PlayListMusicsMenu::previus:
         loop = false;
         break;
      case (int)PlayListMusicsMenu::end:
         exit(0);
         break;
      default:
         cout << "Escolha uma opção válida\n";
         break;
      }
   }
}