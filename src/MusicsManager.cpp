#include "List.hpp"
#include <iostream>
#include "Music.hpp"

using namespace std;

void addMusic(List *musics)
{
   string nome, autor;

   cin.ignore();

   cout << "Nome: ";
   getline(cin, nome);

   cout << "Autor: ";
   getline(cin, autor);

   Music *m = new Music(nome, autor);
   musics->add(m);
   musics->at(0)->toString();
}