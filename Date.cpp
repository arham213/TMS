#include "Date.h"

//virtual fucntions
ostream& Date::output(ostream& out) {
	if (day < 10) {
		out << "0";
		out << day << "-";
	}
	else {
		out << day << "-";
	}
	if (month < 10) {
		out << "0" << month << "-";
	}
	else {
		out << month << "-";
	}
	if (year < 10) {
		out << "000" << year;
	}
	else if (year < 100) {
		out << "00" << year;
	}
	else if (year < 1000) {
		out << "0" << year;
	}
	else {
		out << year;
	}
	cout << endl;
	return out;
}
istream& Date::input(istream& in) {
	cout << "Enter day :";
	in >> day;
	while (day <= 0 || day >= 32) {
		cout << "Invalid day" << endl;
		cout << "Enter day :";
		in >> day;
		cout << endl;
	}
	cout << "Enter month :";
	in >> month;
	while (month <= 0 || month >= 13) {
		cout << "Invalid month" << endl;
		cout << "Enter month :";
		in >> month;
		cout << endl;
	}
	cout << "Enter year :";
	in >> year;
	while (year <= 0 || year >= 2022) {
		cout << "Invalid year" << endl;
		cout << "Enter year :";
		in >> year;
		cout << endl;
	}
	return in;

}
ofstream& Date::write(ofstream& fout) {
	fout << day<<" ";
	fout << month<<" ";
	fout << year<<" ";
	return fout;
}
ifstream& Date::read(ifstream& fin) {
	fin >> day;
	fin >> month;
	fin >> year;
	return fin;
}

//constructors
Date::Date(int d, int m, int y){//parametrized and defalt constructor
	if (d > 0 && d < 32) {
		day = d;
	}
	else {
		day = 0;
	}
	if (m > 0 && m < 13) {
		month = m;
	}
	else {
		month = 0;
	}
	if (y > 0 && y < 2022) {
		year = y;
	}
	else {
		year = 0;
	}
}
Date::Date(const Date& d) {
	day = d.day;
	month = d.month;
	year = d.year;
}

//setters
void Date::set_date(int d, int m, int y) {
	if (d > 0 && d < 32) {
		day = d;
	}
	else {
		while (day <= 0 || day >= 32) {
			cout << "Invalid Day" << endl;
			cout << "Enter the day :";
			cin >> d;
		}
		day = d;
	}
	if (m > 0 && m < 13) {
		month = m;
	}
	else {
		while (m <= 0 || m >= 13) {
			cout << "Invalid month" << endl;
			cout << "Enter the month :";
			cin >> m;
		}
		month = m;
	}
	if (y > 0 && y < 2022) {
		year = y;
	}
	else {
		while (y <= 0 || y >= 2022) {
			cout << "Invalid year" << endl;
			cout << "Enter the year :";
			cin >> y;
		}
		year = y;
	}
}
void Date::set_day(int d) {
	if (d > 0 && d < 32) {
		day = d;
	}
	else {
		while (day <= 0 || day >= 32) {
			cout << "Invalid Day" << endl;
			cout << "Enter the day :";
			cin >> d;
		}
		day = d;
	}
}
void Date::set_month(int m) {
	if (m > 0 && m < 13) {
		month = m;
	}
	else {
		while (m <= 0 || m >= 13) {
			cout << "Invalid month" << endl;
			cout << "Enter the month :";
			cin >> m;
		}
		month = m;
	}
}
void Date::set_year(int y) {
	if (y > 0 && y < 2022) {
		year = y;
	}
	else {
		while (y <= 0 || y >= 2022) {
			cout << "Invalid year" << endl;
			cout << "Enter the year :";
			cin >> y;
		}
		year = y;
	}
}

//getters
Date Date::get_date() {
	return *this;
}
int Date::get_day() {
	return day;
}
int Date::get_month() {
	return month;
}
int Date::get_year() {
	return year;
}

//ostream and istream
ostream& operator<<(ostream& out, Date& d) {
	d.output(out);
	return out;
}
istream& operator>>(istream& in, Date& d) {
	d.input(in);
	return in;
}

//ofstream and ifstream
ofstream& operator<<(ofstream& fout, Date& d) {
	d.write(fout);
	return fout;
}
ifstream& operator>>(ifstream& fin, Date& d) {
	d.read(fin);
	return fin;
}
