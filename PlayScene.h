#pragma once
#include "Player.h"
#include "Enemy.h"

#define MAX_ENEMIES 20

class PlayScene {
private:
    Player *player_;
    Enemy *enemies_[MAX_ENEMIES];
    int defeatedEnemies_;
    int currentEnemyCount_;
    int enemySpawnTimer_;
    bool gameOver_;
    bool gameClear_;
    int overDrawHandle_;
    int clearDrawHandle_;
    int bombSound_;
public:
    PlayScene();
    ~PlayScene();
    void Update(char* keys, char* preKeys);
    void Draw();
    bool IsGameOver();
    bool IsGameClear();
};
