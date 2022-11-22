#pragma once
#include "../Abstract/UnitTemplate.h"

class Player : public UnitTemplate {
public:
	Player();
	void Move() override;
	void Draw() const override;
};
