#include "hashtable.h"
#include <iostream>

using namespace std;

// create table and init load variables
hashtable::hashtable() {
	table = new datum[1];

	entries = 0;
	buckets = 1;
}

// delete table
hashtable::~hashtable() {
	delete[] table;
}