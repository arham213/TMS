#include "Vehicle.h"

//constructor
Vehicle::Vehicle(int vid, int rno, float mil, char* lic, char* ftype, float rank, int d, int m, int y): manufacturingDate(d,m,y) {
	ranking_no = 0;
	service_no = 0;
	feature_no = 0;
	status = true;//free
	if (vid > 0) {
		vId = vid;
	}
	else {
		vId = 0;
	}
	if (rno > 0){
		registrationNo = rno;
	}
	else {
		registrationNo = 0;
	}
	if (mil > 0) {
		avgMileage = mil;
	}
	else {
		avgMileage = 0;
	}
	if (lic != nullptr) {
		LicenceType = new char[strlen(lic) + 1];
		strcpy(LicenceType, lic);
	}
	else {
		LicenceType = nullptr;
	}
	if (ftype != nullptr) {
		fueltype = new char[strlen(ftype) + 1];
		strcpy(fueltype, ftype);
	}
	else {
		fueltype = nullptr;
	}
	if (rank > 0) {
		overallRanking = rank;
		ranking_no++;
	}
	else {
		overallRanking = 0;
	}
}

//setters
void Vehicle::set_vehicle(int vid, int rno, float mil, char* lic, char* ftype, float rank, int d, int m, int y) {
	if (vid > 0) {
		vId = vid;
	}
	else {
		while (vid <= 0) {
			cout << "Invalid Vehicle ID" << endl;
			cout << "Enter Vehicle ID :";
			cin >> vid;
		}
		vId = vid;
	}
	if (rno > 0) {
		registrationNo = rno;
	}
	else {
		while (rno <= 0) {
			cout << "Invalid Registration N " << endl;
			cout << "Enter Registration No :";
			cin >> rno;
		}
		registrationNo = rno;
	}
	if (mil > 0) {
		avgMileage = mil;
	}
	else {
		while (mil <= 0) {
			cout << "Invalid Average Mileage" << endl;
			cout << "Enter Average Mileage :" << endl;
			cin >> mil;
		}
		avgMileage = mil;
	}
	if (lic != nullptr) {
		LicenceType = new char[strlen(lic) + 1];
		strcpy(LicenceType , lic);
	}
	else {
		LicenceType = new char[20];
		cout << "Enter Licence Type :";
		cin.getline(LicenceType, 20);
	}
	status = true;
	if (ftype != nullptr) {
		fueltype = new char[strlen(ftype) + 1];
		strcpy(fueltype, ftype);
	} 
	else {
		fueltype = new char[20];
		cout << "Enter Fuel Type :";
		cin.getline(fueltype, 20);
	}
	if (rank >= 0) {
		if (ranking_no == 0) {
			overallRanking = rank;
			ranking_no++;
		}
		else {
			ranking_no++;
			overallRanking = (overallRanking + rank) / ranking_no;
		}
	}
	else {
		while (rank < 0) {
			cout << "Invalid Ranking" << endl;
			cout << "Enter Vehicle Ranking on scale of 0-5 :";
			cin >> rank;
		}
		if (ranking_no == 0) {
			overallRanking = rank;
			ranking_no++;
		}
		else {
			ranking_no++;
			overallRanking = (overallRanking + rank) / ranking_no;
		}
	}
	manufacturingDate.set_date(d, m, y);
}
void Vehicle::set_vid(int vid) {
	if (vid > 0) {
		vId = vid;
	}
	else {
		while (vid <= 0) {
			cout << "Invalid Vehicle ID" << endl;
			cout << "Enter Vehicle ID :";
			cin >> vid;
		}
		vId = vid;
	}
}
void Vehicle::set_registrationNo(int rno) {
	if (rno > 0) {
		registrationNo = rno;
	}
	else {
		while (rno <= 0) {
			cout << "Invalid Registration N " << endl;
			cout << "Enter Registration No :";
			cin >> rno;
		}
		registrationNo = rno;
	}
}
void Vehicle::set_average_mileage(float mil) {
	if (mil > 0) {
		avgMileage = mil;
	}
	else {
		while (mil <= 0) {
			cout << "Invalid Average Mileage" << endl;
			cout << "Enter Average Mileage :" << endl;
			cin >> mil;
		}
		avgMileage = mil;
	}
}
void Vehicle::set_licence(char* lic) {
	if (lic != nullptr) {
		LicenceType = new char[strlen(lic) + 1];
		strcpy(LicenceType, lic);
	}
	else {
		LicenceType = new char[20];
		cout << "Enter Licence Type :";
		cin.getline(LicenceType, 20);
	}
}
void Vehicle::set_ride_status(bool stat) {
	status = stat;
}
void Vehicle::set_fuelType(char* ftype) {
	if (ftype != nullptr) {
		fueltype = new char[strlen(ftype) + 1];
		strcpy(fueltype, ftype);
	}
	else {
		fueltype = new char[20];
		cout << "Enter Fuel Type :";
		cin.getline(fueltype, 20);
	}
}
void Vehicle::set_overall_ranking(float rank) {
	if (rank >= 0) {
		if (ranking_no == 0) {
			overallRanking = rank;
			ranking_no++;
		}
		else {
			ranking_no++;
			overallRanking = (overallRanking + rank) / ranking_no;
		}
	}
	else {
		while (rank < 0) {
			cout << "Invalid Ranking" << endl;
			cout << "Enter Vehicle Ranking on scale of 0-5 :";
			cin >> rank;
		}
		if (ranking_no == 0) {
			overallRanking = rank;
			ranking_no++;
		}
		else {
			ranking_no++;
			overallRanking = (overallRanking + rank) / ranking_no;
		}
	}
}
void Vehicle::set_date(int d, int m, int y) {
	manufacturingDate.set_date(d, m, y);
}
void Vehicle::add_feature(Feature* f) {
	if (feature_no == 0) {
		feature_no++;
		list = new Feature * [feature_no];
		list[0] = f;
	}
	else {
		Feature** temp = new Feature * [feature_no + 1];
		int i;
		for (i = 0; i < feature_no; i++) {
			temp[i] = list[i];
		}
		temp[i] = f;
		delete[]list;
		list = temp;
		temp = nullptr;
		feature_no++;
	}
}
void Vehicle::add_service(Service* s) {
	if (service_no == 0) {
		service_no++;
		serviceHistory = new Service * [service_no];
		serviceHistory[0] = s;
	}
	else {
		Service** temp = new Service * [service_no + 1];
		int i;
		for (i = 0; i < service_no; i++) {
			temp[i] = serviceHistory[i];
		}
		temp[i] = s;
		delete[]serviceHistory;
		serviceHistory = temp;
		temp = nullptr;
		service_no++;
	}
}

