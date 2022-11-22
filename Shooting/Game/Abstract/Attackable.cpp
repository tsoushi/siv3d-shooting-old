#include "Attackable.h"

bool Attackable::IsInCollision(Polygon body) {
	return body.intersects(GetAttackBody());
}

void Attackable::ExecuteAttack(Damageable& target) {
	Attack(target);
}
