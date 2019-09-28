#include <iostream>
#include <string>
#include "class1.h"

using namespace std;

//Below is the main part of the program to execute
int main()
{
    IndiClass inobj;
    inobj.get_detal();
	cout <<"You are " <<inobj.getName();
	cout << "\n";
	cout <<"You are "<< inobj.getage() <<"\t"<<" years old";
    cout << "\n";
    cout <<"You are "<< inobj.getheight() <<"\t"<<" inch tall";
    cout << "\n";
    cout <<"you are "<< inobj.getcolor() <<"\t"<<"color";
    cout << "\n";
	return 0;
}