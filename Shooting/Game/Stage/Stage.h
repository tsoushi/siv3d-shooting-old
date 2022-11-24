#pragma once
#include "../Game.h"
#include "../Unit/PlayerUnits.h"
#include "../Bullet/EnemyBullets.h"

/* ステージのジェネレーター */
class Stage
{
public:
	virtual void Update() = 0;
	virtual void Draw() const = 0;
};

/*
* 文字列の識別子からエンティティを生成する。
* @param identifier 識別子
* @param position 配置位置
*/
Entity* StringToEntity(String identifier, Vec2 position);

/*
* 数値の識別子からエンティティを生成する
* @param identifier 識別子
* @param position 配置位置
*/
Entity* IntToEntity(int32 identifier, Vec2 position);
