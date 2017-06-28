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
	// get bucket corresponding to the key
	list<datum>* bucket = get_bucket(key);

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
	// get bucket corresponding to the key
	list<datum>* bucket = get_bucket(key);

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

int hashtable::value(string key) {
	list<datum>* bucket = get_bucket(key);

	// iterate over bucket, looking for correct key
	for (auto& it : *bucket) 
		if (not key.compare(it.key)) return it.value;

	// if no match, return 0
	return 0;
}

// return the bucket of a given key
list<datum>* hashtable::get_bucket(string key) {
	hash<string> hash_fn;

	int index = hash_fn(key) % buckets;

	return table + index;
}