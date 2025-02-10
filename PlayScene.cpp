#include "PlayScene.h"

/// <summary>
/// デストラクタ
/// </summary>
PlayScene::~PlayScene() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies_[i] != nullptr) {
            delete enemies_[i];
            enemies_[i] = nullptr;
        }
    }
}
/// <summary>
/// コンストラクタ
/// </summary>
PlayScene::PlayScene() {
    player_ = nullptr;
    player_ = new Player();
    currentEnemyCount_ = 0;
    defeatedEnemies_ = 0;
    enemySpawnTimer_ = 60;
    gameOver_ = false;
    gameClear_ = false;
    overDrawHandle_ = Novice::LoadTexture("./Resources/images/GameOver.png");
    clearDrawHandle_ = Novice::LoadTexture("./Resources/images/GameClear.png");
    bombSound_ = Novice::LoadAudio("./Resources/sounds/bomb.mp3");
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies_[i] = nullptr;  
    }
}

/// <summary>
/// ゲームシーンの更新
/// </summary>
/// <param name="keys">キー入力</param>
/// <param name="preKeys">キーを離す</param>
void PlayScene::Update(char* keys, char* preKeys) {
    if (!gameOver_ && !gameClear_) {
        player_->Update(keys, preKeys);

       
        enemySpawnTimer_--;
        if (enemySpawnTimer_ <= 0 && currentEnemyCount_ < MAX_ENEMIES) {
            enemies_[currentEnemyCount_] = new Enemy();  
            enemies_[currentEnemyCount_]->Init((rand() %1216)+32, -64);
            currentEnemyCount_++;
            enemySpawnTimer_ = 60;
        }

        for (int i = 0; i < currentEnemyCount_; i++) {
            if (enemies_[i] != nullptr) {
                enemies_[i]->Update();


                float distX = float(player_->GetPosX() - enemies_[i]->GetPosX());
                float distY = float(player_->GetPosY() - enemies_[i]->GetPosY());
                float dist = (distX * distX) + (distY * distY);
                int radiusSum = player_->GetRadius() + enemies_[i]->GetRadius();

                if (enemies_[i]->GetPosY() > 720 || dist <= radiusSum * radiusSum) {
                    gameOver_ = true;
                }

               
                Bullet* bullets = player_->GetBullets();
                for (int j = 0; j < MAX_BULLETS; j++) {
                    if (bullets[j].IsShot()) {
                        float bulletDistX = float(bullets[j].GetPosX() - enemies_[i]->GetPosX());
                        float bulletDistY = float(bullets[j].GetPosY() - enemies_[i]->GetPosY());
                        float bulletDist = (bulletDistX * bulletDistX) + (bulletDistY * bulletDistY);
                        int bulletRadiusSum = bullets[j].GetRadius() + enemies_[i]->GetRadius();

                        if (bulletDist <= bulletRadiusSum * bulletRadiusSum) {
                            Novice::PlayAudio(bombSound_, 0, 1);
                            delete enemies_[i];
                            enemies_[i] = nullptr;  
                            bullets[j].IsNotShot();
                            defeatedEnemies_++;

                            if (defeatedEnemies_ >= MAX_ENEMIES) {
                                gameClear_ = true;
                            }
                            break;  
                        }
                    }
                }
            }
        }
    }
}
/// <summary>
/// ゲームシーンの描画
/// </summary>
void PlayScene::Draw() {
    Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
        player_->Draw();
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies_[i] != nullptr) {
            enemies_[i]->Draw();
        }
    }

    if (gameOver_) {
        Novice::DrawSprite(0, 0, overDrawHandle_, 1.0f, 1.0f, 0.0f, WHITE);
    }
    if (gameClear_) {
        Novice::DrawSprite(0, 0, clearDrawHandle_, 1.0f, 1.0f, 0.0f, WHITE);
    }
}

/// <summary>
/// ゲームオーバーのゲッター
/// </summary>
/// <returns>ゲームオーバー画面に</returns>
bool PlayScene::IsGameOver()  {
    return gameOver_;
}

/// <summary>
/// ゲームクリアのゲッター
/// </summary>
/// <returns>クリア画面に</returns>
bool PlayScene::IsGameClear() {
    return gameClear_;
}
