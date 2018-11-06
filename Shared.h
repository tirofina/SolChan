#ifndef SHARED_H
#define SHARED_H

#include <stdio.h>
#include <string>

using namespace std;

class Material;

class Menu {
	string menu_name;
	int menu_price;
	int menu_time;
	string *need_name;
	int *need_num;
	int ingredient_num;
public:
	Menu(string name,int price,int time);
	void set_need(int ingredient, string name, int num);
	int get_price();
	string get_name();
	int check_metreial(Material& m); //order possible return 1,impossible return 0; 
};

class Material {
	string *material_name;
	int *meterial_price;
	int *meterial_amount;
	int meterial_num;
public:
	Material();
	void set_meterial(string name,int price,int amount); //set and add meterial
	void order_meterial(string name,int amount); // for order_meterial
	void print_meterial(); // print your current meterials
	int get_amount(string name);
	int get_num();
	friend Menu;
};

class Purchase {
	int revenue;
	int cost;
public:
	int get_revenue();
	int get_cost();
	void set_revenue(int price);
	void set_cost(int price);
	int calculation_income();
};


void fopen_shared(); //Menu,meterial fread 
void fclose_shared(); //Menu,meterial fwrite

#endif