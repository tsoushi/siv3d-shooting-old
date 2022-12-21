#include "GameScene.h"
#include "Unit/PlayerUnits.h"
#include "Bullet/EnemyBullets.h"
#include "StageManager.h"

GameScene::GameScene(const InitData& init)
	: IScene{ init },
	stageManager{ 1, 1 }
{
	gameSize = Vec2{ Scene::Width(), Scene::Height() };
}

void GameScene::update() {
	stageManager.Update();
	entityManager.Update();
}

void GameScene::draw() const {
	stageManager.Draw();
	entityManager.Draw();

	DebugDraw();
}

void GameScene::DebugDraw() const {
	ClearPrint();
	int32 baseFPS = 60;


	double weights[8];
	weights[0] = 100 * entityManager.debug.updatePlayerUnitTime / (1000000.0 / baseFPS);
	weights[1] = 100 * entityManager.debug.updateEnemyUnitTime / (1000000.0 / baseFPS);
	weights[2] = 100 * entityManager.debug.updatePlayerBulletTime / (1000000.0 / baseFPS);
	weights[3] = 100 * entityManager.debug.updateEnemyBulletTime / (1000000.0 / baseFPS);
	weights[4] = 100 * entityManager.debug.drawPlayerUnitTime / (1000000.0 / baseFPS);
	weights[5] = 100 * entityManager.debug.drawEnemyUnitTime / (1000000.0 / baseFPS);
	weights[6] = 100 * entityManager.debug.drawPlayerBulletTime / (1000000.0 / baseFPS);
	weights[7] = 100 * entityManager.debug.drawEnemyBulletTime / (1000000.0 / baseFPS);

	double totalWeight = 100.0 * baseFPS / Profiler::FPS();
	Print << U"FPS: {: >3}"_fmt(Profiler::FPS()) << U" Weight: {: >7.1f}%"_fmt(totalWeight);
	Print << U"|| PU || EU || PB || EB";
	// 60FPSを基準とした負荷率を表示する
	Print << U"Update || "
		<< U"{: >8.1f}% | "_fmt(weights[0])
		<< U"{: >8.1f}% | "_fmt(weights[1])
		<< U"{: >8.1f}% | "_fmt(weights[2])
		<< U"{: >8.1f}% || "_fmt(weights[3])
		<< U"{: >8.1f}%"_fmt(weights[0] + weights[1] + weights[2] + weights[3]);
	Print << U"Draw   || "
		<< U"{: >8.1f}% | "_fmt(weights[4])
		<< U"{: >8.1f}% | "_fmt(weights[5])
		<< U"{: >8.1f}% | "_fmt(weights[6])
		<< U"{: >8.1f}% || "_fmt(weights[7])
		<< U"{: >8.1f}%"_fmt(weights[4] + weights[5] + weights[6] + weights[7]);
	double entityTotalWeight = weights[0] + weights[1] + weights[2] + weights[3] + weights[4] + weights[5] + weights[6] + weights[7];
	Print << U"Total: {: >8.1f}%"_fmt(entityTotalWeight)
		<< U" Rate(entity/all): {: >8.1f}%"_fmt(100 * entityTotalWeight / totalWeight);

}
