#ifndef _SOUND_H_
#define _SOUND_H_

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

class Sound {
    private:
        bool musicVol;
        bool effectVol;

        Mix_Music* gameBG = nullptr;
        Mix_Music* gameOver = nullptr;
        Mix_Music* win = nullptr;

    public:
        Sound();
        ~Sound();
        void load();
        void changeMusicVol();
        void changeEffectVol();
        void playMusicBG();
        void playMusicGO();
        void playMusicWin();
        bool getMusicVol();
        bool getEffectVol();
};

#endif // _SOUND_H_
