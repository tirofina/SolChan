#ifndef RECIPE_H
#define RECIPE_H

#include<stdio.h>
#include <string>

using namespace std;

class Menu {
	string *menu_name;
	int *menu_price;
	int *menu_time;
	int menu_num;
public:
	Menu();
	void create_menu(Material& M);//friend Declaration need
	void delete_menu();
	void print_menu();
	void get_menu();//
	int pay_menu(int i,int num);//i is menu name
};

class Material {
	string *material_name;
	int *meterial_price;
	int *meterial_amount;
	int meterial_num;
public:
	Material();
	void create_meterial();
	void delete_meterial();
	void print_meterial();
};

class Purchase {

};

void fopen_recipe();
void fclose_recipe();
void order_meterial(Purchase& purchase);

#endif