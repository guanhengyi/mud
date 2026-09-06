#ifndef GOODS_H
#define GOODS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Goods {
public:
	Goods(int id);
	~Goods();

	int getGoodsid();
	string getName();
	string getDesc();
	int getType();
	int getAddHP();
	int getMaxHP();
	int getAddAttack();
	int getAddDefend();
	int getSpeed();
	int getSan();
	int getMaxSan();
	int getPrice();
	void showgood();

private:
	int goodsid;//编号
	string name;
	int type;//类型：食物-0  药品-1  防具-2  武器-3
	string desc;//描述
	//属性
	int addHP = 0;
	int addMaxHP = 0;
	int addattack = 0;
	int adddefend = 0;
	int addsan = 0;
	int addMaxsan = 0;
	int addspeed = 0;
	int price = 0;
};

#endif