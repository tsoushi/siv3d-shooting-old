#pragma once
#include "Bullet.h"
#include "SpriteAnimation.h"
#include "CollisionTemplate.h"

class BulletTemplate : public Bullet, public SpriteAnimation, public CollisionTemplate
{
public:
	BulletTemplate(String spriteSheetName, SpriteSheetConfig spriteSheetConfig, Vec2 position, Vec2 collisionBasePoint, Vec2 collisionSize);
	void Update() override;
	virtual void Move() = 0;

	RectF GetAttackBody() override;
};
