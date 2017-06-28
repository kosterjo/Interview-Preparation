#include <functional>
#include "hashtable.h"
#include <iostream>

using namespace std;

// create table and init load variables
hashtable::hashtable() {
	table = new list<datum>[1];

	entries = 0;
	buckets = 1;
}

// delete table
hashtable::~hashtable() {
	delete[] table;
}

bool hashtable::insert(string key, int value) {
	// generate bucket index of key
	int table_index = key_index(key);

	// pointer to key's bucket
	list<datum>* bucket = table + table_index;

	// iterate over list to ensure key doesn't already exist
	for (auto& it : *bucket)
		if (not key.compare(it.key)) return false;

	// add new entry to hashtable
	datum new_data;
	new_data.key = key;
	new_data.value = value;

	bucket->push_back(new_data);

	// increment num entries in hashtable
	entries++;

	return true;
}

bool hashtable::remove(string key) {
	// calculate bucket index corresponding to the key
	int table_index = key_index(key);

	// pointer to key's bucket
	list<datum>* bucket = table + table_index;

	// iterate over bucket and erase key value datum
	for (list<datum>::iterator it = bucket->begin(); it != bucket->end(); it++) {
		if (not key.compare(it->key)) {
			bucket->erase(it);
			entries--;

			// successfully removed element
			return true;
		}
	}
	
	// if key doesn't exist, return false
	return false;
}

// return the hash of a given key
int hashtable::key_index(string key) {
	hash<string> hash_fn;

	int index = hash_fn(key) % buckets;

	return index;
}