#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


class Person {
public:
    Person();
    Person(string, string, short int);
    void personMake();
    bool compare(string, short int);
    void print();




private:
    string name;
    string accomplishment;
    short int year;




};
