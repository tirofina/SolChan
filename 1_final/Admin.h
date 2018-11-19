#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>
#include "Recipe.h"
//#include "Master.h"
using namespace std;

class Admin { 
	string* menu;
	int num;
	int income;
public:
	Admin(int max=5);
	void print_menu();
	void save_income(int val);
	int get_income();
};
Admin* set_Admin(); //set_Admin(Master* master)
void check_menu(); //Master* check_menu()


#endif