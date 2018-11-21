#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>
#include "Master.h"

using namespace std;

class Admin { 
	string* menu;
	int *possible;
	int *amount;
	int *price;
	int num;
	int income;
public:
	Admin(int max=10);
	~Admin();
	void set_menu(string name, int money, int val,int num, int index);
	void print_menu();
	void set_num(int val);
	void save_income(int val);
	int get_income();
	int get_amount(int index);
	int get_num();
	string get_name(int index);
	bool such_menu(string s);
	bool check_possible(string s, int val);
	int modi_amount(string s, int val);
};

void update_Admin(Admin* admin, Material* ingredient, Recipe* recipe);
void save_Admin(Admin* admin, Master* master, Material* ingredient, Recipe* recipe); //Master* check_menu()


#endif