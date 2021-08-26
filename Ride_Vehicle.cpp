#include "Ride_Vehicle.h"

const char* ride_vehicle::get_vehicle_service_category() {
	return "ride";
}

//constructors
bike::bike(int vid, int rno, float mil, char* lic, char* ftype, float rank, int d, int m, int y) :Vehicle(vid, rno, mil, lic, ftype, rank, d, m, y),ride_vehicle(vid,rno,mil,lic,ftype,rank,d,m,y),delivery_vehicle(vid,rno,mil,lic,ftype,rank,d,m,y) {
	noofpassengers = 2;
}
//getters
int bike::get_noofpassengers() {
	return noofpassengers;
}
const char* bike::get_vehicle_service_category() {
	return"ride and delivery";
}
const char* bike::get_ridetype() {
	return "intercity";
}
//virtual functions
ostream& bike::output(ostream& out) {
	Vehicle::output(out);
	out << "Passengers Allowed :" << noofpassengers << endl;
	return out;
}
istream& bike::input(istream& in) {
	Vehicle::input(in);
	return in;
}
ofstream& bike::write(ofstream& fout) {
	Vehicle::write(fout);
	fout << " ";
	fout << noofpassengers;
	return fout;
}
ifstream& bike::read(ifstream& fin) {
	Vehicle::read(fin);
	fin >> noofpassengers;
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