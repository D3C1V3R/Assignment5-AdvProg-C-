#include <iostream>
#include "prison.h"
using namespace std;
 
char Menu();

int main(){
	Prison P;
	cout << "Criminal Processing System V1.0\n\n";
	for(;;){
		switch(Menu()){
			case '1': P.ReadCrimFile(); break;
			case '2': P.DisplayPrisioners(); break;
			case '3': P.ReduceSentence(); break;
			case '4': P.CheckParole(); break;
			case 'q': cout << "Thanks for using Text File Word Counter\n";
					  return(0);
			default: cout << "Invalid command!\n";
		}
	}
	return 0;
}

char Menu(){
	char Cmd[20];
	cout << endl;
	cout << "(1) Read criminal file\n";
	cout << "(2) Display prisioners\n";
	cout << "(3) Reduce sentence\n";
	cout << "(4) Check for parole\n";
	cout << "(q) Quit\n";
	cout << "Command > ";
	cin.getline(Cmd,20);
	cout<<endl;
	return Cmd[0];
}

