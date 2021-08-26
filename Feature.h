#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Feature {
	int fId; 
	char* description; 
	float cost;
protected:
	//virtual functions
	virtual ostream& output(ostream& out);
	virtual istream& input(istream& in);
	virtual ofstream& write(ofstream& fout);
	virtual ifstream& read(ifstream& fin);
public:
	//constructor
	Feature(int fid = 0, char* des = nullptr, float cost = 0.0f);
	//setters
	void set_feature(int fid = 0, char* des = nullptr, float cost = 0.0f);
	void set_fid(int fid);
	void set_description(char* des);
	void set_cost(float cost);
	//getters
	Feature get_feature();
	int get_fid();
	char* get_description();
	float get_cost();
	//ostream and istream functions
	friend ostream& operator<<(ostream& out, Feature& d);
	friend istream& operator>>(istream& in, Feature& d);
	//ofstream and ifstream functions
	friend ofstream& operator<<(ofstream& fout, Feature& d);
	friend ifstream& operator>>(ifstream& fin, Feature& d);
	//destructor
	~Feature();
	//you can add more members here if required 
	//add member functions
};