#include "Ride.h"

//constructors
Ride::Ride(int psg, char* type, float drank, float vrank, char* src, char* des, float dis, int d, int m, int y, int hr, int min, int sec, float frate, int cid, int did, int vid) :Service(src, des, dis, d, m, y, hr, min, sec, frate, cid, did, vid) {
	if (type != nullptr ) {
		if (strcmp(type, "intercity") == 0 || strcmp(type, "intracity") == 0) {
			rideType = new char[strlen(type) + 1];
			strcpy(rideType, type);
		}
	}
	else {
		rideType = nullptr;
	}
	if (psg > 0) {
		noofPassengers = psg;
	}
	else { 
		psg = 0; 
	}
	if (drank >= 0) {
		DriverRanking = drank;
	}
	else {
		DriverRanking = 0;
	}
	if (vrank >= 0) {
		VehicleRanking = vrank;
	}
	else {
		VehicleRanking = 0;
	}

}

//setters
void Ride::set_Ride(int psg, char* type, float drank, float vrank, char* src, char* des, float dis, int d, int m, int y, int hr, int min, int sec, float frate, int cid, int did, int vid) {
	Service::set_service(src, des, dis, d, m, y, hr, min, sec, frate, cid, did, vid);
	if (type != nullptr&& strcmp(type, "intercity") == 0 || strcmp(type, "intracity") == 0) {
		rideType = new char[strlen(type) + 1];
		strcpy(rideType, type);
	}
	else {
		cout << "Enter ridetype, intercity or intracity" << endl;
		rideType = new char[10];
		cin >> rideType;
		while (strcmp(rideType, "intercity") != 0 || strcmp(rideType, "intracity") != 0) {
			cout << "Invalid ride type" << endl;
			cout << "Enter ridetype\n1.intercity\n2.intracity" << endl;
			cin >> rideType;
		}
	}
	if (psg > 0) {
		noofPassengers = psg;
	}
	else {
		while (psg <= 0) {
			cout << "Invalid passenger number" << endl;
			cout << "Enter no of passengers :";
			cin >> psg;
		}
		noofPassengers = psg;
	}
	if (drank >= 0) {
		DriverRanking = drank;
	}
	else {
		while (drank < 0) {
			cout << "Invalid driver ranking" << endl;
			cout << "Enter driver ranking on scale of 0-5 :";
			cin >> drank;
		}
		DriverRanking = drank;
	}
	if (vrank >= 0) {
		VehicleRanking = vrank;
	}
	else {
		while (vrank < 0) {
			cout << "Invalid vehicle ranking " << endl;
			cout << "Enter vehicle ranking on scale of 0-5 :";
			cin >> vrank;
		}
		VehicleRanking = vrank;;
	}
}
void Ride::set_rideType(char* type) {
	if (type != nullptr && strcmp(type, "intercity") == 0 || strcmp(type, "intracity") == 0) {
		rideType = new char[strlen(type) + 1];
		strcpy(rideType, type);
	}
	else {
		cout << "Enter ridetype\n1.intercity\n2.intracity" << endl;
		rideType = new char[10];
		cin >> rideType;
		while (strcmp(rideType, "intercity") != 0 || strcmp(rideType, "intracity") != 0) {
			cout << "Invalid ride type" << endl;
			cout << "Enter ridetype\n1.intercity\n2.intracity" << endl;
			cin >> rideType;
		}
	}
}
void Ride::set_driver_ranking(float drank) {
	if (drank >= 0) {
		DriverRanking = drank;
	}
	else {
		while (drank < 0) {
			cout << "Invalid driver ranking" << endl;
			cout << "Enter driver ranking on scale of 0-5 :";
			cin >> drank;
		}
		DriverRanking = drank;
	}
}
void Ride::set_vehicle_ranking(float vrank) {
	if (vrank >= 0) {
		VehicleRanking = vrank;
	}
	else {
		while (vrank < 0) {
			cout << "Invalid vehicle ranking " << endl;
			cout << "Enter vehicle ranking on scale of 0-5 :";
			cin >> vrank;
		}
		VehicleRanking = vrank;;
	}
}
void Ride::set_noofpassengers(int psg) {
	if (psg > 0) {
		noofPassengers = psg;
	}
	else {
		while (psg <= 0) {
			cout << "Invalid passenger number" << endl;
			cout << "Enter no of passengers :";
			cin >> psg;
		}
		noofPassengers = psg;
	}
}

//getters
Ride Ride::get_ride() {
	return *this;
}
char* Ride::get_rideType() {
	return rideType;
}
float Ride::get_driver_ranking() {
	return DriverRanking;
}
float Ride::get_vehicle_ranking() {
	return VehicleRanking;
}
int Ride::get_noofpassengers() {
	return noofPassengers;
}

//virtual functions
ostream& Ride::output(ostream& out) {
	Service::output(out);
	out << "Ride Type :" << rideType << endl;
	out << "No of Passengers :" << noofPassengers << endl;
	out << "Driver Ranking :" << DriverRanking << endl;
	out << "Vehicle Ranking :" << VehicleRanking << endl;
	return out;
}
istream& Ride::input(istream& in) {
	Service::input(in);
	cout << "Enter no of passengers :";
	in >> noofPassengers;
	while (noofPassengers <= 0) {
		cout << "Invalid no of passengers" << endl;
		cout << "Enter no of passengers :";
		in >> noofPassengers;
	}
	cout << "Enter ridetype\n1.intercity\n2.intracity" << endl;
	rideType = new char[10];
	in >> rideType;
	while (strcmp(rideType, "intercity") != 0 && strcmp(rideType, "intracity") != 0) {
		cout << "Invalid ride type" << endl;
		cout << "Enter ridetype\n1.intercity\n2.intracity" << endl;
		in >> rideType;
	}
	cout << "Enter driver ranking on sacle of 0-5 :";
	in >> DriverRanking;
	while (DriverRanking < 0) {
		cout << "Invalid driver ranking" << endl;
		cout << "Enter driver ranking on scale of 0-5 :";
		in >> DriverRanking;
	}
	cout << "Enter vehicle ranking on sacle of 0-5 :";
	in >> VehicleRanking;
	while (VehicleRanking < 0) {
		cout << "Invalid vehicle ranking" << endl;
		cout << "Enter vehicle ranking on scale of 0-5 :";
		in >> VehicleRanking;
	}
	return in;
}
ofstream& Ride::write(ofstream& fout) {
	Service::write(fout);
	fout << noofPassengers << " ";
	fout << rideType << " ";
	fout << DriverRanking << " ";
	fout << VehicleRanking << " ";
	return fout;
}
ifstream& Ride::read(ifstream& fin) {
	Service::read(fin);
	fin >> noofPassengers;
	rideType = new char[10];
	fin >> rideType;
	fin >> DriverRanking;
	fin >> VehicleRanking;
	return fin;
}

//ostream ad istream fucntions
ostream& operator << (ostream& out, Ride& r) {
	r.output(out);
	return out;
}
istream& operator>>(istream& in, Ride& r) {
	r.input(in);
	return in;
}
//ofstream and ifstream functions
ofstream& operator << (ofstream& fout, Ride& r) {
	r.write(fout);
	return fout;
}
ifstream& operator>>(ifstream& fin, Ride& r) {
	r.read(fin);
	return fin;
}
//destructor
Ride::~Ride() {
	if (rideType != nullptr) {
		delete[]rideType;
		rideType = nullptr;
	}
}