//============================================================================
// Name        : Hash table
// Author      : Devyn Souza    
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <vector>
#include "hashtable.hpp"

using namespace std;

bool menu(HashTable* tables);

int main (void) {
  
	HashTable tables; 
	bool exit = false;
	cout << "Welcome to my program. Written by Devyn Souza";
	

	while (!exit) {
		exit = menu(&tables);
	}
	return 0;
}

bool menu(HashTable* tables) {
	int input;
	string name, accomplishment, findAccomplish, temp;
	short int year, findYear;
	cout << "\n\nPlease enter an option and input a number" << endl;
	cout << "1. Create a new student object" << endl;
	cout << "2. Search for a student's accomplishment" << endl;
	cout << "3. Exit Application\n" << endl;
	cin >> temp;
	cin.ignore();
	bool valid = true;

	for(unsigned int i = 0; i < temp.length(); i++) { //input validation
		if(!isdigit(temp[i]))
			valid = false;
	}
	if(valid) {
		input = stoi(temp);
	}
	else {
		bool retry = true;
		while (retry) {
			cout << "Please input a number!" << endl;
			cin >> temp;
			cin.ignore();
			valid = true;
			for(unsigned int i = 0; i < temp.length(); i++) {
				if(!isdigit(temp[i]))
					valid = false;
			}
			if(valid) {
				retry = false;
				input = stoi(temp);
			}
		}
	}
	if (input == 1) { //Create a new object manually
	   	cout << "\nName: ";
		getline(cin, name);
		cout << "\nAccomplishment: ";
		getline(cin, accomplishment);
		cout << "\nYear: ";
		string temp1;
		cin >> temp1;
		cin.ignore();
		bool valid = true;

		for(unsigned int i = 0; i < temp1.length(); i++) { //Code under is for input validation
			if(!isdigit(temp1[i]))
				valid = false;
		}

		if(valid) {
			year = stoi(temp1);
		} else {
			bool retry = true;
			while (retry) {
				cout << "Please enter a year!" << endl;
				cin >> temp1;
				cin.ignore();

				valid = true;

				for(unsigned int i = 0; i < temp1.length(); i++) {
					if(!isdigit(temp1[i]))
						valid = false;
				}

				if(valid) {
					retry = false;
					year = stoi(temp1);
				}
			}
		}

		tables->insert(name, accomplishment, year);

		ofstream fs;
		fs.open(FILE, fstream::out | fstream::app);
		if(tables->getSize() > 0) {
			fs << "\n" << name << "," << accomplishment << "," << year;
		} else {
			fs << name << "," << accomplishment << "," << year;
		}
		fs.close();

	} else if (input == 2) { //Finds thigns

		cout << "Please enter an accomplishment you would like to search for!\n";
		getline(cin, findAccomplish);
		cout << "Please enter the year you would like to search!\n";
		string temp1;
		cin >> temp1;
		cin.ignore();
		bool valid = true;

		for(unsigned int i = 0; i < temp1.length(); i++) { //input validation
			if(!isdigit(temp1[i]))
				valid = false;
		}

		if(valid) {
			findYear = stoi(temp1);
		} else {
			bool retry = true;
			while (retry) {
				cout << "Please enter a year!" << endl;
				cin >> temp1;
				cin.ignore();

				valid = true;

				for(unsigned int i = 0; i < temp1.length(); i++) {
					if(!isdigit(temp1[i]))
						valid = false;
				}

				if(valid) {
					retry = false;
					findYear = stoi(temp1);
				}
			}
		}
		tables->find(findAccomplish, findYear); 
		

	} else if (input == 3) { //Exit Application
		return true;
	} else {
		cout << "Error! Please input a number between 1 and 4.";
	}

	return false;
}