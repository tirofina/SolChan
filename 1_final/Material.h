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

Material* fopen_Material();
void fclose_Material(Material* ingredient);

#endif