#include <stdio.h>

int main(void){
    
    int fahr;

    for (fahr = -100; fahr <= 400; fahr+=100)
    {
        printf("Fahr = %d,\tCels = %.2f\n", fahr, 5./9.*(fahr-32));
    }

    return 0;
}
