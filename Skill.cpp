#include <iostream>
#include <iomanip>
#include "Skill.h"
using namespace std;

Skill::Skill() {
	skillLevel_1 = 0;			//在基类构造函数里初始化
	skillLevel_2 = 0;
	skillLevel_3 = 0;
	skillLevel_4 = 0;

	skillLevel_Max_1 = 5;		//每个技能的最高等级
	skillLevel_Max_2 = 5;		//在基类构造函数里初始化
	skillLevel_Max_3 = 5;
	skillLevel_Max_4 = 5;
}
int Skill::getLevel(int whatskill) {
	switch (whatskill) {
	case 1:return skillLevel_1; break;
	case 2:return skillLevel_2; break;
	case 3:return skillLevel_3; break;
	case 4:return skillLevel_4; break;
	default:return 0;
	}
}

int Skill::getLevel_Max(int whatSkill) {
	switch (whatSkill) {
	case 1:return skillLevel_Max_1; break;
	case 2:return skillLevel_Max_2; break;
	case 3:return skillLevel_Max_3; break;
	case 4:return skillLevel_Max_4; break;
	default:return 0;
	}
}

bool Skill::addLevel(int whatSkill)
{
	int lv = getLevel(whatSkill);
	int maxLv = getLevel_Max(whatSkill);
	if (lv >= maxLv)
		return false;
	switch (whatSkill)
	{
	case 1: skillLevel_1++; break;
	case 2: skillLevel_2++; break;
	case 3: skillLevel_3++; break;
	case 4: skillLevel_4++; break;
	default: return false;
	}
	return true;
}

void Skill::setLevel(int whatSkill, int l)
{
	int maxLv = getLevel_Max(whatSkill);
	if (l < 0 || l > maxLv) return;
	switch (whatSkill)
	{
	case 1: skillLevel_1 = l; break;
	case 2: skillLevel_2 = l; break;
	case 3: skillLevel_3 = l; break;
	case 4: skillLevel_4 = l; break;
	default: break;
	}
}

string Skill::getName(int whatskill) {
	switch (whatskill) {
	case 1:return skill_1Name;
	case 2:return skill_2Name;
	case 3:return skill_3Name;
	case 4:return skill_4Name;
	default:return " ";
	}
}

string Skill::getDesc(int whatskill) {
	switch (whatskill) {
	case 1:return skill_1Desc;
	case 2:return skill_2Desc;
	case 3:return skill_3Desc;
	case 4:return skill_4Desc;
	default:return " ";
	}
}

int Skill::getNeedMP(int whatSkill) {
	switch (whatSkill) {
	case 1: return skill_1NeedMp;
	case 2: return skill_2NeedMp;
	case 3: return skill_3NeedMp;
	case 4: return skill_4NeedMp;
	default: return 0;
	}
}

double Skill::getAddAttack(int whatSkill) {
	switch (whatSkill) {
	case 1: return skill_1AddAttack;
	case 2: return skill_2AddAttack;
	case 3: return skill_3AddAttack;
	case 4: return skill_4AddAttack;
	default: return 0;
	}
}

double Skill::getRecoverHp(int whatskill) {
	if (whatskill == 1)
		return skill_1recoverHp;
	if (whatskill == 2)
		return skill_2recoverHp;
	if (whatskill == 3)
		return skill_3recoverHp;
	if (whatskill == 4)
		return skill_4recoverHp;
}

int Skill::getADDDefense(int whatskill) {
	if (whatskill == 1)
		return skill_1ADDDefen;
	if (whatskill == 2)
		return skill_2ADDDefen;
	if (whatskill == 3)
		return skill_3ADDDefen;
	if (whatskill == 4)
		return skill_4ADDDefen;
}

void Skill::showRoleSkill() {
	cout << left << setw(15) << "名称" << "技能描述" << endl;
	for (int i = 1; i < 5; ++i) {
		cout << left << setw(15) << getName(i) << getDesc(i) << endl;
	}
}

