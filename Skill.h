#pragma once
#ifndef SKILL_H
#define SKILL_H

#include <string>
using namespace std;

class Skill {
public:
	Skill();
	int getLevel(int whatSkill);		//判断技能等级（是否为零尚未习得）对应伤害
	bool addLevel(int whatSkill);	    //增加技能等级，每次一级
	void setLevel(int whatSkill, int l);		//设置技能等级

	int getLevel_Max(int whatSkill);	//得到技能的最高等级
	string getName(int whatSkill);		//得到技能名字
	string getDesc(int whatSkill);		//得到技能描述
	//int getType(int whatSkill);			//得到技能类型
	int getNeedMP(int whatSkill);		//得到技能耗蓝
	double getAddAttack(int whatSkill);	//得到技能的攻击力加强
	double getRecoverHp(int whatSkill);	//得到技能恢复的生命值
	int getADDDefense(int whatSkill);   //得到技能的防御力加强
	int getDebuff(int whatSkill);       //角色2的一技能
	void showRoleSkill();		//显示角色的所有技能
protected:
	string skill_1Name;
	string skill_2Name;
	string skill_3Name;
	string skill_4Name;

	string skill_1Desc;
	string skill_2Desc;
	string skill_3Desc;
	string skill_4Desc;

	int skillLevel_1;			//在基类构造函数里初始化
	int skillLevel_2;
	int skillLevel_3;
	int skillLevel_4;

	int skillLevel_Max_1;		//每个技能的最高等级
	int skillLevel_Max_2;		//在基类构造函数里初始化
	int skillLevel_Max_3;
	int skillLevel_Max_4;

	int skill_1NeedMp;
	int skill_2NeedMp;
	int skill_3NeedMp;
	int skill_4NeedMp;

	double skill_1AddAttack;
	double skill_2AddAttack;
	double skill_3AddAttack;
	double skill_4AddAttack;

	double skill_1recoverHp;
	double skill_2recoverHp;
	double skill_3recoverHp;
	double skill_4recoverHp;

	int skill_1ADDDefen;
	int skill_2ADDDefen;
	int skill_3ADDDefen;
	int skill_4ADDDefen;

	//int skill_1debuffattack;
	
};

class Role_1skill :public Skill {
public:
	Role_1skill();

private:

};

class Role_2skill :public Skill {
public:
	Role_2skill();

private:

};

class Role_3skill :public Skill {
public:
	Role_3skill();

private:

};
#endif