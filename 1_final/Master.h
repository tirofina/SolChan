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
	void set_purchase(int money);
	void set_income(int money);
	void set_expense(int money);
	void add_expense(int money);
	void add_income(int money);
	bool check_password(string input);
	string get_password();
	int get_purchase();
	int get_expense();
	int get_income();

};

Master* fopen_master();
void check_menu(Material* ingredient, Recipe* recipe);
void order_ingredient(Master* master, Material* ingredient);
void check_ingredient(Material* ingredient);
void start_master(Master* master, Material* ingredient, Recipe* recipe);
void fclose_master(Master* master);
#endif