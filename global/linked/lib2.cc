#include <stdio.h> // for printf

#include "control.h"

extern double glob;

class myclass{
    int a, b;
    myclass();
};

myclass::myclass(){
    a = 777;
    b = 0;
}


void ff2(){
    glob = 55.5;

    printf(" ---> @ff2(): %g\n", CTE);
}
