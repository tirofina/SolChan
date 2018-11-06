#ifndef MASTER_H
#define MASTER_H

using namespace std;

class Master { // for Master
	int password;
public:
	Master();
	int input_pw(); // input password
	void set_pw(int pw); // set password
	void check_pw(int pw, int input_pw); // check password
};


void start_master();

#endif