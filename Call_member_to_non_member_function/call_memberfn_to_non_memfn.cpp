//This is written by Indiras Khatri
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
class Myinfo
{
public:
	Myinfo();
	~Myinfo();
	void setAge(int z);
	int getAge(void);
	
private:
	int age;
};

Myinfo::Myinfo()
{
	cout <<"my name is indiras"<<endl;
}

Myinfo::~Myinfo()
{
	cout <<"deleting";
}

void Myinfo::setAge(int z)
{    
	age = z;
}

int Myinfo::getAge()
{
	return age;
}

//This is non-member function
//see the way to call the member function in non member function

void get_myinfo(class Myinfo info, int ag)
{
info.setAge(ag);
cout << "my age is:" <<info.getAge() <<endl;
}


int main()
{
int ag = 30;
Myinfo mfo;
get_myinfo(mfo,ag);

return 0;

}
