#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Name {
	char* fname;
	char* lName;
public:
	//connstructors
	Name(char* fn=nullptr, char* ln=nullptr);
	Name(const Name& n);
	//setters
	void set_name(char* fn, char* ln);
	void set_fname(char* fn);
	void set_lname(char* ln);
	//getters
	Name get_name();
	char* get_fname();
	char* lname();
	//ostream and istream functions
	friend ostream& operator <<(ostream& out, const Name& n);
	friend istream& operator>>(istream& in, Name& n);
	//ofstream andifstream functions
	friend ofstream& operator <<(ofstream& fout, Name& n);
	friend ifstream& operator>>(ifstream& fin, Name& n);
	//destructors
	~Name();
};