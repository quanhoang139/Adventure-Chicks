#include "Window.h"

Window::Window() {
    window = nullptr;
    renderer = nullptr;
}

Window::~Window() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
}

void Window::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << SDL_GetError() << std::endl;
    } else {
        window = SDL_CreateWindow(WINDOW_TITTLE.c_str(), SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            std::cout << SDL_GetError() << std::endl;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == nullptr) {
                std::cout << SDL_GetError() << std::endl;
            }
            if (TTF_Init() == -1) {
                std::cout << TTF_GetError() << std::endl;
            }
            Mix_Init(MIX_INIT_FLAC);
            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 4, 4096) < 0) {
                std::cout << Mix_GetError() << std::endl;
            }
        }
    }
}

void Window::run() {
    gamePlay.getData();
    SDL_Event e;
    bool quit = false;
    gamePlay.init(renderer);
    while (!quit) {
        gamePlay.gameTime.start();
        while (SDL_PollEvent( & e) != 0) {
            if (e.type == SDL_QUIT) quit = true;
            else if (e.button.button == SDL_BUTTON_LEFT && e.button.state == SDL_PRESSED)
                if (!gamePlay.handlingEvent(e, renderer)) quit = true;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        gamePlay.renderTexture(renderer);
        SDL_RenderPresent(renderer);

        int real_time = gamePlay.gameTime.get_ticks();
        int time_one_frame = 1000 / 25; // fps = 25
        if (real_time < time_one_frame) {
            int delay_time = time_one_frame - real_time;
            SDL_Delay(delay_time);
        }
        gamePlay.gameTime.stop();
    }
    gamePlay.getRecord();
    gamePlay.saveData();
}

void Window::close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}


