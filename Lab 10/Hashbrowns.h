#pragma once
#include <string>
#include <vector>
using namespace std;

//Thomas Klaesges

class hashMap {
private:
	int size{ 0 };
	string hmap[31];

public:
	hashMap() {
		for (int i = 0; i < 31; i++) {
			hmap[i] = "";
		}
	}

	//Returns first letter of the string as an index
	int hash(string s){
		int x{ s[0] - 97 };

		return x;
	}

	//Inserts at the closest available index
	bool insert(string s) {
		bool collision{ false };
		int ind{ hash(s) };
		if (lookup(s)) {
			collision = true;
			return collision;
		}
		else {
			for (int i = 0; i < 31; i++) {
				if (hmap[(ind + i) % 31] != "") {
					collision = true;
				}
				else {
					hmap[(ind + i) % 31] = s;
					break;
				}
			}
		}
		return collision;
	}

	//Looks for a string within the hash map array, returns true if found, returns false if not
	bool lookup(string s) {
		bool look{ false };
		int ind{ hash(s) };
		for (int i = 0; i < 31; i++) {
			if (hmap[(ind + i) % 31] != "") {
				if (hmap[(ind + i) % 31].compare(s) == 0) {
					look = true;
					break;
				}
				else {
					look = false;
				}
			}
		}
		return look;
	}

	//Returns hash map as a vector 
	vector<string> dump() {
		vector<string> vec;
		for (int i = 0; i < 31; i++) {
			vec.push_back(hmap[i]);
		}
		return vec;
	}
};