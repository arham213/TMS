#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "Person.h"
#include "Service.h"
using namespace std;

class Customer : public Person {
	int cId; // Unique and assigned first time when customer makes first service request 
	Service ** bookingHistory; //Maintain and Update history of customer for each service (ride or goods transportation order) by adding address of service in dynamic array. 
	int service_no;
	//Getter, Setters //Destructor, Default and Parametrized Constructor, Copy Constructor, Output operator (print complete information of customer including history if any) 
protected:
	virtual ostream& output(ostream& out);
	virtual istream& input(istream& in);
	virtual ofstream& write(ofstream& fout);
	virtual ifstream& read(ifstream& fin);
public:
	//constructor
	Customer(int cid = 0, char* fn = nullptr, char* ln = nullptr, int d = 0, int m = 0, int y = 0, int age = 0, int nid = 0);
	//setters
	void set_customer(int cid = 0, char* fn = nullptr, char* ln = nullptr, int d = 0, int m = 0, int y = 0, int age = 0, int nid = 0);
	void set_cid(int cid);
	void add_service(Service* s);
	//getters
	Customer get_customer();
	int get_cid();
	int get_total_services();
	//ostream and istream functions
	friend ostream& operator<<(ostream& out, Customer& c);
	friend istream& operator >> (istream& in, Customer& c);
	//ofstream and ifstream functions
	friend ofstream& operator<<(ofstream& fout, Customer& c);
	friend ifstream& operator >> (ifstream& fin, Customer& c);
};