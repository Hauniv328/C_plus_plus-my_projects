#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

int month_data1[13] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int month_data2[13] = { 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date
{
private:
	int Y = -1, M = -1, D = -1;

	bool ok();
	void set_clear();

public:
	Date(int yy, int mm, int dd);
	void set_data(int y_, int m_, int d_);
	void Add_Year(int inc);
	void Add_Month(int inc);
	void Add_Day(int inc);
	void show_date();
};

Date::Date(int yy, int mm, int dd) {
	Y = yy;
	M = mm;
	D = dd;
}

void Date::set_data(int y_, int m_, int d_) {
	Y = y_;
	M = m_;
	D = d_;
}

void Date::Add_Year(int inc) { Y += inc; }

void Date::Add_Month(int inc) {
	M += inc;

	set_clear();
}

void Date::Add_Day(int inc) {
	D += inc;

	set_clear();
}

void Date::show_date() { cout << "Today's date is " << Y << "." << M << "." << D << endl; }

void Date::set_clear() {
	while (ok()) {
		if (Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0)) {
			if (month_data2[M % 12] < D) {
				D -= month_data2[M % 12];
				M++;
			}
		}

		else {
			if (month_data1[M % 12] < D) {
				D -= month_data1[M % 12];
				M++;
			}
		}

		if (M > 12) {
			M -= 12;
			Y++;
		}
	}
}

bool Date::ok() {
	if (Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0)) {
		if (month_data2[M % 12] < D || M > 12) return true;
		else return false;
	}

	else if (month_data1[M % 12] < D || M > 12) return true;

	else return false;
}

int main() {
	time_t timer = time(NULL);
	struct tm* t;
	t = localtime(&timer);

	Date today(t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	bool go = true;

	while (go)
	{
		today.show_date();
		cout << "1 = reset the date, 2 = increase the day, 3 = increase the month, 4 = increase the year, 5 = Exit\n";
		int command;
		cin >> command;

		switch (command)
		{
		case 1:
			int y, m, d;
			cout << "Please type the data of date(Year, Month, Day)\nYear: ";
			cin >> y;
			cout << "Month: ";
			cin >> m;
			cout << "Day: ";
			cin >> d;

			today.set_data(y, m, d);
			break;

		case 2:
			int i;
			cout << "Please type the amount of day that how much you want to increase: ";
			cin >> i;

			today.Add_Day(i);
			break;

		case 3:
			cout << "Please type the amount of month that how much you want to increase: ";
			cin >> i;

			today.Add_Month(i);
			break;
		case 4:
			cout << "Please type the amount of year that how much you want to increase: ";
			cin >> i;

			today.Add_Year(i);
			break;
		case 5:
			go = false;
			break;
		}

		cout << "please wait...";
		Sleep(3000);
		system("cls");
	}
}
