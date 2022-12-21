#include "Entity.h"

Entity::Entity(EntityRegion region)
	: region(region)
{

}

void Entity::Update() {

}

void Entity::Draw() const {

}

bool Entity::IsRemoved() {
	return removeFlag;
}
