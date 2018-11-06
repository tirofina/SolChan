#include"Master.h"
#include"Shared.h"

Master::Master() {}
int Master::input_pw() {}
void Master::set_pw(int pw) {}
void Master::check_pw(int pw, int input_pw) {}

Material::Material() {}
void Material::set_meterial(string name, int price, int amount) {} 
void Material::order_meterial(string name, int amount) {} 
void Material::print_meterial() {} 

int Purchase::get_revenue() {}
int Purchase::get_cost() {}
void Purchase::set_revenue(int price) {}
void Purchase::set_cost(int price) {}
int Purchase::calculation_income() {}

void Menu::set_need(int ingredient, string name, int num);
int Menu::get_price();