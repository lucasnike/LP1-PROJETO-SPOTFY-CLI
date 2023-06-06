#include <iostream>
#include "Music.hpp"
#include "ListaEncadeada/List.hpp"

using namespace std;

#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

class Playlist
{
private:
   /// @brief Nome da playlist
   string name;
   /// @brief Lista das músicas da playlists
   List<Music *> *musics;
   /// @brief Índice da próxima música a ser tocada
   int currentMusic = 0;

public:
   /// @brief Contrutor da classe Playlist
   /// @param nome Nome da playlist
   Playlist(string);
   Playlist(Playlist*);
   /// @brief Função que adiciona uma música na playlist
   /// @param music Ponteiro para a música que será adicionada
   void addToPlaylist(Music *m) const { this->musics->add(m); }
   /// @brief Função que remove uma música da playlist
   /// @param music Ponteiro para a música que será removida
   void removeFromPlaylist(Music *m) const { this->musics->remove(m); }
   /// @brief Imprime em tela a próxima música a ser tocada na playlist
   void next();
   /// @brief Imprime em tela todas as músicas da playlist de forma recursiva
   /// @param index As músicas serão mostradas a partir do indice fornecido como parametro
   /// @return Valor booleano que é true quanto alguma música foi mostrada e false caso nenhuma música foi mostrada 
   bool displayAllMusics(int index);
   /// @brief Função get da propriedade name
   /// @return Retorna o nome da playlist
   string getName() const { return this->name; }
   void setName(string);
   /// @brief Retorna o ponteira para a lista de músicas da playlist
   /// @return ponteiro para listas de músicas
   List<Music *> *getMusics() const { return this->musics; }
   /// @brief Imprime em tela o nome da playlist de forma personalizada
   void toString();

   Playlist* operator+(Playlist*);
   Playlist* operator+(Music);

   Playlist* operator-(Playlist*);
   Playlist* operator-(Music);

   void operator>>(Music**);
   void operator<<(Music);

   void extend(Playlist*);
   void remove(Playlist*);

};

#endif