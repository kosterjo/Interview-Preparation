#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include "datum.h"
#include <list>
#include <string>

class hashtable {
public:

  //ctor
  hashtable();

  //dtor
  ~hashtable();

  // returns true on success
  bool insert(std::string key, int value);

  // returns true on success
  bool remove(std::string key);

  // returns value of key
  std::string value(std::string key);

private:

  // the table, an array of lists - or buckets
  std::list<datum>* table;

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

#endif