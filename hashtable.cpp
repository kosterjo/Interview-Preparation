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
	// generate hash for key
	size_t hash = gen_hash(key);

	// mod by table size to generate index
	int table_index = hash % buckets;

	// iterate over list to ensure key doesn't already exist
	for (auto& it : *(table + table_index))
		if (not key.compare(it.key)) return false;

	datum new_data;
	new_data.key = key;
	new_data.value = value;

	(table + table_index)->push_back(new_data);

	return true;
}

bool hashtable::remove(string key) {
	// calculate bucket index corresponding to the key
	size_t hash     = gen_hash(key);
	int table_index = hash % buckets;

	// iterate over bucket and erase key value datum
	for (list<datum>::iterator it = (table + table_index)->begin(); it != (table + table_index)->end(); it++) {
		if (not key.compare(it->key)) {
			(table + table_index)->erase(it);
			return true;
		}
	}
	
	// if key doesn't exist, return false
	return false;
}

// return the hash of a given key
size_t gen_hash(string key) {
	hash<string> hash_fn;

	return hash_fn(key);
}