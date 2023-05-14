#include "PlayerUnits.h"
#include "../../Common.h"
#include "../../Game/Game.h"

Player::Player(Vec2 position)
	: UnitTemplate(EntityRegion::player, 100, MyAsset::sprite_player, SpriteSheetConfig{ Point{ 16, 16 }, Point{ 4, 2} }, position, Vec2{ -8, -8 }, Vec2{ 16, 16 })
{
}

void Player::Move() {
	velocity = { 0, 0 };
	if (KeyW.pressed()) velocity.y = -2;
	if (KeyS.pressed()) velocity.y = 2;
	if (KeyA.pressed()) velocity.x = -2;
	if (KeyD.pressed()) velocity.x = 2;

	if (KeySpace.down()) entityManager.AddNewEntity(new Player(pos));

	//if (pos.x > 200) removeFlag = true;
}

void Player::Draw() const {
	GetSprite((Scene::FrameCount() /4)%8).drawAt(pos);
	//TextureAsset(MyAsset::sprite_player).drawAt(pos);
}
