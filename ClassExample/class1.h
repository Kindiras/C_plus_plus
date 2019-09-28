//As the beginner this is a simple example of class in the c++
// This will read the name and print in the screen. 

#include <iostream>
#include <string>

using namespace std;
//make a class as IndiClass which will ask and print my detail.

class IndiClass
{
public:
//This function ask all the information about me. 
//store in the global variable which are define in the private;
	 void get_detal()
	{ 
		string x;
		cout << "\n enter your name"<<"\n";
		cin >> x;
		name =x;
		cout << "\n enter your age"<<"\n";
		double y;
		cin >> y;
        age =y;
		cout <<"\n enter your height in feet "<<"\n";
		double z;
		cin >> z;
		height = z;
		cout <<"\n enter your color"<<"\n";
		string col;
		cin >> col;
		color = col;
    }
//each of the function below will print the information.
    string getName()
    {
    	return name;
    }
    int getage()
    { 
    	return age;
    }
    double getheight()
    {
    	return height;
    }
    string getcolor()
    {
    	return color;
    }
//global variable in the private you can declare it in the public but not the professional way
//since these are not required to change by the public
//care muct be take while decideing the private and public in c++    
private:
	string name;
	double age;
	double height;
	string color;
};
