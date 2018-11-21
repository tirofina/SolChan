#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "Admin.h"
#include "Membership.h"

using namespace std;

class Cart {
	int order_num;
	string* name;
	int* num;
	int income;
public:
	Cart();
	void add_cart(string s, int n,int money);
	void print_cart();
	int get_income();
};

void start_customer(Admin* admin,Membership* member);
#endif CUSTOMER_H