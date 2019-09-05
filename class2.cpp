#include <iostream>
#include <string>
#include "class2.h"

using namespace std;

//Below is the main part of the program to execute
int main()
{
    //inobj is the object for the constructor and given balue are the default value.
    IndiClass inobj("David",30,5.9,"brown");
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