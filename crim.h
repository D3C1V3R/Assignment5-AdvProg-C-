#ifndef CRIM_H
#define CRIM_H

#include <string>
using namespace std;

// base class...

class Criminal {
  public:
	~Criminal();
	Criminal(string *FName, string *LName, string *Crime,int Mths,int Cell);
	bool operator<(const Criminal &C);
	bool operator==(const Criminal &C);
	virtual void Print();

	void ReduceSentence();
	void IncreaseSentence();
	void Sentence();
	void Sentence(bool value);
	virtual string getData();
	virtual bool CheckRelease();
  protected:
	string FamilyName,FirstName; // Prisoner's name
	string Crime; // Crime Committed 
	int Months;// Number of months remaining in sentence
	int CellNo; // The cell the inmate occupies, initially set to -1
};

//derived classes...
class Robber : public Criminal { 
	public:  
		Robber(string *FName, string *LName, string *Crm, int Mths, int Cell, int Amount);
		void Print();
		string getData();
		bool CheckRelease();
	private:  
			int AmountStolen; };

class Murderer : public Criminal { 
	public:
		Murderer(string *FName, string *LName, string *Crm, int Mths, int Cell, string vname, string vlname);
		void Print();
		string getData();
		bool CheckRelease();
	private:  
			string VictimsFirstName, VictimsFamilyName; };



#endif

