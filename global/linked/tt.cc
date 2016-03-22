
#include <fstream>
#include <cmath>
#include <complex>
#include <iostream>
#include <iomanip>
//#include <vector>
#include <limits>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#include "control.h"
using namespace std;

// declarations (not definitions!)
extern double glob;
void my_func(double&); // extern is optional!
void ff2();
//extern class myclass; // asi no; se declara con .h

int main(){
    glob = 9.99;
    printf(" ---> g: %g\n", glob);

    my_func(glob);
    printf(" ---> g: %g\n", glob);

    ff2();
    printf(" ---> g: %g\n", glob);

    printf(" ---> @main(): %g", CTE);
    //myclass mc;
    return 0;
}
