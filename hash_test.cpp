#include "hashtable.h"
#include <iostream>

using namespace std;

int main() {
	hashtable testor;

	string s1 = "ya yee";
	string s2 = "yee";

	// test insert
	testor.insert(s1, 7);
	testor.insert(s2, 24);
	cout << testor.value(s1) << endl;
	cout << testor.value(s2) << endl;

	// make sure you can't add a key twice
	cout << testor.insert(s1, 8) << endl;

	// test remove
	testor.remove(s1);
	cout << testor.value(s1) << endl;
	cout << testor.value(s2) << endl;
	testor.remove(s2);
	cout << testor.value(s2) << endl;

}