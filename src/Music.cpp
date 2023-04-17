#include "Music.hpp"

#include <iostream>

Music::Music(){}
Music::Music(string title, string author)
{
   this->title = title;
   this->author = author;
}

void Music::toString()
{
   cout << this->title << " by " << this->author << endl;
}