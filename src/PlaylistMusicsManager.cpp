#include "PlaylistMusicsManager.hpp"
#include "Playlist.hpp"
#include <iostream>
#include "MusicManager.hpp"

using namespace std;

void addMusicToPlaylist(Playlist *playlist, List<Music *> musics)
{
    if (musics.size < 1)
    {
        cout << "\033[1;31mNão existe nenhuma música salva\033[0m\n";
        return;
    }
    int index;
    listAllMusic(musics);
    cout << "Digite o número da música: ";
    cin >> index;

    if (index > musics.size)
    {
        cout << "\033[1;31mMúsica escolhida é inválida\033[0m\n";
        return;
    }

    index--;
    Music *music = new Music(musics.at(index));
    playlist->addToPlaylist(music);
}

void removeMusicFromPlayList(Playlist *playlist)
{
    bool result = playlist->displayAllMusics(0);

    if (!result)
        return;
    int index;
    cout << "Digite o número da música: ";
    cin >> index;
    

}