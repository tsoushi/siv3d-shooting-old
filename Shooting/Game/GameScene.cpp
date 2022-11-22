#include "GameScene.h"
#include "Unit/PlayerUnits.h"
#include "Bullet/EnemyBullets.h"

EntityManager entityManager;

GameScene::GameScene(const InitData& init)
	: IScene{ init }
{
	for (int i = 0; i < 40; i++) entityManager.AddPlayerUnit(new Player());
	for (int i = 0; i < 40; i++) entityManager.AddEnemyBullet(new EnemyBullet());
}

void GameScene::update() {
	entityManager.Update();
}

void GameScene::draw() const {
	entityManager.Draw();
	DebugDraw();
}

void GameScene::DebugDraw() const {
	//Print << U"GameScene";
}
