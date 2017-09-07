// Note, specific namespace members are imported into the global namespace which is
// better practice than importing all of the members
// eg: "using std::string;", "using std::unique_ptr;" etc. rather than "using namespace std;"

#include <memory> // required for smart pointers
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

#include <string>
#include <iostream>
using std::string;
using std::endl;
using std::cout;

#include "Person.h"

Person printName()
{
	Person thabo{"Thabo",12};
	cout << thabo.name() << endl;
	return thabo; 
} 

shared_ptr<Person> printName2()
{
	auto maryanne_ptr = make_shared<Person>("Maryanne",12);
	cout << maryanne_ptr->name() << endl;
	return maryanne_ptr;
} 

void printName3(shared_ptr<Person> person_ptr)
{
	cout << person_ptr->name() << endl;
	return;
}  


int main()
{
    auto sandile_ptr = make_unique<Person>("Sandile",15);    
	
    auto thabo_in_main = printName();
    cout << thabo_in_main.name() << endl;

    auto person_ptr_in_main = printName2();
    printName3(person_ptr_in_main);

    sandile_ptr = make_unique<Person>("Sandile2",11);  
    cout << sandile_ptr->age() << endl; 

    return 0;
}
// Question 1
// a) The object thabo goes out of scope on line 24 at the end of the printName() function
// b) The pointer maryanne_ptr goes out of scope on line 31 at the end of the printName2() function
// c) The pointer person_ptr goes out of scope on line 37 at the end of the printName3() function
// d) The pointer sandile_ptr goes out of scope on line 53 at the end of main
// e) The pointer thabo_in_main goes out of scope on line 53 at the end of main
// f) The pointer person_ptr_in_main goes out of scope on line 53 at the end of main

// Question 2
// a) The memory is released when the object goes out of scope on line 24.
// b) The memory is released when person_ptr_in_main goes out of scope on line 53 since the object pointed
// to by maryanne_ptr is copied into person_ptr_in_main on line 47
// c) The memory is released when person_ptr_in_main goes out of scope on line 53. This is because although 
// person_ptr is destroyed at the end of line 37, the pointee is still pointed to by person_ptr_in_main and is thus 
// not destroyed
// d) The memory is released when sandile_ptr goes out of scope on line 53
// e) The memory is released on line 53 
// f) The memory is released when person_ptr_in_main goes out of scope on line 53

// Question 3
// a) thabo is copied on line 23 when the function returns 
// b) maryanne_ptr is copied on line 47 when the function printName2() is called and on line 48 when the 
// printName3() function is called
// c) person_prt is not copied
// d) The pointer does not get copied since it is a unique pointer
// e) The pointer is never copied
// f) The pointer is copied online 48 when the object is passed into the printName3 function by value

// Question 4
// Both go out of scope on line 53 at the termination of the program. However, since sandile_ptr is created 
// first, it is assumed that it will be destroyed first