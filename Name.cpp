#include "Name.h"
#include <cstring>

//connstructors
Name::Name(char* fn, char* ln) {
	if (fn != nullptr && ln != nullptr) {
		fname = new char[strlen(fn) + 1];
		lName = new char[strlen(ln) + 1];
		strcpy(fname, fn);
		strcpy(lName, ln);
	}

}
Name::Name(const Name& n) {
	if (n.fname != nullptr && n.lName != nullptr) {
		strcpy(fname, n.fname);
		strcpy(lName, n.lName);
	}
}

//setters
void Name::set_name(char* fn, char* ln) {
	if (fn != nullptr && ln != nullptr) {
		fname = new char[strlen(fn) + 1];
		lName = new char[strlen(ln) + 1];
		strcpy(fname, fn);
		strcpy(lName, ln);
	}
	else {
		fname = new char[strlen(fn) + 1];
		lName = new char[strlen(ln) + 1];
		cout << "Enter first name :";
		cin >> fname;
		cout << "Ennter last name :";
		cin >> lName;
	}
}
void Name::set_fname(char* fn) {
	if (fn != nullptr) {
		fname = new char[strlen(fn) + 1];
		strcpy(fname, fn);
	}
	else {
		fname = new char[strlen(fn) + 1];
		cout << "Enter first name :";
		cin >> fname;
	}
}
void Name::set_lname(char* ln) {
	if (ln != nullptr) {
		lName = new char[strlen(ln) + 1];
		strcpy(lName, ln);
	}
	else {
		lName = new char[strlen(ln) + 1];
		cout << "Enter last name :";
		cin >> lName;
	}
}

//getters
Name Name::get_name() {
	return  *this;
}
char* Name::get_fname() {
	return fname;
}
char* Name::lname() {
	return lName;
}

//ostream and istream functions
ostream& operator <<(ostream& out, const Name& n) {
	out << "Name : " << n.fname << " " << n.lName << endl;
	return out;
}
istream& operator>>(istream& in, Name& n) {
	n.fname = new char[10];
	n.lName = new char[10];
	cout << "Enter First name :";
	in >> n.fname;
	cout << "Enter Last name :";
	in >> n.lName;
	return in;
}

//ofstream andifstream functions
ofstream& operator <<(ofstream& fout, Name& n) {
	fout << n.fname << " ";
	fout << n.lName;
	return fout;
}
ifstream& operator>>(ifstream& fin, Name& n) {
	n.fname = new char[10];
	n.lName = new char[10];
	fin >> n.fname;
	fin >> n.lName;
	return fin;
}

//destructor
Name::~Name() {
	if (fname != nullptr && lName != nullptr) {
		delete[]fname;
		delete[]lName;
		fname = nullptr;
		lName = nullptr;
	}
}