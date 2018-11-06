#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "Shared.h"
#include "Membership.h"

using namespace std;

void start_customer(Menu& menu,int menu_index,Material& material,Purchase& purchase,Membership& member,int member_index);

#endif