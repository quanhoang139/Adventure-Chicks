#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "Core.h"

class Window {
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        Core gamePlay;

        const int SCREEN_WIDTH = 1472;
        const int SCREEN_HEIGHT = 768;
        const std::string WINDOW_TITTLE = "ADVENTURE CHICKS";
    public:
        Window();
        ~Window();
        void init();
        void close();
        void run();
};

#endif // _WINDOW_H_

