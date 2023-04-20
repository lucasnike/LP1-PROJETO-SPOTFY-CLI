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
   cout << this->title << "\033[1;31m by \033[0m" << this->author << endl;
}