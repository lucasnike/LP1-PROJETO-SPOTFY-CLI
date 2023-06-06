#include "Node.hpp"
#include <iostream>
#include "TerminalColors.hpp"
#include <type_traits>

using namespace std;

#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class List
{
private:
   /// @brief Inicio da lista encadeada
   Node<T> *head;
   /// @brief Fim da lista encadeada
   Node<T> *tail;

public:
   /// @brief Guarda o tamanho atual da lista
   int size = 0;
   /// @brief Construtor da List inicia tanto o head quanto o tail com nullptr
   List()
   {
      this->head = nullptr;
      this->tail = nullptr;
   }

   List(List<T> *list)
   {
      this->head = list->head;
      this->tail = list->tail;
   }

   /// @brief Adiciona a lista um valor genérico
   /// @param value Valor a ser adicionado a lista
   void add(T value)
   {
      if (tail != nullptr && head != nullptr)
      {
         this->tail->next = new Node<T>(value);
         this->tail = this->tail->next;
      }
      else if (head == nullptr && tail == nullptr)
      {
         this->head = new Node<T>(value);
         this->tail = nullptr;
      }
      else if (tail == nullptr && head != nullptr && this->size == 1)
      {
         this->tail = new Node<T>(value);
         head->next = tail;
      }
      this->size += 1;
   }
   /// @brief Retorna o item da lista localizado no índice passado como parâmetro
   /// @param index Índice que localiza o item que será retornado
   /// @return Item da lista
   T at(int index)
   {
      Node<T> *current = head;

      for (int i = 0; i < index; i++)
      {
         current = current->next;
      }
      return current->value;
   }

   /// @brief Retorna o nó do índice informado
   /// @param index indice do item
   /// @return Item localizado no índice passado como parâmetro
   Node<T> *at_node(int index)
   {
      Node<T> *current = head;

      for (int i = 0; i < index; i++)
      {
         current = current->next;
      }
      return current;
   }

   /// @brief Remove um item da lista
   /// @param value item a ser removido
   void remove(T value)
   {
      Node<T> *current = this->head;
      Node<T> *last = nullptr;
      int position = 0;

      if (size > 0)
      {
         while (current->value != value)
         {
            last = current;
            current = current->next;
            position++;
         }

         // Se foi encontrado um item para ser removido
         if (current != nullptr)
         {
            // Caso seja o primeiro e único
            if (last == nullptr && this->size == 1)
            {
               Node<T> *temp = current;
               this->head = current->next;

               delete temp;

               this->head = nullptr;
               this->tail = nullptr;
            }
            // Primeiro com dois ou mais
            else if (last == nullptr && this->size > 1)
            {
               Node<T> *temp = current;
               this->head = current->next;
               delete temp;
            }
            // Ultimo com três ou mais
            else if (position + 1 == this->size && this->size > 2)
            {
               this->tail = last;
               delete current;
            }
            // Último com dois
            else if (position + 1 == this->size)
            {
               this->tail = nullptr;
               delete current;
            }
            // Caso seja qualquer outro
            else
            {
               last->next = current->next;
               current->next = nullptr;
               delete current;
            }

            this->size -= 1;
         }
      }
   }

   /// @brief Troca o valor de dois itens da lista
   /// @param from índice do item que será movido
   /// @param to índice para onde o item escolhido no parâmetro from será movido
   /// @return retorna false caso o tamanho da lista seja menor que 2 e seria impossível trocar dois itens de posição, retorna true em qualquer outra situação
   bool move(int from, int to)
   {
      if (size < 2)
      {
         return false;
      }

      Node<T> *from_node = this->at_node(from);
      Node<T> *to_node = this->at_node(to);
      T temp = to_node->value;

      to_node->value = from_node->value;
      from_node->value = temp;

      return true;
   }

   /// @brief Recebe uma List como parâmetro e adiciona todos os seus elementos à lista original
   /// @param newList Uma List do mesmo tipo da lista orginal
   /// @return Retorna um valor booleano que representa se foi possível ou não unir as duas listas
   bool extend(List<T> *newList)
   {
      if (newList->size < 1)
      {
         return false;
      }

      for (int i = 0; i < newList->size; i++)
      {
         this->add(newList->at(i));
      }

      return true;
   }

   /// @brief Recebe uma lista com os itens que serão removidos da lista
   /// @param list Lista com os itens a remover
   void remove(List<T> *list)
   {
      int size = this->size;
      int i = 0;
      while (i < size)
      {
         T current = this->at(i);
         for (int j = 0; j < list->size; j++)
         {
            if (current == list->at(j))
            {
               this->remove(current);
               size = this->size;
               i--;
            }
         }
         i++;
      }
   }

   List<T> operator + (List<T> list)
   {
      List<T> *newList = new List<T>();
      newList->extend(this);
      newList->extend(&list);
      return *newList;
   }

};

#endif