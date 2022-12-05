#include "BackGroundMusic.h"


BackGroundMusic::BackGroundMusic(SDL2pp::Mixer &newmixer): mixer(newmixer),backGround0("music/background.ogg"),
    backGround1("music/background2.ogg"){
    this->isPlayingMusic = true;
    this->channel = 1;
    this->actualMusic = 0;
    this->mixer.PlayChannel(channel, backGround0);
    this->volume = mixer.SetVolume(1,5);
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
