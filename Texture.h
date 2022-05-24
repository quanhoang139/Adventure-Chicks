#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

struct Position {
    int x, y;
    Position (int _x = 0, int _y = 0){
        x = _x; y= _y;
    }
};

struct Tile {
    int x, y;
    Tile (int _x = 0, int _y = 0) {
        x = _x; y = _y;
    }
    bool operator==(const Tile other){
        if (x == other.x && y == other.y) return true;
        return false;
    }
};

struct QandA{
    std::string question;
    std::string answerA;
    std::string answerB;
    std::string answerC;
    std::string answerD;
    std::string answer;
    std::string choose;
};

class Texture{
    private:
        SDL_Texture* background;
        SDL_Texture* chicken_R;
        SDL_Texture* chicken_L;
        SDL_Texture* numberBomb[8];
        SDL_Texture* grass;
        SDL_Texture* bomb;
        SDL_Texture* land;
        SDL_Texture* flag;
        SDL_Texture* HP;
        SDL_Texture* banner;
        SDL_Texture* difficultyBoard;
        SDL_Texture* menuBoard;
        SDL_Texture* easyBoard;
        SDL_Texture* normalBoard;
        SDL_Texture* hardBoard;
        SDL_Texture* titleRecord;
        SDL_Texture* teacher;
        SDL_Texture* student;
        SDL_Texture* bombEffect;
        SDL_Texture* gameOver;
        SDL_Texture* win;
        SDL_Texture* header;
        SDL_Texture* subjectBoard;
        TTF_Font *font = nullptr;

        SDL_Texture* loadImage(SDL_Renderer* renderer, const std::string imgPath);

        void renderText(SDL_Renderer* renderer, std::string text,
                        SDL_Color color, int posX, int posY);

        void renderTextUTF8(SDL_Renderer* renderer, std::string text, SDL_Color color,
                            int posX, int posY, int wrap, int maxHeight);

    public:
        int scale = 0;
        int scaleBomb = 0;

        Texture();
        ~Texture();

        void loadMedia(SDL_Renderer* renderer);
        void renderMenu(SDL_Renderer* renderer);
        void renderWin(SDL_Renderer* renderer);
        void renderGameOver(SDL_Renderer* renderer);
        void renderQandA(SDL_Renderer* renderer, QandA *qanda, int timeRemaining);
        void renderBombEffect(SDL_Renderer* renderer, Position posChick);
        void renderTextureInGame(SDL_Renderer* renderer, int matrixGrass[7][20],
                         int matrixBomb[7][20], int matrixFlag[7][20], float hp,
                         bool isGameOver, bool isWin, bool isSetting, bool isRemoving,
                         int usedMinesweeper, int score, int target);
        void renderChick(SDL_Renderer* renderer, Position posChick, int number,
                         bool isMoving, bool left, int matrixBomb[7][20]);
        void renderRecordList(SDL_Renderer* renderer, int recordEasy[],
                              int recordNormal[], int recordHard[]);
};

#endif //_TEXTURE_H_
