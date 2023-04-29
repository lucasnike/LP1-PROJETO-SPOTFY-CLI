#include "Node.hpp"
#include <iostream>
#include "TerminalColors.hpp"

using namespace std;

#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class List
{
public:
   Node<T> *head;
   Node<T> *tail;
   int size = 0;

   List()
   {
      this->head = nullptr;
      this->tail = nullptr;
   }

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

   T at(int index)
   {
      Node<T> *current = head;

      for (int i = 0; i < index; i++)
      {
         current = current->next;
      }
      return current->value;
   }

   Node<T>* at_node(int index)
   {
      Node<T> *current = head;

      for (int i = 0; i < index; i++)
      {
         current = current->next;
      }
      return current;
   }

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
            else if(position + 1 == this->size && this->size > 2)
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
};

#endif