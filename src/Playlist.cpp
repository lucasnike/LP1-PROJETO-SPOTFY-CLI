#include <iostream>
#include "Playlist.hpp"
#include "ListaEncadeada/List.hpp"
#include "TerminalColors.hpp"

using namespace std;

Playlist::Playlist(string name)
{
   this->musics = new List<Music *>();
   this->name = name;
}

Playlist::Playlist(Playlist *p)
{
   this->name = p->getName();
   this->musics = new List<Music *>();

   List<Music *> *out_musics = p->getMusics();
   for (int i = 0; i < out_musics->size; i++)
   {
      musics->add(new Music(out_musics->at(i)));
   }
}

void Playlist::toString()
{
   cout << str_green(this->name) << endl;
}

void Playlist::next()
{
   if (this->currentMusic < this->musics->size)
   {

      this->musics->at(this->currentMusic)->toString();
      this->currentMusic += 1;
   }
   else
   {
      cout << str_red("\nSem músicas para mostrar\n");
   }
}

bool Playlist::displayAllMusics(int index = 0)
{
   if (musics->size > 0)
   {
      if (index < musics->size)
      {
         cout << index + 1 << "º - ";
         musics->at(index)->toString();
         displayAllMusics(++index);
      }
      return true;
   }
   else
   {
      cout << str_red("\nNão existe nenhuma música salva na playlist\n");
      return false;
   }
}

void Playlist::setName(string name)
{
   this->name = name;
}

Playlist *Playlist::operator+(Playlist *p)
{
   Playlist *newP = new Playlist(this->getName() + " + " + p->getName());

   for (int i = 0; i < musics->size; i++)
   {
      Music *music = musics->at(i);
      newP->addToPlaylist(new Music(music));
   }

   List<Music *> *musics = newP->getMusics();
   List<Music *> *p_musics = p->getMusics();

   for (int i = 0; i < p_musics->size; i++)
   {
      Music *current = p_musics->at(i);
      bool has = false;

      for (int j = 0; j < musics->size; j++)
      {
         Music *compare = musics->at(j);
         if (current->getTitle() == compare->getTitle() &&
             current->getAuthor() == compare->getAuthor())
         {
            has = true;
            break;
         }
      }

      if (!has)
      {
         newP->addToPlaylist(new Music(current));
      }
   }

   return newP;
}

Playlist *Playlist::operator+(Music m)
{
   Playlist *newP = new Playlist(this->getName() + " + " + m.getTitle());

   for (int i = 0; i < musics->size; i++)
   {
      Music *music = musics->at(i);
      newP->addToPlaylist(new Music(music));
   }

   Music *music = new Music(&m);
   newP->addToPlaylist(music);
   return newP;
}

Playlist *Playlist::operator-(Playlist *p)
{
   Playlist *newP = new Playlist(this->getName() + " - " + p->getName());

   List<Music *> *musicsA = this->getMusics();
   List<Music *> *musicsB = p->getMusics();

   for (int i = 0; i < musicsA->size; i++)
   {
      Music *current = musicsA->at(i);
      bool has = false;
      for (int j = 0; j < musicsB->size; j++)
      {
         Music *compare = musicsB->at(j);

         if (current->getTitle() == compare->getTitle() && current->getAuthor() == compare->getAuthor())
         {
            has = true;
            break;
         }
      }

      if (!has)
      {
         newP->addToPlaylist(new Music(current));
      }
   }

   return newP;
}

Playlist *Playlist::operator-(Music m)
{
   Playlist *newP = new Playlist(this->getName() + " - " + m.getTitle());

   for (int i = 0; i < musics->size; i++)
   {
      Music *music = musics->at(i);
      newP->addToPlaylist(new Music(music));
   }

   List<Music *> *added = newP->getMusics();
   bool has = false;

   for (int i = 0; i < added->size; i++)
   {
      Music *music = added->at(i);

      if (music->getAuthor() == m.getAuthor() && music->getTitle() == m.getTitle())
      {
         newP->removeFromPlaylist(music);
         break;
      }
   }

   return newP;
}

void Playlist::operator>>(Music **m)
{
   if (musics->at(0) == nullptr)
   {
      m = nullptr;
   }
   Music *toRemove = musics->at(musics->size - 1);
   (*m) = new Music(toRemove);
   musics->remove(toRemove);
}

void Playlist::operator<<(Music music)
{
   addToPlaylist(new Music(&music));
}

void Playlist::extend(Playlist *p)
{
   List<Music *> *p_musics = p->getMusics();

   for (int i = 0; i < p_musics->size; i++)
   {
      Music *current = p_musics->at(i);
      bool has = false;

      for (int j = 0; j < musics->size; j++)
      {
         Music *compare = musics->at(j);
         if (current->getTitle() == compare->getTitle() &&
             current->getAuthor() == compare->getAuthor())
         {
            has = true;
            break;
         }
      }
      if (!has)
      {
         musics->add(new Music(current));
      }
   }
}

void Playlist::remove(Playlist *p)
{
   List<Music *> *musicsB = p->getMusics();

   int sizeMusicsA = musics->size;
   int i = 0;

   while (i < sizeMusicsA)
   {
      Music *current = musics->at(i);
      bool has = false;
      for (int j = 0; j < musicsB->size; j++)
      {
         Music *compare = musicsB->at(j);

         if (current->getTitle() == compare->getTitle() && current->getAuthor() == compare->getAuthor())
         {
            musics->remove(current);
            sizeMusicsA = musics->size;
            i--;
            break;
         }
      }

      i++;
   }
}