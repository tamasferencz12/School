#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "shared.h"
#include "safeio.h"
#include "dyn.h"

int main(void){

    
    char input_str[BUFFER];
    printf("Kerem a szoveget: ");
    read_string(input_str);

    int n = strlen(input_str)+1;
    char* input_str_copy = malloc(n*sizeof(char));
    if(input_str_copy == NULL){
        printf("Malloc ERROR!\n");
        return 0;
    }else{
        printf("Minden OK!\n");
    }

    strcpy(input_str_copy, input_str);
    printf("Masolat: %s\n\n", input_str_copy);

    free(input_str_copy);

    char* str = "Hello!";
    printf("Str: %s\n",str);
    printf("Str cime: %p es tartalmanak cime: %p\n",(void*)&str, (void*)str);
    str = "Hi!";
    printf("Str: %s\n",str);
    printf("Str cime: %p es tartalmanak cime: %p\n",(void*)&str, (void*)str);
    char* str2 = str;
    printf("Str: %s\n",str2);
    printf("Str2 cime: %p es tartalmanak cime: %p\n",(void*)&str2, (void*)str2);

    char source[BUFFER] = "Indul a gorog aludni";
    char dest[BUFFER];
    strcpy(dest, source);
    printf("S: %s\n",source);
    printf("S cime: %p es tartalmanak cime: %p\n",(void*)&source, (void*)source);
    printf("D: %s\n",dest);
    printf("D cime: %p es tartalmanak cime: %p\n",(void*)&dest, (void*)dest);

    reverse(dest);
    printf("Forditva: %s\n", dest);
    printf("D cime: %p es tartalmanak cime: %p\n",(void*)&dest, (void*)dest);

    char* ptr;
    ptr = reverse2(source);
    printf("ptr: %s\n", ptr);
    printf("ptr cime: %p es tartalmanak cime: %p\n",(void*)&ptr, (void*)ptr);
    free(ptr);

    words();
    words();

    return 0;
}
