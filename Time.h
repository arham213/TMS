#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class mTime {
	int hour;
	int min;
	int sec;
public:
	//constrcutors
	mTime(int h=0,int m=0,int s=0);//parametrized and deafult constructors
	mTime(const mTime& m);//copy constructors
	//setters
	void set_time(int h, int m, int s);//set time
	void set_hour(int h);//set hour
	void set_min(int m);//set min
	void set_sec(int s);//set sec
	//getters
	mTime get_time();// get time
	int get_hour();//get hour
	int get_min();//get min
	int get_sec();//get sec
	//ostream and istream
	friend ostream& operator<< (ostream& out, mTime& m);//ostream
	friend istream& operator>>(istream& in, mTime& m);//istream
	//ofstream and ifstream
	friend ofstream& operator<<(ofstream& fout, mTime& m);//ofstream
	friend ifstream& operator>>(ifstream& fin, mTime& m);//ifstream
};