Role_1skill::Role_1skill() {
	skill_1Name = "蓄意冲拳";
	skill_2Name = "沉淀";
	skill_3Name = "极限透支";
	skill_4Name = "诺克萨斯断头台";
	skill_1Desc = "2倍攻击力；耗蓝 10点";
	skill_2Desc = "下一回合攻击1.5倍，防御加50点；耗蓝10点";
	skill_3Desc = "消耗血量10%，3倍攻击力；耗蓝10点";
	skill_4Desc = "血量低于10%，斩杀，攻击力永久增加1%；耗蓝15";

	skill_1NeedMp = 10;
	skill_2NeedMp = 10;
	skill_3NeedMp = 10;
	skill_4NeedMp = 15;

	skill_1AddAttack = 1.0;
	skill_2AddAttack = 0;
	skill_3AddAttack = 0;
	skill_4AddAttack = 0;

	skill_1recoverHp = 0;
	skill_2recoverHp = 0;
	skill_3recoverHp = -0.1;
	skill_4recoverHp = 0;

	skill_1ADDDefen = 0;
	skill_2ADDDefen = 50;
	skill_3ADDDefen = 0;
	skill_4ADDDefen = 0;

	//skill_1debuffattack = 0 ;
}

Role_2skill::Role_2skill() {
	skill_1Name = "勾股定理";
	skill_2Name = "门捷列夫";
	skill_3Name = "9 3 3 1";
	skill_4Name = "牛顿之力";
	skill_1Desc = "降低敌人20%攻击力；耗蓝 10点";
	skill_2Desc = "持续降低敌人10点生命值；耗蓝10点";
	skill_3Desc = "6.25%的几率降低敌人90%的生命值，37.5%的几率降低敌人30%的生命值，56.25%的几率降低敌人10%的生命值；耗蓝30点";
	skill_4Desc = "交换你和敌人的攻击，防御，生命值；耗蓝150";

	skill_1NeedMp = 10;
	skill_2NeedMp = 10;
	skill_3NeedMp = 30;
	skill_4NeedMp = 150;

	skill_1AddAttack = 0;
	skill_2AddAttack = 0;
	skill_3AddAttack = 0;
	skill_4AddAttack = 0;

	skill_1recoverHp = 0;
	skill_2recoverHp = 0;
	skill_3recoverHp = 0;
	skill_4recoverHp = 0;

	skill_1ADDDefen = 0;
	skill_2ADDDefen = 0;
	skill_3ADDDefen = 0;
	skill_4ADDDefen = 0;

	//skill_1debuffattack = 0;
}

Role_3skill::Role_3skill() {
	skill_1Name = "卜算子";
	skill_2Name = "声声慢";
	skill_3Name = "满江红";
	skill_4Name = "水调歌头";
	skill_1Desc = "50%攻击一次，50%攻击两次；耗蓝 10点";
	skill_2Desc = "对敌人作用：40%不攻击，30%攻击其自身，30%2倍攻击其自身；耗蓝20点";
	skill_3Desc = "回复10%生命值，增加50点防御，并给敌人挂上标记“摧锐”；耗蓝10点";
	skill_4Desc = "3倍攻击，如果敌人身负“摧锐”，1层标记可使敌人本回合无法攻击，多余层数可使攻击力翻倍；耗蓝50";

	skill_1NeedMp = 10;
	skill_2NeedMp = 20;
	skill_3NeedMp = 10;
	skill_4NeedMp = 50;

	skill_1AddAttack = 0;
	skill_2AddAttack = 0;
	skill_3AddAttack = 0;
	skill_4AddAttack = 2;

	skill_1recoverHp = 0;
	skill_2recoverHp = 0;
	skill_3recoverHp = 0.1;
	skill_4recoverHp = 0;

	skill_1ADDDefen = 0;
	skill_2ADDDefen = 0;
	skill_3ADDDefen = 50;
	skill_4ADDDefen = 0;

	//skill_1debuffattack = 0;
}