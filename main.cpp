/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design Hash Table ADT
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */

    HashTable hashTable;

    cout << "-------------------\tTESTING INITIALIZED HASH TABLE\t-------------------\n\n";
    hashTable.printTable();
    cout << endl;
    cout << "Total Entries: " << hashTable.getCount();
    cout << endl << endl;

    cout << "-------------------\tTESTING FILLING HASH TABLE WITH TEST DATA\t-------------------\n\n";

    for (int i = 0; i < testdatasize; i++) {
        cout << "ATTEMPTING TO ADD ENTRY [ID: " << ids[i] << " STR: " << strs[i] << "]";

        if(hashTable.insertEntry(ids[i], &strs[i])) {
            cout << " ... ADDED" << endl;
        } else {
            cout << " ... NOT ADDED" << endl;
        }
    }

    cout << endl;
    cout << "PRINTING HASH TABLE: " << endl;
    hashTable.printTable();
    cout << endl;
    cout << "TOTAL ENTRIES: " <<  hashTable.getCount();
    cout << endl << endl;

    cout << "-------------------\tTESTING GETTING STR DATA FROM HASH TABLE\t-------------------\n\n";

    for (int i = 0; i < testdatasize; i++) {
        cout << "ATTEMPTING TO RETRIEVE STR DATA FROM [ID : " << ids[i] << "]";
        cout << "... RETRIEVED [STR: " << hashTable.getData(ids[i]) << "]" << endl;
    }

    cout << endl;
    cout << "PRINTING HASH TABLE: " << endl;
    hashTable.printTable();
    cout << endl;
    cout << "TOTAL ENTRIES: " <<  hashTable.getCount();
    cout << endl << endl;

    cout << "-------------------\tTESTING REMOVING SOME ENTRIES FROM HASH TABLE\t-------------------\n\n";

    for (int i = 0; i < testdatasize; i += 2) {
        cout << "ATTEMPTING TO REMOVE ENTRY [ID: " << ids[i] << " STR: " << strs[i] << "]";

        if(hashTable.removeEntry(ids[i])) {
            cout << " ... REMOVED" << endl;
        } else {
            cout << " ... NOT REMOVED" << endl;
        }
    }

    cout << endl;
    cout << "PRINTING HASH TABLE: " << endl;
    hashTable.printTable();
    cout << endl;
    cout << "TOTAL ENTRIES: " <<  hashTable.getCount();
    cout << endl << endl;

    cout << "-------------------\tTESTING EMPTYING HASH TABLE\t-------------------\n\n";

    cout << "EMPTYING HASH TABLE";
    for (int i = 0; i < testdatasize; i ++) {
        hashTable.removeEntry(ids[i]);
    }

    if(hashTable.getCount() == 0) {
        cout << " ... EMPTIED" << endl;
    } else {
        cout << " ... ERROR" << endl;
    }

    cout << endl;
    cout << "PRINTING HASH TABLE: " << endl;
    hashTable.printTable();
    cout << endl;
    cout << "TOTAL ENTRIES: " <<  hashTable.getCount();
    cout << endl << endl;

    cout << "-------------------\tREFILLING HASH TABLE WITH TEST DATA\t-------------------\n\n";

    for (int i = 0; i < testdatasize; i++) {
        cout << "ATTEMPTING TO ADD ENTRY [ID: " << ids[i] << " STR: " << strs[i] << "]";

        if(hashTable.insertEntry(ids[i], &strs[i])) {
            cout << " ... ADDED" << endl;
        } else {
            cout << " ... NOT ADDED" << endl;
        }
    }

    cout << endl;
    cout << "PRINTING HASH TABLE: " << endl;
    hashTable.printTable();
    cout << endl;
    cout << "TOTAL ENTRIES: " <<  hashTable.getCount();
    cout << endl << endl;

    cout << "-------------------\tTESTING REMOVING FIRST, MIDDLE, LAST VALID, DUPLICATE, INVALID TEST DATA ENTRIES\t-------------------\n\n";

    int validDataSize = testdatasize - 2;

    cout << "ATTEMPTING TO REMOVE FIRST TEST DATA ENTRY [ID: " << ids[0] << " STR: " << strs[0] << "]";

    if(hashTable.removeEntry(ids[0])) {
        cout << " ... REMOVED" << endl;
    } else {
        cout << " ... NOT REMOVED" << endl;
    }

    cout << "ATTEMPTING TO REMOVE MIDDLE TEST DATA ENTRY [ID: " << ids[validDataSize/2] << " STR: " << strs[validDataSize/2] << "]";

    if(hashTable.removeEntry(ids[validDataSize/2])) {
        cout << " ... REMOVED" << endl;
    } else {
        cout << " ... NOT REMOVED" << endl;
    }

    cout << "ATTEMPTING TO REMOVE LAST VALID TEST DATA ENTRY [ID: " << ids[testdatasize-3] << " STR: " << strs[testdatasize-3] << "]";

    if(hashTable.removeEntry(ids[testdatasize-3])) {
        cout << " ... REMOVED" << endl;
    } else {
        cout << " ... NOT REMOVED" << endl;
    }

    cout << "ATTEMPTING TO REMOVE DUPLICATE TEST DATA ENTRY [ID: " << ids[testdatasize-2] << " STR: " << strs[testdatasize-2] << "]";

    if(hashTable.removeEntry(ids[testdatasize-2])) {
        cout << " ... REMOVED" << endl;
    } else {
        cout << " ... NOT REMOVED" << endl;
    }

    cout << "ATTEMPTING TO REMOVE INVALID TEST DATA ENTRY [ID: " << ids[testdatasize-1] << " STR: " << strs[testdatasize-1] << "]";

    if(hashTable.removeEntry(ids[testdatasize-1])) {
        cout << " ... REMOVED" << endl;
    } else {
        cout << " ... NOT REMOVED" << endl;
    }

    cout << endl;
    cout << "PRINTING HASH TABLE: " << endl;
    hashTable.printTable();
    cout << endl;
    cout << "TOTAL ENTRIES: " <<  hashTable.getCount();
    cout << endl << endl;

    cout << "-------------------\tEMPTYING HASH TABLE\t-------------------\n\n";

    cout << "EMPTYING HASH TABLE";
    for (int i = 0; i < testdatasize; i ++) {
        hashTable.removeEntry(ids[i]);
    }

    if(hashTable.getCount() == 0) {
        cout << " ... EMPTIED" << endl;
    } else {
        cout << " ... ERROR" << endl;
    }

    cout << endl;
    cout << "PRINTING HASH TABLE: " << endl;
    hashTable.printTable();
    cout << endl;
    cout << "TOTAL ENTRIES: " <<  hashTable.getCount();
    cout << endl << endl;

    cout << "-------------------\tTESTING ADDING RANDOM QTY AND TEST DATA INDEX\t-------------------\n\n";

    int qty = (rand() % testdatasize) + 1;

    cout << "RANDOMLY ADDING " << qty << " ENTRIES FROM TEST DATA:" << endl;

    for (int i = 0; i < qty; i++) {
        int randTestData = rand() % testdatasize;

        cout << "ATTEMPTING TO ADD ENTRY [ID: " << ids[randTestData] << " STR: " << strs[randTestData] << "]";

        if(hashTable.insertEntry(ids[randTestData], &strs[randTestData])) {
            cout << " ... ADDED" << endl;
        } else {
            cout << " ... NOT ADDED" << endl;
        }
    }

    cout << endl;
    cout << "PRINTING HASH TABLE: " << endl;
    hashTable.printTable();
    cout << endl;
    cout << "TOTAL ENTRIES: " <<  hashTable.getCount();
    cout << endl << endl;

    cout << "-------------------\tTESTING GETTING STR DATA FOR RANDOM QTY AND TEST DATA INDEX\t-------------------\n\n";

    qty = (rand() % testdatasize) + 1;

    cout << "RANDOMLY RETRIEVING STR DATA FOR" << qty << " ENTRIES FROM TEST DATA:" << endl;

    for (int i = 0; i < qty; i++) {
        int randTestData = rand() % testdatasize;
        cout << "ATTEMPTING TO RETRIEVE STR DATA FROM [ID : " << ids[randTestData] << "]";
        cout << "... RETRIEVED [STR: " << hashTable.getData(ids[randTestData]) << "]" << endl;
    }

    cout << endl;
    cout << "PRINTING HASH TABLE: " << endl;
    hashTable.printTable();
    cout << endl;
    cout << "TOTAL ENTRIES: " <<  hashTable.getCount();
    cout << endl << endl;

    cout << "-------------------\tTESTING REMOVING RANDOM QTY AND TEST DATA INDEX\t-------------------\n\n";

    qty = (rand() % testdatasize) + 1;

    cout << "RANDOMLY REMOVING " << qty << " ENTRIES FROM TEST DATA:" << endl;

    for (int i = 0; i < qty; i++) {
        int randTestData = rand() % testdatasize;

        cout << "ATTEMPTING TO REMOVE ENTRY [ID: " << ids[randTestData] << " STR: " << strs[randTestData] << "]";

        if(hashTable.removeEntry(ids[randTestData])) {
            cout << " ... REMOVED" << endl;
        } else {
            cout << " ... NOT REMOVED" << endl;
        }
    }

    cout << endl;
    cout << "PRINTING HASH TABLE: " << endl;
    hashTable.printTable();
    cout << endl;
    cout << "TOTAL ENTRIES: " <<  hashTable.getCount();
    cout << endl << endl;

    cout << "-------------------\tEMPTYING HASH TABLE\t-------------------\n\n";

    cout << "EMPTYING HASH TABLE";
    for (int i = 0; i < testdatasize; i ++) {
        hashTable.removeEntry(ids[i]);
    }

    if(hashTable.getCount() == 0) {
        cout << " ... EMPTIED" << endl;
    } else {
        cout << " ... ERROR" << endl;
    }

    cout << endl;
    cout << "PRINTING HASH TABLE: " << endl;
    hashTable.printTable();
    cout << endl;
    cout << "TOTAL ENTRIES: " <<  hashTable.getCount();
    cout << endl << endl;

    return 0;
}
