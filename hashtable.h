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
  bool delete(string key);

  // returns value of key
  string value(string key);

  // doubles size of table
  void grow();

  // halves size of table
  void shrink();

private:
}