#include <FileManager.hpp>
#include <ListaEncadeada/List.hpp>
#include <Music.hpp>
#include <Playlist.hpp>
#include <fstream>

void readData(List<Music *> *musics, List<Playlist *> *playlists, string file)
{
   int count = 0;
   ifstream reader;
   reader.open(file);

   if (!reader)
   {
      return;
   }

   while (!reader.eof())
   {
      int index, musicsByPlaylist = 0;
      string line;
      Playlist *currentPlayList;
      getline(reader, line);

      if (line.size() <= 1)
         break;

      index = line.find(';');
      string p_name = line.substr(0, index);
      line.erase(0, index + 1);

      if (count != 0)
      {
         playlists->add(new Playlist(p_name));
         currentPlayList = playlists->at(count - 1);
      }

      for (char c : line)
      {
         if (c == ',')
         {
            musicsByPlaylist += 1;
         }
      }
      musicsByPlaylist++;      
      int i = 0;
      while (i < musicsByPlaylist )
      {
         i++;
         index = line.find(',');
         string sMusic = line.substr(0, index);
         line.erase(0, index + 1);

         index = sMusic.find(':');

         string musicName = sMusic.substr(0, index);
         string musicAuthor = sMusic.substr(index + 1, sMusic.size());

         if (count == 0)
         {
            musics->add(new Music(musicName, musicAuthor));
         }
         else
         {
            currentPlayList->addToPlaylist(new Music(musicName, musicAuthor));
         }

      }

      count++;
   }

   reader.close();
}

void writeData(List<Music *> *musics, List<Playlist *> *playlists, string file)
{
   ofstream writter;
   writter.open(file);

   if (!writter)
   {
      return;
   }

   // Escreve no arquivo a lista de músicas global
   string global = "global;";
   for (int i = 0; i < musics->size; i++)
   {
      Music *current = musics->at(i);
      global += current->getTitle() + ":" + current->getAuthor();
      if (i != musics->size - 1)
         global += ',';
   }
   if (musics->size > 0)
      writter << global << endl;
   
   

   // Escreve no arquivo a lista de playlists
   for (int i = 0; i < playlists->size; i++)
   {
      Playlist *currentPlaylist = playlists->at(i);
      List<Music *> *currentMusics = currentPlaylist->getMusics();

      string currentLine = currentPlaylist->getName() + ";";

      for (int j = 0; j < currentMusics->size; j++)
      {
         Music *currentMusic = currentMusics->at(j);
         currentLine += currentMusic->getTitle() + ":" + currentMusic->getAuthor();
         if (j != currentMusics->size - 1)
         {
            currentLine += ',';
         }
         else
         {
            writter << currentLine << endl;
            currentLine = "";
         }
      }
   }

   writter.close();
}
