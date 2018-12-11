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

class Membership
{
  public:
	Membership()
	{
		Membership("", 0, "");
	};
	Membership(std::string name, int point, std::string password) : _name(name), _point(point), _password(password){};
	~Membership(){};

  public:
	int getPoint() { return _point; };
	std::string getPassword() { return _password; };
	std::string getName() { return _name; };
	void dec(int delta) { _point -= delta; };
	void inc(int delta) { _point += delta; };

  private:
	std::string _name;
	int _point;
	std::string _password;
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
	int getNet_Profit() { return _for_Net_Profit; }; // 06
	int getMemberP(std::string name);
	int take_order(std::string coffee);
	int take_order(std::string coffee, std::string name);
	int take_order(std::string coffee, std::string name, int point);
	void printAllIngredients();
	void createMember(std::string name, std::string password);
	void printMember();
	void PurchaseIngredients();
	bool isExist(std::string name);
	bool iscorrect(std::string name, std::string password);

  private:
	bool isAvailable(const Coffee &c);

  private:
	std::vector<Coffee> _coffee_v;
	std::vector<Ingredient> _ingredient_v;
	std::vector<Membership> _membership_v;

	int _sales;
	int _money;
	int _for_Net_Profit; // 06
};

#endif
