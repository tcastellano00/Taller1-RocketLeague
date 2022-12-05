#ifndef BACK_GROUND_MUSIC_H
#define BACK_GROUND_MUSIC_H

#include <SDL2pp/SDL2pp.hh>

class BackGroundMusic{


    SDL2pp::Mixer &mixer;
    int channel;
    int actualMusic;
    bool isPlayingMusic;
    bool isPlayingTurboSound;
    int volume;
    int turboChannel;
    SDL2pp::Chunk backGround0;
    SDL2pp::Chunk backGround1;
    SDL2pp::Chunk explosionChunk;
    SDL2pp::Chunk jumpChunk;
    SDL2pp::Chunk turboChunk;

    public:

    BackGroundMusic(SDL2pp::Mixer &newmixer);
    //BackGroundMusic();


    void changeMusic();
    void togglePause();
    void setVolume(int volume);
    bool getIsPlayingMusic();

    void jumpSound();
    void turboSound();
    void stopTurboSound();

    bool getIsPlayingTurbo();

    void explosionMusic(bool isInExplosion);
    ~BackGroundMusic() = default;
};

#endif