#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include "Date.h"
#include "Feature.h"
#include "Service.h"
using namespace std;

class Vehicle {
	int vId;
	int registrationNo;
	float avgMileage;
	char* LicenceType; // License required for driving the vehicle 
	bool status; // false for free, true if booked in a service already 
	char* fueltype;
	float overallRanking;
	int ranking_no;//checks for how many rankings have been given
	Date manufacturingDate;
	Feature** list;
	Service** serviceHistory;
	int service_no;//tracks the number of services for a particular vehicle
	int feature_no;//tracks the number of features for a particular vehicle
protected:
	virtual ostream& output(ostream& out);
	virtual istream& input(istream& in);
	virtual ofstream& write(ofstream& fout);
	virtual ifstream& read(ifstream& fin);
public:
	//constructor
	Vehicle(int vid = 0, int rno = 0, float mil = 0.0f, char* lic = nullptr, char* ftype = nullptr, float rank = 0.0f, int d = 0, int m = 0, int y = 0);
	//setters
	void set_vehicle(int vid = 0, int rno = 0, float mil = 0.0f, char* lic = nullptr, char* ftype = nullptr, float rank = 0.0f, int d = 0, int m = 0, int y = 0);
	void set_vid(int id);
	void set_registrationNo(int no);
	void set_average_mileage(float mil);
	void set_licence(char* lic);
	void set_ride_status(bool stat);
	void set_fuelType(char* ftype);
	void set_overall_ranking(float rank);
	void set_date(int d, int m, int y);
	void add_feature(Feature* f);
	void add_service(Service* s);
	//getters
	//Vehicle get_vehicle();
	int get_vid();
	int get_registrationNo();
	float get_average_mileage();
	char* get_licence();
	bool get_ride_status();
	char* get_fuelType();
	float get_overall_ranking();
	Date get_date();
	//virtual const char* get_vehicle_name() = 0;
	//ostream and istream functions
	friend ostream& operator<<(ostream& out, Vehicle& v);
	friend istream& operator>>(istream& in, Vehicle& v);
	//ofstream and ifstream functions
	friend ofstream& operator<<(ofstream& fout, Vehicle& v);
	friend ifstream& operator>>(ifstream& fin, Vehicle& v);
	//destructor
	virtual ~Vehicle();
};
