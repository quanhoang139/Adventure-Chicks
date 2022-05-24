#include "Texture.h"

Texture::Texture(){
}

Texture::~Texture(){
    for (int i = 0; i < 8; i++) SDL_DestroyTexture(numberBomb[i]);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(HP);
    SDL_DestroyTexture(land);
    SDL_DestroyTexture(bomb);
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(flag);
    SDL_DestroyTexture(gameOver);
    SDL_DestroyTexture(win);
    SDL_DestroyTexture(chicken_R);
    SDL_DestroyTexture(chicken_L);
    SDL_DestroyTexture(header);
    SDL_DestroyTexture(difficultyBoard);
    SDL_DestroyTexture(menuBoard);
    SDL_DestroyTexture(banner);
    SDL_DestroyTexture(teacher);
    SDL_DestroyTexture(student);
    SDL_DestroyTexture(bombEffect);
    SDL_DestroyTexture(easyBoard);
    SDL_DestroyTexture(normalBoard);
    SDL_DestroyTexture(hardBoard);
    SDL_DestroyTexture(titleRecord);
    SDL_DestroyTexture(subjectBoard);


    background = nullptr;
    for (int i = 0; i < 8; i++) numberBomb[i] = nullptr;
    HP = nullptr;
    land = nullptr;
    bomb =  nullptr;
    grass =  nullptr;
    flag =  nullptr;
    gameOver = nullptr;
    win = nullptr;
    chicken_R = nullptr;
    chicken_L = nullptr;
    header = nullptr;
    difficultyBoard = nullptr;
    menuBoard = nullptr;
    banner = nullptr;
    teacher = nullptr;
    student = nullptr;
    bombEffect = nullptr;
    easyBoard = nullptr;
    normalBoard = nullptr;
    hardBoard = nullptr;
    titleRecord = nullptr;
    subjectBoard = nullptr;
}

SDL_Texture* Texture::loadImage(SDL_Renderer* renderer, const std::string imgPath) {
    SDL_Surface* Image = IMG_Load(imgPath.c_str());
    SDL_Texture* loadTexture = SDL_CreateTextureFromSurface(renderer, Image);
    SDL_FreeSurface(Image);
    return loadTexture;
}

