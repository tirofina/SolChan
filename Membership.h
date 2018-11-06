<<<<<<< HEAD
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

=======
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

>>>>>>> 9127d6a15cbb5b8da5b2fb87b9dac5d62c6124d9
#endif