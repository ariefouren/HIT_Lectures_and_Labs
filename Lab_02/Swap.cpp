//
// Swap.cpp
//
#define MONTHES_IN_YEAR 12
#define DAYS_IN_MONTH 31

#include <iostream>
#include <iomanip>
#define WIDTH 2

using namespace std;

struct MyDate
{
	int day;
	int month;
	int year;
};

void swapByPtr(int* x, int* y);
void swapByRef(int& x, int& y);
int checkDate(int& day, int& month, int& year);
MyDate* saveDates(int numDates);
void printDates(MyDate* datesArr, int size);



void swapByPtr(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void swapByRef(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int checkDate(int& day, int& month, int& year)
{
	if (1 <= day && day <= DAYS_IN_MONTH &&
		1 <= month && month <= MONTHES_IN_YEAR) {return 0;}
	else
	{
		swapByRef(day, month);
		return 1;
	}

}

MyDate* saveDates(int numDates)
{
	MyDate* datesArr = new MyDate[numDates];
	for (int i = 0; i < numDates; i++)
	{
		cout << "Enter day month year: ";
		cin >> datesArr[i].day >> datesArr[i].month >> datesArr[i].year;
		cout << "Saved date (day): " << datesArr[i].day << endl;
	}
	return datesArr;
}

void printDates(MyDate* datesArr, int size)
{
	int errCount = 0;
	for (int i = 0; i < size; i++)
	{
		errCount += checkDate(datesArr[i].day,
			datesArr[i].month, datesArr[i].year);
		cout << setfill('0')
			<< "Date [" << i << "]: "
			<< setw(WIDTH) << datesArr[i].day << "/"
			<< setw(WIDTH) << datesArr[i].month << "/"
			<< setw(WIDTH) << datesArr[i].year << endl;
	}
	cout << "Total number of errors: " << errCount << endl;
}




int main()
{
	/*
	int x = 10;
	int y = 20;

	cout << "x = " << x << " y = " << y << endl;
	cout << "run swapByPtr(&x, &y)" << endl;
	swapByPtr(&x, &y);
	cout << "x = " << x << " y = " << y << endl << endl;

	cout << "run swapByRef(x, y)" << endl;
	swapByRef(x, y);
	cout << "x = " << x << " y = " << y << endl << endl;
	

	int day = 12;
	int month = 31;
	int year = 2023;

	cout << "day = " << day <<
		"	month = " << month <<
		"	year = " << year << endl;
	cout << "checkDate(day, month, year) returns " 
		<< checkDate(day, month, year) << endl;
	cout << "day = " << day <<
		"	month = " << month <<
		"	year = " << year << endl;

	*/
	int numDates = 3;
	MyDate* datesArr = saveDates(numDates);

	printDates(datesArr, numDates);
}