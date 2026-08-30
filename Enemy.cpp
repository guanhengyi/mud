#include <iostream>
#include "Enemy.h"
#include<cstdlib>
#include<ctime>

using namespace std;


Enemy::Enemy() {}

Enemy::~Enemy() {}

string Enemy::getName() {
	return name;
}

void Enemy::setType(int whatType) {
	type = whatType;
}

int Enemy::getType() {
	return type;
}

int Enemy::getHealth_max() {
	return health;
}

void Enemy::setHealth_max(int hp_m) {
	health_max = hp_m;

}

int Enemy::getHealth() {
	return health;
}

void Enemy::setHealth(int hp) {
	health = hp;

}



int Enemy::getAttack() {
	return attack;
}

void Enemy::setAttack(int a) {
	attack = a;

}

int Enemy::getDefend() {
	return defend;
}

void Enemy::setDefend(int d) {
	defend = d;
}

int* Enemy::getGoodsId() {
	return goodsId;
}

int* Enemy::getGoodsNum() {
	return goodsNum;
}

int Enemy::getExp() {
	return exp;
}

int Enemy::getMoney() {
	return money;
}

double Enemy::useSkill() {
	return getAttack() * 1.5;
}

void Enemy::showEnemy() {
	cout << endl << "当前怪物属性:" << '\t';
	cout << "名称:" << name << '\t' << endl;
	cout << "生命值:" << health << "/" << health_max << '\t';
	
	cout << "攻击:" << attack << '\t';
	cout << "防御:" << defend << endl;
}


Enemy_Small::Enemy_Small() {  //小怪统一血量和攻击？
	health = 50;
	attack = 5;
}

Enemy_Small::~Enemy_Small() {}

