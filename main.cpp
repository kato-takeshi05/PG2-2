#include <Novice.h>
#include "TitleScene.h"
#include "PlayScene.h"

const char kWindowTitle[] = "GC1A_02_カトウ_ツヨシ_EarthDefense";

enum SceneType { TITLE, PLAY };

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	SceneType currentScene = TITLE;
	TitleScene titleScene;
	PlayScene playScene;
	int resetTimer = 0;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		if (currentScene == TITLE) {
			if (resetTimer > 0) {
				resetTimer--;  
			}

			titleScene.Update(keys, preKeys);

			if (resetTimer == 0 && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				currentScene = PLAY;
				playScene = PlayScene();  
				resetTimer = 30; 
			}
		} else if (currentScene == PLAY) {
			playScene.Update(keys, preKeys);

			if (playScene.IsGameOver() || playScene.IsGameClear()) {
				if (resetTimer > 0) {
					resetTimer--;  
				}
				if (resetTimer == 0 && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
					currentScene = TITLE;
					resetTimer = 30;  
				}
			}
		}
		
	
		///
		/// ↑更新処理ここまで
		///
		if (currentScene == TITLE) {
			titleScene.Draw();
		} else if (currentScene == PLAY) {
			playScene.Draw();
		}

		
		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
