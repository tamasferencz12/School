#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_N(void){

    srand(time(NULL));
    int num;
    num = rand() % 6;

    return num;
}
