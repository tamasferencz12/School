#include <stdio.h>

extern char* g;
static int g2 = 12;

void task8(void){
    static int counter = 0;
    counter++;
    printf("Call: %d\n", counter);
}
void task8b(void){
    g = "global_util";
    printf("Global: %s\n", g);
    printf("Static Global: %d\n", g2);
}
int* task8c(void){
    static int counter = 0;
    counter++;
    return &counter;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* bigger(int* a, int* b){
    return (*a>*b)?a:b;
}
