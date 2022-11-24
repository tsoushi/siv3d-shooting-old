#include "CSVStage.h"

CSVStage::CSVStage(int32 primaryStage, int32 secondaryStage)
	: stageData{ U"stage/csv/{}_{}.csv"_fmt(primaryStage, secondaryStage) }
{
	generatingInterval = Milliseconds(Parse<int32>(stageData[0][0]));
	generatingWatch.start();
}

void CSVStage::Update() {
	if (generatingWatch > generatingInterval) {
		int32 rowNum = currentRow + 1;
		for (int x = 0; x < stageData.columns(rowNum); x++) {
			try {
				int32 xPos;
				if (stageData.columns(rowNum) >= 2) xPos = ((double)x / (stageData.columns(rowNum) - 1)) * gameSize.x;
				else xPos = gameSize.x / 2;
				entityManager.AddEntity(
					IntToEntity(
						Parse<int32>(stageData[rowNum][x]),
						Vec2{ xPos, 50 }
					)
				);
			}
			catch (ParseError& e) {

			}
		}
		currentRow++;
		generatingWatch.restart();
	}
}

void CSVStage::Draw() const {

}