void Texture::renderText(SDL_Renderer* renderer, std::string text, SDL_Color color, int posX, int posY) {
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Rect Rect = {posX, posY, textSurface->w, textSurface->h};
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, textTexture, nullptr, &Rect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

void Texture::renderTextUTF8(SDL_Renderer* renderer, std::string text, SDL_Color color,
                             int posX, int posY, int wrap, int maxHeight) {
    SDL_Surface *textSurface =  TTF_RenderUTF8_Solid_Wrapped(font, text.c_str(), color, wrap);
    SDL_Rect Rect = {posX, posY + (maxHeight - textSurface->h)/2, textSurface->w, textSurface->h};
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, textTexture, nullptr, &Rect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

void Texture::loadMedia(SDL_Renderer* renderer){
    background = loadImage(renderer, "asset/img/background.png");
    numberBomb[0] = loadImage(renderer, "asset/img/1.png");
    numberBomb[1] = loadImage(renderer, "asset/img/2.png");
    numberBomb[2] = loadImage(renderer, "asset/img/3.png");
    numberBomb[3] = loadImage(renderer, "asset/img/4.png");
    numberBomb[4] = loadImage(renderer, "asset/img/5.png");
    numberBomb[5] = loadImage(renderer, "asset/img/6.png");
    numberBomb[6] = loadImage(renderer, "asset/img/7.png");
    numberBomb[7] = loadImage(renderer, "asset/img/8.png");
    HP = loadImage(renderer, "asset/img/heart.png");
    land = loadImage(renderer, "asset/img/land.png");
    bomb =  loadImage(renderer, "asset/img/bomb.png");
    grass =  loadImage(renderer, "asset/img/grass.png");
    flag =  loadImage(renderer, "asset/img/flag.png");
    gameOver = loadImage(renderer, "asset/img/gameover.png");
    win = loadImage(renderer, "asset/img/win.png");
    chicken_R = loadImage(renderer, "asset/img/chickright.png");
    chicken_L = loadImage(renderer, "asset/img/chickleft.png");
    header = loadImage(renderer, "asset/img/header.png");
    difficultyBoard = loadImage(renderer, "asset/img/difficulty.png");
    menuBoard = loadImage(renderer, "asset/img/menu.png");
    banner = loadImage(renderer, "asset/img/banner.png");
    teacher = loadImage(renderer, "asset/img/teacher.png");
    student = loadImage(renderer, "asset/img/student.png");
    bombEffect = loadImage(renderer, "asset/img/bombEffect.png");
    easyBoard = loadImage(renderer, "asset/img/easyBoard.png");
    normalBoard = loadImage(renderer, "asset/img/normalBoard.png");
    hardBoard = loadImage(renderer, "asset/img/hardBoard.png");
    titleRecord = loadImage(renderer, "asset/img/tileRecord.png");
    subjectBoard = loadImage(renderer, "asset/img/subject.png");
}

void Texture::renderTextureInGame(SDL_Renderer* renderer, int matrixGrass[7][20],
                          int matrixBomb[7][20], int matrixFlag[7][20], float hp,
                          bool isGameOver, bool isWin, bool isSetting, bool isRemoving,
                          int usedMinesweeper, int score, int target){
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_Rect Rect;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 20; j++) {
            Rect = {j * 64 + 165, i * 64 + 310, 64, 64};
            SDL_RenderCopy(renderer, land, nullptr, &Rect);
            if (matrixBomb[i][j] == 1)
                SDL_RenderCopy(renderer, bomb, nullptr, &Rect);
            if (matrixGrass[i][j] == 1)
                SDL_RenderCopy(renderer, grass, nullptr, &Rect);
            if (matrixFlag[i][j] == 1)
                SDL_RenderCopy(renderer, flag, nullptr, &Rect);
        }
    }
    Rect = {165 - 64, 310, 64, 64};
    SDL_RenderCopy(renderer, land, nullptr, &Rect);

    Rect = {0, 0, 1472, 416};
    SDL_RenderCopy(renderer, header, nullptr, &Rect);

    if (hp > 0){
        Rect = {128, 0, 57, 57};
        SDL_RenderCopy(renderer, HP, nullptr, &Rect);
        if (hp == 2){
            Rect = {185, 0, 57, 57};
            SDL_RenderCopy(renderer, HP, nullptr, &Rect);
        }
    }
    font = TTF_OpenFont("asset/ttf/font_game.ttf", 20);
    if (!isSetting) renderText(renderer, "SET FLAG", {0, 0, 255, 255}, 25, 450);
    else renderText(renderer, "SET FLAG", {255, 0, 0, 255}, 25, 450);

    if (!isRemoving) renderText(renderer, "REMOVE FLAG", {0, 0, 255, 255}, 5, 570);
    else renderText(renderer, "REMOVE FLAG", {255, 0, 0, 255}, 5, 570);

    renderText(renderer, "MINESWEEPER", {0, 0, 255, 255}, 5, 690);
    renderText(renderer, "Remaining: " + std::to_string(usedMinesweeper), {0, 0, 0, 255}, 10, 715);
    font = TTF_OpenFont("asset/ttf/font_game.ttf", 30);
    renderText(renderer, "Target: " + std::to_string(target), {0, 0, 0, 255}, 350, 5);
    font = TTF_OpenFont("asset/ttf/font_game.ttf", 40);
    renderText(renderer, "SCORE: " + std::to_string(score), {255, 0, 0, 255}, 350, 40);
    TTF_CloseFont(font);
}

