<<<<<<< HEAD
#include<iostream>
#include<string>

using namespace std;

class Member { //membership
	string name;
	int stamp;
public:
	Member(string name="empty") {}; //setName;
	string getName(){}
	void operator+(int x){
		this->stamp += x; 
	}
};


int main(int argc,char *argv[]) {
	

	//default_exe


=======
#include<iostream>
#include<string>
#include "Membership.h"

using namespace std;

int main(int argc,char *argv[]) {
	
	//default_exe


>>>>>>> 9127d6a15cbb5b8da5b2fb87b9dac5d62c6124d9
}