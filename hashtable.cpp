#include "hashtable.h"
#include <iostream>

using namespace std;

// create table and init load variables
hashtable::hashtable() {
	table = new list<string>[1];

	entries = 0;
	buckets = 1;
}