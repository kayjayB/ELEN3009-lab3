#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// Comment out this test after inspecting the output.
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
//TEST_CASE("Date has uninitialised state") {	 
//    // make some prior memory allocations - which will be the case in a typical program
//    auto i = {1.0,1.3,1.4,1.5,1.6,1.7,1.8,1.9,10.2,11.0,1.2,1.3,1.23};
//    auto i2 = 1.0;
//    
//    Date today;	
//    std::cout << "Today is: " << endl;
//    printDate(today);
//}

// Write code to make this test pass
TEST_CASE("Valid Date is initialised correctly") {
	Date heritage_day{24, Month::September, 2000};
	CHECK(heritage_day.day() == 24);
	CHECK(heritage_day.month() == Month::September);
	CHECK(heritage_day.year() == 2000);
}


// Exercise 2.2
TEST_CASE("Date is invalid ") {
	CHECK_THROWS_AS(Date heritage_day1(-24, Month::September, 2000), InvalidDay);
	CHECK_THROWS_AS(Date heritage_day(34, Month::September, 2000), InvalidDay);
	CHECK_THROWS_AS(Date heritage_day(31, Month::February, 2000), InvalidDay);
	CHECK_THROWS_AS(Date heritage_day(12, Month::February, -2000), InvalidYear);
}

// Exercise 2.3
TEST_CASE("Identical Dates are Equal") {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::January, 2000);
    CHECK(date_1 == date_2);
	
	Date date_3(2, Month::January, 2000);
	CHECK_FALSE(date_1 == date_3);
	
	Date date_4(1, Month::February, 2000);
	CHECK_FALSE(date_1 == date_4);
	
	Date date_5(1, Month::February, 2001);
	CHECK_FALSE(date_4 == date_5);
}

// Exercise 2.4
// Provide tests for a new member function of the Date class
// which will increase the date by one day.
TEST_CASE("Day can be incremented by 1") {
	Date date_1(1, Month::January, 2000);
	date_1.incrementDay();
	CHECK(date_1.day() == 2);
	CHECK(date_1.month() == Month::January);
	CHECK(date_1.year() == 2000);
}

TEST_CASE("Month is incremented if days overflow ") {
	Date date_1(31, Month::January, 2000);
	date_1.incrementDay();
	CHECK(date_1.day() == 1);
	CHECK(date_1.month() == Month::February);
	CHECK(date_1.year() == 2000);
	
	Date date_2(28, Month:: February, 2016);
	date_2.incrementDay();
	CHECK(date_2.day() == 29);
	CHECK(date_2.month() == Month::February);
	CHECK(date_2.year() == 2016);
	
	Date date_3(28, Month:: February, 2017);
	date_3.incrementDay();
	CHECK(date_3.day() == 1);
	CHECK(date_3.month() == Month::March);
	CHECK(date_3.year() == 2017);
}

TEST_CASE("Year is incremented if days overflow ") {
	Date date_1(31, Month::December, 2000);
	date_1.incrementDay();
	CHECK(date_1.day() == 1);
	CHECK(date_1.month() == Month::January);
	CHECK(date_1.year() == 2001);
}

// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.
TEST_CASE("Check default constructor ") {
	Date date_1;
	Date date_2(1, Month::January, 1900);
	CHECK(date_1==date_2);
}

TEST_CASE("Check that the default date is changed by the set default function") {
	Date::setDefaultDate(1, Month:: October, 1994);
	Date date_1;
	Date date_2(1, Month:: October, 1994);
	CHECK(date_1==date_2);
}
	
	TEST_CASE("Check that the default date is changed for all objects") {
	Date::setDefaultDate(1, Month:: October, 1994);
	Date date_1;
	Date date_2;
	Date date_3(1, Month:: October, 1994);
	CHECK(date_1==date_3);
	CHECK(date_2==date_3);
}
