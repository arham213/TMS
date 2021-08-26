#include "Driver.h"

Driver:://constructor
Driver(int did, float rank, float sal, int exp, int status, char* fn, char* ln, int d, int m, int y, int age, int nid) :Person(fn, ln, d, m, y, age, nid) {
	ranking_no = 0;
	service_no = 0;
	noofLicences = 0;
	if (did > 0) {
		dId = did;
	}
	else {
		did = 0;
	}
	if (rank >= 0&&rank<=5) {
		overallRanking = rank;
		ranking_no++;
	}
	else {
		overallRanking = 0;
	}
	if (salary > 0) {
		salary = sal;
	}
	else {
		salary = 0;
	}
	if (exp >= 0) {
		experience = exp;
	}
	else {
		experience = 0;
	}
	if (status == 1 || status == 2 || status == 3) {
		this->status = status;
	}
	else {
		status = 1;
	}
}

//setters
void Driver::set_driver(int did, float rank, float salary, int exp, int status, char* fn, char* ln, int d, int m, int y, int age, int nid) {
	if (did > 0) {
		dId = did;
	}
	else {
		while (did <= 0) {
			cout << "Inavlid Driver ID " << endl;
			cout << "Enter Druver ID :";
			cin >> did;
		}
		dId = did;
	}
	if (rank >= 0&&rank<=5) {
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
		while (rank < 0||rank>5) {
			cout << "Inavvlid Ranking" << endl;
			cout << "Ennter Driver Ranking on sacle of 0-5 :";
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
	if(salary > 0) {
		this->salary = salary;
	}
	else {
		while (salary <= 0) {
			cout << "INavlid Salary" << endl;
			cout << "Enter Driver Salary :";
			cin >> salary;
		}
		this->salary = salary;
	}
	if (exp >= 0) {
		experience = exp;
	}
	else {
		while (exp < 0) {
			cout << "Inavlid Experience " << endl;
			cout << "Enter Driver Exereince :";
			cin >> exp;
		}
		experience = exp;
	}
	if (status == 1 || status == 2 || status == 3) {
		this->status = status;
	}
	else {
		while (status < 1 || status>3) {
			cout << "Inavlid Status" << endl;
			cout << "Enter driver Status :";
			cin >> status;
		}
		this->status = status;
	}
	Person::set_Person(fn, ln, d, m, y, age, nid);
}
void Driver::set_did(int did) {
	if (did > 0) {
		dId = did;
	}
	else {
		while (did <= 0) {
			cout << "Inavlid Driver ID " << endl;
			cout << "Enter Driver ID :";
			cin >> did;
		}
		dId = did;
	}
}
void Driver::add_licence() {
	if (noofLicences == 0) {
		LicencesList = new char* [1];
		LicencesList[0] = new char[20];
		cout << "Enter the Driver Licence :";
		cin >> LicencesList[0];
		noofLicences++;
	}
	else {
		char** temp = new char* [noofLicences + 1];
		for (int i = 0; i < noofLicences + 1; i++) {
			temp[i] = new char[20];
		}
		int i;
		for (i = 0; i < noofLicences; i++) {
			strcpy(temp[0], LicencesList[0]);
		}
		cout << "Enter the Driver Licence :";
		cin >> temp[i];
		for (int i = 0; i < noofLicences; i++) {
			delete[]LicencesList[i];
		}
		delete[]LicencesList;
		LicencesList = temp;
		temp = nullptr;
		noofLicences++;
	}
}
void Driver::add_service(Service* s) {
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
		delete[]serviceHistory;
		temp[i] = s;
		serviceHistory = temp;
		temp = nullptr;
		service_no++;
	}
}
void Driver::set_ranking(float rank) {
	if (rank >= 0&&rank<=5) {
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
		while (rank < 0||rank>5) {
			cout << "Inavvlid Ranking" << endl;
			cout << "Ennter Driver Ranking on sacle of 0-5 :";
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
void Driver::set_salary(float sal) {
	if (salary > 0) {
		this->salary = salary;
	}
	else {
		while (salary <= 0) {
			cout << "INavlid Salary" << endl;
			cout << "Enter Driver Salary :";
			cin >> salary;
		}
		this->salary = salary;
	}
}
void Driver::set_expereince(int exp) {
	if (exp >= 0) {
		experience = exp;
	}
	else {
		while (exp < 0) {
			cout << "Inavlid Experience " << endl;
			cout << "Enter Driver Exereince :";
			cin >> exp;
		}
		experience = exp;
	}
}
void Driver::set_status(int s) {
	if (status == 1 || status == 2 || status == 3) {
		this->status = status;
	}
	else {
		while (status < 1 && status>3) {
			cout << "Inavlid Status" << endl;
			cout << "Enter driver Status :";
			cin >> status;
		}
		this->status = status;
	}
}

//getters
Driver Driver::get_driver() {
	return *this;
}
char** Driver::get_licences() {
	return LicencesList;
}
int Driver::get_nooflicences() {
	return noofLicences;
}
float Driver::get_driver_ranking() {
	return overallRanking;
}
float Driver::get_salary() {
	return salary;
}
int Driver::get_experience() {
	return experience;
}
int Driver::get_status() {
	return status;
}

//virtual functions
ostream& Driver::output(ostream& out) {
	out << "Driver ID :" << dId << endl;
	Person::output(out);
	out << "Overall Ranking :" << overallRanking << endl;
	out << "Salary :" << salary << endl;
	out << "Expereience :" << experience << endl;
	out << "Status :";
	if (status == 1) {
		out << "Free" << endl;
	}
	else if (status == 2) {
		out << "Booked" << endl;
	}
	else {
		out << "Cancelled" << endl;
	}
	if (noofLicences == 0) {
		cout << "Driver has no Licences" << endl;
	}
	else {
		for (int i = 0; i < noofLicences; i++) {
			out << "-----------------------------------------" << endl;
			out << "Licence No :" << i + 1 << endl;
			out << LicencesList[i] << endl;
		}
		if (service_no == 0) {
			out << "-----------------------------------------" << endl;
		}
	}
	if (service_no == 0) {
		out << "Driver has no Service History" << endl;
	}
	else {
		for (int i = 0; i < service_no; i++) {
			cout << "------------------------------------" << endl;
			cout << "Service No :" << i + 1 << endl;
			out << serviceHistory[i][0];
		}
	}
	return out;
}
istream& Driver::input(istream& in) {
	cout << "Enter Driver ID :";
	in >> dId;
	Person::input(in);
	while (dId <= 0) {
		cout << "Inavlid Driver ID" << endl;
		cout << "Enter Driver ID :";
		in >> dId;
	}
	cout << "Enter Driver Ranking on sacle of 0-5 :";
	in >> overallRanking;
	while (overallRanking < 0 && overallRanking>5) {
		cout << "Inavlid Ranking" << endl;
		cout << "Enter Driver Ranking on sacle of 0-5 :" << endl;
		in >> overallRanking;
	}
	cout << "Enter Driver Salary :";
	in >> salary;
	while (salary < 0) {
		cout << "Inavlid Salary" << endl;
		cout << "Enter Driver Salary :";
		in >> salary;
	}
	cout << "Enter Driver Expereince :";
	in >> experience;
	while (experience < 0) {
		cout << "Invalid Experience" << endl;
		cout << "Enter Driver Expereince :";
		in >> experience;
	}
	cout << "Enter Driver Status\n1.Free\n2.Booked\n3.Cancelled" << endl;
	in >> status;
	while (status < 1 || status>3) {
		cout << "Invalid Staus" << endl;
		cout << "Enter Driver Status\1.Free\n2.Booked\n3.Cancelled" << endl;
		in >> status;
	}
	int temp;
	cout << "Enter 1 to add Driver Licence\nEnter 2 to skip" << endl;
	in >> temp;
	while (temp < 1 || temp>2) {
		cout << "Invalid choice" << endl;
		cout << "Enter 1 to add Driver Licence\nEnter 2 to skip" << endl;
		in >> temp;
	}
	while (temp == 1) {
		if (noofLicences == 0) {
			noofLicences++;
			LicencesList = new char* [noofLicences];
			LicencesList[0] = new char[20];
			cout << "Enter Driver Licence :";
			in.ignore();
			in.getline(LicencesList[0], 20);
		}
		else {
			char** temp = new char* [noofLicences + 1];
			for (int i = 0; i < noofLicences + 1; i++) {
				temp[i] = new char[20];
			}
			int j;
			for (j = 0; j < noofLicences; j++) {
				strcpy(temp[j], LicencesList[j]);
			}
			cout << "Enter Driver Licence :";
			in.ignore();
			in.getline(temp[j], 20);
			for (int i = 0; i < noofLicences; i++) {
				delete[]LicencesList[i];
			}
			delete[]LicencesList;
			LicencesList = temp;
			temp = nullptr;
			noofLicences++;
		}
		cout << "Enter 1 to add Driver Licence\nEnter 2 to skip" << endl;
		in >> temp;
		while (temp < 1 || temp>2) {
			cout << "Invalid choice" << endl;
			cout << "Enter 1 to add Driver Licence\nEnter 2 to skip" << endl;
			in >> temp;
		}
	}
	return in;
}
ofstream& Driver::write(ofstream& fout) {
	fout << dId << " ";
	Person::write(fout);
	fout << overallRanking << " ";
	fout << salary << " ";
	fout << experience << " ";
	fout << status << " ";
	fout << noofLicences << " ";
	/*for (int i = 0; i < noofLicences; i++) {
		fout << LicencesList[i] << endl;
	}*/
	for (int i = 0; i < noofLicences; i++) {
		int j = 0;
		while (LicencesList[i][j] != '\0') {
			if (LicencesList[i][j] == ' ') {
				fout << "-";
			}
			else {
				fout << LicencesList[i][j];
			}
			j++;
		}
		fout << "*";
	}
	return fout;
}
ifstream& Driver::read(ifstream& fin) {
	fin >> dId;
	Person::read(fin);
	fin >> overallRanking;
	fin >> salary;
	fin >> experience;
	fin >> status;
	fin >> noofLicences;
	//if (noofLicences > 0) {
	//	LicencesList = new char* [noofLicences];
	//	for (int i = 0; i < noofLicences; i++) {
	//		LicencesList[i] = new char[20];
	//		fin.getline(LicencesList[i], 20);
	//	}
	//	/*for (int i = 0; i < noofLicences; i++) {
	//		int j = 0;
	//		fin >> LicencesList[i][j];
	//		while (LicencesList[i][j] != '*') {
	//			if (LicencesList[i][j] == '-') {
	//				LicencesList[i][j] = ' ';
	//			}
	//			j++;
	//			fin >> LicencesList[i][j];
	//		}
	//		LicencesList[i][j] = '\0';
	//	}
	//	cout << LicencesList[0] << endl;
	//	cout << LicencesList[1] << endl;*/
	//}
	if (noofLicences > 0) {
		LicencesList = new char* [noofLicences];
		for (int i = 0; i < noofLicences; i++) {
			LicencesList[i] = new char[20];
		}
		for (int i = 0; i < noofLicences; i++) {
			int j = 0;
			char temp;
			fin >> temp;
			LicencesList[i][j] = temp;
			j++;
			while (temp != '*') {
				fin >> temp;
				if (temp == '-') {
					LicencesList[i][j] = ' ';
				}
				else if(temp!='*') {
					LicencesList[i][j] = temp;
				}
				j++;
			}
			LicencesList[i][j-1] = '\0';
		}
	}
	return fin;
}

ostream& operator<<(ostream& out, Driver& d) {
	d.output(out);
	return out;
}
istream& operator>>(istream&in,Driver&d){
	d.input(in);
	return in;
}

ofstream& operator<<(ofstream& fout, Driver& d) {
	d.write(fout);
	return fout;
}
ifstream& operator>>(ifstream& fin, Driver& d) {
	d.read(fin);
	return fin;
}

Driver::~Driver() {
	if (noofLicences > 0) {
		for (int i = 0; i < noofLicences; i++) {
			delete[]LicencesList[i];
		}
		delete[]LicencesList;
		LicencesList = nullptr;
	}
}

