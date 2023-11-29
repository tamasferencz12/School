#include <stdio.h>
#include <stdbool.h>

int monoton(int n, int arr[n]){
    bool inc = true;
    bool dec = true;
 
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            inc = false;
        }
    }
 
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            dec = false;
        }
    }
 
    return inc || dec;
}

int main(void){

    int n;
    printf("Add meg az n-t: ");
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("array[%d]= ", i);
        scanf("%d", &array[i]);
    }

    if(monoton(n, array)){
        printf("Monoton!");
    }else{
        printf("Nem monoton!");
    }
    
    return 0;
}
