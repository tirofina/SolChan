#include<iostream>
#include "Membership.h"
#include "Shared.h"


using namespace std;

int main() {

	Membership* Member;
	Member = fopen_membership();

	string name;
	int point;
	string password;

	int num = Membership::num;
	cout << num << endl;
	
	cout << "write ur name" << endl;
	cin >> name;
	cout << "write ur point" << endl;
	cin >> point;
	cout << "write ur password" << endl;
	cin >> password;


	Member=create_membership(Member, name, point, password);

	num = Membership::num;
	for (int i = 0; i < num; i++) {
		cout<<i<<" member is "<<Member[i].get_name()<<endl;
	}
	cout << "member total number is " << num << endl;

	Material* ingredient;
	ingredient = fopen_Material();

	string material_name;
	int material_price;
	int material_amount;

	cout << "write ingredient name" << endl;
	cin >> material_name;
	cout << "write ingredient price" << endl;
	cin >> material_price;
	cout << "write ingredient amount" << endl;
	cin >> material_amount;

	ingredient->set_material(material_name, material_price, material_amount);
	ingredient->print_material();

	fclose_membership(Member);


	char buffer;
	cin >> buffer;

	return 0;
}