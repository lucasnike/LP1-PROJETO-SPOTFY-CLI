#include <iostream>
#include "Music.hpp"
#include "ListaEncadeada/List.hpp"
#include "MusicManager.hpp"
#include "TerminalColors.hpp"

using namespace std;

void addMusic(List<Music *> *musics)
{
   string nome, autor;

   cin.ignore();

   cout << str_blue("Nome: ");
   getline(cin, nome);

   cout << str_blue("Autor: ");
   getline(cin, autor);

   Music *m = new Music(nome, autor);
   musics->add(m);
}

void removeMusic(List<Music *> *musics, List<Playlist *> *playlists)
{
   if (musics->size < 1)
   {
      cout << str_red("\nAdicione músicas antes de tentar remover\n");
      return;
   }
   int index;

   listAllMusic(*musics);

   cout << str_blue("\nDigite o número da música: ");
   cin >> index;

   if (index < 1 || index > musics->size)
   {
      cout << str_red("\nValor digitado é inválido\n");
      return;
   }

   index--;
   Music *musicToRemove = musics->at(index);
   for (int i = 0; i < playlists->size; i++)
   {
      Playlist *workingPlaylist = playlists->at(i);
      List<Music*> *musics = workingPlaylist->getMusics();
      for (int j = 0; j < musics->size; j++)
      {
         if (musics->at(j)->getTitle() == musicToRemove->getTitle() && 
             musics->at(j)->getAuthor() == musicToRemove->getAuthor())
         {
            musics->remove(musics->at(j));
         }  
      }
   }
   
   musics->remove(musicToRemove);
}

void listAllMusic(List<Music *> musics)
{
   if (musics.size < 1)
   {
      cout << str_red("\nNenhuma música salva\n");
      return;
   }
   
   cout << "\n";

   for (int i = 0; i < musics.size; i++)
   {
      cout << i + 1 << "º - ";
      musics.at(i)->toString();
   }

   cout << "\n";
}