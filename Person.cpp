#include "Person.h"
#include "Date.h"
#include "Name.h"
#include <fstream>

//constructors
Person::Person(char* fn, char* ln, int d, int m, int y, int age, int nid) :pName(fn, ln), DOB(d, m, y) {
	if (age > 0) {
		this->Age = age;
	}
	if (nid > 0) {
		Nid = nid;
	}
	
}

//setters
void Person::set_Person(char* fn, char* ln, int d, int m, int y, int age, int nid) {
	pName.set_name(fn, ln);
	DOB.set_date(d, m, y);
	if (age >= 0) {
		this->Age = age;
	}
	else {
		while (age <= 0) {
			cout << "Invalid Age" << endl;
			cout << "Enter Age :";
			cin >> age;
		}
		Age = age;
	}
	if (nid > 0) {
		Nid = nid;
	}
	else {
		while (nid <= 0) {
			cout << "Invalid National ID" << endl;
			cout << "Enter National ID :";
			cin >> nid;
		}
		Nid = nid;
	}
}
void Person::set_name(char* fn, char* ln) {
	pName.set_name(fn, ln);
}
void Person::set_date(int d, int m, int y) {
	DOB.set_date(d, m, y);
}
void Person::set_age(int age) {
	if (age >= 0) {
		this->Age = age;
	}
	else {
		while (age <= 0) {
			cout << "Invalid Age" << endl;
			cout << "Enter Age :";
			cin >> age;
		}
		Age = age;
	}
}
void Person::set_nid(int nid) {
	if (nid > 0) {
		Nid = nid;
	}
	else {
		while (nid <= 0) {
			cout << "Invalid National ID" << endl;
			cout << "Enter National ID :";
			cin >> nid;
		}
		Nid = nid;
	}
}

//getters
Person Person::get_person() {
	return *this;
}
Name Person::get_name() {
	return pName;
}
Date Person::get_date() {
	return DOB;
}
int Person::get_age() {
	return Age;
}
int Person::get_nid() {
	return Nid;
}

//virtual functions
ostream& Person::output(ostream& out) {
	out << pName;
	out <<"DOB :"<<DOB;
	out << "National Id :" << Nid << endl;
	out << "Age :" << Age << endl;
	return out;
}
istream& Person::input(istream& in) {
	in >> pName;
	cout << "Enter Date of Birth :" << endl;
	in >> DOB;
	cout << "Enter Your Age :";
	in >> Age;
	while (Age < 0) {
		cout << "Invalid Age" << endl;
		cout << "Enter Your Age :";
		in >> Age;
	}
	cout << "Enter National ID :";
	in >> Nid;
	while (Nid < 0) {
		cout << "Invalid National ID" << endl;
		cout << "Enter National ID :";
		in >> Nid;
	}
	return in;
}
ofstream& Person::write(ofstream& fout) {
	fout << pName << " ";
	fout << DOB << " ";
	fout << Age << " ";
	fout << Nid << " ";
	return fout;
}
ifstream& Person::read(ifstream& fin) {
	fin >> pName;
	fin >> DOB;
	fin >> Age;
	fin >> Nid;
	return fin;
}

//ostream andistream functions
ostream& operator<<(ostream& out, Person& p) {
	p.output(out);
	return out;
}
istream& operator>>(istream& in, Person& p) {
	p.input(in);
	return in;
}

//ofstream and ifstream fucntions
ofstream& operator<<(ofstream& fout, Person& p) {
	p.write(fout);
	return fout;

}
ifstream& operator>>(ifstream& in, Person& p) {
	p.read(in);
	return in;
}
