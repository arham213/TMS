#include "Service.h"

//constructor
Service::Service(char* src, char* des, float dis, int d, int m, int y, int hr, int min, int sec, float frate, int cid, int did, int vid) :bookingDate(d, m, y), bookingTime(hr, min, sec) {
	if (src != nullptr && des != nullptr) {
		source = new char[strlen(src) + 1];
		strcpy(source, src);
		destination = new char[strlen(des) + 1];
		strcpy(destination, des);
	}
	else {
		src = nullptr;
		des = nullptr;
	}
	if (dis > 0) {
		distance = dis;
	}
	else {
		distance = 0;
	}
	if (frate > 0) {
		fuelrate = frate;
	}
	else {
		fuelrate = 0;
	}
	if (cid > 0) {
		cId = cid;
	}
	else {
		cId = 0;
	}
	if (did > 0) {
		dId = did;
	}
	else {
		dId = 0;
	}
	if (vid > 0) {
		vId = vid;
	}
	else {
		vId = 0;
	}
	status = true;
}

//setters
void Service::set_service(char* src, char* des, float dis, int d, int m, int y, int hr, int min, int sec, float frate, int cid, int did, int vid) {
	bookingDate.set_date(d, m, y);
	bookingTime.set_time(hr, min, sec);
	if (src != nullptr && des != nullptr) {
		source = new char[strlen(src) + 1];
		strcpy(source, src);
		destination = new char[strlen(des) + 1];
		strcpy(destination, des);
	}
	else {
		src = nullptr;
		des = nullptr;
	}
	if (dis > 0) {
		distance = dis;
	}
	else {
		distance = 0;
	}
	if (frate > 0) {
		fuelrate = frate;
	}
	else {
		fuelrate = 0;
	}
	if (cid > 0) {
		cId = cid;
	}
	else {
		cId = 0;
	}
	if (did > 0) {
		dId = did;
	}
	else {
		dId = 0;
	}
	if (vid > 0) {
		vId = vid;
	}
	else {
		vId = 0;
	}
	status = true;
}
void Service::set_source(char* src) {
	if (src != nullptr) {
		source = new char[strlen(src) + 1];
		strcpy(source, src);
	}
	else {
		cout << "Enter Source :";
		source = new char[15];
		cin >> source;
	}
}
void Service::set_destination(char* des) {
	if (des != nullptr) {
		destination = new char[strlen(des) + 1];
		strcpy(destination, des);
	}
	else {
		cout << "Enter destination :";
		destination = new char[15];
		cin >> destination;
	}
}
void Service::set_distance(float dis) {
	if (dis > 0) {
		distance = dis;
	}
	else {
		while (dis <= 0) {
			cout << "Inavlid Distance" << endl;
			cout << "Enter distnace :";
			cin >> dis;
		}
		distance = dis;
	}
}
void Service::set_date(int d, int m, int y) {
	bookingDate.set_date(d, m, y);
}
void Service::set_time(int hr, int min, int sec) {
	bookingTime.set_time(hr, min, sec);
}
void Service::set_status(bool stat) {
	status = stat;
}
void Service::set_fuel_rate(float frate) {
	if (frate > 0) {
		fuelrate = frate;
	}
	else {
		while (frate <= 0) {
			cout << "Invalid fuel rate" << endl;
			cout << "Enter fuel rate :";
			cin >> frate;
		}
		fuelrate = frate;
	}
}
void Service::set_cid(int cid) {
	if (cid > 0) {
		cId = cid;
	}
	else {
		while (cid <= 0) {
			cout << "Invalid customer ID" << endl;
			cout << "Enter customer ID :";
			cin >> cid;
		}
		cId = cid;
	}
}
void Service::set_did(int did) {
	if (did > 0) {
		dId = did;
	}
	else {
		while (did <= 0) {
			cout << "Invalid driver ID" << endl;
			cout << "Enter driver ID :";
			cin >> did;
		}
		dId = did;
	}
}
void Service::set_vid(int vid) {
	if (vid > 0) {
		vId = vid;
	}
	else {
		while (vid <= 0) {
			cout << "Invalid vehicle ID" << endl;
			cout << "Enter vehicle ID :";
			cin >> vid;
		}
		vId = vid;
	}
}

