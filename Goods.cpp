#include "Goods.h"
using namespace std;

Goods::Goods(int id) {
	switch (id) {
	case 0: 
	{
		goodsid = id;
		name = "绷带";
		type = 1;
		desc = "用于包扎伤口，对于流血伤害有奇效";
		addHP = 30;
		addattack = 0;
		adddefend = 0;
		addsan = 5;
		addspeed = 0;
		price = 5;
		break;
	}
	case 1: {
		goodsid = id;
		name = "急救包";
		type = 1;
		desc = "用于快速处理伤口，可大量回血，HP up up up!!!";
		addHP = 70;
		addattack = 0;
		adddefend = 0;
		addsan = 10;
		addspeed = 0;
		price = 10;
		break;
	}
	case 2: {
		goodsid = id;
		name = "可乐";
		type = 0;
		desc = "甜甜的，喝了很爽";
		addHP = 15;
		addattack = 0;
		adddefend = 0;
		addsan = 30;
		addspeed = 0;
		price = 4;
		break;
	}
	case 3: {
		goodsid = id;
		name = "巧克力";
		type = 0;
		desc = "横扫饥饿，做回自己";
		addHP = 20;
		addattack = 0;
		adddefend = 0;
		addsan = 50;
		addspeed = 0;
		price = 5;
		break;
	}
	case 4: {
		goodsid = id;
		name = "小蓝头盔";
		type = 2;
		desc = "来自小蓝的祝福，安全";
		addMaxHP = 30;
		addattack = 0;
		adddefend = 30;
		addMaxsan = 5;
		addspeed = 0;
		price = 20;
		break;
	}
	case 5: {
		goodsid = id;
		name = "保安头盔";
		type = 2;
		desc = "很安全，暂时借借应该没事吧";
		addMaxHP = 40;
		addattack = 0;
		adddefend = 40;
		addMaxsan = 10;
		addspeed = -5;
		price = 30;
		break;
	}
	case 6: {
		goodsid = id;
		name = "防爆头盔";
		type = 2;
		desc = "超级安全，奇怪的刷新点刷新奇怪";
		addMaxHP = 50;
		addattack = 0;
		adddefend = 50;
		addMaxsan = 20;
		addspeed = -10;
		price = 40;
		break;
	}
	case 7: {
		goodsid = id;
		name = "西乡行马甲";
		type = 2;
		desc = "略微的安全感，西乡行，东...？";
		addMaxHP = 30;
		addattack = 0;
		adddefend = 30;
		addMaxsan = 10;
		addspeed = 0;
		price = 20;
		break;
	}
	case 8: {
		goodsid = id;
		name = "保安防刺服";
		type = 2;
		desc = "挺安全，保安亭是个好地方";
		addMaxHP = 40;
		addattack = 0;
		adddefend = 40;
		addMaxsan = 15;
		addspeed = -5;
		price = 30;
		break;
	}
	case 9: {
		goodsid = id;
		name = "防弹衣";
		type = 2;
		desc = "超级安全，还能再战八百回";
		addMaxHP = 50;
		addattack = 0;
		adddefend = 50;
		addMaxsan = 20;
		addspeed = -10;
		price = 40;
		break;
	}
	case 10: {
		goodsid = id;
		name = "运动鞋";
		type = 2;
		desc = "挺舒服，健步如飞";
		addMaxHP = 10;
		addattack = 0;
		adddefend = 30;
		addsan = 0;
		addspeed = 10;
		price = 30;
		break;
	}
	case 11: {
		goodsid = id;
		name = "户外徒步靴";
		type = 2;
		desc = "一点不慢，安全最重要";
		addMaxHP = 15;
		addattack = 0;
		adddefend = 40;
		addsan = 0;
		addspeed = 15;
		price = 40;
		break;
	}
	case 12: {
		goodsid = id;
		name = "工兵作战靴";
		type = 2;
		desc = "更安全了，不会慢很多哦";
		addMaxHP = 20;
		addattack = 0;
		adddefend = 50;
		addsan = 0;
		addspeed = 25;
		price = 55;
		break;
	}
	case 13: {
		goodsid = id;
		name = "水果刀";
		type = 3;
		desc = "杀西瓜的利器，挺称手";
		addMaxHP = 0;
		addattack = 40;
		adddefend = 0;
		addsan = 0;
		addspeed = 0;
		price = 20;
		break;
	}
	case 14: {
		goodsid = id;
		name = "菜刀";
		type = 3;
		desc = "更有力了，用刀小心";
		addHP = 0;
		addattack = 65;
		adddefend = 0;
		addsan = 0;
		addspeed = 0;
		price = 30;
		break;
	}
	case 15: {
		goodsid = id;
		name = "扫把";
		type = 3;
		desc = "寸长寸强，有点不耐用";
		addHP = 0;
		addattack = 50;
		adddefend = 0;
		addsan = 0;
		addspeed = 0;
		price = 25;
		break;
	}
	case 16: {
		goodsid = id;
		name = "消防斧";
		type = 3;
		desc = "强而有力，神兵在手，天下我有";
		addHP = 0;
		addattack = 100;
		adddefend = 0;
		addsan = 0;
		addspeed = 0;
		price = 50;
		break;
	}
	default: {
		cout << "无效物品！" << endl;
		goodsid = -1;
		name = "未知物品";
		type = -1;
		desc = "该物品id不存在";
		addHP = 0;
		addMaxHP = 0;
		addattack = 0;
		adddefend = 0;
		addsan = 0;
		addMaxsan = 0;
		addspeed = 0;
		price = 0;
		break;
	}
	}
}
//补空析构函数
Goods::~Goods() {}

int Goods::getGoodsid() {
	return goodsid;
}
string Goods::getName() {
	return name;
}
string Goods::getDesc() {
	return desc;
}
int Goods::getType() {
	return type;
}
int Goods::getAddHP() {
	return addHP;
}
int Goods::getMaxHP() {
	return addMaxHP;
}
int Goods::getAddAttack() {
	return addattack;
}
int Goods::getAddDefend() {
	return adddefend;
}
int Goods::getSpeed() {
	return addspeed;
}
int Goods::getSan() {
	return addsan;
}
int Goods::getMaxSan() {
	return addMaxsan;
}
int Goods::getPrice() {
	return price;
}
void Goods::showgood() {
	cout << "名称：" << name << endl;
	cout << "物品描述：" << desc << endl;
	switch (type)
	{
	case 0: {
		cout << "回复血量：" << addHP << endl;
		cout << "回复san值量：" << addsan << endl;
		break;
	}
	case 1: {
		cout << "回复血量：" << addHP << endl;
		cout << "回复san值量：" << addsan << endl;
		break;
	}
	case 2: {
		cout << "防御值：" << adddefend << endl;
		cout << "增加血量上限：" << addMaxHP << endl;
		cout << "增加san值上限：" << addMaxsan << endl;
		cout << "速度影响：" << addspeed << endl;
		break;
	}
	case 3: {
		cout << "攻击力：" << addattack << endl;
		cout << "速度影响：" << addspeed << endl;
		break;
	}
	default:cout << "物品出错啦 " << endl;
	}
	cout << "价格：" << price << endl;
}