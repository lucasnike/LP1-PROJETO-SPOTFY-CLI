#include <iostream>

using namespace std;

#ifndef MUSIC_HPP
#define MUSIC_HPP

class Music
{
private:
   /// @brief Título da música
   string title;
   /// @brief Autor da música
   string author;

public:
   /// @brief Construtor da classe
   Music();
   /// @brief Construtor da classe, inicia as propriedades com os valores passados como parâmetro
   /// @param  Titulo Título da música
   /// @param  Autor Autor da música
   Music(string, string);
   /// @brief Construtor da classe, cria uma música fazendo uma cópia dos valores de uma música existente
   /// @param  Musica ponteira para uma música
   Music(Music*);

   /// @brief Função get da propriedade title
   /// @return Título da música
   string getTitle() const { return this->title; }
   /// @brief Função get da propriedade author
   /// @return Autor da música
   string getAuthor() const { return this->author; }
   /// @brief Imprime a música em tela de forma personalizada
   void toString();
};

#endif