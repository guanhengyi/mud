#include "Fight.h"
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <iomanip>

Fight::Fight(Role player, Enemy enemy)
	:m_player(player), m_enemy(enemy), m_isEscape(false), m_isGameOver(false),
	m_buff_nextAtkMul(1.0), m_buff_tempDef(0), m_usedBuffDef(false),
	m_enemy_atkRate(1.0), m_enemy_dotDmg(0), m_enemy_cuirui(0), m_enemy_stun(false)
{
	srand((unsigned)time(NULL));
	m_round = 1;
}

Fight::~Fight()
{

}

bool Fight::fightRound()
{
	cout << "\n=====战斗"<< m_round << "回合开始=====" << endl;
	m_round += 1;
	//【回合前置处理】敌人持续掉血dot
	if (m_enemy_dotDmg > 0 && m_enemy.getHealth() > 0)
	{
		int dmg = m_enemy_dotDmg;
		cout << "【门捷列夫持续伤害】敌人受到 " << dmg << " 点腐蚀伤害！" << endl;
		m_enemy.setHealth(m_enemy.getHealth() - dmg);
	}
	//每回合重置眩晕标记（仅本回合生效）
	m_enemy_stun = false;
	m_usedBuffDef = false;

	showFight();

	cout << "\n请选择行动：" << endl;
	cout << "1.普通攻击\t2.释放技能\t3.使用药品\t4.尝试逃跑\t5.结束游戏" << endl;
	int op;
	cin >> op;

	switch (op)
	{
	case 1:
	{
		//玩家普通攻击，应用沉淀buff倍率
		int realDamage = static_cast<int>(m_player.getAttack() * m_buff_nextAtkMul) - m_enemy.getDefend();
		if (realDamage < 1) realDamage = 1;
		if (m_buff_nextAtkMul > 1.0)
		{
			cout << "【沉淀加成生效】";
			m_buff_nextAtkMul = 1.0; //buff消耗掉
		}
		cout << "你发动普通攻击，造成 " << realDamage << " 点伤害！" << endl;
		m_enemy.setHealth(m_enemy.getHealth() - realDamage);
		break;
	}
	case 3:
	{
		recoverHpOrMp();
		break;
	}
	case 4:
	{
		int r = rand() % 2;
		if (r == 1)
		{
			cout << "逃跑成功！" << endl;
			m_isEscape = true;
			return true;
		}
		else
		{
			cout << "逃跑失败！怪物拦住了你！" << endl;
		}
		break;
	}
	case 5:
	{
		GameEnd();
		break;
	}
	case 2:
	{
		RoleuseSkill();
		break;
	}
	default:
		cout << "输入错误，跳过回合" << endl;
		break;
	}

	//怪物行动，如果怪物没死，且没有被眩晕
	if (m_enemy.getHealth() > 0 && !m_enemy_stun)
	{
		enemyFight();
	}
	else if (m_enemy_stun && m_enemy.getHealth() > 0)
	{
		cout << "\n敌人被摧锐标记眩晕，本回合无法行动！" << endl;
	}

	//玩家死亡检测
	if (m_player.getHealth() <= 0)
	{
		cout << "你被击败了！" << endl;
		GameEnd();
	}

	return m_isEscape;
}

void Fight::showFight()
{
	cout << "--------我方--------" << endl;
	m_player.showRole();
	if (m_buff_nextAtkMul > 1.0 || m_buff_tempDef > 0)
	{
		cout << "【我方Buff】下回合攻击倍率:" << m_buff_nextAtkMul << " 临时防御+" << m_buff_tempDef << endl;
	}
	cout << "\n--------敌方--------" << endl;
	m_enemy.showEnemy();
	cout << "怪物技能：" << m_enemy.getSkillName() << endl;
	if (m_enemy_atkRate < 1.0) cout << "【Debuff】敌人攻击降低" << (1.0 - m_enemy_atkRate) * 100 << "%" << endl;
	if (m_enemy_dotDmg > 0) cout << "【Debuff】敌人每回合受到" << m_enemy_dotDmg << "持续腐蚀伤害" << endl;
	if (m_enemy_cuirui > 0) cout << "【标记】摧锐层数：" << m_enemy_cuirui << endl;
}

