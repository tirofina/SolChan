#ifndef SHARED_H
#define SHARED_H

#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Material;

class Recipe {
	string menu_name;
	int menu_price;
	int menu_time; // for time
	string *need_name;
	int *need_num;
	int ingredient_num;
public:
	Recipe();
	Recipe(string name, int price, int time);
	void set_need(int ingredient, string name, int num);
	int get_price();
	int set_price();
	int set_time(); // for time
	//int check_metreial(Material& m); //order possible return 1,impossible return 0; 
	static int menu_num;
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
	void order_material(string name, int amount); // for order_meterial
	void print_material(); // print your current meterials
	int get_amount(string name);
	int get_num();
	string get_name(int i);
	//friend Menu;
};

Recipe* fopen_Menu(Recipe* m, int &menu_index); //Menu fread
Material* fopen_Material();

void fclose_Menu(); //Menu,meterial fwrite
void fclose_Material(Material* ingredient);

#endif