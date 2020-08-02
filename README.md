# Best Hashing

At an optometrist store, glasses of various shapes and sizes are put on a display that has 10 cubbies. Each pair of glasses on display has a unique 7-digit barcode. 

There are too many pairs of glasses and they can't be stored individually in a dedicated cubby, so each cubby would have more than one pair of glasses. The glasses have to be organized into cubbies in a manner which makes most of them visible.

One way of organizing these glasses is to group them based on individual digits of their barcode from left to right. This means that the glasses with the same N<sup>th</sup> digit are grouped together.

The "Best" balancing function (which ensures equal distribution of glasses in different cubbies) is calculated in the following manner:

  + A variable `balance` is the difference between the number of pairs of glasses in the most populated cubby and the least populated cubby
  
  + The cubby having the minimum value of `balance` is the one which is most organized.

**Note 1:** Ignore the cubbies in which the value of `balance` is `None`.

**Note 2:** If two (or more) cubbies have the same value of `balance`, then return the cubby which is indicated by a lower number. Assuming each cubby is implemented using a hash table, if `hash table 2`, `hash table 4`, and `hash table 6` all have the lowest `balance` factor, then return `hash table 2`.

For example, consider two hash functions which organize glasses based on the first and second digit of their barcode respectively. And there are 18 pairs of glasses having the following barcodes:

1234567, 2345678, 3456789, 4567890, 5678901, 6789012, 7890123, 8901234, 9012345, 5432109, 6543210, 7654321, 8765432, 9876543, 1098765, 2109876, 3210987, 4321098

If the glasses are organized based on the first digit of their barcode, then the cubbies would look like:

```
Cubby 0: None
Cubby 1: 1234567, 1098765
Cubby 2: 2345678, 2109876
Cubby 3: 3456789, 3210987
Cubby 4: 4567890, 4321098
Cubby 5: 5678901, 5432109
Cubby 6: 6789012, 6543210
Cubby 7: 7890123, 7654321
Cubby 8: 8901234, 8765432
Cubby 9: 9012345, 9876543
```

The value of `balance` is 2.

Similarly, if the glasses are organized based on the second digit of their barcode, then the cubbies would look like:

```
Cubby 0: 9012345, 1098765
Cubby 1: 2109876
Cubby 2: 1234567, 3210987
Cubby 3: 2345678, 4321098
Cubby 4: 3456789, 5432109
Cubby 5: 4567890, 6543210
Cubby 6: 5678901, 7654321
Cubby 7: 6789012, 8765432
Cubby 8: 7890123, 9876543
Cubby 9: 8901234
```

The value of `balance` is 1.
This cubby is clearly more organized, which means that the hash table which groups the glasses based on the second digit of their barcode produces the best hashing.

# Implementation Specifications

`ItemCollection.hpp` contains the skeleton for classes and function members. The code to decide which digit leads to the most balanced hashtable is to be implemented in class. 

`ItemCollection.cpp`. This class has seven hash tables as its member variables. These hash tables differ only in the hash function they use to group the barcodes by. Each hash function will take a 7-digit number and return either the first, second, ... , or seventh (last) digit.

  + `hash_function1(barcode)`: Returns the first digit of number
  + `hash_function2(barcode)`: Returns the second digit of number
  + `hash_function3(barcode)`: Returns the third digit of number
  + `hash_function4(barcode)`: Returns the fourth digit of number
  + `hash_function5(barcode)`: Returns the fifth digit of number
  + `hash_function6(barcode)`: Returns the fourth digit of number
  + `hash_function7(barcode)`: Returns the fifth digit of number

This class also contains the below member functions:

  + `readTextfile`: Reads space separated values for attributes *color*, *shape*, *brand*, and *barcode*. This method calls `addItem()` for each line.

  + `addItem`: Creates an *Item* object and inserts them into all seven hashtables. Each hash table has the *barcode* as the key and the *Item* object as value
  
  + `removeItem`: Removes a pair of glasses from each hashtable, corresponding to the given product number

  + `bestHashing`: Computes best hashing for each of the seven hashtables, and then identifies the hashtable with the best balance

`main.cpp` contains tests for to verify implementation of the specifications.

# Execution and Functionality Test

`gcc --version`

*(Output on Ubuntu 20.04)*:
```
gcc (Ubuntu 9.3.0-10ubuntu2) 9.3.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

`g++ -o output ItemCollection.cpp main.cpp`

`./output`
