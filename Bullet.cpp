#include "Bullet.h"

/// <summary>
/// コンストラクタ
/// </summary>
Bullet::Bullet() {
    isShot_ = false;
    speedY_ = -7;
}
/// <summary>
/// 弾の初期化
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
void Bullet::Init(int x, int y) {
    posX_ = x;
    posY_ = y;
    isShot_ = true;
}
/// <summary>
/// 弾の更新
/// </summary>
void Bullet::Update() {
    if (isShot_) {
        posY_ += speedY_;
        if (posY_ < 0) {
            isShot_ = false;
        }
    }
}
/// <summary>
/// デストラクタ
/// </summary>
Bullet::~Bullet() {

}
/// <summary>
/// 弾の描画
/// </summary>
void Bullet::Draw() {
    if (isShot_) {
        Novice::DrawEllipse(posX_, posY_, 4, 4, 0.0f, RED, kFillModeSolid);
    }
}
/// <summary>
/// 弾の発射のゲッター
/// </summary>
/// <returns>発射のフラグをオン</returns>
int Bullet::IsShot(){
    return isShot_;
}
/// <summary>
/// 弾の未発射状態のゲッター
/// </summary>
void Bullet::IsNotShot() {
    isShot_ = false;
}
/// <summary>
/// 弾のX座標のゲッター
/// </summary>
/// <returns>弾のX座標</returns>
int Bullet::GetPosX(){
    return posX_;
}
/// <summary>
/// 弾のY座標のゲッター
/// </summary>
/// <returns>弾のY座標</returns>
int Bullet::GetPosY(){
    return posY_;
}
/// <summary>
/// 弾の半径のゲッター
/// </summary>
/// <returns>弾の半径</returns>
int Bullet::GetRadius(){
    return 4;
}
