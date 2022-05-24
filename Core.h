#ifndef _CORE_H_
#define _CORE_H_

#include "Texture.h"
#include "Button.h"
#include "Sound.h"
#include "Time.h"
#include <fstream>
#include <random>

using namespace std;

class Core {
    private:
        Texture gameTexture;
        Sound gameSound;
        Mix_Chunk* clickEffect;
        Mix_Chunk* bombEffect;
        Mix_Chunk* correctEffect;

        int matrixBomb[7][20];
        int matrixGrass[7][20];
        int matrixFlag[7][20];
        int recordEasy[3] = {0};
        int recordNormal[3] = {0};
        int recordHard[3] = {0};
        int score;
        int target;
        int difficulty = 0, curDifficulty = 0;
        int curRun;
        int numberBomb;
        int usedMinesweeper;
        int maxTimeToAnswer;
        int maxBomb;
        int timeRemaining;
        int subject = 0;
        float healthPoint;

        bool isContinue = false;
        bool isLeft;
        bool gameOver = false;
        bool win = false;
        bool checkClickMenu;
        bool isAnswering = false;
        bool isSetingFlag;
        bool isRemovingFlag;
        bool isMoving;
        bool isRenderQandA;

        QandA qanda;
        vector<QandA> listQandA;
        Position curPosChick;
        Tile curTileChick, nextTileChick;

        Button button[30];
        void renderMenu(SDL_Renderer* renderer);
        void renderInGame(SDL_Renderer* renderer);
        void renderRecordList(SDL_Renderer* renderer);
    public:
        static const int MENU = 0;
        static const int INGAME = 1;
        static const int RECORD_LIST = 2;
        static const int EASY = 0;
        static const int NORMAL = 1;
        static const int HARD = 2;
        static const int CHICK_SPEED = 16;
        static const int HISTORY = 0;
        static const int PHYSICS = 1;
        static const int GEOGRAPHY = 2;
        static const int COMBINATION = 3;

        Timer gameTime;
        Timer timeAnswer;

        Core () {;};
        ~Core() {;};

        void dataInit();
        void init(SDL_Renderer* &renderer);
        bool handlingEvent(SDL_Event &e, SDL_Renderer* renderer);
        void renderTexture(SDL_Renderer* renderer);
        void minesweeper();
        int getNumberBomb();
        int getScore();
        void moveRight(Tile nextTile);
        void moveLeft(Tile nextTile);
        void moveUp(Tile nextTile);
        void moveDown(Tile nextTile);
        void setUpBomb();
        void chooseDifficulty();
        void chooseSubject();

        void getRecord();
        void getQandA(QandA &qanda);
        void saveData();
        void getData();
};

#endif // _CORE_H_

