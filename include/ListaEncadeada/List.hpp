#include "Node.hpp"
#include <iostream>

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
      if (tail != nullptr)
      {
         this->tail->next = new Node<T>(value);
         this->tail = this->tail->next;
      }
      else if (head == nullptr)
      {
         this->head = new Node<T>(value);
      }
      else if (tail == nullptr)
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
      cout << current->value << endl;

      return current->value;
   }

   void remove(T value)
   {
      Node<T> *current = this->head;
      Node<T> *last = nullptr;

      if (size > 0)
      {
         while (current->value != value)
         {
            last = current;
            current = current->next;
         }

         // Se foi encontrado um item para ser removido
         if (current != nullptr)
         {
            // Caso seja o primeiro
            if (last == nullptr)
            {
               cout << "Primeiro\n";
               Node<T> *temp = current;
               this->head = current->next;
               delete temp;
            }
            // Caso seja qualquer outro
            else
            {
               last->next = current->next;
               delete current;
            }

            this->size -= 1;
         }
      }
   }
};

#endif