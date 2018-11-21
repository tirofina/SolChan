#include<iostream>
#include "Membership.h"
#include "Material.h"
#include "Recipe.h"
#include "Admin.h"
#include "Customer.h"

using namespace std;

void sample_Membership() {
	Membership* Member;
	Member = fopen_membership();

	string name;
	int point;
	string password;

	int num = Membership::num;
	cout << num << endl;

	cout << "write ur name" << endl;
	cin >> name;
	cout << "write ur point" << endl;
	cin >> point;
	cout << "write ur password" << endl;
	cin >> password;


	Member = create_membership(Member, name, point, password);

	num = Membership::num;
	for (int i = 0; i < num; i++) {
		cout << i << " member is " << Member[i].get_name() << endl;
	}
	cout << "member total number is " << num << endl;

	fclose_membership(Member);
}

void sample_Material() {

	Material* ingredient;
	ingredient = fopen_Material();

	string material_name;
	int material_price;
	int material_amount;

	cout << "write ingredient name" << endl;
	cin >> material_name;
	cout << "write ingredient price" << endl;
	cin >> material_price;
	cout << "write ingredient amount" << endl;
	cin >> material_amount;

	ingredient->set_material(material_name, material_price, material_amount);

	fclose_Material(ingredient);
}

void sample_Recipe() {
	Recipe* recipe;
	recipe = fopen_recipe();

	string name;
	int price;
	string ingredient_name;
	int ingredient_num;
	int time;

	int num = Recipe::num;
	cout << num << endl;

	cout << "write recipe name" << endl;
	cin >> name;
	cout << "write recipe price" << endl;
	cin >> price;
	cout << "write recipe ingredient name" << endl;
	cin >> ingredient_name;
	cout << "write recipe ingredient num" << endl;
	cin >> ingredient_num;
	cout << "write recipe time" << endl;
	cin >> time;


	recipe = create_recipe(recipe, name, price, ingredient_name, ingredient_num, time);

	num = Recipe::num;
	for (int i = 0; i < num; i++) {
		cout << i << " recipe name is " << recipe[i].get_name() << endl;
	}
	cout << "recipe total number is " << num << endl;

	fclose_recipe(recipe);
}


int main() {

	//sample_Membership();
	//sample_Recipe();
	//sample_Material();

	Membership* member;
	member = fopen_membership();
	Material* ingredient;
	ingredient = fopen_Material();
	Recipe* recipe;
	Master* master;
	master = fopen_master();
	recipe = fopen_recipe();
	Admin* admin = new Admin;
	//booting
	string mode_flag;

	while (true) {
		cout << '\n' << "-------------------- SOLCHAN --------------------" << '\n';
		cout << "Please select a mode" << '\t' << "customer/master" << '\n';
		cout << "If you want to quit, please enter the quit" << '\n';
		cout << "-------------------------------------------------" << '\n';

		cin >> mode_flag;
		if (!mode_flag.compare("customer")) {
			update_Admin(admin, ingredient, recipe);
			start_customer(admin, member);
			save_Admin(admin, master, ingredient, recipe);
		}
		else if (!mode_flag.compare("master")) {
			start_master(master, ingredient, recipe);
		}
		else if (!mode_flag.compare("quit"))
			break;
	}

	fclose_membership(member);
	fclose_recipe(recipe);
	fclose_Material(ingredient);
	fclose_master(master);

	return 0;
}