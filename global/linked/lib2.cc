#include <stdio.h> // for printf

#include "control.h"

extern double glob;

void ff2(){
    glob = 55.5;

    printf(" ---> @ff2(): %g\n", CTE);
}
