#pragma once
#include <Novice.h>

class Bullet {
private:
    int posX_;
    int posY_;
    int speedY_;
    int isShot_;

public:
    Bullet();
    ~Bullet();
    void Init(int x, int y);
    void Update();
    void Draw();
    int IsShot() ;
    void IsNotShot();
    int GetPosX() ;
    int GetPosY();
    int GetRadius() ;
};
