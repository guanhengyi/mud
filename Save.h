#pragma once
#ifndef SAVE_H
#define SAVE_H
#include"role.h"
#include"Bag.h"
#include"Skill.h"

class Save {
public:
	Save();
	~Save();
	static void setToFile(Role player);
	static void saveBag(int** saveBagArray);

private:
};

#endif