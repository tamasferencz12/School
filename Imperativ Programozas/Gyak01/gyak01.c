#include <stdio.h>

int main(void){
    printf("Ferencz Tamas!\n");

    int a = 5;
    int b = 6;

    int c = 0;

    printf("%d + %d = %d\n", a, b, a + b);
    printf("A c valtozo tartalma: %d\n", c);

    printf("%d / %d = %d\n", a, b, a / b);

    printf("%d %% %d = %d\n", a, b, a % b);

    float d = 3;
    float e = 6;
    printf("%.1f / %.1f = %.1f\n", d, e, d / e);
    printf("Int merete: %ld\n", sizeof(int));

    printf("Kerem a kedvenc szamat!\n");
    float szam;
    scanf("%f",&szam);
    printf("A szam: %.2f\n",szam);

    char name[6] = "Tamas"; // '\0' terminalo karakter

    printf("A nevem: %s\n", name);

    float f;
    float g;
    float h;
    float i;

    printf("Add meg a negyszog oldalait:\n");
    scanf("%f", &f);
    scanf("%f", &g);
    scanf("%f", &h);
    scanf("%f", &i);
    printf("A negyszog kerulete: %.2f\n", f + g + h + i);

    float j;
    float k;
    float l;

    printf("Add meg a negyszog szembelevo oldalait:\n");
    scanf("%f", &j);
    scanf("%f", &k);
    printf("Add meg a negyszog magassagat:\n");
    scanf("%f", &l);
    printf("A negyszog terulete: %.2f\n", ((j+k)*l)/2);

    float m;

    printf("Add meg a kor sugarat:\n");
    scanf("%f", &m);
    printf("A kor kerulete: %.4f\n", 2 * m * 3.1415);
    printf("A kor terulete: %.4f\n", m * m * 3.1415);

    return 0;
}
