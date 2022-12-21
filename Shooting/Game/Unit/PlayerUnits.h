#pragma once
#include "../Abstract/UnitTemplate.h"

class Player : public UnitTemplate {
public:
	Player(Vec2 Position);
	void Move() override;
	void Draw() const override;
};
