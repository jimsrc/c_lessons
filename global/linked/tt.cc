
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

using namespace std;

extern double glob;
void my_func(double&); // extern is optional!
void ff2();

int main(){
    glob = 9.99;
    printf(" ---> g: %g\n", glob);

    my_func(glob);
    printf(" ---> g: %g\n", glob);

    ff2();
    printf(" ---> g: %g\n", glob);

    return 0;
}
