#pragma once
#include "Damageable.h"

/** 他のオブジェクトにダメージを与えるオブジェクト */
class Attackable
{
public:
	/**
	* 攻撃処理を行う。
	* @param &target 対象オブジェクト
	*/
	virtual void Attack(Damageable &target) = 0;

	/**
	* 与ダメージ当たり判定を行うときに使うポリゴンを返す
	* @return 攻撃範囲を表すポリゴン
	*/
	virtual Polygon GetAttackBody() = 0;

	/**
	* ポリゴンが攻撃範囲内かどうかを調べる
	* @return 攻撃範囲内なら true
	*/
	bool IsInCollision(Polygon body);

	/**
	* オブジェクトに攻撃処理を行う。エンティティマネージャーから呼ばれる。
	* @param target 攻撃対象
	*/
	virtual void ExecuteAttack(Damageable& target);
};
