//Shared.h

#ifndef SHARED_H
#define SHARED_H

#include <stdio.h>
#include <string>

using namespace std;

class Menu {
	string *menu_name;
	int *menu_price;
	int *menu_time;
	int menu_num;
public:
	Menu();
	void add_menu(Material& M); // friend Declaration need
	void delete_menu(); // for delete_menu
	void print_menu(); // for print_menu
	void get_menu(); // for get_menu
	int pay_menu(int i, int num); // i is menu name
};

class Material {
	string *material_name;
	int *meterial_price;
	int *meterial_amount;
	int meterial_num;
public:
	Material();
	void add_meterial(); // for add_menu
	void delete_meterial(); // for delete_meterial
	void order_meterial(); // for order_meterial
	void print_meterial(); // print your current meterials
};

class Purchase {

};

// Edited 2018,11,06,16,44
class Net_profit {
	string *net_profit;

public:
	Net_profit();
	int add_sales(); // for computing Sales
	int pay_order_cost(); // Pay for ordering ingredients
	int net_profit(int a, int b); // for computing Net profit
};
	



void fopen_shared();
void fclose_shared();
void order_meterial(Purchase& purchase);

#endifd