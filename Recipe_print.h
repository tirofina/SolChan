//Recipe_print.h

#ifndef RECIPE_PRINT_H
#define RECIPE_PRINT_H

#include <string>
using namespace std;

class Recipe_print {
   string recipe_name;
   int beans;
   int water;
   int ingredient;
public:
   Recipe_print(string recipe_name); // Print your current Cooking ingredients
};

#endif