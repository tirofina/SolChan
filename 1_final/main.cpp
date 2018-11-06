#include<iostream>
#include<string>
#include "Membership.h"
#include "Shared.h"
#include "Customer.h"
#include "Master.h"

using namespace std;

int main(){
	int menu_index;
	int member_index;
	Menu menu[4];
	fopen_Menu(*menu,menu_index); //need debug
	Material meterial=fopen_Material();
	Purchase purchase=fopen_Purchase();
	Membership member[1];
	fopen_Membership(*member,member_index);//need debug

	while (true) {
		int i;
		string in;
		cout << "반갑습니다. SolChan Cafe입니다." << endl << "원하는 서비스를 골라주세요!" << endl;
		cout << "1. 주문" << endl << "2.관리자 모드" << endl << "3. 프로그램 종료" << endl << ">>";
		cin >> i;

		switch (i) {
		case 1:
			start_customer(*menu,menu_index,meterial,purchase,*member,member_index);
			break;
		case 2:
			start_master(); //*menu, menu_index, meterial, purchase, *member, member_index
			break;
		case 3:
			cout << "프로그램을 종료합니다.";
			in = "quit";
			break;
		default:
			cout << "잘못된 접근입니다." << endl;
			break;
		}
		
		if (in == "quit")
			break;
	}

	fclose_Menu(); //Menu,meterial fwrite
	fclose_Material();
	fclose_Purchase();
	fclose_Membership();

}