#include "Node.hpp"

#ifndef LISTS_HPP
#define LISTS_HPP

template <typename T>
class Lists
{
public:
   Node<T> *head;
   Node<T> *tail;
   int size = 0;

   Lists()
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
         return;
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

      return current->value;
   }

   void remove(T value)
   {
      Node<T> *current = this->head;
      Node<T> *last = nullptr;

      if (size > 0)
      {
         while (current != nullptr && last->value != value)
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
               Node<T> *temp = current;
               this->head = this->head->next;
               delete temp;
            }
            // Caso seja qualquer outro
            else
            {

               anterior->next = (*nextList)->next;
               delete *nextList;
            }
         }
      }
   }
};

#endif