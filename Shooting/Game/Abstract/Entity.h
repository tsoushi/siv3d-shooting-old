#pragma once
#include "../GameType.h"

class Entity
{
protected:
	bool removeFlag = false;
public:
	Entity(EntityRegion region);

	virtual void Update();
	virtual void Draw() const;

	/* 所属属性 */
	const EntityRegion region;
	bool IsRemoved();
};
