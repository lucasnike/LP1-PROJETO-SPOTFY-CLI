#include <iostream>
#include "Playlist.hpp"

using namespace std;

Playlist::Playlist(string name)
{
   this->musics = new List();
   this->name = name;
}

Playlist::~Playlist()
{

}