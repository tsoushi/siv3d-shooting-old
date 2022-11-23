#pragma once

/**
* スプライトシートの設定
*/
struct SpriteSheetConfig {
	/** スプライト１枚のサイズ */
	Point size;
	/** スプライトの縦横それぞれの枚数 */
	Point length;
};

/**
* スプライトシートによるアニメーションをサポートするクラス
*/
class SpriteAnimation
{
private:
	/** スプライトシート */
	String spriteSheetName;

	/** スプライトシートの設定 */
	SpriteSheetConfig spriteSheetConfig;
public:
	/**
	* @param spriteSheetName スプライトシートとなるアセット名
	* @param config スプライトシートの設定
	*/
	SpriteAnimation(String spriteSheetName, SpriteSheetConfig config);

	/**
	* @param spriteSheetName スプライトシートとなるアセット名
	* @param size スプライト１枚のサイズ
	* @param length スプライトの縦横それぞれの枚数
	*/
	SpriteAnimation(String spriteSheetName, Point size, Point length);

	/** スプライトシートから指定したインデックスのスプライトを取得する
	* @param index インデックス。左上から右へ0から始まる連番。
	* @return テクスチャ
	*/
	TextureRegion GetSprite(int32 index) const;
};
