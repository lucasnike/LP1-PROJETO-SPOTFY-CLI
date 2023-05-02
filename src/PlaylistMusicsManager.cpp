#include "PlaylistMusicsManager.hpp"
#include "Playlist.hpp"
#include <iostream>
#include "MusicManager.hpp"
#include "TerminalColors.hpp"

using namespace std;

void addMusicToPlaylist(Playlist *playlist, List<Music *> musics)
{
    if (musics.size < 1)
    {
        cout << str_red("\nNão existe nenhuma música salva\n");
        return;
    }
    int index;
    listAllMusic(musics);
    cout << str_blue("\nDigite o número da música: ");
    cin >> index;

    if (index > musics.size)
    {
        cout << str_red("\nMúsica escolhida é inválida\n");
        return;
    }

    index--;

    Music *musicToCopy = musics.at(index);
    List<Music *> *playlistMusics = playlist->getMusics();

    for (int i = 0; i < playlistMusics->size; i++)
    {
        Music *current = playlistMusics->at(i);

        if (current->getTitle() == musicToCopy->getTitle() &&
            current->getAuthor() == musicToCopy->getAuthor())
        {
            cout << str_red("\nMúsica já está na playlist\n");
            return;
        }
    }

    Music *music = new Music(musicToCopy);
    playlist->addToPlaylist(music);
}

void removeMusicFromPlayList(Playlist *playlist)
{
    bool result = playlist->displayAllMusics(0);
    if (!result)
        return;

    List<Music *> *musics = playlist->getMusics();
    int index;
    cout << str_blue("\nDigite o número da música: ");
    cin >> index;

    if (index > musics->size)
    {
        str_red("\nNúmero digitado é inválido\n");
        return;
    }

    index--;
    musics->remove(musics->at(index));
}

void moveMusic(Playlist *playlist)
{
    List<Music *> *musics = playlist->getMusics();
    if (musics->size < 2)
    {
        cout << str_red("\nÉ necessário ter duas ou mais músicas para realizar a ordenação\n");
        return;
    }

    bool result = playlist->displayAllMusics(0);

    if (!result)
        return;

    int from, to;
    cout << str_blue("\nDigite o número da música que trocará de posição: ");
    cin >> from;

    if (from > musics->size)
    {
        cout << str_red("\nO número da música digitado é inválido\n");
        return;
    }

    from--;
    Music selected = *musics->at(from);

    cout << "\nMúsica selecionada: " << str_cyan(selected.getTitle() + "\n");

    cout << str_blue("\nDigite para qual posiçção a música selecionada irá: ");
    cin >> to;

    if (to > musics->size)
    {
        cout << str_red("\nO número da música digitado é inválido\n");
        return;
    }

    to--;

    musics->move(from, to);
}