#include"Membership.h"

Membership::Membership() {}
Membership::~Membership() { num--; }
string Membership::get_name() { return name; } //return member name
int Membership::get_point() { return point; } //return member point
string Membership::get_password() { return password; }
void Membership::set_member(string name,int point,string password) {
	this->name = name;
	this->point = point;
	this->password = password;
} //set member point and name and password
void Membership::modi_point(int val) {
	point = point + val;
} //modification point value
int Membership::num = 0;
int Membership::max = 10;


Membership* fopen_membership() {
	string filePath = "Membership.txt";
	int i;
	int max = Membership::max;
	Membership* Member = new Membership[max];


	ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		string line;
		string buf;
		vector<string> tokens;
		tokens.reserve(3);
		
		i = 0;
		while (getline(openFile, line)) {
			stringstream ss(line);
			while (ss >> buf)
				tokens.push_back(buf);

			if(i>=max) {
				Membership* Member2 = new Membership[max*2];
				
				for (int k = 0; k < max; k++) {
					Member2[k].set_member(Member[k].get_name(), Member[k].get_point(), Member[k].get_password());
				}
				delete[] Member;
				max = max * 2;
				Membership::max = max;
				Member = Member2;
			}
			Member[i].set_member(tokens[0], stoi(tokens[1]), tokens[2]);
			Membership::num++;
			i++;
		
			tokens.clear();
		}
		openFile.close();
		return Member;
	}
	else {
		cout << "Membership flie open error" << endl;
	}
}//booting(fread membership list),make class


Membership* create_membership(Membership* Member,string name,int point,string password) {
	int num = Membership::num;
	int max = Membership::max;

	if (num >= max) {
		Membership* Member2 = new Membership[max * 2];

		for (int k = 0; k < max; k++) {
			Member2[k].set_member(Member[k].get_name(), Member[k].get_point(), Member[k].get_password());
		}
		delete[] Member;
		max = max * 2;
		Membership::max = max;
		Member = Member2;
	}

	Member[num].set_member(name, point, password);
	Membership::num++;

	return Member;
} //create membership class


void fclose_membership(Membership* Member) {
	string filePath = "Membership.txt";
	ofstream writeFile(filePath.data());
	int i;
	int num = Membership::num;

	if (writeFile.is_open()) {
		for (i = 0; i < num; i++) {
			writeFile << Member[i].get_name() << " " << Member[i].get_point() << " " << Member[i].get_password();
			writeFile << "\n";
		}
		writeFile.close();
		delete[] Member;
	} else {
		cout << "Membership flie open error" << endl;
	}
} //fwrite membership list