Enemy_Boss::Enemy_Boss(int whatType) {

	srand((unsigned)time(NULL));
	setType(whatType);
	switch (whatType) {
	case 1: {
		name = "体育生丧尸#沉淀中";
		type = 0;
		health = 150;
		health_max = 150;
		
		attack = 20;
		defend = 10;

		int num = 0 + rand() % (4);//物品编号
		


		goodsNum[0] = 2;		//对应每件物品的数量
		goodsNum[1] = 1;
		goodsNum[2] = 0;
		goodsNum[3] = 0;
		goodsNum[4] = 1;

		goodsId[0] = num;	//打死该怪物会掉落的物品
		goodsId[1] = 4;
		goodsId[2] = -1;	//空，代表只有以上两件
		goodsId[3] = -1;
		goodsId[4] = 13;

		exp = 8;		//打死该怪物得到的经验
		money = 30;		//打死该怪物得到的金钱
		break;
	}
	case 3: {
		name = "丧尸耄耋";
		type = 2;
		health = 350;
		health_max = 350;
	
		attack = 30;
		defend = 15;

		int num = 0 + rand() % (4);//物品编号

		goodsNum[0] = 2;			//对应每件物品的数量
		goodsNum[1] = 0;
		goodsNum[2] = 1;
		goodsNum[3] = 0;
		goodsNum[4] = 0;

		goodsId[0] = num;	//打死该怪物会掉落的物品
		goodsId[1] = -1;
		goodsId[2] = 7;
		goodsId[3] = -1;
		goodsId[4] = -1;

		exp = 10;		//打死该怪物得到的经验
		money = 50;		//打死该怪物得到的金钱
		break;
	}
	case 4: {
		name = "丧尸刀盾";
		type = 3;
		health = 700;
		health_max = 700;
	
		attack = 100;
		defend = 50;

		int num = 0 + rand() % (4);//物品编号

		goodsNum[0] = 3;			//对应每件物品的数量
		goodsNum[1] = 0;
		goodsNum[2] = 0;
		goodsNum[3] = 1;
		goodsNum[4] = 0;

		goodsId[0] = num;	//打死该怪物会掉落的物品
		goodsId[1] = -1;
		goodsId[2] = -1;
		goodsId[3] = 10;
		goodsId[4] = -1;

		exp = 10;		//打死该怪物得到的经验
		money = 50;		//打死该怪物得到的金钱
		break;
	}
	case 5: {
		name = "rapper丧尸（西海岸限定";
		type = 4;
		health = 1000;
		health_max = 1000;
		
		attack = 200;
		defend = 100;

		int num = 0 + rand() % (4);//物品编号
		int num2 = 0 + rand() % (4);//物品编号


		goodsNum[0] = 5;			//对应每件物品的数量
		goodsNum[1] = 5;
		goodsNum[2] = 1;
		goodsNum[3] = 1;
		goodsId[0] = num;	//打死该怪物会掉落的物品
		goodsId[1] = num2;
		goodsId[2] = 11;
		goodsId[3] = 14;

		exp = 15;		//打死该怪物得到的经验
		money = 40;		//打死该怪物得到的金钱
		break;
	}

	case 6: {
		name = "乘警丧尸";
		type = 5;
		health = 4000;
		health_max = 4000;
		
		attack = 400;
		defend = 200;

		int num = 0 + rand() % (4);//物品编号
		int num2 = 0 + rand() % (4);//物品编号


		goodsNum[0] = 3;			//对应每件物品的数量
		goodsNum[1] = 3;
		goodsNum[2] = 1;
		goodsNum[3] = 1;
		goodsId[0] = num;	//打死该怪物会掉落的物品
		goodsId[1] = num2;
		goodsId[2] = 5;
		goodsId[3] = 8;

		exp = 15;		//打死该怪物得到的经验
		money = 40;		//打死该怪物得到的金钱
		break;
	}
	case 7: {
		name = "列车长丧尸";
		type = 6;
		health = 4000;
		health_max = 4000;
		
		attack = 400;
		defend = 200;

		int num = 0 + rand() % (4);//物品编号
		int num2 = 0 + rand() % (4);//物品编号
		int num3 = 0 + rand() % (4);//物品编号


		goodsNum[0] = 2;			//对应每件物品的数量
		goodsNum[1] = 2;
		goodsNum[2] = 2;
		goodsNum[3] = 1;
		goodsNum[4] = 1;

		goodsId[0] = num;	//打死该怪物会掉落的物品
		goodsId[1] = num2;
		goodsId[2] = num3;
		goodsId[3] = 6;
		goodsId[4] = 12;

		exp = 15;		//打死该怪物得到的经验
		money = 40;		//打死该怪物得到的金钱
		break;
	}
	case 8: {
		name = "骏丰叔叔";
		type = 7;
		health = 8000;
		health_max = 8000;
	
		attack = 600;
		defend = 500;

		int num = 0 + rand() % (4);//物品编号
		int num2 = 0 + rand() % (4);//物品编号


		goodsNum[0] = 3;			//对应每件物品的数量
		goodsNum[1] = 3;
		goodsNum[2] = 1;
		goodsNum[3] = 1;
		goodsId[0] = num;	//打死该怪物会掉落的物品
		goodsId[1] = num2;
		goodsId[2] = 9;
		goodsId[3] = 16;

		exp = 30;		//打死该怪物得到的经验
		money = 110;		//打死该怪物得到的金钱
		break;
	}
	case 9: {
		name = "小桂";
		type = 8;
		health = 12000;
		health_max = 12000;
	
		attack = 800;
		defend = 700;

		int num = 0 + rand() % (4);//物品编号

		goodsNum[0] = 1;			//对应每件物品的数量
		goodsNum[1] = 0;
		goodsNum[2] = 0;
		goodsNum[3] = 0;
		goodsId[0] = 17;	//打死该怪物会掉落的物品
		goodsId[1] = -1;
		goodsId[2] = -1;
		goodsId[3] = -1;


		exp = 50;		//打死该怪物得到的经验
		money = 500;		//打死该怪物得到的金钱
		break;
	}
	default:break;
	}
}