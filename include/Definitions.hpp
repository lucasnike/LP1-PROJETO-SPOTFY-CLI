#ifndef DEF_HPP
#define DEF_HPP

/// @brief Enumeração para identificar os itens escolhidos no menu principal dentro do switch
enum class MainMenu
{
   musics = 1,
   playlists = 2,
   end = 3
};

/// @brief Enumeração para identificar os itens escolhidos no menu de gerenciamento de músicas dentro do switch
enum class MusicsMenu
{
   add = 1,
   remove = 2,
   list = 3,
   main = 4
};

/// @brief Enumeração para identificar os itens escolhidos no menu de gerenciamento de playlists dentro do switch
enum class PlayListMenu
{
   manage = 1,
   add = 2,
   remove = 3,
   list = 4,
   join = 5,
   extend = 6,
   reduce = 7,
   main = 8
};

/// @brief Enumeração para identificar os itens escolhidos no menu de gerenciamento de uma playlist dentro do switch
enum class PlayListMusicsMenu
{
   add = 1,
   remove = 2,
   list = 3,
   next = 4,
   move = 5,
   previus = 6
};

#endif