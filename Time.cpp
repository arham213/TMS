#include "Time.h"

//constrcutors
mTime::mTime(int h, int m, int s) {
	if (h > 0 && h < 25) {
		hour = h;
	}
	else {
		hour = 0;
	}
	if (m > 0 && m < 61) {
		min = m;
	}
	else {
		min = 0;
	}
	if (s > 0 && s < 61) {
		sec = s;
	}
	else {
		sec = 0;
	}
}
mTime::mTime(const mTime& m) {
	hour = m.hour;
	min = m.min;
	sec = m.sec;
}

//setters
void mTime::set_time(int h, int m, int s) {
	if (h > 0 && h < 25) {
		hour = h;
	}
	else {
		while (h <= 0 || h >= 25) {
			cout << "Invalid hour" << endl;
			cout << "Enter hour :";
			cin >> h;
		}
		hour = h;
	}
	if (m > 0 && m < 61) {
		min = m;
	}
	else {
		while (m <= 0 || m >= 61) {
			cout << "Invalid minute" << endl;
			cout << "Enter minute :";
			cin >> m;
		}
		min = m;
	}
	if (s > 0 && s < 61) {
		sec = s;
	}
	else {
		while (s <= 0 || s >= 61) {
			cout << "Invalid second" << endl;
			cout << "Enter second :";
			cin >> s;
		}
		sec = s;
	}
}
void mTime::set_hour(int h) {
	if (h > 0 && h < 25) {
		hour = h;
	}
	else {
		while (h <= 0 || h >= 25) {
			cout << "Invalid hour" << endl;
			cout << "Enter hour :";
			cin >> h;
		}
		hour = h;
	}
}
void mTime::set_min(int m) {
	if (m > 0 && m < 61) {
		min = m;
	}
	else {
		while (m <= 0 || m >= 61) {
			cout << "Invalid minute" << endl;
			cout << "Enter minute :";
			cin >> m;
		}
		min = m;
	}
}
void mTime::set_sec(int s) {
	if (s > 0 && s < 61) {
		sec = s;
	}
	else {
		while (s <= 0 || s >= 61) {
			cout << "Invalid second" << endl;
			cout << "Enter second :";
			cin >> s;
		}
		sec = s;
	}
}

//getters
mTime mTime::get_time() {
	return *this;
}
int mTime::get_hour() {
	return hour;
}
int mTime::get_min() {
	return min;
}
int mTime::get_sec() {
	return sec;
}

//ostream and istream
ostream& operator<< (ostream& out, mTime& m) {
	if (m.hour < 10) {
		out <<"0"<< m.hour << ":";
	}
	else {
		out << m.hour << ":";
	}
	if (m.min < 10) {
		out << "0" << m.min << ":";
	}
	else {
		out << m.min << ":";
	}
	if (m.sec < 10) {
		out <<"0"<< m.sec;
	}
	else {
		out << m.sec;
	}
	return out;
}
istream& operator>>(istream& in, mTime& m) {
	cout << "Enter hour in 24hrs format :";
	in >> m.hour;
	while (m.hour <= 0 && m.hour >= 25) {
		cout << "Invalid hour" << endl;
		cout << "Enter hour in 24hrs format :";
		in >> m.hour;
	}
	cout << "Enter minutes :";
	in >> m.min;
	while (m.min <= 0 && m.min >= 61) {
		cout << "Invalid minutes" << endl;
		cout << "Enter minutes :";
		in >> m.min;
	}
	cout << "Enter seconds :";
	in >> m.sec;
	while (m.sec <= 0 && m.sec >= 61) {
		cout << "Invalid second" << endl;
		cout << "Enter seconds :";
		in >> m.sec;
	}
	return in;
}
ofstream& operator<<(ofstream& fout, mTime& m) {
	fout << m.hour<<" ";
	fout << m.min<<" ";
	fout << m.sec<<" ";
	return fout;
}
ifstream& operator>>(ifstream& fin, mTime& m) {
	fin >> m.hour;
	fin >> m.min;
	fin >> m.sec;
	return fin;
}