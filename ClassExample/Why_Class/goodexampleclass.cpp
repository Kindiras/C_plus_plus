#include <iostream>
#include <string>

using namespace std; //This is for stardard library.
// Define a class called student with S capital

class Student
{
	//3 string and variables are required and those are private.
	string name;
	int id;
	int gradDate;

public:
	Student(string x, int y, int z); // Constructor
	~Student(); //destructor
	void set_detail(); // use `set` to access the private variable
	string get_name(); // use `get` to assign the values for the variables
	int get_id();
	int get_graduation();
	void print();


};
// This sets the default values for the program. 
Student::Student(string x, int y, int z)
   {
   	name =x;
   	id =y;
   	gradDate =z;
   }

   Student::~Student()
   {
   	cout <<"emptying the varibles if any?"<<"\n";
   }
//This function get the info of a student
 void Student::set_detail()
    {
    	string x;
    	cout <<"\n enter student name" <<"\n";
    	cin >> x;
    	name =x;
        int y;
        cout <<"enter student id" <<"\n";
        cin >> y;
        id = y;
        int z;
        cout <<"enter student graduation date" <<"\n";
        cin >> z;
        gradDate = z;
    }  

    // Now I have to return the values and varibles
 string Student::get_name()
      { 
      	return name;
      }   
 int Student::get_id()
 {
 	return id;
 }
  
  int Student::get_graduation()
  {
  	return gradDate;
  }
 
 void Student::print()
    {
    	cout <<"name:"<<name <<"\t" <<"id:" <<id <<"\t" <<"gradDate:" <<gradDate <<"\n";
    }


int main()
    {
      int i; int tstdnt=0;
      while(tstdnt<5)    
        {
    	  Student stdninfo("Indiras",200,2020); //it sets the default value
        stdninfo.set_detail();
        stdninfo.get_name();
        stdninfo.get_id();
        stdninfo.get_graduation();
        stdninfo.print();
        tstdnt++;
      }
        return 0;
    }


