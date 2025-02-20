#include <iostream>
#include <string>
#include <vector>
#include "Hashbrowns.h"
using namespace std;

//Thomas Klaesges
//I predict it will take about 10 elements before a collision occurs

int main() {
	hashMap hash;

	hash.insert("apple");
	hash.insert("cherry");
	hash.insert("banana");
	hash.insert("barnacle");
	hash.insert("barnacle");
	hash.insert("zucchini");
	hash.insert("horse");
	hash.insert("dunkey");
	hash.insert("zebra");

	vector<string> vec{ hash.dump() };

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	cout << endl << "Looking up 'dunkey', should return true" << endl;
	if (hash.lookup("dunkey")) {
		cout << "dunkey was found" << endl;
	}
	else { cout << "Bubby, you blew it" << endl; }
	cout << endl << "Inserting 'dunkey', should return true and not insert" << endl;
	if (hash.insert("dunkey")) {
		cout << "dunkey was found" << endl;
	}
	else { cout << "Bubby, you blew it" << endl; }
}