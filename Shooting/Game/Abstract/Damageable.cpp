#include "Damageable.h"

Damageable::Damageable(int32 hp)
	: hp(hp)
{
}

int32 Damageable::GetHp() {
	return hp;
}

int32 Damageable::Damaged(int32 quantity) {
	hp -= quantity;
	return quantity;
}
