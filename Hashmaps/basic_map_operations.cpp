#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    // Creation of an unordered map, which stores (key, value) pairs.
    unordered_map<string, int> m;

    // Insertion
    // Method 1: Using `make_pair` to create a pair and then inserting it.
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    // Method 2: Directly creating a pair object and inserting it.
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    // Method 3: Using the [] operator, which creates a new entry if the key doesn't exist.
    m["mera"] = 1;

    // Searching
    // Accessing values using keys.
    cout << "Value associated with 'mera': " << m["mera"] << endl;
    cout << "Value associated with 'babbar': " << m.at("babbar") << endl;

    // Accessing a non-existing key with []
    // If the key is not found, [] will create it with a default value (0 for int).
    cout << "Value associated with 'unknownKey' (created using []): " << m["unknownKey"] << endl;

    // Accessing a non-existing key with `at`
    // `at` throws an exception if the key is not found, which will terminate the program.
    try {
        cout << m.at("unknownKey") << endl;
    } catch (const out_of_range& e) {
        cout << "Key 'unknownKey' not found using 'at'." << endl;
    }

    // Size
    // Display the number of elements in the map.
    cout << "Size of map: " << m.size() << endl;

    // Check presence
    // `count` returns 1 if the key exists, otherwise it returns 0.
    cout << "Is 'babbar' present in map? " << m.count("babbar") << endl;

    // Erase
    // Removes the key-value pair with key "love" if it exists.
    m.erase("love");
    cout << "Size of map after erasing 'love': " << m.size() << endl;

    // Iteration
    // Using an iterator to traverse and print all key-value pairs in the map.
    unordered_map<string, int>::iterator it = m.begin();
    while(it != m.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}
