#pragma once

#include "Vehicle.h"
#include "Delivery_Vehicle.h"

class ride_vehicle :public virtual Vehicle {
public:
	ride_vehicle(int vid = 0, int rno = 0, float mil = 0.0f, char* lic = nullptr, char* ftype = nullptr, float rank = 0.0f, int d = 0, int m = 0, int y = 0):Vehicle(vid,rno,mil,lic,ftype,rank,d,m,y){}
	virtual const char* get_vehicle_service_category();
};

class bike :public ride_vehicle,delivery_vehicle {
	int noofpassengers;
protected:
	virtual ostream& output(ostream& out);
	virtual istream& input(istream& in);
	virtual ofstream& write(ofstream& fout);
	virtual ifstream& read(ifstream& fin);
public:
	//constructors
	bike(int vid = 0, int rno = 0, float mil = 0.0f, char* lic = nullptr, char* ftype = nullptr, float rank = 0.0f, int d = 0, int m = 0, int y = 0);
	//getters
	int get_noofpassengers();
	const char* get_vehicle_service_category() override;
	const char* get_ridetype();
	//ostream and istream functions
	friend ostream& operator<<(ostream& out, Vehicle& v);
	friend istream& operator>>(istream& in, Vehicle& v);
	//ofstream and ifstream functions
	friend ofstream& operator<<(ofstream& fout, Vehicle& v);
	friend ifstream& operator>>(ifstream& fin, Vehicle& v);
};