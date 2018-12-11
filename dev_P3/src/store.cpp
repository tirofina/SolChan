#include "store.h"

Store::Store()
{
    Ingredient i_water("water", 2, 1000);
    Ingredient i_bean("beans", 1, 2000);
    _ingredient_v.push_back(i_water);
    _ingredient_v.push_back(i_bean);

    req_t req;
    Coffee c_americano("Americano", 5000);
    req.ingredient = i_water;
    req.amount = 1;
    c_americano.setRequirement(req);
    req.ingredient = i_bean;
    req.amount = 1;
    c_americano.setRequirement(req);

    Coffee c_water("Water", 2000);
    req.ingredient = i_water;
    req.amount = 1;
    c_water.setRequirement(req);

    _coffee_v.push_back(c_americano);
    _coffee_v.push_back(c_water);

    _money = 10000;
    _sales = 0;
    _for_Net_Profit = 0;
}

std::string Store::makeMenu()
{
    std::string menu("***menu***\n");
    int cnt = 0;
    for (int i = 0; i < _coffee_v.size(); i++)
    {
        Coffee c = _coffee_v[i];
        if (isAvailable(c))
        {
            menu += std::to_string(++cnt);
            menu += (". " + c.getName());
            menu += (":\t\tprice: " + std::to_string(c.getPrice()));
            menu += "\n";
        }
    }
    menu += "****************";

    return menu;
}

