#pragma once
#include "common.h"
#include "Game.h"
#include "StageManager.h"

class GameScene : public App::Scene
{
private:
	StageManager stageManager;
public:
	GameScene(const InitData& init);
	void update() override;
	void draw() const override;

	void DebugDraw() const;
};

