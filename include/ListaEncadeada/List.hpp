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
      if (tail != nullptr && head != nullptr)
      {
         cout << "Final da lista\n";
         this->tail->next = new Node<T>(value);
         this->tail = this->tail->next;
      }
      else if (head == nullptr && tail == nullptr)
      {
         cout << "Primeiro item\n";
         this->head = new Node<T>(value);
         this->tail = nullptr;
      }
      else if (tail == nullptr && head != nullptr && this->size == 1)
      {
         cout << "Segundo item\n";
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
      cout << current << endl;

      return current->value;
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
            // Caso seja o primeiro
            if (last == nullptr && this->size == 1)
            {
               Node<T> *temp = current;
               this->head = current->next;
               temp->next = nullptr;
               delete temp;

               this->head = nullptr;
               this->tail = nullptr;
            }
            else if (last == nullptr && this->size > 1)
            {
               Node<T> *temp = current;
               this->head = current->next;
               temp->next = nullptr;
               delete temp;
            }
            else if (position + 1 == this->size)
            {
               cout << "Ultimo\n";
               this->tail = nullptr;
               current->next = nullptr;
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
};

#endif