void Fight::enemyFight()
{
	cout << "\n>>>怪物行动回合<<<" << endl;
	int randOpt = rand() % 2;
	int rawDamage;
	if (randOpt == 0)
	{
		rawDamage = m_enemy.getAttack();
		cout << m_enemy.getName() << "发动普通攻击！" << endl;
	}
	else
	{
		rawDamage = static_cast<int>(m_enemy.useSkill());
		cout << m_enemy.getName() << "释放【" << m_enemy.getSkillName() << "】！" << endl;
	}
	//应用敌人被降低攻击debuff
	rawDamage = static_cast<int>(rawDamage * m_enemy_atkRate);

	int playerDef = m_player.getDefend();
	if (!m_usedBuffDef)
	{
		playerDef += m_buff_tempDef;
		m_usedBuffDef = true; //临时防御只挡一次怪物攻击
	}
	int finalDmg = rawDamage - playerDef;
	if (finalDmg < 1) finalDmg = 1;
	cout << "对你造成 " << finalDmg << " 点伤害！" << endl;
	m_player.setHealth(m_player.getHealth() - finalDmg);
}

bool Fight::isFightEnd()
{
	if (m_player.getHealth() <= 0)
		return true;
	if (m_enemy.getHealth() <= 0)
		return true;
	if (m_isEscape)
		return true;
	return false;
}

Role& Fight::endFight()
{
	cout << "\n====战斗胜利！敌人被消灭====" << endl;
	int dropExp = m_enemy.getExp();
	int dropMoney = m_enemy.getMoney();
	int* dropIds = m_enemy.getGoodsId();
	int* dropNums = m_enemy.getGoodsNum();

	addExp(dropExp);
	addMoney(dropMoney);
	addFightEndGoods(dropIds, dropNums);
	return m_player;
}

Role& Fight::runEndFight()
{
	cout << "\n====战斗结束：逃跑成功====" << endl;
	return m_player;
}

void Fight::addMoney(int addMoney)
{
	int old = m_player.getMoney();
	m_player.setMoney(old + addMoney);
	cout << "获得金钱：" << addMoney << "，当前金钱：" << m_player.getMoney() << endl;
}

void Fight::addFightEndGoods(int* addGoods, int* num)
{
	m_player.addGoodsToBag(addGoods, num);
}

void Fight::addExp(int addExp)
{
	int oldExp = m_player.getExp();
	m_player.setExp(oldExp + addExp);
	cout << "获得经验值：" << addExp << "，当前总经验：" << m_player.getExp() << endl;
}

void Fight::recoverHpOrMp()
{
	m_player.useDrug();
}

void Fight::GameEnd()
{
	cout << "\n游戏结束，即将退出程序..." << endl;
	m_isGameOver = true;
	exit(0);
}

