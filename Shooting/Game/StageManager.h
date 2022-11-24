#pragma once
#include "Stage/Stage.h"

/* ステージの進行を管理するクラス */
class StageManager
{
private:
	/* ステージのジェネレーター */
	Stage* stage;
public:
	/*
	* @param primaryStage 初期エリア数
	* @param secondaryStage 初期ステージ数
	*/
	StageManager(int32 primaryStage, int32 secondaryStage);

	/* Update処理 */
	void Update();
	/* Draw処理 */
	void Draw() const;

	int32 primaryStage;
	int32 secondaryStage;
};
