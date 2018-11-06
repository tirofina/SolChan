#ifndef MASTER_H
#define MASTER_H

using namespace std;

class Master { // for Master
	int password;
public:
	Master();
	int input_pw(); // input password
	void set_pw(int pw); // set password
	void compare_pw(); // compare password
};

#endif