#include "Sound.h"

Sound::Sound() {
}

Sound::~Sound() {
}

void Sound::load() {
    gameBG = Mix_LoadMUS("asset/Sound/GameBG.flac");
    if (gameBG == nullptr) std::cout << Mix_GetError();
    Mix_PlayMusic(gameBG, -1);
    effectVol = true;
    musicVol = true;
    gameOver = Mix_LoadMUS("asset/Sound/EffectGameOver.wav");
    win = Mix_LoadMUS("asset/Sound/EffectLevelCleared.wav");
}

void Sound::playMusicBG(){
    Mix_PlayMusic(gameBG, -1);
}

void Sound::playMusicGO(){
    Mix_PlayMusic(gameOver, -1);
}

void Sound::playMusicWin(){
    Mix_PlayMusic(win, -1);
}

void Sound::changeMusicVol() {
    musicVol = !musicVol;
    if (musicVol) Mix_VolumeMusic(MIX_MAX_VOLUME);
    else Mix_VolumeMusic(0);
}

void Sound::changeEffectVol() {
    effectVol = !effectVol;
    if (effectVol) Mix_Volume(-1, MIX_MAX_VOLUME);
    else Mix_Volume(-1, 0);
}

bool Sound::getEffectVol() {
    return effectVol;
}

bool Sound::getMusicVol() {
    return musicVol;
}
