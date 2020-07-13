#include "hashtable.hpp"

HashTable::HashTable() {
    //Gets info from file
    //Send info to insert
    string name, accomplishment, yearString;
    short int year;
    ifstream dataFile(FILE);
    string buffer;
        while(!dataFile.eof()) {
            getline(dataFile, name, ',');
            getline(dataFile, accomplishment, ',');
            getline(dataFile, yearString);
            year = stoi(yearString);
            insert(name, accomplishment, year);
        }
    dataFile.close();
}

int HashTable::hash(short int year, string accomplishment) { //Creates a hash to store is index in the array
    unsigned long int key = year * year;
    #define MASK 0xF800 //1111 1000 0000 0000
    for(unsigned int i = 0; i < accomplishment.size(); i++) {
        unsigned long long int shifted;
        shifted = (key & MASK) >> 11;
        key = key << 5;
        key = (key | shifted);
        key = key ^ (int) accomplishment.back();
        
    } 
    return key % maxSize;  
}

void HashTable::insert(string name, string accomplishment, short int year) {
    size++;
    int idx = HashTable::hash(year, accomplishment);
    table[idx].push_back(Person(name, accomplishment, year)); 
}

void HashTable::find(string findAccomplish, short int findYear) { //Finds stuff and calls the compare function
    int idx;            
    idx = hash(findYear, findAccomplish);
    for(vector<Person>::iterator it = table[idx].begin(); it != table[idx].end(); it++) {
        if(it -> compare(findAccomplish, findYear)) {
            it -> print();
        }
    }
}
