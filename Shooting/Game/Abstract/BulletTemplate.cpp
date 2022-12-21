#include "BulletTemplate.h"

BulletTemplate::BulletTemplate(EntityRegion region, String spriteSheetName, SpriteSheetConfig spriteSheetConfig, Vec2 position, Vec2 collisionBasePoint, Vec2 collisionSize)
	: Bullet{ region },
	SpriteAnimation{ spriteSheetName, spriteSheetConfig },
	CollisionTemplate{ position, collisionBasePoint, collisionSize }
{
}

void BulletTemplate::Update() {
	Move();
	EnsureMove();
}

RectF BulletTemplate::GetAttackBody() {
	return GetCollisionBody();
}
