#include "UnitTemplate.h"

UnitTemplate::UnitTemplate(EntityRegion region, int32 hp, String spriteSheetName, SpriteSheetConfig spriteSheetConfig, Vec2 position, Vec2 collisionBasePoint, Vec2 collisionSize)
	: Unit{ region, hp },
	SpriteAnimation {spriteSheetName, spriteSheetConfig },
	CollisionTemplate{ position, collisionBasePoint, collisionSize }
{
}

void UnitTemplate::Update() {
	Move();
	EnsureMove();
}

RectF UnitTemplate::GetDamageableBody() {
	return GetCollisionBody();
}
