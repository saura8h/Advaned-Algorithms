#pragma once
#include <string>
#include <unordered_map>
using std::string;

//*******************
// Struct and classes
//*******************

// struct to store all the info about a particular pair of glasses
struct Item{
    string itemColor_;
    string itemShape_;
    string itemBrand_;
    unsigned int barcode_;
    Item(string itemColor = "", string itemShape = "", string itemBrand = "",
        unsigned int barcode = 1000000);
};

unsigned int hash_function1(unsigned int);
unsigned int hash_function2(unsigned int);
unsigned int hash_function3(unsigned int);
unsigned int hash_function4(unsigned int);
unsigned int hash_function5(unsigned int);
unsigned int hash_function6(unsigned int);
unsigned int hash_function7(unsigned int);

// Typedef for custom hash table
typedef std::unordered_map<unsigned int, Item, decltype(&hash_function1)> CustomHashTable;

// class to store data collection
class ItemCollection {

    public:
        void addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode);	// add specified pair of glasses to main display
        bool removeItem(unsigned int barcode);		// remove specified glass from the main display
        unsigned int bestHashing();					// compute the most balanced hash table
        void readTextfile(string filename);			// load data from a text file
        size_t size();								// ensure size of all hashtables are the same

        // constructor for the 7 hashtables of size 10 which use different hash functions
        ItemCollection():
            hash_table1{10, hash_function1},
            hash_table2{10, hash_function2},
            hash_table3{10, hash_function3},
            hash_table4{10, hash_function4},
            hash_table5{10, hash_function5},
            hash_table6{10, hash_function6},
            hash_table7{10, hash_function7}{ }

    private:
        // hash_tableN stores data based on hash_functionN
        CustomHashTable hash_table1, hash_table2, hash_table3, hash_table4, hash_table5, hash_table6, hash_table7;
};
