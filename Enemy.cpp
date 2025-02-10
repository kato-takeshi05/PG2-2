#include "Enemy.h"
/// <summary>
/// コンストラクタ
/// </summary>
Enemy::Enemy() {
    isAlive_ = false;
    speedY_ = 2;
    radius_ = 32;
}
/// <summary>
/// デストラクタ
/// </summary>
Enemy::~Enemy() {

}
/// <summary>
/// エネミーの初期化
/// </summary>
/// <param name="x">x座標</param>
/// <param name="y">ｙ座標</param>
void Enemy::Init(int x, int y) {
    posX_ = x;
    posY_ = y;
    isAlive_ = true;
    enemyDrawHandle_ = Novice::LoadTexture("./Resources/images/enemy.png");
}

/// <summary>
/// 敵の更新処理
/// </summary>
void Enemy::Update() {
    if (isAlive_) {
        posY_ += speedY_;
        if (posY_ > 720) {
            isAlive_ = false;
        }
    }
}

/// <summary>
/// 敵の描画処理
/// </summary>
void Enemy::Draw() {
    if (isAlive_) {
        Novice::DrawSprite(posX_ - radius_, posY_ - radius_, enemyDrawHandle_, 1.0f, 1.0f, 0.0f, WHITE);
        //Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
    }
}
/// <summary>
/// 敵の削除
/// </summary>
void Enemy::IsNotAlive() {
    isAlive_ = false;
}

/// <summary>
/// 敵の生成
/// </summary>
/// <returns>敵の生存変数をオン</returns>
int Enemy::IsAlive() {
    return isAlive_;
}


/// <summary>
/// 敵のX座標のゲッター
/// </summary>
/// <returns>敵のX座標</returns>
int Enemy::GetPosX(){
    return posX_;
}

/// <summary>
/// 敵のY座標のゲッター
/// </summary>
/// <returns>敵のY座標</returns>
int Enemy::GetPosY(){
    return posY_;
}

/// <summary>
/// 敵の半径のゲッター
/// </summary>
/// <returns>敵の半径</returns>
int Enemy::GetRadius(){
    return radius_;
}
