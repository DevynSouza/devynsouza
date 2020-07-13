#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "person.hpp"
using namespace std;
#define FILE "data.txt"

class HashTable {
public:
    HashTable();
    int hash(short int, string);
    void insert(string, string, short int);
    void find(string, short int);
    unsigned int getSize() { return size; }


private:
    vector<Person> table[97] = {}; //Store the person objects in this
    int maxSize = 97;
    int hash(string, short int);
    unsigned int size = 0;


};