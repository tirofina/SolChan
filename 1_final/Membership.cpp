#include"Membership.h"

Membership::Membership() {}
Membership::Membership(string name, int point = 0) {}
string Membership::get_name() {} //return member name
int Membership::get_point() {} //return member point
void Membership::set_point(int x) {} //set member point


void fopen_Membership(Membership& member,int &member_index) {}//booting(fread membership list),make class
void fclose_Membership() {}//fwrite membership list
void create_Membership(string name) {} //create membership class
void delete_Membership(string name) {} //delete membership class
void print_Membership() {} //print all membership class
