#include "Material.h"

Material::Material() {
	material_name=new string[5];
	material_price=new int[5];
	material_amount=new int[5];
	num = 0;
	max = 5;
}
Material::~Material() {
	if (material_name)
		delete[] material_name;
	if (material_price)
		delete[] material_price;
	if (material_amount)
		delete[] material_amount;
}
void Material::set_material(string name, int price, int amount) {
	if (num == max) {
		string *material_name2 = new string[max*2];
		int *material_price2 = new int[max*2];
		int *material_amount2 = new int[max*2];
		for (int i = 0; i < num; i++) {
			material_name2[i] = material_name[i];
			material_price2[i] = material_price[i];
			material_amount2[i] = material_amount[i];
		}
		delete[] material_name;
		delete[] material_price;
		delete[] material_amount;
		material_name = material_name2;
		material_price = material_price2;
		material_amount = material_amount2;

		max *= 2;
	}
	material_name[num] = name;
	material_price[num] = price;
	material_amount[num] = amount;
	num++;

} //set and add material
void Material::modi_material(string name, int val) {
	
} // for order_material
void Material::print_material() { 
	for (int i = 0; i < num; i++) {
		cout << "ingredient name is " << material_name[i] << "\n";
	}
} // print your current materials
int Material::get_num() { return num; }
int Material::get_amount(int index) { return material_amount[index]; }
int Material::get_price(int index) { return material_price[index]; }
string Material::get_name(int index) { return material_name[index]; }


Material* fopen_Material() {
	string filePath = "Material.txt";

	ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		string line;
		string buf;
		vector<string> tokens;
		tokens.reserve(3);

		Material* ingredients=new Material;

		while (getline(openFile, line)) {
			stringstream ss(line);
			while (ss >> buf)
				tokens.push_back(buf);

			if (tokens.size() == 3) {
				ingredients->set_material(tokens[0], stoi(tokens[1]), stoi(tokens[2]));
			}
			else {
				cout << "tokens error in Material" << endl;
			}
			tokens.clear();
		}
		openFile.close();
		return ingredients;
	}
	else {
		cout << "Material flie open error" << endl;
		return NULL;
	}
}



void fclose_Material(Material* ingredient) {
	string filePath = "Material.txt";
	ofstream writeFile(filePath.data());
	int i;
	int num = ingredient->get_num();
	if (writeFile.is_open()) {
		for (i = 0; i < num; i++) {
			writeFile << ingredient->get_name(i) << " " <<ingredient->get_price(i) << " " << ingredient->get_amount(i);
			writeFile << "\n";
		}
		writeFile.close();
		delete ingredient;
	}
	else {
		cout << "Material flie open error" << endl;
	}
}
