#include "Admin.h"

Admin::Admin(int max) { menu = new string[max]; possible = new int[max]; price = new int[max]; amount = new int[max]; } //Need to supplement later
Admin::~Admin() { 
	if (menu)
		delete[] menu;
	if (possible)
		delete[] possible;
	if (price)
		delete[] price;
	int income = 0;
}
void Admin::print_menu() { //interface intergration need
	cout << '\n' << "-------------------- MENU --------------------" << '\n';
	for (int i = 0; i < num; i++) {
		cout << '\t' << menu[i] << '\t' << '\t' << price[i] << '\n';
	}
	cout << "----------------------------------------------" << '\n';
}
void Admin::set_menu(string name, int money, int val,int num, int index) {
	menu[index] = name;
	price[index] = money;
	possible[index] = val;
	amount[index] = num;
}
void Admin::set_num(int val) { num = val; }
void Admin::save_income(int val) { income += val; }
int Admin::get_income() { return income; }
int Admin::get_amount(int index) { return amount[index]; }
int Admin::get_num() { return num; }
string Admin::get_name(int index) { return menu[index]; }
bool Admin::such_menu(string s) { 
	int i = 0;
	for (i = 0; i < num; i++) {
		if (!s.compare(menu[i]))
			return true;
	}
	return false;
}
bool Admin::check_possible(string s, int val) {
	int i = 0;
	for (i = 0; i < num; i++) {
		if (!s.compare(menu[i])) {
			if ((amount[i]/possible[i]) >= (val*possible[i])) {
				amount[i] -= val * possible[i];
				return true;
			}
		}
	}
	return false;
}
int Admin::modi_amount(string s, int val) {
	int i = 0;
	int amount;
	for (i = 0; i < num; i++) {
		if (!s.compare(menu[i])) {
			amount = price[i] * val;
			return amount;
		}
	}
	return 0;
}

void update_Admin(Admin* admin, Material* ingredient, Recipe* recipe) {
	int menu_num = Recipe::num;
	int i, j, k = 0;
	string ingredient_name;
	int ingredient_num;
	int value;

	for (i = 0; i < menu_num; i++) {
		ingredient_name = recipe[i].get_ingredient_name();
		ingredient_num = recipe[i].get_ingredient_num();
		for (j = 0; j < ingredient->get_num(); j++) {
			if (!ingredient_name.compare(ingredient->get_name(j))) {
				if (ingredient_num <= ingredient->get_amount(j)) {
					value = ingredient->get_amount(j);
					admin->set_menu(recipe[i].get_name(), recipe[i].get_price(), ingredient_num, value, k);
					k++;
					break;
				}
			}
		}
	}
	admin->set_num(k);
} 
void save_Admin(Admin* admin,Master* master, Material* ingredient, Recipe* recipe) {
	int menu_num = Recipe::num;
	int num=admin->get_num();
	int val;
	string ad_name;
	string ingredient_name;

	for (int i = 0; i < num; i++) {
		val = admin->get_amount(i);
		ad_name = admin->get_name(i);
		for (int j = 0; j < menu_num; j++) {
			if (!ad_name.compare(recipe[i].get_name())) {
				ingredient_name = recipe[i].get_ingredient_name();
			}
		}
		ingredient->replace_material(ingredient_name, val);
	}
	int income = admin->get_income();
	master->add_income(income);
}