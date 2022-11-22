#include "Motion.h"

Motion::Motion(Vec2 position, Vec2 velocity)
	: pos{ position }, velocity{ velocity }
{
}

void Motion::EnsureMove() {
	pos += velocity;
}
