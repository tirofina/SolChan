#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include <iostream>

class Ingredient
{
  public:
	Ingredient()
	{
		Ingredient("", 0, 0);
	};
	Ingredient(std::string name, int amount, int price) : _name(name), _amount(amount), _price(price){};
	~Ingredient(){};

  public:
	std::string getName() { return _name; };
	int getAmount() { return _amount; };
	void dec(int delta) { _amount -= delta; };

	// for increaseAmount
	int increaseAmount(int numPurchase)
	{
		int sumPurchase = 0;
		sumPurchase = (_price)*numPurchase;
		return sumPurchase;
	};

	int increase(int numPurchase)
	{
		_amount += numPurchase;
	};

  private:
	int getPrice() { return _price; };

  private:
	std::string _name;
	int _amount;
	int _price;
};

typedef struct Req
{
	Ingredient ingredient;
	int amount;
} req_t;

class Coffee
{
  public:
	Coffee(std::string name, int price) : _name(name), _price(price){};
	~Coffee(){};
	std::vector<req_t> _required_ingredient_v;

  public:
	void setRequirement(req_t req) { _required_ingredient_v.push_back(req); }
	std::string getName() { return _name; };
	int getPrice() { return _price; };

  private:
	std::string _name;
	int _price;
};

class Store
{
  public:
	Store();
	~Store(){};

  public:
	void createMenu();
	std::string makeMenu();
	int getmoney() { return _money; };
	int getSales() { return _sales; };
	int take_order(std::string coffee);
	void PurchaseIngredients();
	void printAllIngredients();

  private:
	bool isAvailable(const Coffee &c);

  private:
	std::vector<Coffee> _coffee_v;
	std::vector<Ingredient> _ingredient_v;

	int _money;
	int _sales;
};

#endif
