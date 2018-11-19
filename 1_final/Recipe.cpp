#include "Recipe.h"


Recipe::Recipe() {}
Recipe::~Recipe() { num--; }
void Recipe::set_recipe(string name, int price, string ingredient_name, int ingredient_num, int time) {
	this->name = name;
	this->price = price;
	this->ingredient_name = ingredient_name;
	this->ingredient_num = ingredient_num;
	this->time = time;
}
string Recipe::get_name() { return name; }
int Recipe::get_price() { return price; }
string Recipe::get_ingredient_name() { return ingredient_name; }
int Recipe::get_ingredient_num() { return ingredient_num; }
int Recipe::get_time() { return time; }
int Recipe::num=0;
int Recipe::max=5;

Recipe* fopen_recipe() {
	string filePath = "Recipe.txt";
	int i=0;
	int max = Recipe::max;
	Recipe* recipe = new Recipe[max];

	ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		string line;
		string buf;
		vector<string> tokens;
		tokens.reserve(5);

		while (getline(openFile, line)) {
			stringstream  ss(line);
			while (ss >> buf)
				tokens.push_back(buf);

			if (i == max) {
				Recipe* recipe2 = new Recipe[max * 2];

				for (int k = 0; k < max; k++) {
					recipe2[k].set_recipe(recipe[k].get_name(), recipe[k].get_price(), recipe[k].get_ingredient_name(), recipe[k].get_ingredient_num(), recipe[k].get_time());
				}
				delete[] recipe;
				max = max * 2;
				Recipe::max = max;
				recipe = recipe2;
			}
			recipe[i].set_recipe(tokens[0],stoi(tokens[1]),tokens[2],stoi(tokens[3]),stoi(tokens[4]));
			Recipe::num++;
			i++;

			tokens.clear();
		}
		openFile.close();
		return recipe;
	}
	else {
		cout << "Recipe flie open error" << endl;
		return NULL;
	}
}

Recipe* create_recipe(Recipe* recipe, string name, int price, string ingredient_name, int ingredient_num, int time) {
	int num = Recipe::num;
	int max = Recipe::max;

	if (num == max) {
		Recipe* recipe2 = new Recipe[max * 2];

		for (int k = 0; k < max; k++) {
			recipe2[k].set_recipe(recipe[k].get_name(), recipe[k].get_price(), recipe[k].get_ingredient_name(), recipe[k].get_ingredient_num(), recipe[k].get_time());
		}
		delete[] recipe;
		max = max * 2;
		Recipe::max = max;
		recipe = recipe2;
	}

	recipe[num].set_recipe(name, price, ingredient_name, ingredient_num, time);
	Recipe::num++;

	return recipe;
}

void fclose_recipe(Recipe* recipe) {
	string filePath = "Recipe.txt";
	ofstream writeFile(filePath.data());
	int i;
	int num = Recipe::num;

	if (writeFile.is_open()) {
		for (i = 0; i < num; i++) {
			writeFile << recipe[i].get_name() << " " << recipe[i].get_price() << " " << recipe[i].get_ingredient_name() << " " << recipe[i].get_ingredient_num() << " " << recipe[i].get_time();
			writeFile << "\n";
		}
		writeFile.close();
		delete[] recipe;
	}
	else {
		cout << "Recipe flie open error" << endl;
	}
}
