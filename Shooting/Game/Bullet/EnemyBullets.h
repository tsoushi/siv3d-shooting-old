#pragma once
#include "../Abstract/BulletTemplate.h"

class EnemyBullet : public BulletTemplate {
public:
	EnemyBullet();
	void Move() override;
	void Draw() const override;
	void Attack(Damageable &target) override;
};
