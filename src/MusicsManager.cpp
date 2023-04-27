#include <iostream>
#include "Music.hpp"
#include "ListaEncadeada/List.hpp"
#include "MusicManager.hpp"

using namespace std;

void addMusic(List<Music *> *musics)
{
   string nome, autor;

   cin.ignore();

   cout << "Nome: ";
   getline(cin, nome);

   cout << "Autor: ";
   getline(cin, autor);

   Music *m = new Music(nome, autor);
   musics->add(m);
   // musics->at(0)->toString();
}

void removeMusic(List<Music *> *musics, List<Playlist *> *playlists)
{
   if (musics->size < 1)
   {
      return;
   }
   int index;

   listAllMusic(*musics);

   cout << "Digite o número da música: ";
   cin >> index;

   if (index < 1 || index > musics->size)
   {
      cout << "Valor digitado é inválido\n";
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
            i = playlists->size;
            break;
         }  
      }
   }
   
   musics->remove(musicToRemove);
}

void listAllMusic(List<Music *> musics)
{
   if (musics.size < 1)
   {
      cout << "Não existe nenhuma música salva\n";
      return;
   }
   
   cout << "\n\n";

   for (int i = 0; i < musics.size; i++)
   {
      cout << i + 1 << "º - ";
      musics.at(i)->toString();
   }

   cout << "\n\n";
}