#include "CollisionTemplate.h"

CollisionTemplate::CollisionTemplate(Vec2 position, Vec2 collisionBasePoint, Vec2 collisionSize)
	: Motion{ position }, collisionBasePoint{ collisionBasePoint }, collisionSize{ collisionSize }
{

}

Polygon CollisionTemplate::GetCollisionBody() const {
	return RectF{ pos + collisionBasePoint, collisionSize }.asPolygon();
}
