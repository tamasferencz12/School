#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void op_chains(void){
    int a, b, c;
    a = 1; b = 1; c = 1;
    printf("%d == %d == %d\n", a, b, c);  ((a == b) == c) ? printf("True\n") : printf("False\n");
    a = 0; b = 1; c = 2;
    printf("%d == %d == %d\n", a, b, c);  ((a == b) == c) ? printf("True\n") : printf("False\n");
    a = 2; b = 1; c = 0;
    printf("%d == %d == %d\n", a, b, c);  ((a == b) == c) ? printf("True\n") : printf("False\n");
    a = 0; b = 0; c = 0;
    printf("%d == %d == %d\n", a, b, c);  (a == (b == c)) ? printf("True\n") : printf("False\n");

}

void types(void){
    printf("Short Int %lu\n", sizeof(short int));
    printf("Int %lu\n", sizeof(int));
    printf("Long Int %lu\n", sizeof(long int));
    printf("Long Long Int %lu\n", sizeof(long long int));  // -std=c99

    printf("Char %lu\n", sizeof(char));
    printf("_Bool %lu\n", sizeof(_Bool));
    printf("Bool %lu\n", sizeof(bool));

    printf("Float %lu\n", sizeof(float));
    printf("Double %lu\n", sizeof(double));
    printf("Long Double %lu\n", sizeof(long double));
}

void leap_year(void){
    printf("Kerek egy evszamot: ");
    int year;
    scanf("%d", &year);

    if((year % 4 != 0) || (year % 100 == 4 && year % 400 != 0)){
        printf("nem szokoev\n");
    } else {
        printf("szokoev\n");
    }

    _Bool isLY = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    (isLY) ? printf("szokoev\n") : printf("nem szokoev\n");
}

void guessing(void){
    int num,x,y;
    int max = 100;
    int min = 0;

    printf("Add meg a tetszolegesen valasztott szamod 1 es 100 kozott: ");
    scanf("%d", &num);

    srand(time(NULL));
    

    do
    {

        x = rand() % max + min;

        if (x == num)
        {
            printf("Megtalaltam a szamod, ami %d\n", x);
        }else {
            printf("A tippelt szam: %d\n", x);
            printf("A tippelt szamnal kisebb vagy nagyob a szamod? (0-kisebb, 1-nagyobb): ");
            scanf("%d",&y);
            if (y == 1)
            {
                min = x;
            }
            if (y == 0)
            {
                max = x;
            }
        }
        
    } while (x != num);
    
}

int main(void){

    /*
    srand(time(NULL));
    //srand(0);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", rand()%6+1);
    }
    */
    
    
    // 1. feladat
    //types();

    // 2. feladat
    //op_chains();

    // 4. feladat
    //leap_year();

    // 1. gyakorlo
    guessing();

    return 0;
}
