#include <iostream>
#include <algorithm>
#include <iomanip>
#include "crim.h"
using namespace std;


Criminal::~Criminal() {
	CellNo = -1;
	Months = 0;
	delete this;
}

//Constructor
Criminal::Criminal(string *FName, string *LName, string *nCrime,int Mths,int Cell){
	FirstName = *FName;
	FamilyName = *LName;
	Crime = *nCrime;
	Months = Mths;
	CellNo = Cell;
}

// Operator< returns true if *this name is less than Other name
bool Criminal::operator<(const Criminal &Other) {
	return (FamilyName < Other.FamilyName);
}
bool Criminal::operator==(const Criminal &Other) {
	return (CellNo == Other.CellNo);
}
// Prints criminal details on screen
void Criminal::Print(){
	string nCrime = Crime;
	transform(nCrime.begin(), nCrime.end(), nCrime.begin(), ::tolower);
	cout << left	<< setw(10) << FamilyName
					<< setw(10) << FirstName
					<< " Crime- " << setw(10) << Crime
					<< " Cell- " << setw(10) << CellNo
					<< "[Serving " << Months << " months for " << nCrime <<" ]" << endl;
}

void Criminal::ReduceSentence() {
	if (Months <= 6) {
		Months = Months - Months;
	}
	else
		Months = Months - 6;
}
void Criminal::IncreaseSentence() {
	Months = Months+=6;
}
bool Criminal::CheckRelease() { // all others become eligible for parole when the months remaining is 12 months or less
	if (Months <= 12	)
		return true;
	else
		return false;
}
void Criminal::Sentence() {
	cout << "Do you want to parole " << FirstName <<" "<< FamilyName << "(y/n)?" << endl;
}
void Criminal::Sentence(bool value) {
	if (value == true)
		cout << FirstName <<" "<< FamilyName << " has been paroled." << endl;
	else {
		cout << FirstName <<" "<< FamilyName << " has been refused." << endl;
		IncreaseSentence();
	}

}
string Criminal::getData() {
	string a = FirstName + " " + FamilyName + " " + Crime + " "+ to_string(Months) +"\n";
	return a;
}

/*---------Robber Functions---------*/

Robber::Robber(string *FName, string *LName, string *Crm, int Mths, int Amnt, int Cell) 
	: Criminal(FName, LName, Crm, Mths, Cell) { 
	AmountStolen = Amnt; 
}
string Robber::getData() {
	string a = FirstName + " " + FamilyName + " " + Crime + " " + to_string(Months) + to_string(AmountStolen) + "\n";
	return a;
}
void Robber::Print() {
	cout << left << setw(10) << FamilyName
		<< setw(10) << FirstName
		<< " Crime- " << setw(10) << Crime
		<< " Cell- " << setw(10) << CellNo
		<< "[Serving " << Months << " months for stealing $" << AmountStolen << " ]" << endl;
}
bool Robber::CheckRelease() { //  Robbers become eligible for parole when their months remaining is 9 months or less
	if (Months <= 9)
		return true;
	else
		return false;
}

/*---------Murderer Functions---------*/
Murderer::Murderer(string *FName, string *LName, string *Crm, int Mths, int Cell, string vname, string vlname)
	: Criminal(FName, LName, Crm, Mths, Cell) { 
	VictimsFirstName = vname;
	VictimsFamilyName = vlname;
}

void Murderer::Print() {
	cout << left << setw(10) << FamilyName
		<< setw(10) << FirstName
		<< " Crime- " << setw(10) << Crime
		<< " Cell- " << setw(10) << CellNo
		<< "[Serving " << Months << "months for murdering " << VictimsFirstName <<" "<< VictimsFamilyName << " ]" << endl;
}
bool Murderer::CheckRelease() { // Murderers become eligible for parole when their months remaining is 6 months or less
	if (Months <= 6)
		return true;
	else
		return false;
}
string Murderer::getData() {
	string a = FirstName + " " + FamilyName + " " + Crime + " " + to_string(Months) + "  " + VictimsFirstName + " " + VictimsFamilyName + "\n";
	return a;
}