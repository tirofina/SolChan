#pragma once
#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Membership { //membership
	string name;
	int point;
	string password;
public:
	Membership();
	~Membership();
	//Membership(string name="", int point = 0); //setName,point;
	string get_name();
	int get_point(); //point_increase
	string get_password();
	void set_member(string name,int point,string password);
	void modi_point(int val);
	static int num;
	static int max;
};

Membership* fopen_membership();
void fclose_membership(Membership* Member);
Membership* create_membership(Membership* Member, string name, int point, string password);


#endif