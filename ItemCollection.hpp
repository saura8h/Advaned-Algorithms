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


//******************************
// Typedef for custom hash table
//******************************
typedef std::unordered_map<unsigned int, Item, decltype(&hash_function1)> CustomHashTable;


// class to store data collection
class ItemCollection {

    public:
        // function that adds the specified pair of glasses to main display
        void addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode);

        // removes a specified glass from the main display; if successful, returns true, false otherwise
        bool removeItem(unsigned int barcode);

        // identifies the best hash_function from the seven provided and computes the most balanced hash table
        unsigned int bestHashing();

        // Load information from a text file with the given filename
        void readTextfile(string filename);

        // size of a hashtable. Throws exception if the sizes differ
        size_t size();

        // constructor that initializes seven hashtables with different hash functions
        ItemCollection():
            hash_table1{10, hash_function1},
            hash_table2{10, hash_function2},
            hash_table3{10, hash_function3},
            hash_table4{10, hash_function4},
            hash_table5{10, hash_function5},
            hash_table6{10, hash_function6},
            hash_table7{10, hash_function7}

    private:
        // 7 hash tables of size 10 each to store data
        // hash_tableN sotres data based on hash_functionN
        CustomHashTable hash_table1, hash_table2, hash_table3, hash_table4, hash_table5, hash_table6, hash_table7;
};
