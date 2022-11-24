#include "Stage.h"

Entity* StringToEntity(String identifier, Vec2 position) {
	if (identifier == U"player") return new Player(position);
	return nullptr;
}

Entity* IntToEntity(int32 identifier, Vec2 position) {
	switch (identifier) {
		case 1:
			return new Player(position);
		default:
			return nullptr;
	}
}
