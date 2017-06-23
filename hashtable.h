#include <list>
#include <string>

using namespace std;

class hashtable {
public:

  //ctor
  hashtable();

  //dtor
  ~hashtable();

  // returns true on success
  bool insert(string key, int value);

  // returns true on success
  bool remove(string key);

  // returns value of key
  string value(string key);

private:

  // the table, an array of lists - or buckets
  list<int> table[];

  // number of entries and buckets
  int entries, buckets;

  // minimum and maximum loads
  double max = 0.75;
  double min = 0.25;

  // doubles size of table
  void grow();

  // halves size of table
  void shrink();
};