#include "BackGroundMusic.h"
#include <iostream>


BackGroundMusic::BackGroundMusic(SDL2pp::Mixer &newmixer): mixer(newmixer),backGround0("music/background.ogg"),
    backGround1("music/background2.ogg"),explosionChunk("music/explosion.ogg"),
    jumpChunk("music/jump.ogg"), turboChunk("music/turboSound.ogg"),bounceChunk("music/bounce.ogg"){
    this->isPlayingMusic = true;
    this->isPlayingTurboSound = false;
    this->channel = 1;
    this->actualMusic = 0;
    this->mixer.PlayChannel(channel, backGround0);
    this->volume = mixer.SetVolume(1,1);
}


void BackGroundMusic::changeMusic(){
    std::cout << actualMusic << std::endl;
    actualMusic = (actualMusic + 1)%2;
    std::cout << actualMusic << std::endl;
    if(actualMusic == 0){mixer.PlayChannel(channel, backGround0);}
    else if (actualMusic == 1){mixer.PlayChannel(channel, backGround1);}
}

void BackGroundMusic::setVolume(int volume){
    mixer.SetVolume(1,volume);
}

void BackGroundMusic::togglePause(){
    if (isPlayingMusic){
        isPlayingMusic = false;
        mixer.PauseChannel(channel);
    } else {
        isPlayingMusic = true;
        mixer.ResumeChannel(channel);
    }
}

bool BackGroundMusic::getIsPlayingMusic(){
    return isPlayingMusic;
}



void BackGroundMusic::explosionMusic(bool isInExplosion){
    if(isInExplosion && mixer.IsChannelPlaying(2) == 0){
        mixer.SetVolume(2,10);
        mixer.PlayChannel(2, explosionChunk);}
}


void BackGroundMusic::jumpSound(){
    if (mixer.IsChannelPlaying(-1) >= mixer.GetNumChannels()) {return;}
    mixer.PlayChannel(-1, jumpChunk);
}


void BackGroundMusic::turboSound() {
    turboChannel = mixer.PlayChannel(-1, turboChunk, -1);
    this->isPlayingTurboSound = true;
}

bool BackGroundMusic::getIsPlayingTurbo() {
    return this->isPlayingTurboSound;
}


void BackGroundMusic::stopTurboSound() {
    mixer.HaltChannel(turboChannel);
    this->isPlayingTurboSound = false;
}

void BackGroundMusic::bounceMusic(){
    if (mixer.IsChannelPlaying(-1) >= mixer.GetNumChannels()) {return;}
    mixer.PlayChannel(-1, bounceChunk);
}