bool Store::isAvailable(const Coffee &c)
{
    for (int i = 0; i < c._required_ingredient_v.size(); i++)
    {
        req_t req = c._required_ingredient_v[i];
        for (int j = 0; j < _ingredient_v.size(); j++)
        {
            Ingredient ingre = _ingredient_v[j];
            if (req.ingredient.getName() == ingre.getName())
            {
                if (req.amount > ingre.getAmount())
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

bool Store::isExist(std::string name)
{
    for (int i = 0; i < _membership_v.size(); i++)
    {
        if (_membership_v[i].getName() == name)
            return 1;
    }
    return 0;
}

int Store::take_order(std::string coffee)
{
    for (int i = 0; i < _coffee_v.size(); i++)
    {
        Coffee c = _coffee_v[i];
        if (coffee == c.getName())
        {
            _sales += c.getPrice();
			inc_money(c.getPrice());

            for (int j = 0; j < c._required_ingredient_v.size(); j++)
            {
                req_t req_i = c._required_ingredient_v[j];
                for (int k = 0; k < _ingredient_v.size(); k++)
                {
                    Ingredient ingredient = _ingredient_v[k];
                    if (req_i.ingredient.getName() == ingredient.getName())
                    {
                        _ingredient_v[k].dec(req_i.amount);
                    }
                }
            }
            break;
        }
    }
}

int Store::take_order(std::string coffee, std::string name)
{
    int point = 0;
    for (int i = 0; i < _coffee_v.size(); i++)
    {
        Coffee c = _coffee_v[i];
        if (coffee == c.getName())
        {
            _sales += c.getPrice();
			inc_money(c.getPrice());
            point = c.getPrice() / 10;
            for (int j = 0; j < c._required_ingredient_v.size(); j++)
            {
                req_t req_i = c._required_ingredient_v[j];
                for (int k = 0; k < _ingredient_v.size(); k++)
                {
                    Ingredient ingredient = _ingredient_v[k];
                    if (req_i.ingredient.getName() == ingredient.getName())
                    {
                        _ingredient_v[k].dec(req_i.amount);
                    }
                }
            }
            break;
        }
    }

    for (int k = 0; k < _membership_v.size(); k++)
    {
        if (name == _membership_v[k].getName())
        {
            _membership_v[k].inc(point);
            break;
        }
    }
}

int Store::take_order(std::string coffee, std::string name, int point)
{
	bool point_flag = false;
	for (int k = 0; k < _membership_v.size(); k++)
	{
		if (name == _membership_v[k].getName())
		{
			if (_membership_v[k].getPoint() >= point) {
				_membership_v[k].dec(point);
				point_flag = true;
			}
			break;
		}
	}

    for (int i = 0; i < _coffee_v.size(); i++)
    {
        Coffee c = _coffee_v[i];
        if (coffee == c.getName())
        {
			if (point_flag) {
				_sales += (c.getPrice() - point);
				inc_money(c.getPrice() - point);
			}
			else {
				_sales += c.getPrice();
				inc_money(c.getPrice());
			}

            for (int j = 0; j < c._required_ingredient_v.size(); j++)
            {
                req_t req_i = c._required_ingredient_v[j];
                for (int k = 0; k < _ingredient_v.size(); k++)
                {
                    Ingredient ingredient = _ingredient_v[k];
                    if (req_i.ingredient.getName() == ingredient.getName())
                    {
                        _ingredient_v[k].dec(req_i.amount);
                    }
                }
            }
            break;
        }
    }

}
void Store::printAllIngredients()
{
    std::cout << "Remaining Ingredients" << std::endl;
    for (int i = 0; i < _ingredient_v.size(); i++)
    {
        std::cout << i + 1 << ". " << _ingredient_v[i].getName() << ": " << _ingredient_v[i].getAmount() << std::endl;
    }
}

void Store::printMember()
{
    std::cout << "Check Member" << std::endl;
    for (int i = 0; i < _membership_v.size(); i++)
    {
        std::cout << _membership_v[i].getName() << ": " << _membership_v[i].getPoint() << std::endl;
    }
}

void Store::createMember(std::string name, std::string password)
{
    Membership m_new(name, 0, password);
    _membership_v.push_back(m_new);
}

void Store::createMenu()
{
    std::string c_name;
    std::cout << "Input new Menu name" << std::endl;
    std::cin >> c_name;

    int c_price;
    std::cout << "Input new Menu price" << std::endl;
    std::cin >> c_price;

    std::string i_name;
    int i_amount;
    int j;
    std::cout << "Input the number of ingredient required" << std::endl;
    std::cin >> j;

    req_t req;
    Coffee c_new(c_name, c_price);

    int k = 0;
    for (int i = 0; i < j; i++)
    {
        std::cout << "Input need ingredient name (" << i << ")" << std::endl;
        std::cin >> i_name;
        std::cout << "Input need ingredient amount(" << i << ")" << std::endl;
        std::cin >> i_amount;
        for (k = 0; k < _ingredient_v.size(); k++)
        {
            if (_ingredient_v[k].getName() == i_name)
            {
                req.ingredient = _ingredient_v[k];
                break;
            }
        }
        if (k == _ingredient_v.size())
        {
            int i_price = 0;
            std::cout << "Input new ingredient price" << std::endl;
            std::cin >> i_price;
            Ingredient i_new(i_name, 0, i_price);
            _ingredient_v.push_back(i_new);
            req.ingredient = i_new;
        }
        req.amount = i_amount;
        c_new.setRequirement(req);
    }

    _coffee_v.push_back(c_new);

    std::cout << "createMenu completed!" << std::endl;
}

int Store::getMemberP(std::string name)
{
    for (int k = 0; k < _membership_v.size(); k++)
    {
        if (name == _membership_v[k].getName())
        {
            return _membership_v[k].getPoint();
        }
    }

    return -1;
}

bool Store::iscorrect(std::string name, std::string password)
{
    for (int k = 0; k < _membership_v.size(); k++)
    {
        if (name == _membership_v[k].getName())
        {
            if (password == _membership_v[k].getPassword())
            {
                return 1;
            }
        }
    }
    return 0;
}

void Store::PurchaseIngredients()
{

    int Purchase;
    std::cin >> Purchase;
    int numPurchase = 0;
    int sumPurchase = 0;

    std::cout << "How many would you want to Purchase? ";
    std::cin >> numPurchase;

    sumPurchase = _ingredient_v[Purchase - 1].increaseAmount(numPurchase);

    if (getmoney() > sumPurchase)
    {
        _money -= sumPurchase;

        _for_Net_Profit += sumPurchase; // 08

        _ingredient_v[Purchase - 1].increase(numPurchase);
        std::cout << "Price: " << sumPurchase << std::endl;
        
        std::cout << "Your current possession money is : " << _money << "\n";
    }
    else
    {
        std::cout << "Sorry! You don't have enough money." << std::endl;
    }
}
