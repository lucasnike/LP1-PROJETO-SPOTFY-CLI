#include <iostream>
#include "ListaEncadeada/List.hpp"
#include "Playlist.hpp"
#include "PlaylistManager.hpp"

using namespace std;

void addPlayList(List<Playlist *> *playlists)
{
   string name;
   cin.ignore();

   cout << "Nome da playlist: ";
   getline(cin, name);

   playlists->add(new Playlist(name));
}

void removePlayList(List<Playlist *> *playlists)
{
   if (playlists->size < 1)
   {
      cout << "\033[1;31mNão existe nenhuma música salva\033[0m\n";
      return;
   }
   int index;

   listAllPlaylists(*playlists);

   cout << "Digite o número da playlist: ";
   cin >> index;

   if (index < 1 || index > playlists->size)
   {
      cout << "Valor digitado é inválido\n";
      return;
   }

   index--;
   playlists->remove(playlists->at(index));
}

void listAllPlaylists(List<Playlist *> playlists)
{
   if (playlists.size < 1)
   {
      cout << "Não existe nenhuma música salva\n";
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
      cout << "\033[1;31mNão existe nenhuma música salva\033[0m\n";
      return nullptr;
   }
   int index;

   listAllPlaylists(*playlists);

   cout << "Digite o número da playlist: ";
   cin >> index;

   if (index < 1 || index > playlists->size)
   {
      cout << "Valor digitado é inválido\n";
      return nullptr;
   }

   index--;

   return playlists->at(index);
}