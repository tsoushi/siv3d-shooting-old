#include "EnemyBullets.h"

EnemyBullet::EnemyBullet()
	: BulletTemplate(Texture(), SpriteSheetConfig{}, Vec2{ 300, 100 }, Vec2{ -8, -8 }, Vec2{ 16, 16 })
{

}

void EnemyBullet::Move() {
	velocity = { -1, 1 };
}
void EnemyBullet::Draw() const {
	RectF{ pos, 50, 50 }.draw(Palette::Blue);
}

void EnemyBullet::Attack(Damageable& target) {
	target.Damaged(3);
}
