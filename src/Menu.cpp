#include <iostream>
#include "Definitions.hpp"
#include "Menu.hpp"
#include "DisplayMenus.hpp"
#include "MusicManager.hpp"
#include "PlaylistManager.hpp"
#include "PlaylistMusicsManager.hpp"
#include "TerminalColors.hpp"
#include "FileManager.hpp"

using namespace std;

void start(List<Music *> *musics, List<Playlist *> *playlists)
{
   bool loop = true;
   int choice;

   while (loop)
   {
      displayMainMenu();

      cout << str_blue("\nEscolha: ");
      cin >> choice;
      cout << endl;

      switch (choice)
      {
      case (int)MainMenu::musics:
         startMusicsMenu(musics, playlists);
         break;
      case (int)MainMenu::playlists:
         startPlaylistMenu(musics, playlists);
         break;
      case (int)MainMenu::end:
         loop = false;
         break;
      default:
         cout << str_red("\nEscolha uma opção válida\n");
         break;
      }
   }
}

void startMusicsMenu(List<Music *> *musics, List<Playlist *> *playlists)
{
   bool loop = true;
   int choice;

   while (loop)
   {
      displayMusicsMenu();

      cout << str_blue("\nEscolha: ");
      cin >> choice;
      cout << endl;
      switch (choice)
      {
      case (int)MusicsMenu::add:
         addMusic(musics);
         break;
      case (int)MusicsMenu::remove:
         removeMusic(musics, playlists);
         break;
      case (int)MusicsMenu::list:
         listAllMusic(*musics);
         break;

      case (int)MusicsMenu::main:
         loop = false;
         break;
      default:
         cout << str_red("\nEscolha uma opção válida\n");
         break;
      }
   }
}

void startPlaylistMenu(List<Music *> *musics, List<Playlist *> *playlists)
{
   bool loop = true;
   int choice;

   while (loop)
   {
      displayPlaylistsMenu();

      cout << str_blue("\nEscolha: ");
      cin >> choice;
      cout << endl;

      switch (choice)
      {
      case (int)PlayListMenu::manage:
         Playlist *selectedPlaylist;
         selectedPlaylist = choosePlaylist(playlists);
         if (selectedPlaylist != nullptr)
         {
            startPlaylistMusicsMenu(selectedPlaylist, musics);
         }
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
      case (int)PlayListMenu::join:
         joinPlaylists(playlists);
         break;
      case (int)PlayListMenu::reduce:
         reducePlaylist(playlists);
         break;
      case (int)PlayListMenu::extend:
         extendPlaylist(playlists);
         break;
      case (int)PlayListMenu::main:
         loop = false;
         break;
      default:
         cout << str_red("\nEscolha uma opção válida\n");
         break;
      }
   }
}

void startPlaylistMusicsMenu(Playlist *pl, List<Music *> *musics)
{
   bool loop = true;
   int choice;

   while (loop)
   {
      displayPlaylistsMusicsMenu(*pl);

      cout << str_blue("\nEscolha: ");
      cin >> choice;
      cout << endl;
      switch (choice)
      {
      case (int)PlayListMusicsMenu::add:
         addMusicToPlaylist(pl, *musics);
         break;
      case (int)PlayListMusicsMenu::remove:
         removeMusicFromPlayList(pl);
         break;
      case (int)PlayListMusicsMenu::list:
         pl->displayAllMusics(0);
         break;
      case (int)PlayListMusicsMenu::next:
         pl->next();
         break;
      case (int)PlayListMusicsMenu::move:
         moveMusic(pl);
         break;
      case (int)PlayListMusicsMenu::previus:
         loop = false;
         break;
      default:
         cout << str_red("\nEscolha uma opção válida\n");
         break;
      }
   }
}