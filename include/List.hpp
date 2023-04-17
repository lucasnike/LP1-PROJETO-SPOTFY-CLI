#include <iostream>
#include "Music.hpp"

using namespace std;

#ifndef LIST_HPP 
#define LIST_HPP

class List {
   private:
      Music *head;
      List *next;
      unsigned int size;
   public:
      List();
      ~List();
      void add(Music*);
      void remove(Music*);
      Music* at(unsigned int);
      Music getMusicByTitle(string);
      Music getMusicByAuthor(string);

      unsigned int getSize() const { return this->size; }
};

#endif