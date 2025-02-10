#include "TitleScene.h"
/// <summary>
/// コンストラクタ
/// </summary>
TitleScene::TitleScene() {
    start_ = false; 
}

/// <summary>
/// デストラクタ
/// </summary>
TitleScene::~TitleScene() {

}
/// <summary>
/// タイトルの更新
/// </summary>
/// <param name="keys">キーの入力</param>
/// <param name="preKeys">キーを離す</param>
void TitleScene::Update(char* keys, char* preKeys) {
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        start_ = true;
    }
}
/// <summary>
/// タイトルの描画
/// </summary>
void TitleScene::Draw() {
    Novice::DrawSprite(0,0,titleDrawHandle_, 1.0f, 1.0f, 0.0f, WHITE);
}
/// <summary>
/// タイトルのゲッター
/// </summary>
/// <returns>タイトルの開始</returns>
bool TitleScene::IsStart()  {
    return start_;
}
