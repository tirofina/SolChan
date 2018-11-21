#pragma once
#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Recipe { 
	string name;
	int price;
	string ingredient_name;
	int ingredient_num;
	int time;
public:
	Recipe();
	~Recipe();
	void set_recipe(string name, int price, string ingredient_name, int ingredient_num, int time);
	string get_name();
	int get_price(); //point_increase
	string get_ingredient_name();
	int get_ingredient_num();
	int get_time();
	static int num;
	static int max;
};

Recipe* fopen_recipe();
void fclose_recipe(Recipe* recipe);
Recipe* create_recipe(Recipe* recipe, string name, int price, string ingredient_name, int ingredient_num, int time);


#endif