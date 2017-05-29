#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "prison.h"
using namespace std;


// ========== class Prison Function definitions ==========

// Destructor: Iterates Crims set and deletes each ptr to Criminal 
Prison::~Prison(){
	for (Criminal *a : Crims) {
		delete a;
	}
}

// Reads data in "crims.txt" into Crims set
void Prison::ProcessString(string line) {
	string fname, lname, crime, vname, vlname, word;
	int months = -1, amount =0; 

	istringstream is(line);
	while (is >> word) { //for each word
		if (fname.size() == 0) {
			fname = word;
		}else if (lname.size() == 0) {
			lname = word;
		}else if (crime.size() == 0) {
			crime = word;
		}else if (months == -1) {
			months = stoi(word);
		}else if (word.find_first_not_of("0123456789") == std::string::npos) {
			amount = stoi(word);
		}else if (vname.size() == 0) {
			vname = word;
		}else {
			vlname = word;
		}
	}
	if (amount != 0) {
		Robber* C  = new Robber(&fname, &lname, &crime, months, amount, Crims.size());
		Crims.insert(C);
	}else if (vname.size()!=0 && vlname.size()!=0) {
		Murderer* C = new Murderer(&fname, &lname, &crime, months, Crims.size(), vname, vlname);
		Crims.insert(C);
	}else {
		Criminal* C = new Criminal(&fname, &lname, &crime, months, Crims.size());
		Crims.insert(C);
	}
}

void Prison::ReadCrimFile(){
	string line;
	ifstream File;
	File.open("crims.txt");
	if (!File.is_open()) {
		cout << "Can't find data file!\n";
		return;
	}
	while (!File.eof()) {
		getline(File, line);
		if (line.size() > 0) {
			ProcessString(line);
		}
		
	}
	File.close();

	cout << Crims.size() << " Criminals read into database" << endl;
}

// Iterates Crims set and displays criminal records on screen 10 at a time
void Prison::DisplayPrisioners() {
	int i = 0;
	for (Criminal *a : Crims) {
		a->Print();
		i++;
		if (i >= 10) {
			string input;
			cout << "Would you like 10 more results? (y/n) \n";
			cin >> input;
			if (input != "y") {
				cin.ignore();
				return;
			}
			else {
				i = 0;
				cout << endl;
			}
		}
	}
}

//ReduceSentence( ) should reduce the remaining months of all the inmates by 6 months
void Prison::ReduceSentence() {
	cout << "Reducing sentence of all prisoners by 6 months." << endl;
	for (Criminal *a : Crims) {
		a->ReduceSentence();
	}	
	cout << "Do you want to check for prisoners awaiting release? (y/n)"<< endl;
	string input;
	cin >> input;
	cin.ignore();

	if (input == "y") {
		CheckParole();
	}
	else
		return;
}

void Prison::CheckParole(){
	if (Crims.size() == 0) {
		cout << "Plase load the database first." << endl;
		return;
	}
	for (Criminal *inmate : Crims) {
		if (inmate->CheckRelease()) inmate->Print();

	}
	for (Criminal *inmate : Crims) {
		if (inmate->CheckRelease() == true) {
			inmate->Sentence();
			string input;
			cin >> input;
			if (input == "y") {
				inmate->Sentence(true);
				//Criminal *tmp = inmate;
				//delete (inmate);
				Release(inmate);
			}
			else
				inmate->Sentence(false);
		}
	}
	SaveData();
}
void Prison::Release(Criminal* b) {
	set<Criminal*, Comp>::iterator it = Crims.begin();
	for (; it != Crims.end(); ) {
		Criminal *n = *it;
		if (*n == *b) {
			it = Crims.erase(it);
		}
		else {
			++it;
		}
	}
}

void Prison::SaveData() {
	ofstream  File;
	File.open("Crims.txt");
	for (Criminal *inmate : Crims) {
		File << inmate->getData();
	}
	File.close();
}
