/*
	* person.cpp
	*
	*  Created on: May 9, 2020
	*      Author: Devyn
	*/
#include "person.hpp"
using namespace std;



Person::Person() {
	
	
}

Person::Person(string nam, string accomp, short int yer) { 
    this->name = nam;
    this->accomplishment = accomp;
    this->year = yer;
	


}

bool Person::compare(string findAccomplish, short int findYear) {

	if (findAccomplish == accomplishment || findYear == year) {
		return true;
	} else {
		return false;
	}

}

void Person::print() {
//prints thing to make them look nice
cout << "\nName: " << name << "\n";
cout << "Accomplishment: " << accomplishment << "\n";
cout << "Year: " << year << "\n";

}

