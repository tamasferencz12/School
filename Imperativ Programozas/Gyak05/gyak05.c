#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 5
#define DIM 10
#define BUFFER 256

#define STRX(x) STR(x)
#define STR(x) #x

void arr_w_sum(int arr[DIM]){
    int w[DIM] = {1,1,1,1,2,2,2,3,3,4};
    int sum = 0;
    for (int i = 0; i < DIM; i++)
    {
        sum += arr[i]*w[i];
    }
    printf("A tomb sujozott szummaja: %d\n", sum);
}

void arr_w_avg(int arr[],float w[], size_t n){
    printf("A tomb kapott merete %zu\n", n);
    size_t n2 = sizeof(arr) /sizeof(arr[0]);
    printf("A tomb szamitott merete %zu", n2);
}

int main(void){

    //const int CN = 5;
    /*int arr0[N] = {0,0,0,0,0};
    int arr1[N]={0};
    int arr2[N]={1};
    int arr3[N]={2,3};

    for(int i=0; i<N;i++){
        printf("%d \t%d \t%d \t%d\t\n",arr0[i], arr1[i],arr2[i], arr3[i]);
    }
    printf("\n");

    int arr2D[2][3] = {{1 ,2 , 3},{4 ,5 ,6}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",arr2D[i][j]);
        }
        printf("\n");
        
    }
    printf("\n");
    
    int arr[] = {8,6,4,2,0,1,3,5,7,9};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    printf("A tomb merete: %zu\n", n);

    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum+= arr[i];
    }
    printf("A tomb szummaja: %d\n", sum);
    
    int max = arr[0];
    for (size_t i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("A tomb maximuma: %d\n", max);

    arr_w_sum(arr);

    float w[] = {0.8,0.6,0.4,0.2,0.0,0.1,0.3,0.5,0.7,0.9};
    arr_w_avg(arr, w, n);
    printf("\n");

    char word1[] = "alma";    //5
    char word2[] = "almafa";  //7
    size_t s1 = sizeof(word1) / sizeof(word1[0]);
    size_t s2 = sizeof(word2) / sizeof(word2[0]);

    for (size_t i = 1; i < ((s1 < s2)? s1 : s2); i++)
    {
        if (tolower(word1[i]) < tolower(word2[i]))
        {
            printf("A gyoztes: %s\n", word1);
            break;
        }else if (tolower(word1[i]) > tolower(word2[i]))
        {
            printf("A gyoztes: %s\n", word2);
            break;
        }
    }

    if (strcmp(word1, word2)==0)
    {
        printf("A gyoztes: %s\n", word2);
    }

    */

    char input[BUFFER + 1];
    printf("Kerem a szoveget: \n");
    scanf("%"STRX(BUFFER)"[^\n]s", input);
    printf("Az input: %s\n", input);

    size_t n = sizeof(input) / sizeof(input[0]);
    printf("A meret: %zu\n", n);

    printf("A meret: %zu\n", strlen(input));
    size_t strs = 0;
    while (input[strs]!= '\0')
    {
        strs++;
    }

    printf("A meret: %zu\n", strs);
    

    return 0;
}
