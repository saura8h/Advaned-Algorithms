#include <iomanip>
#include <iostream>
#include "ItemCollection.hpp"

// Helper Class Definitions
struct AssertEquals {
    template <typename T, typename U>
    void operator() ( 
    	const std::string & test_name, 
    	const T & expected, 
    	const U & actual, 
    	bool equality_test = true 
    ) 
    {
        if( (actual == expected)  ==  equality_test ) {
            std::cout << "[PASSED] " << test_name << ": ";
            std::cout << "Expected " << expected << " and received: " << actual << '\n';
        }
        else {
            std::cout << "[FAILED] " << test_name << " - Expected: \"" << expected << "\" to "
                      << ( equality_test ? "match " : "not match ")
                      << "Actual: \"" << actual << "\"\n";
        }
    }
};


int main() {
    AssertEquals assertEquals;		// test hash functions

    assertEquals( "hash_function1(1234567)", 1U, hash_function1(1234567U) );
    assertEquals( "hash_function2(1234567)", 2U, hash_function2(1234567U) );
    assertEquals( "hash_function3(1234567)", 3U, hash_function3(1234567U) );
    assertEquals( "hash_function4(1234567)", 4U, hash_function4(1234567U) );
    assertEquals( "hash_function5(1234567)", 5U, hash_function5(1234567U) );
    assertEquals( "hash_function6(1234567)", 6U, hash_function6(1234567U) );
    assertEquals( "hash_function7(1234567)", 7U, hash_function7(1234567U) );
    assertEquals( "hash_function1(6789012)", 6U, hash_function1(6789012U) );
    assertEquals( "hash_function2(6789012)", 7U, hash_function2(6789012U) );
    assertEquals( "hash_function3(6789012)", 8U, hash_function3(6789012U) );
    assertEquals( "hash_function4(6789012)", 9U, hash_function4(6789012U) );
    assertEquals( "hash_function5(6789012)", 0U, hash_function5(6789012U) );
    assertEquals( "hash_function6(6789012)", 1U, hash_function6(6789012U) );
    assertEquals( "hash_function7(6789012)", 2U, hash_function7(6789012U) );

    ItemCollection itemCollection;
    itemCollection.addItem("red", "butterfly", "smooth", 1234567U);
    itemCollection.addItem("pink", "butterfly", "smooth", 2345678U);
    assertEquals( "size after adding two bows", 2U, itemCollection.size() );

    ItemCollection pairs1;
    pairs1.readTextfile("in1.txt");
    assertEquals( "size after reading in1.txt", 18U, pairs1.size() );
    assertEquals( "bestHashing() for in1.txt", 2U, pairs1.bestHashing() );

    ItemCollection pairs2;
    pairs2.readTextfile("in2.txt");
    assertEquals( "size after reading in2.txt", 36U, pairs2.size() );
    assertEquals( "bestHashing() for in2.txt", 3U, pairs2.bestHashing() );

    pairs2.removeItem(8890123);
    assertEquals( "size after removing 8890123", 35U, pairs2.size() );
    assertEquals( "bestHashing() after removing 8890123", 4U, pairs2.bestHashing() );
    return 1;
}
