#pragma once
#include "Abstract/Bullet.h"
#include "Abstract/Unit.h"

class EntityManager
{
private:
	Array<Unit *> playerUnits;
	Array<Unit *> enemyUnits;
	Array<Bullet *> playerBullets;
	Array<Bullet *> enemyBullets;
public:
	void AddPlayerUnit(Unit *unit);
	void AddEnemyUnit(Unit *unit);
	void AddPlayerBullet(Bullet *bullet);
	void AddEnemyBullet(Bullet *bullet);

	void Update();

	void Draw() const;
};
