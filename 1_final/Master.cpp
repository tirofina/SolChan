#include "Master.h"

Master::Master() {}
void Master::set_password(string password) { this->password = password; }
void Master::set_perchase(int money) { this->purchase = money; }
void Master::set_income(int money) { this->income = money; }
void Master::set_expense(int money) { this->expense = money; }
bool Master::check_password(string input) {
	if (!input.compare(password))
		return true;
	return false;
}

Master* fopen_master() {
	string filePath = "Master.txt";

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
				if (stoi(tokens[1]) == 0) {
					string password;
					cout << "input password>>";
					cin >> password;
					master->set_password(password);
					cout << endl << "setting password done!" << endl;
				}else
					master->set_password(tokens[1]);
			}
			else if (!tag.compare("purchase"))
				master->set_perchase(stoi(tokens[1]));
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
	int i,j;
	string ingredient_name;
	int ingredient_num;

	for (i = 0; i < menu_num; i++) {
		ingredient_name = recipe[i].get_ingredient_name();
		ingredient_num = recipe[i].get_ingredient_num();
		cout << i + 1 << ". " << recipe[i].get_name();
		for (j = 0; j < ingredient->get_num(); j++) {
			if (!ingredient_name.compare(ingredient->get_name(j))) {
				if (ingredient_num <= ingredient->get_amount(j)) {
					cout << " (available)" << endl;
					break;
				}
			}
			cout << " (not available)" << endl;
		}
	}

}

void order_ingredient(Material* ingredient) {
	//modi_material use
	//show order ingredient state
}

void check_ingredient(Material* ingredient) {
	//get_name, get_amount use
}

void start_master(Master* master, Material* ingredient, Recipe* recipe) {

}

