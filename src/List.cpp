#include "List.hpp"
#include <iostream>

using namespace std;

List::List()
{
   this->next = NULL;
   this->size = 0;
}

List::~List()
{
   delete this->head;
}

void List::add(Music *music)
{
   List **nextList = &this->next;
   while (*nextList != NULL)
   {
      nextList = &(*nextList)->next;
   }

   *nextList = new List();
   (*nextList)->head = music;
   this->size += 1;
}

Music *List::at(unsigned int index)
{
   List *nextList = this->next;
   for (int i = 0; i < index; i++)
   {
      nextList = nextList->next;
   }

   return nextList->head;
}

void List::remove(Music *music)
{
   List **nextList = &this->next;
   if (this->size > 0)
   {
      List *anterior = nullptr;
      while (*nextList != nullptr && (*nextList)->head != music)
      {
         anterior = *nextList;
         nextList = &(*nextList)->next;
      }

      if (nextList != nullptr)
      {
         if (anterior == nullptr)
         {
            (*nextList)->head = (*nextList)->next->head;
         }
         else
         {

            anterior->next = (*nextList)->next;
            delete *nextList;
         }
      }
   }
}