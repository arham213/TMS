#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "Service.h"
using namespace std;

class Delivery : public Service {
	float goodsWeight; // Weight of goods in Kg 
	char * goodsType; //type of goods food, furniture, petroleum, chemicals, etc.
protected:
	virtual ostream& output(ostream& out);
	virtual istream& input(istream& in);
	virtual ofstream& write(ofstream& fout);
	virtual ifstream& read(ifstream& fin);
public:
	//constructors
	Delivery(float wgt = 0.0f, char* type = nullptr, char* src = nullptr, char* des = nullptr, float dis = 0.0f, int d = 0, int m = 0, int y = 0, int hr = 0, int min = 0, int sec = 0, float frate = 0.0f, int cid = 0, int did = 0, int vid = 0);
	//setters
	void set_Delivery(float wgt = 0.0f, char* type = nullptr, char* src = nullptr, char* des = nullptr, float dis = 0.0f, int d = 0, int m = 0, int y = 0, int hr = 0, int min = 0, int sec = 0, float frate = 0.0f, int cid = 0, int did = 0, int vid = 0);
	void set_goods_weight(float wgt);
	void set_goods_type(char* type);
	//getters
	Delivery get_delivery();
	float get_goods_weight();
	char* get_goods_type();
	//ostream and istream functions
	friend ostream& operator<<(ostream& out, Delivery& d);
	friend istream& operator>>(istream& in, Delivery& d);
	//ofstream and ifstream functions
	friend ofstream& operator<<(ofstream& fout, Delivery& d);
	friend ifstream& operator>>(ifstream& fin, Delivery& d);
	//destructor
	~Delivery();
	//you can add more members here if required //add member functions 
};