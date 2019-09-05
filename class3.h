//As the beginner this is a simple example of class in the c++
// This will read the name and print in the screen. 

#include <iostream>
#include <string>

using namespace std;
//make a class as IndiClass which will ask and print my detail.

class IndiClass
{
    public:
//This is the constructor has the same name as the class.
// It can neither return nor even void.         
	    IndiClass(string x, double y, double z, string col);
	//Destructor and have the same name as the Class and constructor with ~
        ~IndiClass();
	    void get_detal();
	    string getName();
        int getage();
        double getheight();
        string getcolor();
    
    private:
    //global variable in the private you can declare it in the public but not the professional way
    //since these are not required to change by the public
    //care muct be take while decideing the private and public in c++    	
	    string name;
	    double age;
	    double height;
	    string color;

};

//Constructor passing the default variables. 
    IndiClass::IndiClass(string x, double y, double z, string col)
    {
    	name=x;
    	age=y;
    	height=z;
    	color=col;
    }
    
    IndiClass::~IndiClass()
    {
        cout<<"emptying variables"<<"\n";
        cout<<"you can delete the varible and memory allocation in variables here."<<"\n";
    }
//This function ask all the information about me.
//store in the global variable w
	void IndiClass::get_detal()
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
    string IndiClass::getName()
    {
    	return name;
    }
    int IndiClass::getage()
    { 
    	return age;
    }
    double IndiClass::getheight()
    {
    	return height;
    }
    string IndiClass::getcolor()
    {
    	return color;
    }
