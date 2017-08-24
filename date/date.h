#ifndef DATE_H
#define DATE_H
// date.h
// class Date declaration

#include <cassert>
#include <iostream>
using namespace std;

class InvalidDay{};
class InvalidMonth{};
class InvalidYear{};

enum class Month 
{
	January = 1, 
	February,
	March, 
	April,
	May,
	June,
	July, 
	August, 
	September,
	October,
	November, 
	December
};
	
class Date
{
public:	

	// constructor
	Date(int days, Month months, int years);
	// return the day of the month
	int day () const;
	// return the month of the year
	Month month () const;
	// return the year
	int year () const;
	// return true if it is a leap-year, false if not
	bool isLeapYear () const;	
	bool operator==(const Date& rhs) const;
	void incrementDay();

private:
	// return the number of days in the _month
	int	daysInMonth () const;	
	int	_day;
	Month _month;
	int	_year;

};

// standalone function for printing the date
void printDate(const Date& date);

#endif