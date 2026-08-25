#ifndef GOODS_H
#define GOODS_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Goods {
	public:
		Goods();
	private:
		int goodid;
		string goodname;
    string gooddesc[50];
};
