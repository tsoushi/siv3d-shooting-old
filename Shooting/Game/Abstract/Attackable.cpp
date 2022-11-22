#include "Attackable.h"

bool Attackable::IsInCollision(RectF body) {
	return body.intersects(GetAttackBody());
}

void Attackable::ExecuteAttack(Damageable& target) {
	Attack(target);
}
