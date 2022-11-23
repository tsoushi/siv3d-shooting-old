#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation(String spriteSheetName, SpriteSheetConfig config)
	: spriteSheetName{ spriteSheetName }, spriteSheetConfig{ config }
{
}
SpriteAnimation::SpriteAnimation(String spriteSheetName, Point size, Point length)
	: SpriteAnimation{ spriteSheetName, SpriteSheetConfig{ size, length } }
{
}

TextureRegion SpriteAnimation::GetSprite(int32 index) const {
	return TextureAsset(spriteSheetName)(
		(index % spriteSheetConfig.length.x) * spriteSheetConfig.size.x,
		(index / spriteSheetConfig.length.x) * spriteSheetConfig.size.y,
		spriteSheetConfig.size
	);
}
