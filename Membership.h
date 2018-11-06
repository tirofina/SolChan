#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include <string>

using namespace std;

class Membership { //membership
	string name;
	int point;
public:
	Membership(string name, int point = 0); //setName,point;
	string get_name();
	int get_point(); //point_increase
	void set_point(int x);
	static int num;
};

void fopen_membership();
void fclose_membership();
void create_membership(string name);
void delete_membership(string name);
void print_membership();


#endif