//getters
int Vehicle::get_vid() {
	return vId;
}
int Vehicle::get_registrationNo() {
	return registrationNo;
}
float Vehicle::get_average_mileage() {
	return avgMileage;
}
char* Vehicle::get_licence() {
	return LicenceType;
}
bool Vehicle::get_ride_status() {
	return status;
}
char* Vehicle::get_fuelType() {
	return fueltype;
}
float Vehicle::get_overall_ranking() {
	return overallRanking;
}
Date Vehicle::get_date() {
	return manufacturingDate;
}

//virtual functions
ostream& Vehicle::output(ostream& out) {
	out << "Vehicle ID :" << vId << endl;
	out << "Registration NO :" << registrationNo << endl;
	out << "Average Mileage :" << avgMileage << endl;
	out << "Licence Type :" << LicenceType << endl;
	out << "Status :";
	if (status == true) {
		out << "Free" << endl;
	}
	else {
		out << "Booked" << endl;
	}
	out << "Fuel Type :" << fueltype << endl;
	out << "Overall Rankking :" << overallRanking << endl;
	out << "Manufacturing Date :" << manufacturingDate << endl;
	if (feature_no == 0) {
		out << "Vehicle has no Features" << endl;
	}
	else {
		for (int i = 0; i < feature_no; i++) {
			cout << "------------------------------------" << endl;
			cout << "Feature No :" << i + 1 << endl;
			out << list[i][0];
		}
	}
	if (service_no == 0) {
		cout << "------------------------------------" << endl;
		cout << "Vehicle has no Service History" << endl;
	}
	else {
		for (int i = 0; i < service_no; i++) {
			cout << "------------------------------------" << endl;
			cout << "Service No :" << i + 1 << endl;
			out << serviceHistory[i][0];
		}
		cout << "------------------------------------" << endl;
	}
	return out;

}
istream& Vehicle::input(istream& in) {
	cout << "Enter Vehicle ID :";
	in >> vId;
	while (vId <= 0) {
		cout << "Invalid Vehicle ID" << endl;
		cout << "Enter Vehicle ID :";
		in >> vId;
	}
	cout << "Enter Registration NO :";
	in >> registrationNo;
	while (registrationNo <= 0) {
		cout << "Invalid Registration NO " << endl;
		cout << "Enter Registration NO :";
		in >> registrationNo;
	}
	cout << "Enter Average Mileage :";
	in >> avgMileage;
	while (avgMileage <= 0) {
		cout << "Invalid Average Mileage " << endl;
		cout << "Enter Average Mileage :";
		in >> avgMileage;
	}
	cout << "Enter Licence Type :";
	LicenceType = new char[20];
	in.ignore();
	in.getline(LicenceType, 20);
	cout << "Enter Status\n1.Free\n2.Booked" << endl;
	int temp;
	in >> temp;
	while (temp < 1 && temp > 2) {
		cout << "Invalid Choice " << endl;
		cout << "Enter Status\n1.Free\n2.Booked" << endl;
		in >> temp;
	}
	if (temp == 1) {
		status = true;
	}
	else {
		status = false;
	}
	cout << "Enter Fuel Type :";
	fueltype = new char[20];
	in.ignore();
	in.getline(fueltype, 20);
	cout << "Enter Overall Ranking :";
	float temp1;
	in >> temp1;
	while (overallRanking < 0) {
		cout << "Invalid Overall Ranking" << endl;
		cout << "Enter Overall Ranking :";
		in >> temp1;
	}
	if (ranking_no == 0) {
		overallRanking = temp1;
		ranking_no++;
	}
	else {
		ranking_no++;
		overallRanking = (overallRanking + temp1) / ranking_no;
	}
	cout << "Enter Manufacturing Date " << endl;
	in >> manufacturingDate;
	cout << "Enter 1 to add Features\nEnter 2 to skip" << endl;
	in >> temp;
	while (temp < 1 && temp>2) {
		cout << "Invalid Choice " << endl;
		cout << "Enter 1 to add Features\n Enter 2 to skip" << endl;
		in >> temp;
	}
	while (temp == 1) {
		if (temp == 1) {
			if (feature_no == 0) {
				feature_no++;
				list = new Feature * [feature_no];
				list[0] = new Feature;
				in >> list[0][0];
			}
			else {
				Feature** temp = new Feature * [feature_no + 1];
				int i;
				for (i = 0; i < feature_no; i++) {
					temp[i] = list[i];
				}
				temp[i] = new Feature;
				in >> temp[i][0];
				delete[]list;
				list = temp;
				temp = nullptr;
				feature_no++;
			}
		}
		cout << "Enter 1 to add Features\n Enter 2 to skip" << endl;
		in >> temp;
		while (temp < 1 && temp>2) {
			cout << "Invalid Choice " << endl;
			cout << "Enter 1 to add Features\n Enter 2 to skip" << endl;
			in >> temp;
		}
	}
	return in;
}
ofstream& Vehicle::write(ofstream& fout) {
	fout << vId << " ";
	fout << registrationNo << " ";
	fout << avgMileage << " ";
	fout << status << " ";
	fout << overallRanking << " ";
	fout << ranking_no << " ";
	fout << manufacturingDate;
	int i = 0;
	while (LicenceType[i] != '\0') {
		if (LicenceType[i] == ' ') {
			fout << "-";
		}
		else {
			fout << LicenceType[i];
		}
		i++;
	}
	fout << "*";
	i = 0;
	while (fueltype[i] != '\0') {
		if (fueltype [i] == ' ') {
			fout << "-";
		}
		else {
			fout << fueltype[i];
		}
		i++;
	}
	fout << "*";
	if (feature_no > 0) {
		fout << feature_no << " ";
		for (int i = 0; i < feature_no; i++) {
			fout << list[i][0];
		}
	}
	return fout;
}
ifstream& Vehicle::read(ifstream& fin) {
	fin >> vId;
	fin >> registrationNo;
	fin >> avgMileage;
	int temp;
	fin >> temp;
	if (temp == 1) {
		status = true;
	}
	else {
		status = false;
	}
	fin >> overallRanking;
	fin >> ranking_no;
	fin >> manufacturingDate;
	//licencetype read
	LicenceType = new char[20];
	int i = 0;
	char temp2;
	fin >> temp2;
	LicenceType[i] = temp2;
	i++;
	while (temp2 != '*') {
		fin >> temp2;
		if (temp2 == '-') {
			LicenceType[i] = ' ';
		}
		else {
			LicenceType[i] = temp2;
		}
		i++;
	}
	LicenceType[i-1] = '\0';
	//fueltype read
	fueltype = new char[20];
	i = 0;
	fin >> temp2;
	fueltype[i] = temp2;
	i++;
	while (temp2 != '*') {
		fin >> temp2;
		if (temp2 == '-') {
			fueltype[i] = ' ';
		}
		else {
			fueltype[i] = temp2;
		}
		i++;
	}
	fueltype[i-1] = '\0';
	fin >> feature_no;
	if (feature_no > 0) {
		list = new Feature * [feature_no];
		for (int i = 0; i < feature_no; i++) {
			list[i] = new Feature;
			fin >> list[i][0];
		}
	}
	return fin;
}

//ostream and istream functions
ostream& operator<<(ostream& out, Vehicle& v) {
	v.output(out);
	return out;
}
istream& operator>>(istream& in, Vehicle& v) {
	v.input(in);
	return in;
}

//ofstream and ifstream functions
ofstream& operator<<(ofstream& fout, Vehicle& v) {
	v.write(fout);
	return fout;
}
ifstream& operator>>(ifstream& fin, Vehicle& v) {
	v.read(fin);
	return fin;
}

//destructor
Vehicle::~Vehicle() {
	if (LicenceType != nullptr) {
		delete[]LicenceType;
		LicenceType = nullptr;
	}
	if (fueltype != nullptr) {
		delete[]fueltype;
		fueltype = nullptr;
	}
	if (feature_no > 0) {
		for (int i = 0; i < feature_no; i++) {
			delete list[i];
		}
		delete[]list;
		list = nullptr;
	}
}