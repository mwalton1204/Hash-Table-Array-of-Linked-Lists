/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design Hash Table ADT
**********************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASHTABLESIZE 15

#include <string>
#include <iostream>
#include "linkedlist.h"

using std::string;
using std::cout;
using std::endl;

class HashTable {

public:

    HashTable();
    ~HashTable();

    bool insertEntry(int, string*);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();

private:

    int hash(int);

    int count;
    LinkedList hashTable[HASHTABLESIZE];

};

#endif //HASHTABLE_H