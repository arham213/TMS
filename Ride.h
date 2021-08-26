#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "Service.h"
using namespace std;

class Ride : public Service {
	int noofPassengers; // false for pending, true if complete 
	char * rideType; // intercity, intracity 
	float DriverRanking; // 0 to 5 scale (worst to best) 
	float VehicleRanking; // 0 to 5 scale (worst to best)
protected:
	virtual ostream& output(ostream& out);
	virtual istream& input(istream& in);
	virtual ofstream& write(ofstream& fout);
	virtual ifstream& read(ifstream& fin);
public:
	//constructors
	Ride(int psg = 0,char*type=nullptr,float drank=0.0f,float vrank=0.0f, char* src = nullptr, char* des = nullptr, float dis = 0.0f, int d = 0, int m = 0, int y = 0, int hr = 0, int min = 0, int sec = 0, float frate = 0.0f, int cid = 0, int did = 0, int vid = 0);
	//setters
	void set_Ride(int psg = 0, char* type = nullptr, float drank = 0.0f, float vrank = 0.0f, char* src = nullptr, char* des = nullptr, float dis = 0.0f, int d = 0, int m = 0, int y = 0, int hr = 0, int min = 0, int sec = 0, float frate = 0.0f, int cid = 0, int did = 0, int vid = 0);
	void set_rideType(char* rtype);
	void set_driver_ranking(float drank);
	void set_vehicle_ranking(float vrank);
	void set_noofpassengers(int psg);
	//getters
	Ride get_ride();
	char* get_rideType();
	float get_driver_ranking();
	float get_vehicle_ranking();
	int get_noofpassengers();
	//ostream ad istream fucntions
	friend ostream& operator << (ostream & out, Ride & r);
	friend istream& operator>>(istream& in, Ride& r);
	//ofstream and ifstream functions
	friend ofstream& operator << (ofstream& fout, Ride& r);
	friend ifstream& operator>>(ifstream& fin, Ride& r);
	//destructor
	virtual ~Ride();
};