#include "Shared.h"

Menu::Menu(string name, int price, int time) {}
void Menu::set_need(int ingredient, string name, int num) {}
int Menu::get_price() {}
string Menu::get_name() {}
int Menu::check_metreial(Material& m) {} //order possible return 1,impossible return 0;

Material::Material() {}
void Material::set_meterial(string name, int price, int amount) {} //set and add meterial
void Material::order_meterial(string name, int amount) {} // for order_meterial
void Material::print_meterial() {} // print your current meterials
int Material::get_amount(string name) {}
int Material::get_num() {}

int Purchase::get_revenue() {}
int Purchase::get_cost() {}
void Purchase::set_revenue(int price) {}
void Purchase::set_cost(int price) {}
int Purchase::calculation_income() {}

void fopen_shared() {} //Menu,meterial fread 
void fclose_shared() {} //Menu,meterial fwrite