#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "Date.h"
#include "Time.h"
using namespace std;

class Service {
	char* source; 
	char* destination; 
	float distance; //in km 
	Date bookingDate; 
	mTime bookingTime; 
	bool status; // false for pending, true if complete 
	float fuelrate;
	int cId; // Customer Id who booked the ride 
	int dId; // Driver Id 
	int vId; // vehicle Id 
protected:
	virtual ostream& output(ostream& out);
	virtual istream& input(istream& in);
	virtual ofstream& write(ofstream& fout);
	virtual ifstream& read(ifstream& fin);
public:
	//constructors
	Service(char* src = nullptr, char* des = nullptr, float dis = 0.0f, int d = 0, int m = 0, int y = 0, int hr = 0, int min = 0, int sec = 0, float frate = 0.0f, int cid = 0, int did = 0, int vid = 0);
	//setters
	void set_service(char* src = nullptr, char* des = nullptr, float dis = 0.0f, int d = 0, int m = 0, int y = 0, int hr = 0, int min = 0, int sec = 0, float frate = 0.0f, int cid = 0, int did = 0, int vid = 0);
	void set_source(char* src);
	void set_destination(char* des);
	void set_distance(float dis);
	void set_date(int d, int m, int y);
	void set_time(int hr, int min, int sec);
	void set_status(bool stat);
	void set_fuel_rate(float frate);
	void set_cid(int cid);
	void set_did(int did);
	void set_vid(int vid);
	//getters
	Service get_service();
	char* get_source();
	char* get_destination();
	float get_distance();
	Date get_date();
	mTime get_time();
	bool get_status();
	float get_fuel_rate();
	int get_cid();
	int get_vid();
	int get_did();
	//ostream and istream fucntions
	friend ostream& operator << (ostream & out, Service & s);
	friend istream& operator >> (istream& out, Service& s);
	//ofstream andifstream functions
	friend ofstream& operator << (ofstream& out, Service& s);
	friend ifstream& operator >> (ifstream& out, Service& s);
	//destructor
	virtual ~Service();
	
};