#ifndef BACK_GROUND_MUSIC_H
#define BACK_GROUND_MUSIC_H

#include <SDL2pp/SDL2pp.hh>


//Clase que se encarga de toda la musica en la aplicacion. Estas sean la musica de fondo, las explosiones,
//los saltos, el turbo y las colisiones entre la pelota y el jugador.
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

    //Init.
    BackGroundMusic(SDL2pp::Mixer &newmixer);
    //BackGroundMusic();

    //Cambio de las canciones de fondo. 
    void changeMusic();

    //Pausa la musica de fondo
    void togglePause();

    //Setea el volumen del canal de la musica de fondo
    void setVolume(int volume);
    
    //True si se esta reproduciendo la musica de fondo.
    bool getIsPlayingMusic();

    //Sonido del salto del auto.
    void jumpSound();

    //Sonido del turbo del auto.
    void turboSound();

    //Para el sonido del turbo en caso de soltar la tecla.
    void stopTurboSound();

    bool getIsPlayingTurbo();

    //Sonido de la explosion.
    void explosionMusic(bool isInExplosion);
    ~BackGroundMusic() = default;
};

#endif