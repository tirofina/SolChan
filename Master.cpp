#include"Master.h"
#include"Shared.h"

Master::Master() {}
int Master::input_pw() {}
void Master::set_pw(int pw) {}
void Master::check_pw(int pw, int input_pw) {}

void start_master() {

	int end_master = 0;
	while (! end_master = 1) {

		cout << "Administrator mode. Please enter your number."<<endl << ">>";

		cout << "1. Material Check" << endl;

		cout << "2. Material Order" << endl;

		cout << "3. Add Menu" << endl;

		cout << "4. Sales & net income check" << endl;

		cout << "5. Exit Admin Mode" << endl;

		int Mmn = 0; //Master menu num

		switch (Mmn) {
		case 1:	// 재료 조회
			cout << "- Material Check -" << endl;
			print_meterial();
			break;
		case 2:	// 재료 주문
			cout << "- Material Order -"
			order_meterial(string name, int amount);
			break;
		case 3:	// 메뉴 추가
			cout << "- Add Menu -" << endl;
			cout << "Enter a name for the menu you want to add and press Enter." << endl;
			add_set_menu_name();
			add_set_menu_material();
			add_set_menu_price();
			
			break;
		case 4:	// 매출 & 순이익 조회
			cout << "- Sales & net income check -" << endl;


			break;
		case 5: // 관리자 모드 종료
			cout << "- Exit Admin Mode -" << endl;
			

			int end_master = 1;
			break;
		}
		
	}
	int end_master = 0;







}