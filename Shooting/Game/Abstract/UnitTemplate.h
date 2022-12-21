#pragma once
#include "Unit.h"
#include "SpriteAnimation.h"
#include "CollisionTemplate.h"

class UnitTemplate : public Unit, public SpriteAnimation, public CollisionTemplate
{
public:
	UnitTemplate(EntityRegion region, int32 hp, String spriteSheetName, SpriteSheetConfig spriteSheetConfig, Vec2 position, Vec2 collisionBasePoint, Vec2 collisionSize);
	void Update() override;
	virtual void Move() = 0;

	RectF GetDamageableBody() override;
};
