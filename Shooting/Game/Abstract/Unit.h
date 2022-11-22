#pragma once
#include "Entity.h"
#include "Damageable.h"

class Unit : public Entity, public Damageable
{
public:
	Unit(int32 hp);
};
