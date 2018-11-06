//Recipe_order.h

#ifndef RECIPE_ORDER_H
#define RECIPE_ORDER_H

#include <string>
using namespace std;

class Recipe_order {
   string recipe_name;

public:
   Recipe_order(string recipe_name);
   int set_ingr(); // Set Number of ingredients in order list
   int add_ingr(); // Add Number of ingredients
   int pay_ingr(); // Pay money for ordering ingredients

};

#endif