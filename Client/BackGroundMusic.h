#ifndef BACK_GROUND_MUSIC_H
#define BACK_GROUND_MUSIC_H

#include <SDL2pp/SDL2pp.hh>

class BackGroundMusic{


    SDL2pp::Mixer &mixer;
    int channel;
    int actualMusic;
    bool isPlayingMusic;
    int volume;
    SDL2pp::Chunk backGround0;
    SDL2pp::Chunk backGround1;
    SDL2pp::Chunk explosionChunk;

    public:

    BackGroundMusic(SDL2pp::Mixer &newmixer);
    //BackGroundMusic();


    void changeMusic();
    void togglePause();
    void setVolume(int volume);
    bool getIsPlayingMusic();


    void explosionMusic(bool isInExplosion);
    ~BackGroundMusic() = default;
};

#endif