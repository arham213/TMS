#pragma once
#include <iostream>
#include <fstream>
#include "Name.h"
#include "Date.h"
using namespace std;

class Person {
	Name pName;
	Date DOB;
	int Age;
	int Nid;
protected:
	virtual ostream& output(ostream& out);
	virtual istream& input(istream& in);
	virtual ofstream& write(ofstream& fout);
	virtual ifstream& read(ifstream& fin);
public: 
	//constructors
	Person(char* fn = nullptr, char* ln = nullptr, int d = 0, int m = 0, int y = 0, int age = 0, int nid = 0);
	//setters
	void set_Person(char* fn = nullptr, char* ln = nullptr, int d = 0, int m = 0, int y = 0, int age = 0, int nid = 0);
	void set_name(char* fn = nullptr, char* ln = nullptr);
	void set_date(int d = 0, int m = 0, int y = 0);
	void set_age(int age);
	void set_nid(int id);
	//getters
	Person get_person();
	Name get_name();
	Date get_date();
	int get_age();
	int get_nid();
	//ostream andistream functions
	friend ostream& operator<<(ostream& out,Person& p);
	friend istream& operator>>(istream& in, Person& p);
	//ofstream and ifstream fucntions
	friend ofstream& operator<<(ofstream& out, Person& p);
	friend ifstream& operator>>(ifstream& in, Person& p);
};