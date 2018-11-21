#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Material {
	string *material_name;
	int *material_price;
	int *material_amount;
	int num;
	int max;
public:
	Material();
	~Material();
	void set_material(string name, int price, int amount); //set and add meterial
	bool check_material(string name);
	int name_price(string name);
	void replace_material(string name, int val);
	void modi_material(string name, int val); // for modification meterial
	int get_num();
	int get_amount(int index);
	int get_price(int index);
	string get_name(int inedx);
};

Material* fopen_Material();
void fclose_Material(Material* ingredient);

#endif