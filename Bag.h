#pragma once
#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <vector>
#include <map>
#include "Goods.h"
using namespace std;

class Bag {
	public:
		Bag();
		~Bag();

		void showbag();
		void showgoods(int* goodsid, int* num);
		void showgoods(int goodsid, int num);
		int  getGoodsNum();                     //背包物品数量
		int getWhichGoodsId(int whichGoods);	//得到背包里第whichGoods件物品的Id
		int getWhichGoodsNum(int whichGoods);	//得到背包里第whichGoods件物品的数量
		void addgoods(int id,int num);          //拾取
		bool discardgood(int id,int num);       //丢弃
		void saveBag();			                //最后保存游戏时单独将物品存入一个数组


		bool isUseDrug();		//判断是否有药品食物可以用
		map<int, int> getMapBags();
		//void wearequip();                  //穿戴装备
		//bool takeoffequip();               //卸下装备,返回值  1-成功  0-失败
		//void softgood();                   //排序（价格）（类型）
		//void operator=(Bag bag);
	private:
		map<int, int> bags;
		int saveGoods[20][2];		//用来Save物品的数组
		//物品实例化
		Goods goods[17] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
};

#endif