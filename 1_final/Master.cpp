#include "Master.h"

Master::Master() {}
void Master::set_password(int password) { this->password = password; }
void Master::set_perchase(int money) { this->purchase = money; }
void Master::set_income(int money) { this->income = money; }

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
			if (tag.compare("password"))
				master->set_password(stoi(tokens[1]));
			else if (tag.compare("purchase"))
				master->set_perchase(stoi(tokens[1]));
			else if (tag.compare("income"))
				master->set_income(stoi(tokens[1]));
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

Master* check_menu(Master* master, Material* ingredient, Recipe* recipe) {
	int menu_num=Recipe::num;
	int i;


}