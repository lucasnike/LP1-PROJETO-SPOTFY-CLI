#include <iostream>
#include <Playlist.hpp>
#include "DisplayMenus.hpp"

using namespace std;

void displayMainMenu()
{
   cout << "----------------------------\n";
   cout << "MENU PRINCIPAL\n";
   cout << "[1] - Gerenciar músicas\n";
   cout << "[2] - Gerenciar playlists\n";
   cout << "[3] - Fechar app\n";
   cout << "----------------------------\n";
}

void displayMusicsMenu()
{
   cout << "----------------------------\n";
   cout << "MENU MÚSICAS\n";
   cout << "[1] - Adicionar músicas\n";
   cout << "[2] - Remover músicas\n";
   cout << "[3] - Listar todas as músicas\n";
   cout << "[4] - Retornar ao menu principal\n";
   cout << "[5] - Fechar app\n";
   cout << "----------------------------\n";
}

void displayPlaylistsMenu()
{
   cout << "----------------------------\n";
   cout << "MENU PLAYLISTS\n";
   cout << "[1] - Gerenciar uma playlist\n";
   cout << "[2] - Adicionar playlist\n";
   cout << "[3] - Remover playlist\n";
   cout << "[4] - Listar todas as playlists\n";
   cout << "[5] - Retornar ao menu principal\n";
   cout << "[6] - Fechar app\n";
   cout << "----------------------------\n";
}
void displayPlaylistsMusicsMenu(Playlist pl)
{
   cout << "----------------------------\n";
   cout << "Playlist selecionada: " << pl.getName() << endl;
   cout << "[1] - Adicionar músicas à playlist\n";
   cout << "[2] - Remover músicas da playlist\n";
   cout << "[3] - Listar todas as músicas da playlist\n";
   cout << "[4] - Retornar ao menu anterior\n";
   cout << "[5] - Fechar app\n";
   cout << "----------------------------\n";
}