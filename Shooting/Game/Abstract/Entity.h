#pragma once

class Entity
{
protected:
	bool removeFlag = false;
public:
	virtual void Update();
	virtual void Draw() const;

	bool IsRemoved();
};
