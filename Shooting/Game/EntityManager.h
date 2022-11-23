#pragma once
#include "Abstract/Bullet.h"
#include "Abstract/Unit.h"

/* デバッグ用構造体 */
struct EntityManagerDebug {
	/* プレイヤーユニットのUpdate処理にかかった時間(マイクロ秒)。Update関数が呼ばれる度に更新。*/
	uint64 updatePlayerUnitTime;
	uint64 updateEnemyUnitTime;
	uint64 updatePlayerBulletTime;
	uint64 updateEnemyBulletTime;

	/* プレイヤーユニットのDraw処理にかかった時間(マイクロ秒)。Draw関数が呼ばれる度に更新。*/
	uint64 drawPlayerUnitTime;
	uint64 drawEnemyUnitTime;
	uint64 drawPlayerBulletTime;
	uint64 drawEnemyBulletTime;
};

class EntityManager
{
private:
	/* プレイヤーユニットの配列 */
	Array<Unit *> playerUnits;
	/* 敵ユニットの配列 */
	Array<Unit *> enemyUnits;
	/* プレイヤー弾の配列 */
	Array<Bullet *> playerBullets;
	/* 敵弾の配列 */
	Array<Bullet *> enemyBullets;

public:
	void AddPlayerUnit(Unit *unit);
	void AddEnemyUnit(Unit *unit);
	void AddPlayerBullet(Bullet *bullet);
	void AddEnemyBullet(Bullet *bullet);

	/* 管理下のエンティティの更新処理を行う */
	void Update();

	/* 管理下のエンティティを描画する */
	void Draw();

	EntityManagerDebug debug;
};
