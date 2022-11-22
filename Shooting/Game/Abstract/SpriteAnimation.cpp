#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation(Texture spriteSheet, SpriteSheetConfig config)
	: spriteSheet{ spriteSheet }, spriteSheetConfig{ config }
{
}
SpriteAnimation::SpriteAnimation(Texture spriteSheet, Point size, Point length)
	: SpriteAnimation{ spriteSheet, SpriteSheetConfig{ size, length } }
{
}

TextureRegion SpriteAnimation::GetSprite(int32 index) const {
	return spriteSheet(
		(index % spriteSheetConfig.length.x) * spriteSheetConfig.size.x,
		(index / spriteSheetConfig.length.x) * spriteSheetConfig.size.y,
		spriteSheetConfig.size
	);
}
