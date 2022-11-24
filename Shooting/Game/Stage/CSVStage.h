#pragma once
#include "Stage.h"

/* CSVファイルからステージを生成するためのクラス */
class CSVStage : public Stage
{
private:
	/* CSVデータ */
	CSV stageData;
	/* エンティティ生成のインターバルを取るためのストップウォッチ */
	Stopwatch generatingWatch;
	/* エンティティ生成間隔 */
	Milliseconds generatingInterval;
	/* 現在の読み込み行 */
	int32 currentRow = 0;
public:
	/*
	* @param primaryStage 読み込むエリア番号
	* @param secondaryStage 読み込むステージ番号
	*/
	CSVStage(int32 primaryStage, int32 secondaryStage);

	/* 更新処理。毎フレーム呼ぶ。 */
	void Update() override;
	/* 描画処理。毎フレーム呼ぶ。 */
	void Draw() const override;
};
