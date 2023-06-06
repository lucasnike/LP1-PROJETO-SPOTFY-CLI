#include <iostream>
#include <Playlist.hpp>
#include "DisplayMenus.hpp"
#include "TerminalColors.hpp"

using namespace std;

void displayMainMenu()
{
   cout << str_purple("\nMENU PRINCIPAL\n");
   cout << "[1] - Gerenciar músicas\n";
   cout << "[2] - Gerenciar playlists\n";
   cout << "[3] - Fechar app\n";
}

void displayMusicsMenu()
{
   cout << str_purple("\nMENU MÚSICAS\n");
   cout << "[1] - Adicionar músicas\n";
   cout << "[2] - Remover músicas\n";
   cout << "[3] - Listar todas as músicas\n";
   cout << "[4] - Retornar ao menu principal\n";
   cout << "\n";
}

void displayPlaylistsMenu()
{
   cout << str_purple("\nMENU PLAYLISTS\n");
   cout << "[1] - Gerenciar uma playlist\n";
   cout << "[2] - Adicionar playlist\n";
   cout << "[3] - Remover playlist\n";
   cout << "[4] - Listar todas as playlists\n";
   cout << "[5] - Unir playlists\n",
   cout << "[6] - Ampliar playlist\n",
   cout << "[7] - Reduzir playlist\n",
   cout << "[8] - Retornar ao menu principal\n";
   cout << "\n";
}
void displayPlaylistsMusicsMenu(Playlist pl)
{
   cout << str_purple("\nMENU GERENCIADOR DE PLAYLIST\n");
   cout << "Playlist selecionada: " + str_green(pl.getName()) + "\n";
   cout << "[1] - Adicionar músicas à playlist\n";
   cout << "[2] - Remover músicas da playlist\n";
   cout << "[3] - Listar todas as músicas da playlist\n";
   cout << "[4] - Mostrar próxima música na playlist\n";
   cout << "[5] - Trocar ordem de músicas\n";
   cout << "[6] - Retornar ao menu anterior\n";
   cout << "\n";
}