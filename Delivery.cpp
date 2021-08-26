#include "Delivery.h"

//constructors
Delivery::Delivery(float wgt, char* type, char* src, char* des, float dis, int d, int m, int y, int hr, int min, int sec, float frate, int cid, int did, int vid) :Service(src, des, dis, d, m, y, hr, min, sec, frate, cid, did, vid) {
	if (wgt > 0) {
		goodsWeight = wgt;
	}
	else {
		goodsWeight = 0;
	}
	if (type != nullptr) {
		goodsType = new char[15];
		strcpy(goodsType, type);
	}
}

//setters
void Delivery::set_Delivery(float wgt, char* type, char* src, char* des, float dis, int d, int m, int y, int hr, int min, int sec, float frate, int cid, int did, int vid) {
	Service::set_service(src, des, dis, d, m, y, hr, min, sec, frate, cid, did, vid);
	if (wgt > 0) {
		goodsWeight = wgt;
	}
	else {
		cout << "Enter goods Weight :";
		cin >> wgt;
		while (wgt <= 0) {
			cout << "Invalid goods weight" << endl;
			cout << "Enter goods Weight :";
			cin >> wgt;
		}
		goodsWeight = wgt;
	}
	if (type != nullptr) {
		goodsType = new char[15];
		strcpy(goodsType, type);
	}
	else {
		goodsType = new char[15];
		cout << "Enter goods type :";
		cin >> goodsType;
	}
}
void Delivery::set_goods_weight(float wgt) {
	if (wgt > 0) {
		goodsWeight = wgt;
	}
	else {
		cout << "Enter goods Weight :";
		cin >> wgt;
		while (wgt <= 0) {
			cout << "Invalid goods weight" << endl;
			cout << "Enter goods Weight :";
			cin >> wgt;
		}
		goodsWeight = wgt;
	}
}
void Delivery::set_goods_type(char* type) {
	if (type != nullptr) {
		goodsType = new char[15];
		strcpy(goodsType, type);
	}
	else {
		goodsType = new char[15];
		cout << "Enter goods type :";
		cin >> goodsType;
	}
}

//getters
Delivery Delivery::get_delivery() {
	return *this;
}
float Delivery::get_goods_weight() {
	return goodsWeight;
}
char* Delivery::get_goods_type() {
	return goodsType;
}

//virtual functions
ostream& Delivery::output(ostream& out) {
	Service::output(out);
	out << "Goods Type :" << goodsType << endl;
	out << "Goods Weight :" << goodsWeight << endl;
	return out;
}
istream& Delivery::input(istream& in) {
	Service::input(in);
	cout << "Enter goods weight :";
	in >> goodsWeight;
	while (goodsWeight <= 0) {
		cout << "Invalid goods weight" << endl;
		cout << "Enter goods weight :";
		cin >> goodsWeight;
	}
	goodsType = new char[15];
	cout << "Enter goods type :";
	in >> goodsType;
	return in;
}
ofstream& Delivery::write(ofstream& fout) {
	Service::write(fout);
	fout << goodsWeight << " ";
	fout << goodsType << " ";
	return fout;
}
ifstream& Delivery::read(ifstream& fin) {
	Service::read(fin);
	fin >> goodsWeight;
	goodsType = new char[15];
	fin >> goodsType;
	return fin;
}

//ostream and istream functions
ostream& operator<<(ostream& out, Delivery& d) {
	d.output(out);
	return out;
}
istream& operator>>(istream& in, Delivery& d) {
	d.input(in);
	return in;
}

//ofstream and ifstream functions
ofstream& operator<<(ofstream& fout, Delivery& d) {
	d.write(fout);
	return fout;
}
ifstream& operator>>(ifstream& fin, Delivery& d) {
	d.read(fin);
	return fin;
}

//destructor
Delivery::~Delivery() {
	if (goodsType != nullptr) {
		delete[]goodsType;
		goodsType = nullptr;
	}
}