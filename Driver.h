#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "Person.h"
#include "Service.h"
using namespace std;

class Driver : public Person {
	int dId; 
	char** LicencesList; 
	int noofLicences; 
	float overallRanking; 
	float salary; 
	int experience; 
	int status; // 1 for free, 2 if booked and 3 if canceled 
	Service ** serviceHistory; //Add services address in the array for tracking complete information of service.
	int service_no;
	int ranking_no;
protected:
	virtual ostream& output(ostream& out);
	virtual istream& input(istream& in);
	virtual ofstream& write(ofstream& fout);
	virtual ifstream& read(ifstream& fin);
public: 
	//constructor
	Driver(int did = 0, float rank = 0.0f, float sal = 0.0f, int exp = 0, int status = 0, char* fn = nullptr, char* ln = nullptr, int d = 0, int m = 0, int y = 0, int age = 0, int nid = 0);
	//setters
	void set_driver(int did = 0, float rank = 0.0f, float salary = 0.0f, int exp = 0, int status = 0, char* fn = nullptr, char* ln = nullptr, int d = 0, int m = 0, int y = 0, int age = 0, int nid = 0);
	void set_did(int id);
	void add_licence();
	void add_service(Service* s);
	void set_ranking(float rank);
	void set_salary(float sal);
	void set_expereince(int exp);
	void set_status(int s);
	//getters
	Driver get_driver();
	char** get_licences();
	int get_nooflicences();
	float get_driver_ranking();
	float get_salary();
	int get_experience();
	int get_status();
	//ostream andistream functions
	friend ostream& operator << (ostream & out, Driver & d);
	friend istream& operator>>(istream& in, Driver& d);
	//ofstream and ifstream functions
	friend ofstream& operator << (ofstream& fout, Driver& d);
	friend ifstream& operator>>(ifstream& fin, Driver& d);
	//destructor
	~Driver();
};