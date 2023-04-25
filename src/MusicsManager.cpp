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

void removeMusic(List<Music *> *musics)
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
   musics->remove(musics->at(index));
}

void listAllMusic(List<Music *> musics)
{
   if (musics.size < 1)
   {
      cout << "Não existe nenhuma música salva\n";
      return;
   }
   for (int i = 0; i < musics.size; i++)
   {
      cout << i + 1 << "º - ";
      musics.at(i)->toString();
   }
}