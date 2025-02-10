#pragma once
#include <Novice.h>

class Enemy {
private:
    int posX_;
    int posY_;
    int speedY_;
    int radius_;
    int isAlive_;
    int enemyDrawHandle_;
public:
    Enemy();
    ~Enemy();
    void Init(int x, int y);
    void Update();
    void Draw();
    void IsNotAlive();
    int IsAlive();
    int GetPosX();
    int GetPosY();
    int GetRadius();
};
