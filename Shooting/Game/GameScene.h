#pragma once
#include "common.h"
#include "Game.h"

class GameScene : public App::Scene
{
public:
	GameScene(const InitData& init);
	void update() override;
	void draw() const override;

	void DebugDraw() const;
};

