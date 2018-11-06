#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;

class Menu { //membership
	string *menu_name;
	int *menu_price;
	int *menu_time;
	int menu_num;
public:
	Menu();
};

#endif