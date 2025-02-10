#pragma once
#include "Bullet.h"

#define MAX_BULLETS 10

class Player {
private:
    int posX_;
    int posY_;
    int speedX_;
    int speedY_;
    int radius_;
    Bullet bullets_[MAX_BULLETS];
    int playerDrawHandle_;
    int shotSound_;
public:
    Player();
    ~Player();
    void Update(char* keys, char* preKeys);
    void Draw();
    Bullet* GetBullets();
    int GetPosX();
    int GetPosY();
    int GetRadius();
};
