#pragma once
#include "Motion.h"

class CollisionTemplate : public Motion
{
protected:
	Vec2 collisionBasePoint;
	Vec2 collisionSize;
public:
	CollisionTemplate(Vec2 position, Vec2 collisionBasePoint, Vec2 collisionSize);
	RectF GetCollisionBody() const;
};
