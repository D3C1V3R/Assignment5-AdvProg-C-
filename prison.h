#ifndef PRISON_H
#define PRISON_H

#include <iostream>
#include <cstring>
#include <set>
#include "crim.h"
using namespace std;


struct Comp
{
	bool operator()(Criminal* x, Criminal* y) { return(*x < *y); }; // compare what pointers are pointing at
};
typedef set<Criminal*, Comp> CrimSet;

class Prison {
  public:
    ~Prison();
	void ReadCrimFile();
	void DisplayPrisioners(); // prints inmates in order of their names
	void ReduceSentence();
	void CheckParole();
	void Release(Criminal* a);
	void SaveData();

  private:
	  set<Criminal*, Comp> Crims; // set of pointers to class Criminal
	void ProcessString(string line);
};
#endif