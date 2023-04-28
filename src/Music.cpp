#include "Music.hpp"

#include <iostream>

Music::Music(){}
Music::Music(string title, string author)
{
   this->title = title;
   this->author = author;
}
Music::Music(Music *music)
{
   this->title = music->getTitle();
   this->author = music->getAuthor();
}

void Music::toString()
{
   cout << this->title << "\033[1;31m by \033[0m" << this->author << endl;
}