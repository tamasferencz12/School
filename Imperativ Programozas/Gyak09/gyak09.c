#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "my_utils.h"


char* g = "global";
int g2 = 0;

void task(void){

    char* l = "var_tasc-local";
    printf("task: %s\t %s \n", g,l);

    for (int i = 0; i < 10; i++)
    {
        int r = rand() % 3;
        if (r == 0)
        {
            int a = 10;
            printf("%d.: 1.True %d [%d]\n", i, r, a);
        }else if (r == 1)
        {
            int b = 20;
            printf("%d.: 2.True %d [%d]\n", i, r, b);
        } else {
            int c = 30;
            printf("%d.: 2.False %d [%d]\n", i, r, c);
        }
    }
    //printf("%d %d %d\n", i, r, c);
    printf("\n");
    
}

//int task6( int p )
int task6( int );

//int task7(int a, int a);

void nested_swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void){

    srand(time(NULL));

    //1.

    char* f = "var_main-local";
    g = "var-global";
    printf("main: %s\t %s \n", g, f);

    //2.

    task();

    //3.

    char x='x';
    {
        char y='y';
        {
            char z='z';
            printf("Belso: %c %c %c\n", x, y, z);
        }
        printf("Kulso: %c %c\n", x, y);
    }
    printf("Main: %c\n\n", x);

    //4.

    int sz= 100;
    {
        int sz= 70;
        {
            int sz= 50;
            printf("Belso: %d\n", sz);
        }
        printf("Kulso: %d\n", sz);
    }
    printf("Main: %d\n\n", sz);
    
    //5.

    printf("%d\n", task6(7));

    printf("Main Global: %s\n", g);
    task8b();
    printf("Main Global: %s\n", g);

    for (int i = 0; i < 10; i++)
    {
        task8();
    }
    int* p;
    for (int i = 0; i < 10; i++)
    {
        p=task8c();
    }
    printf("Hivasok: %d\n", *p);

    int a = 10;
    int b = 6;
    printf("a: %d \t b: %d\n", a, b);
    swap(&a,&b);
    printf("a: %d \t b: %d\n", a, b);

    printf("Nagyobb: %d\n", *bigger(&a,&b));

    a = 10;
    b = 6;
    printf("a: %d \t b: %d\n", a, b);
    nested_swap(&a,&b);
    printf("a: %d \t b: %d\n", a, b);


    return 0;
}

int task6(int neg){
    return -neg;
}

/*
int task6(double dup){
    return 2*dup;
}*/
