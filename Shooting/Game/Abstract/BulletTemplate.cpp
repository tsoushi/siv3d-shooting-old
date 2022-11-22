#include "BulletTemplate.h"

BulletTemplate::BulletTemplate(Texture spriteSheet, SpriteSheetConfig spriteSheetConfig, Vec2 position, Vec2 collisionBasePoint, Vec2 collisionSize)
	: SpriteAnimation{ spriteSheet, spriteSheetConfig },
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
