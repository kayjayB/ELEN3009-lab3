// date.cpp
// Implementation of the Date class

#include "date.h"

Date Date::_default{1,  Month:: January, 1900};

Date::Date():
_day{_default._day},
_month{_default._month},
_year{_default._year}
{ }

Date::Date(int days, Month months, int years):
	_day{days},
	_month{months},
	_year{years}
{ 
	if (_day<1) // if day is less than 1, throw an exception
	{
		throw InvalidDay();
	}
	
	if (_day > daysInMonth()) // if day is more than the days in the month, throw an exception
	{
		throw InvalidDay();
	}
		if (_year < 0) // if year is negative, throw an exception
	{
		throw InvalidYear();
	}
	
}

int Date::day() const
{
	return _day;
}

Month Date::month() const
{
    return _month;
}

int Date::year() const
{
	return _year;
}

bool Date::isLeapYear() const
{
    // leap years must be divisible by 4 but not by 100
    // or divisible by 400
    if(((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
        return true;
    else
        return false;
}

int Date::daysInMonth() const
{
	switch (_month) {
		case Month::January: 
		case Month::March: 
		case Month::May: 
		case Month::July:
		case Month::August: 
		case Month::October: 
		case Month::December:
			return 31;	
		case Month::April: 
		case Month::June: 
		case Month::September:
		case Month::November:
			return 30;	
		case Month::February:
			if ( isLeapYear() ) return 29;
			else return 28;
		default:
			// should never reach here 
			assert(false); // See: http://www.cplusplus.com/reference/cassert/assert/
            return -1;
	}    
}

bool Date::operator==(const Date& rhs) const
{
	if (_day==rhs.day() &&  _month==rhs.month() && _year==rhs.year() )
		return true;
	else
	return false;
}

void Date::incrementDay()
{
	_day++;
	if (_day > daysInMonth())
	{
		auto monthNumber =static_cast<int>(_month);
		
		monthNumber=monthNumber % 12;
		
		if (monthNumber==0)
		{
			_year++;
		}
			
		monthNumber++;
		
		_month=static_cast<Month>(monthNumber);
		_day=1;
		
	}  
}

// Note, this standalone function is not part of the Date class
void printDate(const Date& date)
{
	cout << date.day() << "/"
		// cast to an integer to allow the month to be sent to the stream
        << static_cast<int>(date.month()) << "/"
		<< date.year()
		<< endl;
}

void Date::setDefaultDate(int day, Month month, int year)
{
	_default._day = day;
	_default._month =month;
	_default._year = year;
}