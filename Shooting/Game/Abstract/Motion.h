#pragma once

class Motion
{
protected:
	Vec2 pos;
	Vec2 velocity;
public:
	Motion(Vec2 position, Vec2 velocity = { 0, 0 });
	void EnsureMove();
	
};
