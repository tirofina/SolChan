#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include <string>

using namespace std;

class Membership { //membership
	string name;
	int point;
public:
	Membership();
	Membership(string name, int point = 0); //setName,point;
	string get_name();
	int get_point(); //point_increase
	void set_point(int x);
	static int num;
};

void fopen_Membership(Membership& member, int &member_index);
void fclose_Membership();
void create_Membership(string name);
void delete_Membership(string name);
void print_Membership();


#endif