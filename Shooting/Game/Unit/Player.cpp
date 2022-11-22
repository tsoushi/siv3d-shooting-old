#include "PlayerUnits.h"

Player::Player()
	: UnitTemplate(100, Texture(), SpriteSheetConfig{}, Vec2{ 100, 100 }, Vec2{ -8, -8 }, Vec2{ 16, 16 })
{

}

void Player::Move() {
	velocity = { 1, 1 };
	//if (pos.x > 200) removeFlag = true;
}

void Player::Draw() const {
	RectF{pos, 50, 50}.draw(Palette::Red);
}
