#include <iostream>
#include "ListaEncadeada/List.hpp"
#include "Playlist.hpp"
#include "PlaylistManager.hpp"
#include "TerminalColors.hpp"

using namespace std;

void addPlayList(List<Playlist *> *playlists)
{
   string name;
   cin.ignore();

   cout << str_blue("\nNome da playlist: ");
   getline(cin, name);

   playlists->add(new Playlist(name));
}

void removePlayList(List<Playlist *> *playlists)
{
   if (playlists->size < 1)
   {
      cout << str_red("\nNão existe nenhuma playlist cadastrada\n");
      return;
   }
   int index;

   listAllPlaylists(*playlists);

   cout << str_blue("\nDigite o número da playlist: ");
   cin >> index;

   if (index < 1 || index > playlists->size)
   {
      cout << str_red("\nValor digitado é inválido\n");
      return;
   }

   index--;
   playlists->remove(playlists->at(index));
}

void listAllPlaylists(List<Playlist *> playlists)
{
   if (playlists.size < 1)
   {
      cout << str_red("\nNão existe nenhuma playlist cadastrada\n");
      return;
   }

   for (int i = 0; i < playlists.size; i++)
   {
      cout << i + 1 << "º - ";
      playlists.at(i)->toString();
   }
}

Playlist* choosePlaylist(List<Playlist *> *playlists)
{
   if (playlists->size < 1)
   {
      cout << str_red("\nNão existe nenhuma playlist cadastrada\n");
      return nullptr;
   }
   int index;

   listAllPlaylists(*playlists);

   cout << str_blue("\nDigite o número da playlist: ");
   cin >> index;

   if (index < 1 || index > playlists->size)
   {
      cout << str_red("\nValor digitado é inválido\n");
      return nullptr;
   }

   index--;

   return playlists->at(index);
}