//====================完整实现全部技能效果====================
void Fight::RoleuseSkill()
{
	cout << "\n====选择要释放的技能====" << endl;
	bool canUse = m_player.showSkill();
	if (!canUse)
	{
		cout << "你没有可用技能！" << endl;
		return;
	}
	cout << "请输入技能编号(1‑4)，输入0取消：";
	int skId;
	cin >> skId;
	if (skId == 0)
	{
		cout << "取消释放技能" << endl;
		return;
	}
	if (skId < 1 || skId>4)
	{
		cout << "无效技能编号！" << endl;
		return;
	}
	//拿到技能信息
	Skill* sk = nullptr;
	//从m_player拿skill指针（role修改后的skill指针）
	sk = reinterpret_cast<Skill*>(&m_player); 
	
	sk = m_player.getSkillPtr();
	if (!sk)
	{
		cout << "技能对象为空！" << endl;
		return;
	}
	int needMp = sk->getNeedMP(skId);
	if (m_player.getMagic() < needMp)
	{
		cout << "san值不足！需要" << needMp << "，当前" << m_player.getMagic() << endl;
		return;
	}
	//扣蓝
	m_player.setMagic(m_player.getMagic() - needMp);

	// ==========角色1 小管 Role_1skill==========
	if (m_player.getType() == 1)
	{
		switch (skId)
		{
		case 1: {
			//蓄意冲拳：2倍攻击力；耗蓝10
			double mul = 2.0;
			int dmg = static_cast<int>(m_player.getAttack() * mul) - m_enemy.getDefend();
			if (dmg < 1) dmg = 1;
			cout << "你释放【蓄意冲拳】！2倍攻击！造成" << dmg << "伤害！" << endl;
			m_enemy.setHealth(m_enemy.getHealth() - dmg);
			break;
		}
		case 2: {
			  //沉淀：下一回合攻击1.5倍，防御加50点；耗蓝10
			  m_buff_nextAtkMul = 1.5;
			  m_buff_tempDef += 50;
			  cout << "你释放【沉淀】！下一次攻击1.5倍，获得临时防御+50！" << endl;
			  break;
		}
		case 3: {
			  //极限透支：消耗血量10%，3倍攻击力；耗蓝10
			  int loseHp = static_cast<int>(m_player.getHealth_max() * 0.1);
			  m_player.setHealth(m_player.getHealth() - loseHp);
			  double mul = 3.0;
			  int dmg = static_cast<int>(m_player.getAttack() * mul) - m_enemy.getDefend();
			  if (dmg < 1) dmg = 1;
			  cout << "你释放【极限透支】！消耗自身10%血量，发动3倍攻击，造成" << dmg << "伤害！" << endl;
			  m_enemy.setHealth(m_enemy.getHealth() - dmg);
			  break;
		  }
		case 4: {
			  //诺克萨斯断头台：血量低于10%，斩杀，攻击力永久增加1%；耗蓝15
			  double hpRate = 1.0 * m_player.getHealth() / m_player.getHealth_max();
			  if (hpRate < 0.10)
			  {
				  cout << "【诺克萨斯断头台】触发斩杀！！" << endl;
				  m_enemy.setHealth(0);
				  int newAtk = static_cast<int>(m_player.getAttack() * 1.01);
				  m_player.setAttack(newAtk);
				  cout << "你的攻击力永久提升1%！现在攻击：" << m_player.getAttack() << endl;
			  }
			  else {
				  cout << "你的生命值高于10%，无法释放斩杀！" << endl;
			  }
			  break;
		}
		}
	}
	// ==========角色2 小杜 Role_2skill==========
	else if (m_player.getType() == 2)
	{
		switch (skId)
		{
		case 1: {
			//勾股定理：降低敌人20%攻击力；耗蓝10
			m_enemy_atkRate = 0.8;
			cout << "你释放【勾股定理】敌人攻击力降低20%！" << endl;
			break;
			}
		case 2: {
		//门捷列夫：持续降低敌人10点生命值；耗蓝10
			m_enemy_dotDmg = 10;
			cout << "你释放【门捷列夫】敌人挂上腐蚀，每回合扣10点生命！" << endl;
			break;
		}
		case 3: {
			//9331：6.25% 90%hp伤害；37.5% 30%hp；56.25% 10%hp
			int r = rand() % 10000;
			double rate;
			if (r < 625) rate = 0.90;
			else if (r < 625 + 3750) rate = 0.30;
			else rate = 0.10;
			int dmg = static_cast<int>(m_enemy.getHealth_max() * rate);
			cout << "你释放【9 3 3 1】！对敌人造成" << rate * 100 << "%最大生命值伤害！(" << dmg << ")" << endl;
			m_enemy.setHealth(m_enemy.getHealth() - dmg);
			break;
		}
		case 4: {
		//牛顿之力：交换你和敌人攻击，防御，生命值；耗蓝150
			int pAtk = m_player.getAttack();
			int pDef = m_player.getDefend();
			int pHp = m_player.getHealth();

			int eAtk = m_enemy.getAttack();
			int eDef = m_enemy.getDefend();
			int eHp = m_enemy.getHealth();

			m_player.setAttack(eAtk);
			m_player.setDefend(eDef);
			m_player.setHealth(eHp);

			m_enemy.setAttack(pAtk);
			m_enemy.setDefend(pDef);
			m_enemy.setHealth(pHp);
			cout << "【牛顿之力】交换了你与敌人的攻击、防御、当前生命值！" << endl;
			break;
		}
		}
	}
	// ==========角色3 小龚 Role_3skill==========
	else if (m_player.getType() == 3)
	{
		switch (skId)
		{
		case 1: {
			//卜算子：50%攻击一次，50%攻击两次；耗蓝10
			int cnt = (rand() % 2 == 0) ? 1 : 2;
			int totalDmg = 0;
			for (int i = 0; i < cnt; i++)
			{
				int d = m_player.getAttack() - m_enemy.getDefend();
				if (d < 1) d = 1;
				totalDmg += d;
			}
			cout << "你释放【卜算子】！攻击" << cnt << "次，合计造成" << totalDmg << "伤害！" << endl;
			m_enemy.setHealth(m_enemy.getHealth() - totalDmg);
			break;
			}
		case 2: {
			//声声慢：40%不攻击，30%攻击其自身，30%2倍攻击其自身；耗蓝20
			int r = rand() % 100;
			if (r < 40)
			{
				cout << "【声声慢】敌人心智混乱，什么都没做！（本效果标记，敌人下回合行动生效）" << endl;
			}
			else if (r < 70)
			{
				int dmg = m_enemy.getAttack() - m_enemy.getDefend();
				if (dmg < 1) dmg = 1;
				cout << "【声声慢】敌人陷入混乱攻击自己！造成" << dmg << "自伤！" << endl;
				m_enemy.setHealth(m_enemy.getHealth() - dmg);
			}
			else
			{
				int dmg = m_enemy.getAttack() * 2 - m_enemy.getDefend();
				if (dmg < 1) dmg = 1;
				cout << "【声声慢】敌人疯狂2倍攻击自身！造成" << dmg << "自伤！" << endl;
				m_enemy.setHealth(m_enemy.getHealth() - dmg);
			}
			break;
			}
		case 3: {
			//满江红：回复10%生命值，增加50点防御，并给敌人挂上标记“摧锐”；耗蓝10
			int heal = static_cast<int>(m_player.getHealth_max() * 0.10);
			m_player.setHealth(m_player.getHealth() + heal);
			m_buff_tempDef += 50;				
			m_enemy_cuirui += 1;
			cout << "【满江红】回复" << heal << "生命，临时防御+50，敌人获得摧锐标记(" << m_enemy_cuirui << "层)！" << endl;
			break;
		}
		case 4: {
			//水调歌头：3倍攻击，如果敌人身负“摧锐”，1层标记可使敌人本回合无法攻击，多余层数可使攻击力翻倍；耗蓝50
			double mul = 3.0;
			if (m_enemy_cuirui >= 1)
			{
				m_enemy_stun = true;
				int extraLayer = m_enemy_cuirui - 1;
				mul *= (1 + extraLayer);
				cout << "摧锐标记生效！敌人眩晕！额外" << extraLayer << "层标记放大伤害！倍率：" << mul << endl;
				m_enemy_cuirui = 0; //消耗全部摧锐标记
			}
			int dmg = static_cast<int>(m_player.getAttack() * mul) - m_enemy.getDefend();
			if (dmg < 1) dmg = 1;
			cout << "【水调歌头】发动！造成" << dmg << "伤害！" << endl;
			m_enemy.setHealth(m_enemy.getHealth() - dmg);
			break;
		}
		}
	}
}
