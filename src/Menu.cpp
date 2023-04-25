#include <iostream>
#include "Definitions.hpp"
#include "Menu.hpp"
#include "DisplayMenus.hpp"
#include "MusicManager.hpp"
#include "PlaylistManager.hpp"

using namespace std;

void start(List<Music*> *musics, List<Playlist*> *playlists)
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
         startPlaylistMenu(musics, playlists);
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

void startMusicsMenu(List<Music*> *musics)
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
         break;
      case (int)MusicsMenu::remove:
         removeMusic(musics);
         break;
      case (int)MusicsMenu::list:
         listAllMusic(*musics);
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

void startPlaylistMenu(List<Music*> *musics, List<Playlist*> *playlists)
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
         startPlaylistMusicsMenu(choosePlaylist(playlists));
         break;
      case (int)PlayListMenu::add:
         addPlayList(playlists);
         break;
      case (int)PlayListMenu::remove:
         removePlayList(playlists);
         break;
      case (int)PlayListMenu::list:
         listAllPlaylists(*playlists);
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