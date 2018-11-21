#include "Master.h"


Master::Master() {}
void Master::set_password(string password) { this->password = password; }
void Master::set_purchase(int money) { this->purchase = money; }
void Master::set_income(int money) { this->income = money; }
void Master::set_expense(int money) { this->expense = money; }
void Master::add_expense(int val) { expense += val; purchase -= val; } //input positive value
void Master::add_income(int val) { income += val; purchase += val; } //input positive value
bool Master::check_password(string input) {
	if (!input.compare(password))
		return true;
	return false;
}
string Master::get_password() { return password; }
int Master::get_purchase() { return purchase; }
int Master::get_expense() { return expense; }
int Master::get_income() { return income; }

Master* fopen_master() {
	string filePath = "./res/Master.txt";

	ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		string line;
		string buf;
		vector<string> tokens;
		tokens.reserve(2);

		Master* master = new Master;

		while (getline(openFile, line)) {
			stringstream ss(line);
			while (ss >> buf)
				tokens.push_back(buf);

			string tag = tokens[0];
			if (!tag.compare("password")) {
				if (!tokens[1].compare("0")) {
					string password;
					cout << "input password>>";
					cin >> password;
					master->set_password(password);
					cout << endl << "setting password done!" << endl;
				}else
					master->set_password(tokens[1]);
			}
			else if (!tag.compare("purchase"))
				master->set_purchase(stoi(tokens[1]));
			else if (!tag.compare("income"))
				master->set_income(stoi(tokens[1]));
			else if (!tag.compare("expense"))
				master->set_expense(stoi(tokens[1]));
			else
				cout << "master file error" << endl;

			tokens.clear();
		}
		openFile.close();
		return master;
	}
	else {
		cout << "Master flie open error" << endl;
		return NULL;
	}
}

void check_menu(Material* ingredient, Recipe* recipe) {
	int menu_num = Recipe::num;
	int i, j;
	string ingredient_name;
	int ingredient_num;

	for (i = 0; i < menu_num; i++) {
		ingredient_name = recipe[i].get_ingredient_name();
		ingredient_num = recipe[i].get_ingredient_num();

		cout << recipe[i].get_name();
		for (j = 0; j < ingredient->get_num(); j++) {
			if (!ingredient_name.compare(ingredient->get_name(j))) {
				if (ingredient_num <= ingredient->get_amount(j)) {
					cout << " (available)" << endl;
				}
				else {
					cout << " (not available)" << endl;
				}
			}
		}
	}
}

void order_ingredient(Master* master,Material* ingredient) {
	//modi_material use , need input negative value
	//pay add_expense use, need input positive value  
	//show order ingredient state

	int menu_num = ingredient->get_num();
	string ingredient_name;
	
	cout << "Please enter a menu of materials to add" << "\n";
	      
	cout << "----------- Current Materials List -----------" << "\n";
	for (int i = 0; i < menu_num; i++) {
		cout << "name: " << ingredient->get_name(i) << " / amount:";
		cout << ingredient->get_amount(i) << "\n";
	}
	cout << "-----------------------------------------------" << '\n';

	cout << "Enter name of material to add >> ";
	string input_ingredient_name;
	cin >> input_ingredient_name;

	int expense;
	if (ingredient->check_material(input_ingredient_name)) {
		int input_ingredient_amount = 0;
		cout << "Please enter the desired number >> ";
		cin >> input_ingredient_amount;

		expense=ingredient->name_price(input_ingredient_name)*input_ingredient_amount;
		if (master->get_purchase() >= expense) {
			char pay_flag;
			cout << "Would you like to pay? (Y/N)" << '\n';
			cin >> pay_flag;
			if (pay_flag == 'Y') {
				ingredient->modi_material(input_ingredient_name, input_ingredient_amount);
				master->add_expense(expense);
				cout << "payment complete." << '\n';
			}
		}
		else {
			cout << "don't have enough money." << '\n';
		}
	}
	else {
		cout << "It's a wrong approach." << '\n';
	}
}

void check_ingredient(Material* ingredient) {
	//get_name, get_amount use
	int menu_num = ingredient->get_num();
	cout << '\n' << "-------------------- INGREDIENT --------------------" << '\n';
	for (int i = 0; i < menu_num; i++) {
		cout  << ingredient->get_name(i) << '\t' << ingredient->get_amount(i) << '\n';
	}
	cout << "----------------------------------------------------" << '\n';
}

