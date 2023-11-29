#include <stdio.h>

#define BUFFER 10

int arr_sum(int array[], size_t n){
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return sum;
}

int arr_sum2(int* array, int* end){
    int sum = 0;
    for (; array < end; array++)
    {
        sum += *array;
    }
    return sum;
}

void print_arr(int* array, int* end){
    for (; array < end-1; array++)
    {
        printf("%d, ", *array);
    }
    printf("%d\n", *array);
}

int arr_avg(int* start, int* end){
    int avg = 0;
    for (int* array = start; array < end; array++)
    {
        avg += *array;
    }
    return avg / (end-start);
}

int p_comparator(int* p1, int* p2){
    return (p1>p2) - (p1<p2);
}

/*
int main(void){
    int loc = 5;
    prinf("A loc cime %p es erteke: %d\n", (void*)&loc, loc);
    {
        int loc = 15;
        prinf("A loc cime %p es erteke: %d\n", (void*)&loc, loc);
    }
    prinf("A loc cime %p es erteke: %d\n", (void*)&loc, loc);
}
*/

int* local_pointer(void){
    int local = 42;
    int* p = &local;
    return p;
}

int main(void){

    /*
    int* p;
    int * p;
    int *p;
    

    int c = 4;
    printf("A c cime %p es erteke %d\n", (void*)&c, c);
    int* p = &c;
    printf("A c cime %p es erteke %p\n", (void*)&p, (void*)p);
    printf("A p altal mutatott cim %p es az ott levo erteke: %d\n", (void*)&(*p), *p);

    c++;
    printf("A c cime %p es erteke %d\n", (void*)&c, c);
    printf("A c cime %p es erteke %p\n", (void*)&p, (void*)p);
    printf("A p altal mutatott cim %p es az ott levo erteke: %d\n", (void*)&(*p), *p);
    p++;
    printf("A c cime %p es erteke %d\n", (void*)&c, c);
    printf("A c cime %p es erteke %p\n", (void*)&p, (void*)p);
    printf("A p altal mutatott cim %p es az ott levo erteke: %d\n", (void*)&(*p), *p);

    int b = 8;
    int* p1 = &b; // p1 mutasson b-re
    int* p2 = p1; // p2 mutasson b-re
    int** p3 = &p1;
    printf("eredeti b: %d\n", b);
    printf("p2 inc b: %d\n", ++(*p2));
    printf("p3 inc b: %d\n", ++(*(*p3)));

    void* pi = &pi;
    printf("int* %zu\n", sizeof(int*));
    printf("char* %zu\n", sizeof(char*));
    printf("double* %zu\n", sizeof(double*));

    int array[BUFFER] = {1,2,3,4,5,6,7,8,9,0};
    size_t n = sizeof(array) / sizeof(*array); // array[0]

    printf("osszeg: %d\n", arr_sum(array,n));
    printf("osszeg: %d\n", arr_sum2(array,array+n));
    print_arr(array, array+n);
    print_arr(array, array+n+1);
    print_arr(array, array+n+10);
    printf("atlag: %d\n", arr_avg(array,array+n));
    printf("atlag: %d\n", arr_sum2(array,array+n) / (int)((array+n)-(array)));
    return 0;
    

    int* lp = local_pointer();
    printf("A lokalis ertek: %d\n",*lp);

    int* pNull = NULL;
    if(pNull != NULL){
        printf("d\n", *pNull);
    }else{
        printf("Ez egy NULL pointer\n");
    }

    int p10[BUFFER];
    int* p20 = p10;
    p20 +=3;

    switch (p_comparator(p10, p20))
    {
    case 1:
        printf("p10\n");
        break;
    case 0:
        printf("==\n");
        break;
    case -1:
        printf("p20\n");
        break;
    }
    */

}
