#include <iostream>

using namespace std;

int main()
{
	//syntax
	//enum type_name {value1,value2,value3};

	enum MONTH {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
	MONTH my_best_month;
	my_best_month = May;
	if(my_best_month==May)
	{
		cout<<"This is my birth month\n";

	}
	return 0;
}