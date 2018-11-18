#ifndef SHARED_H
#define SHARED_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Material;

class Recipe {
	string menu_name;
	int menu_price;
	//int menu_time; // for time
	string *need_name;
	int *need_num;
	int ingredient_num;
	int ingredient_max;
public:
	Recipe();
	~Recipe();
	void set_menu(string name, int price, int num);
	void set_need(string name, int ingredient);
	string get_name();
	int get_price();
	int set_time(); // for time
	//int check_metreial(Material& m); //order possible return 1,impossible return 0; 
	static int menu_num;
	static int menu_max;
};

class Material {
	string *material_name;
	int *material_price;
	int *material_amount;
	//int meterial_num;
	int num;
	int max;
public:
	Material();
	~Material();
	void set_material(string name, int price, int amount); //set and add meterial
	void modi_material(string name, int val); // for modification meterial
	void print_material(); // print your current meterials
	int get_num();
	int get_amount(int index);
	int get_price(int index);
	string get_name(int inedx);
	//friend Menu;
};

Recipe* fopen_Menu(Recipe* m, int &menu_index); //Menu fread
Material* fopen_Material();

void fclose_Menu(); //Menu,meterial fwrite
void fclose_Material(Material* ingredient);

bool exist_ingredient(string name);
#endif