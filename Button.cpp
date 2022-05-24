#include "Button.h"

Button::Button() {
    option = 0;
}

Button::~Button() {
}

void Button::loadButton(SDL_Renderer* renderer, const int width,
                        const int height, const int posX, const int posY,
                        const std::string fiImgPath, std::string seImgPath) {
    this->width = width;
    this->height = height;
    this->posX = posX;
    this->posY = posY;

    if (fiImgPath != " ") {
        SDL_Surface* Image = IMG_Load(fiImgPath.c_str());
        fiButtonTexture = SDL_CreateTextureFromSurface(renderer, Image);
        SDL_FreeSurface(Image);
    }
    if (seImgPath != " ") {
        SDL_Surface* Image = IMG_Load(seImgPath.c_str());
        seButtonTexture = SDL_CreateTextureFromSurface(renderer, Image);
        SDL_FreeSurface(Image);
    }
    buttonEffect = Mix_LoadWAV("asset/Sound/EffectButton.wav");
}

bool Button::checkUserClickPos() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x < posX || y < posY || x > posX + width || y > posY + height)
        return false;

    Mix_PlayChannel(-1, buttonEffect, 0);
    return true;
}

void Button::renderButton(SDL_Renderer* renderer) {
    SDL_Rect dsRect = {posX, posY, width, height};
    if (fiButtonTexture != nullptr) {
        if (option == 0)
            SDL_RenderCopy(renderer, fiButtonTexture, nullptr, &dsRect);
        else
            SDL_RenderCopy(renderer, seButtonTexture, nullptr, &dsRect);
    }
}

void Button::reloadButton(const int option) {
    this->option = option;
}

