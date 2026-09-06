#include"Bag.h"
#include <iomanip>
#include<vector>
using namespace std;

Bag::Bag() :saveGoods{} {
	
}

Bag::~Bag() {}

void Bag::showbag() {
	if (bags.begin() == bags.end())
		cout << "当前背包无物品！" << endl;
	else {
		cout << "当前背包:" << endl;
		cout << "物品ID	 物品名称      数量" << endl;
		map<int, int>::iterator iter;
		for (iter = bags.begin(); iter != bags.end(); ++iter)
		{
			cout << left << setw(10) << goods[iter->first].getGoodsid() << setw(10) << goods[iter->first].getName() << setw(3) << '\t' << iter->second << endl;
		}
	}
}

void Bag::showgoods(int* goodsId, int* num) {

	for (int i = 0; goodsId[i] >= 0; i++)
		cout << i + 1 << "." << setw(10) << left << goods[goodsId[i]].getName() << num[i] << "件" << endl;
	cout << endl;
}

void Bag::showgoods(int goodsId, int num) {
	cout << 1 << "." << setw(10) << left << goods[goodsId].getName() << num << "件" << endl;
	cout << endl;
}

void Bag::addgoods(int id, int num) {
	if (bags.count(id))
	{
		bags[id] += num;
	}
	else
	{
		bags.insert(pair<int, int>(id, num));
	}
}

void Bag::saveBag() {
	map<int, int>::iterator iter;
	for (iter = bags.begin(); iter != bags.end(); ++iter) {
		int i = 0;
		saveGoods[i][0] = goods[iter->first].getGoodsid();
		saveGoods[i][1] = iter->second;
		i++;
	}
}

bool Bag::discardgood(int id, int num) {
	map<int, int>::iterator iter;
	if (bags.find(id) == bags.end())
		return false;
	else {
		bags[id] -= num;
		if (bags[id] <= 0)
			bags.erase(id);
		return true;
	}
}

bool Bag::isUseDrug() {
	map<int, int>::iterator iter;
	for (iter = bags.begin(); iter != bags.end(); ++iter) {
		if (goods[iter->first].getGoodsid() == 0 || goods[iter->first].getGoodsid() == 1 || goods[iter->first].getGoodsid() == 2 || goods[iter->first].getGoodsid() == 3)
			return true;
	}
	return false;
}

//void Bag::operator=(Bag bag){}

map<int, int> Bag::getMapBags()
{
	return bags;
}

int Bag::getGoodsNum() {  //返回背包里物品的数量
	return bags.size();
}

int Bag::getWhichGoodsId(int whichGoods) {
	map<int, int>::iterator iter;
	iter = bags.begin();
	for (; whichGoods > 1; whichGoods--)
		iter++;
	return  goods[iter->first].getGoodsid();

}

int Bag::getWhichGoodsNum(int whichGoods) {
	map<int, int>::iterator iter;
	for (iter = bags.begin(); whichGoods > 1; whichGoods--)
		iter++;
	return  iter->second;
}