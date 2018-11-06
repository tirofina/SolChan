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


}