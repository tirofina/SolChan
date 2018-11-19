#ifndef MASTER_H
#define MASTER_H

#include <string>
#include <iostream>
#include "Recipe.h"
#include "Material.h"
//#include "Master.h"
using namespace std;

class Master {
	int password;
	int purchase;
	int income;
public:
	void set_password(int password);
	void set_perchase(int money);
	void set_income(int money);
};

Master* fopen_master();

#endif