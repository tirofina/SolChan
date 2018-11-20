#ifndef MASTER_H
#define MASTER_H

#include <string>
#include <iostream>
#include "Recipe.h"
#include "Material.h"
#include "Admin.h"

using namespace std;

class Master {
	string password;
	int purchase;
	int income;
	int expense;
	int wating_time;
public:
	Master();
	void set_password(string password);
	void set_perchase(int money);
	void set_income(int money);
	void set_expense(int money);
	bool check_password(string input);
};

Master* fopen_master();
void check_menu(Master* master, Material* ingredient, Recipe* recipe);
#endif