#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_D 5
#define BUFFER_X 20

#define N 5
#define M 3

void print_arr(int* array, int* end){
    for (; array < end-1; array++)
    {
        printf("%d, ", *array);
    }
    printf("%d\n", *array);
}

void print_2Darr(int matrix[N][M]){
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int hex2dec(char hex[], size_t n){
    int dec = 0;
    for (size_t i = 0; i < n; i++)
    {
        if(isdigit(hex[i])){
            dec += (hex[i]-'0')*pow(16,n-i-1);
        }else if( 'a' <= hex[i] && hex[i] <= 'f'){
            dec += (hex[i]-'a'+10)*pow(16,n-i-1);
        }else if( 'A' <= hex[i] && hex[i] <= 'F'){
            dec += (hex[i]-'A'+10)*pow(16,n-i-1);
        }
    }
    return dec;
}

void m_table(int matrix[N][M]){
//void m_table(int matrix[N][M], size_t n)
//void m_table(int *matrix[M], size_t n) // *matrix = matrix[0]
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            matrix[i][j] = (i+1) * (j+1);
        }
    }
}

int sum(int* array, int* end){
    int sum = 0;
    for (; array < end; array++)
    {
        sum += *array;
    }
    return sum;
}

void firstToLast(int num){
    int first, last, middle;
    int nDigits = floor(log10(abs(num))) + 1;
    first = num / pow(10,nDigits-1);
    middle = (num / 10) % (int)pow(10, nDigits - 2);
    int nDigitsM = floor(log10(abs(middle))) + 1;
    last = num % 10;

    printf("lenght: %d\n", nDigits);
    printf("first: %d\n", first);
    printf("middle: %d\n", middle);
    printf("last: %d\n", last);
    

    int numEnd = last * pow(10, nDigits - 1) + (middle * pow(10, nDigits - nDigitsM - 1)) + first;

    printf("%d\n",numEnd);
}

int main(void){
/*
    int numbers[BUFFER_D];
    char hex[BUFFER_X];
    printf("Kerem adja meg a hexa szamokat:\n");
    char c;

    size_t i = 0; // 16-os szam szamjegyei
    size_t j = 0; // elmentett det szamok szama

    while ((c = getchar()) != EOF && j< BUFFER_D)
    {
        if(isxdigit(c)){
            hex[i++] = c; 
        }else if (isspace(c))
        {   
            numbers[j++] = hex2dec(hex, i);
            i = 0;
        }else{
            printf("elvetes: %c\n", c);
        }
    }
    print_arr(numbers, numbers+j);

    int matrix[N][M];
    m_table(matrix);
    printf("\n");
    print_2Darr(matrix);

    int n;
    printf("Add meg az n-t:");
    scanf("%d", &n);

    printf("%d ",sum(1, 1+n));

    int num;
    printf("Add meg a szamot:");
    scanf("%d", &num);

    firstToLast(num); */

    int n;
    printf("Add meg az n-t:");
    scanf("%d", &n);

    int arr[n];
    // Version 2
    //int* arr = malloc(n);

    for(int i=0; i<n;i++){
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }

    printf("%d ",sum(arr, arr+n));
    //Version 2
    //free(arr);
    
    return 0;
}
