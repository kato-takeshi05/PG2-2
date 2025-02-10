#pragma once
#include <Novice.h>

class TitleScene {
private:
    bool start_;
    int  titleDrawHandle_ = Novice::LoadTexture("./Resources/images/title.png");
public:
    TitleScene();
    ~TitleScene();
    void Update(char* keys, char* preKeys);
    void Draw();
    bool IsStart();
};
