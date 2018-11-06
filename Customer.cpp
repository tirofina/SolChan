#include "Customer.h"

using namespace std;

Cart::Cart() {}
void Cart::add_cart(string s, int n) {}
void Cart::print_cart() {}
int Cart::payment_cart() {}

void start_customer(Menu& menu, int menu_index, Material& material, Purchase& purchase, Membership& member, int member_index) {
	
	Cart c;

	while (true) {
		for (int i = 0; i < menu_index; ++i) {//
			if (menu.check_metreial == 1) {
				cout << endl;
			}
			else if (menu.check_metreial == 0) {
				cout << "(주문 불가)" << endl;
			}
		}

		string s_order;
		cout << "주문 하실 메뉴를 입력해주세요.(번호)" << endl << ">>";
		cin >> s_order;

		int i_order;
		cout << "갯수를 입력해주세요." << endl << ">>";
		cin >> i_order;
		c.add_cart(s_order, i_order);

		cout << "주문 내역" << endl;
		c.print_cart();

		int i_pay;
		cout << "결제는 0번, 추가 주문은 1번을 입력해주세요." << endl << ">>";
		cin >> i_pay;
		
		if (i_pay == 1)
			break;
	}

	int pay = c.payment_cart();

	char c_member;
	cout << "회원이신가요? (Y/N)" << endl << ">>";
	cin >> c_member;


	if (c_member == 'Y') {
		cout << "아이디를 입력해주세요." << endl << ">>";
		string str_member;
		int customer_index=-1;
		getline(cin, str_member);

		for (int i = 0; i < member_index; ++i) {
			if (member.get_name == str_member) {
				customer_index = i;
				cout << "포인트 잔액은 " << member.get_point << "입니다." << endl;
				break;
			}
		}

		if (customer_index != -1) {
			char c_point;
			cout << "포인트를 사용하시겠습니까? (Y/N)" << endl << ">>";
			cin >> c_point;
			if (c_point == 'Y') {
				purchase.set_revenue(pay - member.get_point());
				cout << "결제가 완료되었습니다." << endl;
			}
			else {
				member.set_point(pay);
				purchase.set_revenue(pay);
				cout << "결제가 완료되었습니다." << endl;
			}
		}
		else {
			cout << "잘못된 접근입니다." << endl;
		}
	}
	else if (c_member == 'N') {
		char c_join;
		cout << "회원가입을 하시겠습니까? (Y/N)" << endl << ">>";
		cin >> c_join;

		if (c_join == 'Y') {
			string id;
			int flag;
			while (true) {
				cout << "사용할 아이디를 입력해주세요" << endl << ">>";
				getline(cin, id);
				for (flag=0; flag < member_index; ++flag) {//
					if (member.get_name == id) {
						cout << "중복 아이디입니다." << endl;
						break;
					}
				}
				if (flag == member_index)
					break;
			}
			create_Membership(id);
			member.set_point(pay);//
			purchase.set_revenue(pay);
			cout << "결제가 완료되었습니다." << endl;
		}
		else {
			purchase.set_revenue(pay);
			cout << "결제가 완료되었습니다." << endl;
		}
	}

}