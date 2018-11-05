#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include <string>

using namespace std;

class Membership { //membership
	string name;
	int stamp;
public:
	Membership(string name); //setName;
	string getName();
	void operator+(int x); //stamp_increase
};

#endif