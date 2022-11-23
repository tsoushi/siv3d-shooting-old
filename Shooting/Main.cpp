# include <Siv3D.hpp> // OpenSiv3D v0.6.5
#include "Common.h"
#include "Init.h"
#include "Game/GameScene.h"

void Main()
{
	App manager;

	manager.add<GameScene>(U"Game");

	manager.init(U"Game");

	SetAssets();

	while (System::Update())
	{
		if (not manager.update()) {
			break;
		}
	}
}
