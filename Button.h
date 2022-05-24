#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>

class Button {
    private:
        int option;
        int width;
        int height;
        int posX;
        int posY;

        Mix_Chunk* buttonEffect = nullptr;
        SDL_Texture* fiButtonTexture = nullptr;
        SDL_Texture* seButtonTexture = nullptr;
    public:
        Button();
        ~Button();

        bool checkUserClickPos();
        void renderButton(SDL_Renderer* renderer);
        void reloadButton(const int option);
        void loadButton(SDL_Renderer *renderer, const int width,
                        const int heigth,const int scrPosX,
                        const int scrPosY, const std::string fiImgPath = " ", std::string seImgPath = " ");
};
#endif // _BUTTON_H_

