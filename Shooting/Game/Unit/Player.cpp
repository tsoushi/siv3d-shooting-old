﻿#include "PlayerUnits.h"
#include "../../Common.h"

Player::Player()
	: UnitTemplate(100, MyAsset::sprite_player, SpriteSheetConfig{ Point{ 16, 16 }, Point{ 4, 2} }, Vec2{ 100, 100 }, Vec2{ -8, -8 }, Vec2{ 16, 16 })
{
}

void Player::Move() {
	velocity = { 1, 1 };
	//if (pos.x > 200) removeFlag = true;
}

void Player::Draw() const {
	GetSprite((Scene::FrameCount() /4)%8).drawAt(pos);
	//TextureAsset(MyAsset::sprite_player).drawAt(pos);
}
