#include <iostream>

using namespace std;

#ifndef MUSIC_HPP
#define MUSIC_HPP

class Music
{
private:
   string title;
   string author;

public:
   Music();
   Music(string, string);
   Music(Music*);
   string getTitle() const { return this->title; }
   string getAuthor() const { return this->author; }
   void toString();
};

#endif