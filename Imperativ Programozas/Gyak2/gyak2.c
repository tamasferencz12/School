#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h> // INT_MIN INT_MAX

int main(void){

    //printf("gyak02\n");

    //1. feladat
    /*

    int num=0;
    printf("A num erteke: %d\n", num);

    //2. feladat
    
     const int num2 = 6;  //read only

     if (num2 % 2 ==0)
     {
         printf("Paros\n");
     }else
    {
         printf("Paratlan\n");
     }

    //felteteles operator
    (num2 % 2 ==0) ? printf("Paros\n") : printf("Paratlan\n");


    // 3. feladat

    int num3;
    printf("A vizsgalando szam: \n");
    scanf("%d", &num3);
    if(num3 > 0){
        printf("A szam pozitiv!\n");
    }else{
        if (num3 == 0)
        {
            printf("A szam 0!\n");
        }else{
            printf("A szam negativ!\n");
        }
    }
    

   // 4. feladat

   printf("\n === Int ertekek === \n");
   int num4 = 4;
   printf("Egesz: %d\n", num4);
   num4 = 4.4;
   printf("Valos: %d\n", num4);
   num4 = true;
   printf("Logikai: %d\n", num4);
   num4 = 'c';
   printf("Karakter: %d\n", num4);
   num4 = "abc";
   printf("Karakter lanc: %d\n", num4);
    

   // 5. feladat
   
    printf("\n === Int ertekek === \n");
   float num5 = 4;
   printf("Egesz: %.2f\n", num5);
   num5 = 4.4;
   printf("Valos: %.2f\n", num5);
   num5 = true;
   printf("Logikai: %.2f\n", num5);
   num5 = 'c';
   printf("Karakter: %.2f\n", num5);
   //num5 = "abc";
   //printf("Karakter lanc: %.2f\n", num5);
    
    

   // 6. feladat

    long int n;
    printf("Az int merete: %ld bajt\n", sizeof(n)); // 4 bajt -> 32 bit,  1 bit elojel 31 bit
    int min = -pow(2, 31);
    int max = pow(2, 31);
    printf("Legkisebb: %d\n", min);
    printf("Legnagyobb: %d\n", max);
    printf("Legkisebb-1: %d\n", min-1);
    printf("Legnagyobb+1: %d\n", max+1);
    printf("Legkisebb: %d\n", INT_MIN);
    printf("Legnagyobb: %d\n", INT_MAX);

    // 7. feladat

    float a = 5.0;
    float b = 4.0;

    printf("%.2f es %.2f atlaga = %.2f\n", a, b, (a+b)/2.0);

    // 7. gyakorlo
    // NOT SAFE
    for (float i = 0.0; i <= 1.0; i += 0.1)         // i = i + 0.1
    {
        printf("%.1f\n", i);                       // lebegopontos szamok "zajosak"
    }

    printf("\n");

    // ciklusvaltozo EGESZ
    for (float i = 0; i <= 10; i += 1)              // i = i + 1
    {
        printf("%.1f\n", i* 0.1);                       // lebegopontos szamok "zajosak"
    }
    

    // 5. feladat

    int a, b;
    printf("kerek 2 egesz szamot\n");
    scanf("%d %d", &a , &b);
    a = (a > 0) ? a : -a;
    b = (b > 0) ? b : -b;

    //Brute Force
    int lnko;
    for (int i = 1; i < i<=a && i<=b; i++)
    {
        if(a% i == 0 && b%i == 0){
            lnko = i;
        }
    }

    printf("lnko: %d\n", lnko);


    // Kivonsasos

    int aa = a;
    int bb = b;
    while (aa != bb)
    {
        if(aa > bb){
            aa-=bb;
        }else
        {
            bb-=aa;
        }
    }

    printf("lnko: %d\n", lnko);
    

    //Euklideszi modszer

    int temp;
    while (b>0)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    printf("lnko: %d\n", a);


    //szorzo tabla

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            printf("%d  ", i*j);
        }
        printf("\n");
    }


    //sakk tabla
    
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if ((i+j) % 2 == 0)
            {
                printf("  ");
            }else{
                printf("[]");
            }
            
            
        }
        printf("\n");
    }

   printf("%lu\n", sizeof(int));
   printf("%lu\n", sizeof(long int));
   printf("%lu\n", sizeof(unsigned int));
   printf("%lu\n", sizeof(unsigned long int));
   printf("%lu\n", sizeof(char));
   printf("%lu\n", sizeof(bool));
   printf("%lu\n", sizeof(float));
   printf("%lu\n", sizeof(double));
   printf("%lu\n", sizeof(long double));
 */

    return 0;
}
