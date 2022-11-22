#include "UnitTemplate.h"

UnitTemplate::UnitTemplate(int32 hp, Texture spriteSheet, SpriteSheetConfig spriteSheetConfig, Vec2 position, Vec2 collisionBasePoint, Vec2 collisionSize)
	: Unit{ hp },
	SpriteAnimation {spriteSheet, spriteSheetConfig },
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