void Texture::renderChick(SDL_Renderer* renderer, Position posChick,
                          int number, bool isMoving, bool left, int matrixBomb[7][20]){
    SDL_Rect Rect;
    Rect = {posChick.x, posChick.y, 64, 64};

    if (!left)
        SDL_RenderCopy(renderer, chicken_R, nullptr, &Rect);
    else
        SDL_RenderCopy(renderer, chicken_L, nullptr, &Rect);

    if (posChick.x != 165 - 64 && number != 0 && !isMoving
        && matrixBomb[(posChick.y-310)/64][(posChick.x - 165)/64] == 0){
        Rect = {posChick.x, posChick.y - 64, 64, 64};
        SDL_RenderCopy(renderer, numberBomb[number - 1], nullptr, &Rect);
    }
}

void Texture::renderMenu(SDL_Renderer* renderer) {
    scale = 0;
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_Rect Rect;
    Rect = {500, 200, 408, 540};
    SDL_RenderCopy(renderer, difficultyBoard, nullptr, &Rect);
    Rect = {50, 200, 408, 540};
    SDL_RenderCopy(renderer, menuBoard, nullptr, &Rect);
    Rect = {460, 0, 512, 190};
    SDL_RenderCopy(renderer, banner, nullptr, &Rect);
    Rect = {940, 200, 408, 540};
    SDL_RenderCopy(renderer, subjectBoard, nullptr, &Rect);
}

void Texture::renderQandA(SDL_Renderer* renderer, QandA *qanda, int timeRemaining){

    font = TTF_OpenFont("asset/ttf/RadioCanada-Bold.ttf", 25);
    renderTextUTF8(renderer, qanda->question, {0, 0, 0, 255}, 110, 95, 1250, 90);

    font = TTF_OpenFont("asset/ttf/RadioCanada-Bold.ttf", 25);
    renderTextUTF8(renderer, qanda->answerA, {0, 0, 0, 255}, 100 - 10, 205, 280, 90);
    renderTextUTF8(renderer, qanda->answerB, {0, 0, 0, 255}, 433 - 10, 205, 280, 90);
    renderTextUTF8(renderer, qanda->answerC, {0, 0, 0, 255}, 766 - 10, 205, 280, 90);
    renderTextUTF8(renderer, qanda->answerD, {0, 0, 0, 255}, 1100 - 10, 205, 280, 90);

    SDL_Rect Rect;
    Rect = {0, 100, 90, 90};
    SDL_RenderCopy(renderer, teacher, nullptr, &Rect);
    Rect = {5, 210, 75, 75};
    SDL_RenderCopy(renderer, student, nullptr, &Rect);

    if (qanda->choose == ""){
        if (timeRemaining > 0){
            font = TTF_OpenFont("asset/ttf/font_game.ttf", 30);
            renderText(renderer, "Choose a correct answer!", {255, 255, 0, 255}, 1010, 12);
            font = TTF_OpenFont("asset/ttf/dlxfont_.ttf", 25);
            if (timeRemaining >= 10)
                renderText(renderer, "Time Remaining:" + std::to_string(timeRemaining), {255, 0, 0, 255}, 960, 52);
            else
                renderText(renderer, "Time Remaining:0" + std::to_string(timeRemaining), {255, 0, 0, 255}, 960, 52);
        }
    }

    if (qanda->answer == qanda->choose){
        font = TTF_OpenFont("asset/ttf/font_game.ttf", 50);
        renderText(renderer, "CORRECT ANSWER!", {35, 133, 37, 255}, 970, 5);
        font = TTF_OpenFont("asset/ttf/font_game.ttf", 30);
        renderText(renderer, "You are safe here", {0, 0, 0, 255}, 1050, 55);
    }

    else if (timeRemaining <= 0){
        font = TTF_OpenFont("asset/ttf/font_game.ttf", 50);
        renderText(renderer, "TIME OUT!", {255, 0, 0, 255}, 1065, 5);
        font = TTF_OpenFont("asset/ttf/font_game.ttf", 30);
        renderText(renderer, "Correct answer is: " + qanda->answer, {0, 0, 255, 255}, 1050, 55);
    }
    else if(qanda->choose != ""){
        font = TTF_OpenFont("asset/ttf/font_game.ttf", 50);
        renderText(renderer, "INCORRECT!", {255, 0, 0, 255}, 1050, 5);
        font = TTF_OpenFont("asset/ttf/font_game.ttf", 30);
        renderText(renderer, "Correct answer is: " + qanda->answer, {0, 0, 255, 255}, 1050, 55);
    }

    TTF_CloseFont(font);
}

