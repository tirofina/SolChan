#include "Customer.h"


Cart::Cart() { name = new string[4]; num = new int[4]; order_num = 0; } //Need to supplement later - size
void Cart::add_cart(string s, int n,int money) {
	name[order_num] = s;
	num[order_num] = n;
	income += money;
	order_num++;
}
void Cart::print_cart() {
	cout << '\n' << "-------------------- CART --------------------" << '\n';
	for (int i = 0; i < order_num; i++) {
		cout << '\t' << i + 1 << ") " << name[i] << '\t' << '\t' << num[i] << '\n';
	}
	cout << "----------------------------------------------" << '\n';
	cout << '\t' << "amount due: " << income << '\n' << '\n';
}
int Cart::get_income() { return income; }

void start_customer(Admin* admin,Membership* member) {

	Cart c;

	string _order_menu;
	int _order_num;
	int amount = 0;
	int pay_flag;
	int amount_due = 0;

	while (true) {
		
		admin->print_menu();
		cout << "Please enter the menu you want to order." << '\n' << ">>";
		cin >> _order_menu;
		
		if (!admin->such_menu(_order_menu)) {
			cout << "It's a wrong approach." << '\n';
			continue;
		}

		cout << "Please enter the number you want to order." << '\n' << ">>";
		cin >> _order_num;

		if (!admin->check_possible(_order_menu, _order_num)) {
			cout<<"There is not enough material to order. I'm sorry." << '\n';
			continue;
		} 

		amount=admin->modi_amount(_order_menu, _order_num);
		c.add_cart(_order_menu, _order_num, amount);
		c.print_cart();

		cout << "Please enter number 1 if you want to pay, or enter any number for additional orders." << endl << ">>";
		cin >> pay_flag;

		if (pay_flag == 1)
			break;
	} //Need to supplement later - back function

	amount_due = c.get_income();

	char member_flag;
	cout << "Are you a member? (Y/N)" << '\n' << ">>";
	cin >> member_flag;

	int point = 0;
	int num = Membership::num;

	if (member_flag == 'Y') {
		string m_name;
		int m_flag = 0;
		string m_password;
		int m_point;
		int index;

		while (true) {
			cout << "Please enter your ID" << '\n' << ">>";
			cin >> m_name;
			for (int i = 0; i < num; i++) {
				if (!m_name.compare(member[i].get_name())) {
					m_point = member[i].get_point();
					index = i;
					m_flag++;
					break;
				}
			}
			if (m_flag == 1)
				break;

			cout << "ID does not exist." << '\n';
		}

		cout << '\n' << "-------------------- POINT --------------------" << '\n';
		cout << '\t' << "Your point is " << m_point << '\n';
		cout << "-----------------------------------------------" << '\n' << '\n';
		
		if (m_point > 0) {
			char point_flag;
			cout << "Do you want to use points? (Y/N)" << '\n' << ">>";
			cin >> point_flag;

			if (point_flag == 'Y') {
				while (true) {
					cout << "Please enter your Password" << '\n' << ">>";
					cin >> m_password;

					if (!m_password.compare(member[index].get_password()))
						break;

					cout << "Incorrect password." << '\n';
				}
				cout << "How much would you like to use?" << '\n';
				cin >> point;
	
				amount_due -= point;
				admin->save_income(amount_due);
				member[index].modi_point(-point);
				cout << "Point used." << '\n';
				cout << '\n' << "-------------------- BILL --------------------" << '\n';
				cout << '\t' << "You paid " << amount_due << '\n';
				cout << "----------------------------------------------" << '\n' << '\n';
				cout << "Thank you for visiting. Have a good day :)" << '\n';
			}
			else {
				point = (amount_due / 100) * 5;
				admin->save_income(amount_due);
				member[index].modi_point(point);
				cout << "Payment has been made." << '\n';
				cout << "Points have been accumulated." << '\n';
				cout << '\n' << "-------------------- BILL --------------------" << '\n';
				cout << '\t' << "You paid " << amount_due << '\n';
				cout << "----------------------------------------------" << '\n' << '\n';
				cout << "Thank you for visiting. Have a good day :)" << '\n';
			}
		}
	}
	else if (member_flag == 'N') {
		char join_flag;
		cout << "Would you like to join the membership? (Y/N)" << '\n' << ">>";
		cin >> join_flag;

		if (join_flag == 'Y') {
			string id;
			string password;

			int flag = 0;
			while (true) {
				cout << "Please enter ID to use" << '\n' << "(without spaces)" << ">>";
				cin >> id;
				for (flag = 0; flag < num; flag++) {
					if (!id.compare(member[flag].get_name())) {
						cout << "Duplicate ID." << '\n';
						break;
					}
				}
				if (flag == num)
					break;
			}

			cout << "Please enter a password to use" << '\n' << "(Both letters and numbers are possible)" << ">>";
			cin >> password;

			point = (amount_due / 100) * 5;
			member = create_membership(member, id, point, password);
			admin->save_income(amount_due);
			cout << "Congratulations on becoming a member!!" << '\n';
			cout << "Points have been accumulated." << '\n';
			cout << '\n' << "-------------------- BILL --------------------" << '\n';
			cout << '\t' << "You paid " << amount_due << '\n';
			cout << "----------------------------------------------" << '\n' << '\n';
			cout << "Thank you for visiting. Have a good day :)" << '\n';
		}
		else {
			admin->save_income(amount_due);
			cout << '\n' << "-------------------- BILL --------------------" << '\n';
			cout << '\t' << "You paid " << amount_due << '\n';
			cout << "----------------------------------------------" << '\n' << '\n';
			cout << "Thank you for visiting. Have a good day :)" << '\n';
		}
	}
	else {
		admin->save_income(amount_due);
		cout << '\n' << "-------------------- BILL --------------------" << '\n';
		cout << '\t' << "You paid " << amount_due << '\n';
		cout << "----------------------------------------------" << '\n' << '\n';
		cout << "Thank you for visiting. Have a good day :)" << '\n';
	}
	//Need to supplement later - back function

}