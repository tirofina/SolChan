//Net_profit.h

#ifndef NET_PROFIT_H
#define NET_PROFIT_H

#include <string>
using namespace std;

class Net_profit {
   string recipe_name;

public:
   Net_profit(string recipe_name);
   int add_sales(); // Sales
   int pay_order_cost(); // Pay for ordering ingredients
   int net_profit(int a, int b); // Net profit

};

#endif