void Texture::renderGameOver(SDL_Renderer* renderer) {
    SDL_Rect Rect;
    scale += 3;
    if (scale > 200) scale = 200;
    Rect.w = 5 * scale;
    Rect.h = 1 * scale;
    Rect.x = (1472 - Rect.w) / 2;
    Rect.y = (64*12 - Rect.h) / 2;
    SDL_RenderCopy(renderer, gameOver, nullptr, &Rect);
}

void Texture::renderWin(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_Rect Rect;
    scale += 3;
    if (scale > 200) scale = 200;
    Rect.w = 5 * scale;
    Rect.h = 1 * scale;
    Rect.x = (1472 - Rect.w) / 2;
    Rect.y = (64*12 - Rect.h) / 2;
    SDL_RenderCopy(renderer, win, nullptr, &Rect);
}

void Texture::renderBombEffect(SDL_Renderer* renderer, Position posChick) {
    SDL_Rect Rect;
    scaleBomb += 1;
    if (scaleBomb > 20) scaleBomb = 20;
    Rect.w = 3 * scaleBomb;
    Rect.h = 3 * scaleBomb;
    Rect.x = posChick.x + (64 - Rect.w) / 2;
    Rect.y = posChick.y + (64 - Rect.h) / 2;
    if (scaleBomb !=20)
        SDL_RenderCopy(renderer, bombEffect, nullptr, &Rect);
}

void Texture::renderRecordList(SDL_Renderer* renderer, int recordEasy[],
                               int recordNormal[], int recordHard[]) {
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_Rect Rect;

    Rect = {470, 10, 497, 97};
    SDL_RenderCopy(renderer, titleRecord, nullptr, &Rect);
    Rect = {70, 200, 408, 540};
    SDL_RenderCopy(renderer, easyBoard, nullptr, &Rect);
    Rect = {500, 200, 408, 540};
    SDL_RenderCopy(renderer, normalBoard, nullptr, &Rect);
    Rect = {930, 200, 408, 540};
    SDL_RenderCopy(renderer, hardBoard, nullptr, &Rect);

    font = TTF_OpenFont("asset/ttf/dlxfont_.ttf", 35);

    renderText(renderer, "TOP1:" + std::to_string(recordEasy[0]), {255, 0, 0, 255}, 130, 370);
    renderText(renderer, "TOP2:" + std::to_string(recordEasy[1]), {255, 0, 0, 255}, 130, 470);
    renderText(renderer, "TOP3:" + std::to_string(recordEasy[2]), {255, 0, 0, 255}, 130, 570);

    renderText(renderer, "TOP1:" + std::to_string(recordNormal[0]), {37, 97, 46, 255}, 570, 370);
    renderText(renderer, "TOP2:" + std::to_string(recordNormal[1]), {37, 97, 46, 255}, 570, 470);
    renderText(renderer, "TOP3:" + std::to_string(recordNormal[2]), {37, 97, 46, 255}, 570, 570);

    renderText(renderer, "TOP1:" + std::to_string(recordHard[0]), {245, 240, 36, 255}, 990, 370);
    renderText(renderer, "TOP2:" + std::to_string(recordHard[1]), {245, 240, 36, 255}, 990, 470);
    renderText(renderer, "TOP3:" + std::to_string(recordHard[2]), {245, 240, 36, 255}, 990, 570);
    TTF_CloseFont(font);
}
