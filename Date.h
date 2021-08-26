#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Date {
	int day; 
	int month; 
	int year; 
protected:
	//virtual functions
	virtual ostream& output(ostream& out);
	virtual istream& input(istream& in);
	virtual ofstream& write(ofstream& fout);
	virtual ifstream& read(ifstream& fin);
public:
	//constructors
	Date(int d = 0, int m = 0, int y = 0);//parametrized and defalt constructor
	Date(const Date & d);//copy constructor
	//setters
	void set_date(int d, int m, int y);//set date
	void set_day(int d);//set day
	void set_month(int m);//set month
	void set_year(int y);//set year
	//getters
	Date get_date();//get date
	int get_day();//get day;
	int get_month();//get month
	int get_year();//get year
	//ostream and istream
	friend ostream& operator<<(ostream& out, Date& d);//ostream
	friend istream& operator>>(istream& in, Date& d);//istream
	//ofstream and ifstream
	friend ofstream& operator<<(ofstream& fout, Date& d);//ofstream
	friend ifstream& operator>>(ifstream& fin, Date& d);//ifstream
};