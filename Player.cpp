#include "Player.h"
#include <Novice.h>
/// <summary>
/// プレイヤーのコンストラクタ
/// </summary>
Player::Player() {
    posX_ = 640;
    posY_ = 600;
    speedX_ = 10;
    speedY_ = 5;
    radius_ = 32;
    playerDrawHandle_ = Novice::LoadTexture("./Resources/images/player.png");
    shotSound_ = Novice::LoadAudio("./Resources/sounds/shot.mp3");
}
/// <summary>
/// プレイヤーのデストラクタ
/// </summary>
Player::~Player() {
  
}
/// <summary>
/// プレイヤーの動き
/// </summary>
/// <param name="keys">キーの入力</param>
/// <param name="preKeys">キーを戻す</param>
void Player::Update(char* keys, char* preKeys) {
    if (keys[DIK_A]) {
        if (posX_ - radius_ > 0) { 
            posX_ -= speedX_;
        }
    }
    if (keys[DIK_D]) {
        if (posX_ + radius_ < 1280) {
            posX_ += speedX_;
        }
    }
    if (keys[DIK_W]) {
        if (posY_ - radius_ > 0) { 
            posY_ -= speedY_;
        }
    }
    if (keys[DIK_S]) {
        if (posY_ + radius_ < 720) { 
            posY_ += speedY_;
        }
    }

    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bullets_[i].IsShot()) {
                Novice::PlayAudio(shotSound_, 0, 1);
                bullets_[i].Init(posX_, posY_ - radius_);
                break;
            }
        }
    }

    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets_[i].Update();
    }
}

/// <summary>
/// プレイヤーの描画
/// </summary>
void Player::Draw() {
    Novice::DrawSprite(posX_ - radius_, posY_ - radius_, playerDrawHandle_, 1.0f, 1.0f, 0.0f, WHITE);
   // Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets_[i].Draw();
    }
}

/// <summary>
/// バレットのゲッター
/// </summary>
/// <returns>バレット</returns>
Bullet* Player::GetBullets() {
    return bullets_;
}

/// <summary>
/// プレイヤーのX座標のゲッター
/// </summary>
/// <returns>プレイヤーのX座標</returns>
int Player::GetPosX() {
    return posX_;
}

/// <summary>
/// プレイヤーのY座標のゲッター
/// </summary>
/// <returns>プレイヤーのY座標</returns>
int Player::GetPosY(){
    return posY_;
}

/// <summary>
/// プレイヤーの半径のゲッター
/// </summary>
/// <returns>プレイヤーの半径</returns>
int Player::GetRadius(){
    return radius_;
}
