/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design Hash Table ADT
**********************/

#include "hashtable.h"

HashTable::HashTable() {
    count = 0;
}

HashTable::~HashTable() {}

bool HashTable::insertEntry(int id, std::string* data) {
    bool inserted = false;
    int position = hash(id);

    if (hashTable[position].addNode(id, data)) {
        count++;
        inserted = true;
    }

    return inserted;
}

string HashTable::getData(int id) {
    int position = hash(id);
    Data tmpData;

    if (id > 0) {
        hashTable[position].getNode(id, &tmpData);
    }

    return tmpData.data;
}

bool HashTable::removeEntry(int id) {
    bool removed = false;
    int position = hash(id);

    if (id > 0 && hashTable[position].deleteNode(id)) {
        count--;
        removed = true;
    }

    return removed;
}

int HashTable::getCount() {
    return count;
}

void HashTable::printTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        cout << "Entry " << i + 1 << ": ";
        hashTable[i].printList();
        cout << endl;
    }
}

int HashTable::hash(int id) {
    return id % HASHTABLESIZE;
}