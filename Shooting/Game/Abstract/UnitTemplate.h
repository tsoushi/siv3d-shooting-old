#pragma once
#include "Unit.h"
#include "SpriteAnimation.h"
#include "CollisionTemplate.h"

class UnitTemplate : public Unit, public SpriteAnimation, public CollisionTemplate
{
public:
	UnitTemplate(int32 hp, Texture spriteSheet, SpriteSheetConfig spriteSheetConfig, Vec2 position, Vec2 collisionBasePoint, Vec2 collisionSize);
	void Update() override;
	virtual void Move() = 0;

	Polygon GetDamageableBody() override;
};
