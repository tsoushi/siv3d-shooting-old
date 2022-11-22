#pragma once
#include "Entity.h"
#include "Attackable.h"

class Bullet : public Entity, public Attackable
{
public:
	Bullet();
};
