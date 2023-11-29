#include <stdio.h>
#include <ctype.h>
#include <math.h>

#ifdef M_PI
#  define M_PI 3.1415926
#endif

void operator(void);
void little_big(void);
void aritmetics(void);
void circle(void);
void numChange(void);

void triangle(void);
void rectangle(void);
void powerOf(void);

int main(void){

    //operator();
    //operator(42); // helytelen parameter
    //little_big();
    //aritmetics();
    //circle();
    numChange();



    //triangle();
    //rectangle();
    //powerOf();

    return 0;
}

void numChange(void){
    int a, b;
    printf("Add meg a ket szamot: ");
    scanf("%d %d", &a, &b);
    printf("a: %d\n", a);
    printf("b: %d\n", b);

    b = a + b;
    a = b - a;
    b = b - a; 

    printf("a: %d\n", a);
    printf("b: %d\n", b);
}

void operator(void){
    int i = 3;
    int j = ++i;
    printf("j = ++i: %d, %d\n", i, j);
     i = 3;
     j = i++;
    printf("j = i++: %d, %d\n", i, j);
}

void little_big(void){
    char l;

    do{
        printf("Kerem a betuket: ");
        scanf(" %c", &l);
        /*
        scanf(" %c", &l);   // ignore white-space
        scanf("%c", &l);    // formazott adat bekeres
        scanf("%c ", &l);  scanf("%c\n", &l); // sikeres beolvasas utan, a kovetkezo nem white-spaceig olvas
        */

        if (isalpha(l))
        {
            if (islower(l)) printf("Nagy: %c\n", toupper(l));
            if (isupper(l)) printf("Nagy: %c\n", tolower(l));

        }else if('0' != l)
        {
            printf("Nem betu! Ujra kerlek!\n");
        }
        
    }while('0' != l);

    printf("Viszlat!");
}

void aritmetics(void){
    float a, b;

    printf("Kerem a szamokat: ");
    scanf("%f %f", &a, &b);

    printf("%.2f + %.2f = %.2f\n", a, b, a + b);
    printf("%.2f - %.2f = %.2f\n", a, b, a - b);
    printf("%.2f * %.2f = %.2f\n", a, b, a * b);
    printf("%.2f / %.2f = %.2f\n", a, b, a / b);
}

void triangle(void){
    float a, b, c;
    float m, ter = 0;
    printf("Add meg a haromszog oldalait:");
    scanf("%f %f %f", &a, &b, &c);

    m = sqrt(pow(c,2) - pow((a/2), 2));
    ter = (a * m) / 2;

    printf("A haromszog terulete: %.2f\n", ter);
    printf("A haromszog kerulete: %.2f\n", a + b + c);
}

void rectangle(void){
    float a, b, c, d;
    printf("Add meg a teglalap oldalait:");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    printf("A teglalap terulete: %.2f\n", a * b);
    printf("A teglalap kerulet: %.2f\n", a + b + c + d);
}

void powerOf(void){
    int a, b;
    printf("Add meg ket szamot:");
    scanf("%d %d", &a, &b);

    printf("%d ^ %d = %.1f\n", a, b, pow(a, b));
    printf("%d ^ %d = %.1f\n", b, a, pow(b, a));
}

void circle(void){
    float r;
    printf("Add meg a kor sugarat:");
    scanf("%f", &r);

    printf("A kor atmeroje: %.1f\n", r);
    printf("A kor kerulete: %.1f\n", 2 * M_PI * r);
    printf("A kor terulete: %.1f\n", pow(r,2) * M_PI);

}
