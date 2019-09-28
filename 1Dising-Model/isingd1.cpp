#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctime>    
#include <cstdlib>
#include "isingd1.h"

using namespace std;

int main()
{
	IsingD1  ising(315,0.01,0); 
    ising.mcmove();
	return 0;
}