//getters
Service Service::get_service() {
	return *this;
}
char* Service::get_source() {
	return source;
}
char* Service::get_destination() {
	return destination;
}
float Service::get_distance() {
	return distance;
}
Date Service::get_date() {
	return bookingDate;
}
mTime Service::get_time() {
	return bookingTime;
}
bool Service::get_status() {
	return status;
}
float Service::get_fuel_rate(){
	return fuelrate;
}
int Service:: get_cid(){
	return cId;
}
int Service::get_vid() {
	return vId;
}
int Service::get_did() {
	return dId;
}

//virtual functions
ostream& Service::output(ostream& out) {
	out << "Customer ID :" << cId << endl;
	out << "Driver ID :" << dId << endl;
	out << "Vehicle ID :" << vId << endl;
	out << "Source :" << source << endl;
	out << "Destination :" << destination << endl;
	out << "Distance :" << distance << endl;
	out << "Fuel Rate :" << fuelrate << endl;
	out <<"Booking Date :" << bookingDate;
	out << "Booking Time :" << bookingTime << endl;
	out << "Status :";
	if (status == true) {
		out << "Free" << endl;
	}
	else {
		out << "Booked" << endl;
	}
	return out;
}
istream& Service::input(istream& in) {
	cout << "Enter Customer ID :";
	in >> cId;
	while (cId <= 0) {
		cout << "Inavlid Customer ID" << endl;
		cout << "Enter Customer ID :";
		in >> cId;
	}
	cout << "Enter Driver ID :";
	in >> dId;
	while (dId <= 0) {
		cout << "Inavlid Driver ID" << endl;
		cout << "Enter Driver ID :";
		in >> dId;
	}
	cout << "Enter Vehicle ID :";
	in >> vId;
	while (vId <= 0) {
		cout << "Inavlid Vehicle ID" << endl;
		cout << "Enter Vehicle ID :";
		in >> vId;
	}
	cout << "Enter Source :" ;
	source = new char[15];
	in >> source;
	cout << "Enter Destination :";
	destination = new char[15];
	in >> destination;
	cout << "Enter Distance :";
	in >> distance;
	while (distance <= 0) {
		cout << "Invalid Distance" << endl;
		cout << "Enter Distance :";
		in >> distance;
	}
	cout << "Enter Fuel rate :";
	in >> fuelrate;
	while (fuelrate <= 0) {
		cout << "Inavlid Fuel rate" << endl;
		cout << "Enter Fuel rate :";
		in >> fuelrate;
	}
	cout << "Enter Booking Date :" << endl;
	in >> bookingDate;
	cout << "Enter Booking Time "<<endl;
	in >> bookingTime;
	cout << "Enter Status :" << endl;
	int temp;
	cout << "Enter 1 for Free\nEnter 2 for Completed" << endl;
	in >> temp;
	if (temp == 1) {
		status = true;
	}
	else if (temp == 2) {
		status = false;
	}
	else {
		while (temp < 1 || temp>2) {
			cout << "Invalid status" << endl;
			cout << "Enter 1 for Free\nEnter 2 for Completed" << endl;
			in >> temp;
		}
		if (temp == 1) {
			status = true;
		}
		else if (temp == 2) {
			status = false;
		}
	}
	return in;
}
ofstream& Service::write(ofstream& fout) {
	fout << cId << " ";
	fout << dId << " ";
	fout << vId << " ";
	fout << source << " ";
	fout << destination << " ";
	fout << distance << " ";
	fout << fuelrate << " ";
	fout << bookingDate;
	fout << bookingTime;
	if (status == true) {
		fout << "1" << " ";
	}
	else {
		fout << "0" << " ";
	}
	return fout;
}
ifstream& Service::read(ifstream& fin) {
	fin >> cId;
	fin >> dId;
	fin >> vId;
	source = new char[10];
	fin >> source;
	destination = new char[10];
	fin >> destination;
	fin >> distance;
	fin >> fuelrate;
	fin >> bookingDate;
	fin >> bookingTime;
	int temp = 0;
	fin >> temp;
	if (temp == 1) {
		status = true;
	}
	else {
		status = false;
	}
	return fin;
}

//ostream and istream fucntions
ostream& operator << (ostream& out, Service& s) {
	s.output(out);
	return out;
}
istream& operator >> (istream& in, Service& s) {
	s.input(in);
	return in;
}

//ofstream andifstream functions
ofstream& operator << (ofstream& out, Service& s) {
	s.write(out);
	return out;
}
ifstream& operator >> (ifstream& out, Service& s) {
	s.read(out);
	return out;
}

Service::~Service() {
	if (source != nullptr) {
		delete[]source;
		source = nullptr;
	}
	if (destination != nullptr) {
		delete[]destination;
		destination = nullptr;
	}
}