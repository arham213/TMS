#include "Feature.h"

//constructor
Feature::Feature(int fid, char* des, float cost) {
	if (fid > 0) {
		fId = fid;
	}
	else {
		fId = 0;
	}
	if (des != nullptr) {
		description = new char[strlen(des) + 1];
		strcpy(description, des);
	}
	else {
		description = des;
	}
	if (cost > 0) {
		this->cost = cost;
	}
	else {
		this->cost = 0;
	}
}

//setters
void Feature::set_feature(int fid, char* des, float cost) {
	if (fid > 0) {
		fId = fid;
	}
	else {
		while (fid <= 0) {
			cout << "Invalid Feature ID " << endl;
			cout << "Enter Feature ID " << endl;
			cin >> fid;
		}
		fId = fid;
	}
	if (des != nullptr) {
		description = new char[strlen(des) + 1];
		strcpy(description, des);
	}
	else {
		cout << "Enter Feature Description, not more than 50 characters :";
		description = new char[51];
		cin.getline(description, 51);
	}
	if (cost > 0) {
		this->cost = cost;
	}
	else {
		this->cost = 0;
	}
}
void Feature::set_fid(int fid) {
	if (fid > 0) {
		fId = fid;
	}
	else {
		while (fid <= 0) {
			cout << "Invalid Feature ID " << endl;
			cout << "Enter Feature ID " << endl;
			cin >> fid;
		}
		fId = fid;
	}
}
void Feature::set_description(char* des) {
	if (des != nullptr) {
		description = new char[strlen(des) + 1];
		strcpy(description, des);
	}
	else {
		cout << "Enter Feature Description, not more than 50 characters :";
		description = new char[51];
		cin.getline(description, 51);
	}
}
void Feature::set_cost(float cost) {
	if (cost > 0) {
		this->cost = cost;
	}
	else {
		this->cost = 0;
	}
}

//getters
Feature Feature::get_feature() {
	return *this;
}
int Feature::get_fid() {
	return fId;
}
char* Feature::get_description() {
	return description;
}
float Feature::get_cost() {
	return cost;
}

//virtual functions
ostream& Feature::output(ostream& out) {
	out << "Feature ID :" << fId << endl;
	out << "Feature Description :" << description << endl;
	out << "Feature Cost :" << cost << endl;
	return out;
}
istream& Feature::input(istream& in) {
	cout << "Enter Feature ID :";
	in >> fId;
	while (fId <= 0) {
		cout << "Inavlid Feature ID " << endl;
		cout << "Enter Feature ID :";
		in >> fId;
	}
	cout << "Enter Feature Description, not more than 50 Characters :";
	description = new char[51];
	in.ignore();
	in.getline(description, 51);
	cout << "Enter Feature Cost :";
	in >> cost;
	while (cost <= 0) {
		cout << "Invalid Cost " << endl;
		cout << "Enter Feature Cost :";
		in >> cost;
	}
	return in;
}
ofstream& Feature::write(ofstream& fout) {
	fout << fId << " ";
	fout << cost << " ";
	int i = 0;
	while (description[i] != '\0') {
		if (description[i] == ' ') {
			fout << "-";
		}
		else {
			fout << description[i];
		}
		i++;
	}
	fout << "*";
	return fout;
}
ifstream& Feature::read(ifstream& fin) {
	fin >> fId;
	fin >> cost;
	int i = 0;
	description = new char[51];
	char temp;
	fin >> temp;
	description[i] = temp;
	i++;
	while (temp != '*') {
		fin >> temp;
		if (temp == '-') {
			description[i] = ' ';
		}
		else {
			description[i] = temp;
		}
		i++;
	}
	description[i-1] = '\0';
	return fin;
}

//ostream and istream functions
ostream& operator<<(ostream& out, Feature& d) {
	d.output(out);
	return out;
}
istream& operator>>(istream& in, Feature& d) {
	d.input(in);
	return in;
}

//ofstream and ifstream functions
ofstream& operator<<(ofstream& fout, Feature& d) {
	d.write(fout);
	return fout;
}
ifstream& operator>>(ifstream& fin, Feature& d) {
	d.read(fin);
	return fin;
}

//destructor
Feature::~Feature() {
	if (description != nullptr) {
		delete[]description;
		description = nullptr;
	}
}