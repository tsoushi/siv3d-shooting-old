#pragma once
#include "../Abstract/BulletTemplate.h"
#include "../Game.h"

class EnemyBullet : public BulletTemplate {
public:
	EnemyBullet(Vec2 position);
	void Move() override;
	void Draw() const override;
	void Attack(Damageable &target) override;
};