void add_recipe(Recipe* recipe) {
	string input_recipe_name;
	int input_recipe_price;
	string input_need_ingredient_name;
	int input_need_ingredient_num;
	int input_time;

	cout << "Enter the name of the drink you want to add" << '\n' << ">>";
	cin >> input_recipe_name;
	cout << "Enter the price of the drink you want to add" << '\n' << ">>";
	cin >> input_recipe_price;
	cout << "Enter the required ingredient name" << '\n' << ">>";
	cin >> input_need_ingredient_name;
	cout << "Enter the number of ingredient required" << '\n' << ">>";
	cin >> input_need_ingredient_num;
	cout << "Enter the time it takes to make a drink" << '\n' << ">>";
	cin >> input_time;

	char add_check_flag;
	cout << '\n' <<"name: "<< input_recipe_name << " price: " << input_recipe_price << '\n';
	cout<< input_need_ingredient_name << " " << input_need_ingredient_num << '\n' << input_time << "sec" << '\n';
	cout << "Please make sure it's the drink recipe you want to add. (Y/N)" << '\n';
	cin >> add_check_flag;

	if (add_check_flag == 'Y') {
		recipe = create_recipe(recipe, input_recipe_name, input_recipe_price, input_need_ingredient_name, input_need_ingredient_num, input_time);
		cout << "Add successful!! " << '\n';
	}
	else {
		cout << "Add falied" << '\n';
	}
}

void add_ingredient(Material* ingredient) {

	string material_name;
	int material_price;
	int material_amount=0;

	cout << "Enter the ingredient name, you want to add" << '\n' << ">>";
	cin >> material_name;
	cout << "Enter the ingredient price" << '\n' << ">>";
	cin >> material_price;


	char add_check_flag;
	cout << '\n' << "name: " << material_name << " price: " << material_price << '\n';
	cout << "Please make sure it's the drink recipe you want to add. (Y/N)" << '\n';
	cin >> add_check_flag;

	if (add_check_flag == 'Y') {
		ingredient->set_material(material_name, material_price, material_amount);
		cout << "Add successful!! " << '\n';
	}
	else {
		cout << "Add falied" << '\n';
	}
}

void start_master(Master* master, Material* ingredient, Recipe* recipe) {
	string input_password;
	cout << "Please enter a password" << '\n' << ">>";
	cin >> input_password;

	if (master->check_password(input_password)) {
		int master_flag=0;
		while (true) {
			cout << '\n' << "------------------ Welcome Master ------------------" << '\n';
			cout <<  "1) " << '\t' << "ingredient check" << '\n';
			cout <<  "2) " << '\t' << "ordering ingredient" << '\n';
			cout <<  "3) " << '\t' << "Makeable drink check" << '\n';
			cout <<  "4) " << '\t' << "Sales and net income check" << '\n';
			cout <<  "5) " << '\t' << "Add Recipe" << '\n';
			cout <<  "6) " << '\t' << "Add ingredient type" << '\n';
			cout <<  "7) " << '\t' << "Quit master mode" << '\n';
			cout << "----------------------------------------------------" << '\n';

			int system_flag;
			cout << "Please select number" << '\n' << ">>";
			cin >> system_flag;

			string quit_flag;
			switch (system_flag) {
			case 1:
				check_ingredient(ingredient);
				cout << '\n' << "if you want quit, enter any key";
				cin >> quit_flag;
				break;
			case 2:
				order_ingredient(master, ingredient);
				cout << '\n' << "if you want quit, enter any key";
				cin >> quit_flag;
				break;
			case 3:
				check_menu(ingredient, recipe);
				cout << '\n' << "if you want quit, enter any key";
				cin >> quit_flag;
				break;
			case 4:
				cout << '\n' << "------------------- Current Purchase -------------------" << '\n';
				cout << '\t' << "Sales:" << '\t' << master->get_income() << '\n';
				cout << '\t' << "net income:" << '\t' << master->get_income() - master->get_expense() << '\n';
				cout << "--------------------------------------------------------" << '\n';
				cout << '\n' << "if you want quit, enter any key";
				cin >> quit_flag;
				break;
			case 5:
				add_recipe(recipe);
				cout << '\n' << "if you want quit, enter any key";
				cin >> quit_flag;
				break;
			case 6:
				add_ingredient(ingredient);
				cout << '\n' << "if you want quit, enter any key";
				cin >> quit_flag;
				break;
			case 7:
				master_flag++;
				break;
			default:
				cout << "It's a wrong approach." << '\n';
			}
			if (master_flag == 1)
				break;
		}
	
	}
	else {
		cout << "Incorrect password." << '\n';
	}
}

void fclose_master(Master* master) {
	string filePath = "./res/Master.txt";
	ofstream writeFile(filePath.data());
	if (writeFile.is_open()) {
		writeFile << "password " << master->get_password() << "\n";
		writeFile << "purchase " << master->get_purchase() << "\n";
		writeFile << "income " << master->get_income() << "\n";
		writeFile << "expense " << master->get_expense() << "\n";

		writeFile.close();
		delete master;
	}
	else {
		cout << "Master flie open error" << endl;
	}
}
