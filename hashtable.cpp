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
	hash<string> hash_fn;
	size_t hash = hash_fn(key);

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