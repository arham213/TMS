#include "Customer.h"

//constructor
Customer::Customer(int cid, char* fn, char* ln, int d, int m, int y, int age, int nid):Person(fn,ln,d,m,y,age,nid){
	if (cid > 0) {
		cId = cid;
	}
	else {
		cId = 0;
	}
	service_no = 0;
}

//setters
void Customer::set_customer(int cid, char* fn, char* ln, int d, int m, int y, int age, int nid) {
	Person::set_Person(fn, ln, d, m, y, age, nid);
	if (cid > 0) {
		cId = cid;
	}
	else {
		while (cId <= 0) {
			cout << "Invalid Customer ID " << endl;
			cout << "Enter Customer ID :";
			cin >> cid;
		}
		cId = cid;
	}
}
void Customer::set_cid(int cid) {
	while (cid <= 0) {
		cout << "Inavlid Customer ID " << endl;
		cout << "Enter Customer ID :";
		cin >> cid;
	}
	cId = cid;
}
void Customer::add_service(Service* s) {
	if (service_no == 0) {
		service_no++;
		bookingHistory = new Service * [service_no];
		bookingHistory[0] = s;
	}
	else {
		Service** temp = new Service * [service_no + 1];
		//copying objects
		int i;
		for (i = 0; i < service_no; i++) {
			temp[i] = bookingHistory[i];
		}
		temp[i] = s;
		//deleting old history
		delete[]bookingHistory;
		//assigning new history
		bookingHistory = temp;
		temp = nullptr;
		service_no++;
	}
}

//getters
Customer Customer::get_customer() {
	return *this;
}
int Customer::get_cid() {
	return cId;
}
int Customer::get_total_services() {
	return service_no;
}

//virtual functions
ostream& Customer::output(ostream& out) {
	out << "Customer ID :" << cId << endl;
	Person::output(out);
	if (service_no == 0) {
		cout << "Customer has no booking history" << endl;
	}
	else {
		for (int i = 0; i < service_no; i++) {
			cout << "--------------------------------------------------------" << endl;
			cout << "Service_NO :" << i + 1 << endl;
			out << bookingHistory[i][0];
		}
	}
	return out;
}
istream& Customer::input(istream& in) {
	cout << "Enter Customer ID :";
	in >> cId;
	while (cId <= 0) {
		cout << "Inavlid Customer ID " << endl;
		cout << "Enter Customer ID :";
		in >> cId;
	}
	Person::input(in);
	return in;
}
ofstream& Customer::write(ofstream& fout) {
	fout << cId << " ";
	Person::write(fout);
	return fout;
}
ifstream& Customer::read(ifstream& fin) {
	fin >> cId;
	Person::read(fin);
	return fin;
}

//ostream and istream functions
ostream& operator<<(ostream& out, Customer& c) {
	c.output(out);
	return out;
}
istream& operator >> (istream& in, Customer& c) {
	c.input(in);
	return in;
}

//ofstream and ifstream functions
ofstream& operator<<(ofstream& fout, Customer& c) {
	c.write(fout);
	return fout;
}
ifstream& operator >> (ifstream& fin, Customer& c) {
	c.read(fin);
	return fin;
}