#pragma once

/** ダメージを受けるオブジェクト */
class Damageable {
protected:
	/** HP */
	int32 hp;
public:
	/** @param hp 初期HP */
	Damageable(int32 hp);

	/* 現在のHPを取得する */
	int32 GetHp();

	/**
	* 外部からダメージを与える際に呼び出す
	* @param quantity 与えたダメージ量
	*/
	virtual int32 Damaged(int32 quantity);

	/**
	* 被ダメージ当たり判定を行うときに使うポリゴンを返す
	* @return ダメージを受ける範囲を表す四角形
	*/
	virtual RectF GetDamageableBody() = 0;
};
