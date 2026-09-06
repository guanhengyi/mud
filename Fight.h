#ifndef FIGHT_H
#define FIGHT_H
#include <iostream>
#include "role.h"
#include "Enemy.h"
using namespace std;

class Fight
{
public:
	Fight(Role player, Enemy enemy);
	~Fight();
	bool fightRound();			//显示当前回合战斗,返回是否逃跑 true逃跑成功
	void showFight();			//显示战斗状态
	void enemyFight();			//怪物的随机攻击
	bool isFightEnd();			//判断是否结束战斗 true战斗结束
	Role& endFight();			//结束战斗,将战斗完后的玩家返回覆盖main里的
	Role& runEndFight();		//逃跑结束战斗
	void addMoney(int addMoney);//添加金钱
	void addFightEndGoods(int* addGoods, int* num);//添加物品
	void addExp(int addExp);	//添加经验
	void recoverHpOrMp();		//物品回复生命值，调用角色使用药品
	void RoleuseSkill();		//战斗角色中使用技能
	void GameEnd();				//判断游戏结束，程序退出

private:
	Role m_player;
	Enemy m_enemy;
	int m_round;		//战斗回合数
	bool m_isEscape;	//是否逃跑成功
	bool m_isGameOver;	//是否游戏结束

	//====玩家临时buff（仅战斗内生效，战斗结束丢弃）====
	double m_buff_nextAtkMul; //沉淀技能：下一回合攻击倍率
	int m_buff_tempDef;       //沉淀增加临时防御
	bool m_usedBuffDef;       //本回合是否消耗临时防御

	//====敌人debuff状态====
	double m_enemy_atkRate;	//敌人攻击倍率（勾股定理降低20% →0.8）
	int m_enemy_dotDmg;		//门捷列夫每回合持续扣血
	int m_enemy_cuirui;		//摧锐标记层数
	bool m_enemy_stun;		//水调歌头造成本回合无法行动
};

#endif