#include "StageManager.h"
#include "Stage/CSVStage.h"

StageManager::StageManager(int32 primaryStage, int32 secondaryStage)
	: primaryStage(primaryStage), secondaryStage(secondaryStage)
{
	stage = new CSVStage(primaryStage, secondaryStage);
}

void StageManager::Update() {
	stage->Update();
}

void StageManager::Draw() const{

}

