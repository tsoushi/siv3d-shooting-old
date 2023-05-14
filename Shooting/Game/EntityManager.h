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

/* エンティティを管理するクラス */
class EntityManager
{
private:
	/* プレイヤーユニットの配列 */
	Array<Unit*> playerUnits;
	Array<Unit*> playerUnitsTmp;
	/* 敵ユニットの配列 */
	Array<Unit*> enemyUnits;
	Array<Unit*> enemyUnitsTmp;
	/* プレイヤー弾の配列 */
	Array<Bullet*> playerBullets;
	Array<Bullet*> playerBulletsTmp;
	/* 敵弾の配列 */
	Array<Bullet*> enemyBullets;
	Array<Bullet*> enemyBulletsTmp;

	/* 追加予定のエンティティ配列 */
	Array<Entity*> additionalEntities;

	void AddEntity(Entity* entity);
	void AddPlayerUnit(Unit* unit);
	void AddEnemyUnit(Unit* unit);
	void AddPlayerBullet(Bullet* bullet);
	void AddEnemyBullet(Bullet* bullet);

	void EnsureAdditionalEntities();
public:
	void AddNewEntity(Entity* entity);

	/* 管理下のエンティティの更新処理を行う */
	void Update();

	/* 管理下のエンティティを描画する */
	void Draw();

	EntityManagerDebug debug;
};
