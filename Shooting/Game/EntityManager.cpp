#include "EntityManager.h"

bool DEBUG = true;

void EntityManager::AddPlayerUnit(Unit *unit) {
	playerUnits << unit;
}

void EntityManager::AddEnemyUnit(Unit* unit) {
	enemyUnits << unit;
}

void EntityManager::AddPlayerBullet(Bullet* bullet) {
	playerBullets << bullet;
}

void EntityManager::AddEnemyBullet(Bullet* bullet) {
	enemyBullets << bullet;
}



void EntityManager::Update() {
	auto t = Time::GetMicrosec();
	// プレイヤーユニット
	for (auto unit = playerUnits.begin(); unit != playerUnits.end();) {
		(*unit)->Update();
		if ((*unit)->IsRemoved()) {
			delete *unit;
			unit = playerUnits.erase(unit);
			continue;
		}
		unit++;
	}
	if (DEBUG) { Print << U"player unit: " << Time::GetMicrosec() - t; t = Time::GetMicrosec(); }

	// 敵ユニット
	for (auto unit = enemyUnits.begin(); unit != enemyUnits.end();) {
		(*unit)->Update();
		if ((*unit)->IsRemoved()) {
			delete* unit;
			unit = enemyUnits.erase(unit);
			continue;
		}
		unit++;
	}

	if (DEBUG) { Print << U"enemy unit: " << Time::GetMicrosec() - t; t = Time::GetMicrosec(); }
	// プレイヤー弾
	for (auto bullet = playerBullets.begin(); bullet != playerBullets.end();) {
		(*bullet)->Update();
		if ((*bullet)->IsRemoved()) {
			delete* bullet;
			bullet = playerBullets.erase(bullet);
			continue;
		}
		// 敵ユニットとの当たり判定
		for (auto enemyUnit = enemyUnits.begin(); enemyUnit != enemyUnits.end(); enemyUnit++) {
			if ((*bullet)->IsInCollision((*enemyUnit)->GetDamageableBody())) {
				(*bullet)->ExecuteAttack(**enemyUnit);
			}
		}
		bullet++;
	}
	if (DEBUG) { Print << U"player bullet: " << Time::GetMicrosec() - t; t = Time::GetMicrosec(); }
	// 敵弾
	for (auto bullet = enemyBullets.begin(); bullet != enemyBullets.end();) {
		(*bullet)->Update();
		if ((*bullet)->IsRemoved()) {
			delete* bullet;
			bullet = enemyBullets.erase(bullet);
			continue;
		}
		// プレイヤーユニットとの当たり判定
		for (auto playerUnit = playerUnits.begin(); playerUnit != playerUnits.end(); playerUnit++) {
			if ((*bullet)->IsInCollision((*playerUnit)->GetDamageableBody())) {
				(*bullet)->ExecuteAttack(**playerUnit);
			}
		}
		bullet++;
	}
	if (DEBUG) { Print << U"enemy bullet: " << Time::GetMicrosec() - t; }
}


void EntityManager::Draw() const {
	auto t = Time::GetMicrosec();
	// プレイヤーユニット
	for (auto unit = playerUnits.begin(); unit != playerUnits.end(); unit++) {
		(*unit)->Draw();
	}
	if (DEBUG) { Print << U"DRAW player unit: " << Time::GetMicrosec() - t; t = Time::GetMicrosec(); }
	// 敵ユニット
	for (auto unit = enemyUnits.begin(); unit != enemyUnits.end(); unit++) {
		(*unit)->Draw();
	}
	if (DEBUG) { Print << U"DRAW enemy unit: " << Time::GetMicrosec() - t; t = Time::GetMicrosec(); }

	// プレイヤー弾
	for (auto bullet = playerBullets.begin(); bullet != playerBullets.end(); bullet++) {
		(*bullet)->Draw();
	}
	if (DEBUG) { Print << U"DRAW player bulelt: " << Time::GetMicrosec() - t; t = Time::GetMicrosec(); }
	// 敵弾
	for (auto bullet = enemyBullets.begin(); bullet != enemyBullets.end(); bullet++) {
		(*bullet)->Draw();
	}
	if (DEBUG) { Print << U"DRAW enemy bullet: " << Time::GetMicrosec() - t; }

}
