#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <array>
#include "ItemCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

unsigned int hash_function1(unsigned int barcode) {
    // function to return the hash value based on the first digit of a unique 7-digit key
    unsigned int d;
    d = barcode / 1000000;
    d = d % 10;
    return d;
}

unsigned int hash_function2(unsigned int barcode) {
    // function to return the hash value based on the second digit of a unique 7-digit key
    unsigned int d;
    d = barcode / 100000;
    d = d % 10;
    return d;
}

unsigned int hash_function3(unsigned int barcode) {
    // function to return the hash value based on the third digit of a unique 7-digit key
    unsigned int d;
    d = barcode / 10000;
    d = d % 10;
    return d;
}

unsigned int hash_function4(unsigned int barcode) {
    // function to return the hash value based on the fourth digit of a unique 7-digit key
    unsigned int d;
    d = barcode / 1000;
    d = d % 10;
    return d;
}

unsigned int hash_function5(unsigned int barcode) {
    // function to return the hash value based on the fifth digit of a unique 7-digit key
    unsigned int d;
    d = barcode / 100;
    d = d % 10;
    return d;
}

unsigned int hash_function6(unsigned int barcode) {
    // function to return the hash value based on the sixth digit of a unique 7-digit key
    unsigned int d;
    d = barcode / 10;
    d = d % 10;
    return d;
}

unsigned int hash_function7(unsigned int barcode) {
    // function to return the hash value based on the seventh digit of a unique 7-digit key
    unsigned int d;
    d = barcode;
    d = d % 10;
    return d;
}

// Constructor for struct "Item"
Item::Item(string itemColor, string itemShape, string itemBrand, unsigned int barcode):
            itemColor_(itemColor),itemShape_(itemShape), itemBrand_(itemBrand), barcode_(barcode)
{};

void ItemCollection::readTextfile(string filename) {
    // load information from the text file passed as argument
    ifstream myfile(filename);
    if (myfile.is_open()) {
        cout << "Successfully opened file " << filename << endl;
        string itemColor;
        string itemShape;
        string itemBrand;
        unsigned int barcode;
        while (myfile >> itemColor >> itemShape >> itemBrand >> barcode) {
            if (itemColor.size() > 0)
                addItem(itemColor, itemShape, itemBrand, barcode);
        }
        myfile.close();
    }
    else
        throw std::invalid_argument("Could not open file " + filename);
}

void ItemCollection::addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode) {
    // add specific glass and it's details to main display (i.e., to all hash tables)
    Item item(itemColor, itemShape, itemBrand, barcode);
    hash_table1[barcode] = item;
    hash_table2[barcode] = item;
    hash_table3[barcode] = item;
    hash_table4[barcode] = item;
    hash_table5[barcode] = item;
    hash_table6[barcode] = item;
    hash_table7[barcode] = item;
}

bool ItemCollection::removeItem(unsigned int barcode) {
    /*
    removes glass (and its details) specified by the barcode from the display
    (i.e., from all hash tables). If barcode is found, return true, else return false
    */
    if (hash_table1.erase(barcode) != 1)
        return false;
    if (hash_table2.erase(barcode) != 1)
        return false;
    if (hash_table3.erase(barcode) != 1)
        return false;
    if (hash_table4.erase(barcode) != 1)
        return false;
    if (hash_table5.erase(barcode) != 1)
        return false;
    if (hash_table6.erase(barcode) != 1)
        return false;
    if (hash_table7.erase(barcode) != 1)
        return false;
    else
        return true;
}

unsigned int ItemCollection::bestHashing() {
    /*
    Balance is computed by subtracting the maximum element from the minimum element.
    This process is done for every hash_function, and the one with the lowest balance is returned.
    */
    unsigned int min_loc, max_loc;
    unsigned int balance[8];
    unsigned int bucket[10];

    balance[0] = 0;

    for (unsigned int i = 0; i < 10; ++i) {
        bucket[i] = hash_table1.bucket_size(i);
    }
    min_loc =* std::min_element(bucket, bucket + 10);
    max_loc =* std::max_element(bucket, bucket + 10);
    balance[1] = max_loc - min_loc;

    for (unsigned int i = 0; i < 10; ++i) {
        bucket[i] = hash_table2.bucket_size(i);
    }
    min_loc =* std::min_element(bucket, bucket + 10);
    max_loc =* std::max_element(bucket, bucket + 10);
    balance[2] = max_loc - min_loc;

    for (unsigned int i = 0; i < 10; ++i) {
        bucket[i] = hash_table3.bucket_size(i);
    }
    min_loc =* std::min_element(bucket, bucket + 10);
    max_loc =* std::max_element(bucket, bucket + 10);
    balance[3] = max_loc - min_loc;

    for (unsigned int i = 0; i < 10; ++i) {
        bucket[i] = hash_table4.bucket_size(i);
    }
    min_loc =* std::min_element(bucket, bucket + 10);
    max_loc =* std::max_element(bucket, bucket + 10);
    balance[4] = max_loc - min_loc;

    for (unsigned int i = 0; i < 10; ++i) {
        bucket[i] = hash_table5.bucket_size(i);
    }
    min_loc =* std::min_element(bucket, bucket + 10);
    max_loc =* std::max_element(bucket, bucket + 10);
    balance[5] = max_loc - min_loc;

    for (unsigned int i = 0; i < 10; ++i) {
        bucket[i] = hash_table6.bucket_size(i);
    }
    min_loc =* std::min_element(bucket, bucket + 10);
    max_loc =* std::max_element(bucket, bucket + 10);
    balance[6] = max_loc - min_loc;

    for (unsigned int i = 0; i < 10; ++i) {
        bucket[i] = hash_table7.bucket_size(i);
    }
    min_loc =* std::min_element(bucket, bucket + 10);
    max_loc =* std::max_element(bucket, bucket + 10);
    balance[7] = max_loc - min_loc;

    unsigned int result = balance[1];
    result =* std::min_element(balance + 1, balance + 8);
    for (unsigned int pos = 1; pos <= 7; pos++) {
        if (result == balance[pos]) {
            min_loc = pos;
            break;
        }
    }
    return min_loc;
}

size_t ItemCollection::size() {
    if ((hash_table1.size() != hash_table2.size()) ||
            (hash_table1.size() != hash_table3.size()) ||
            (hash_table1.size() != hash_table4.size()) ||
            (hash_table1.size() != hash_table5.size()) ||
            (hash_table1.size() != hash_table6.size()) ||
            (hash_table1.size() != hash_table7.size()))
        throw std::length_error("Hash table sizes are not the same");

    return hash_table1.size();
}
