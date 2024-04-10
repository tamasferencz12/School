#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "shared.h"
#include "safeio.h"

void reverse(char* text){
    size_t n = strlen(text);
    for(size_t i = 0; i < n/2; i++){
        char temp = text[i];
        text[i]= text[n - 1 - i];
        text[n - 1 - i] = temp;
    }
}

char* reverse2(char* text){
    size_t n  = strlen(text)+1;

    char* newt = calloc(n, sizeof(char)); // bit "0zas"
    if(newt == NULL){
        printf("Calloc ERROR!\n");
        return NULL;
    }
    memset(newt, '\0', n);

    for(size_t i=0; i<n-1; i++){
        *(newt + n-2 -i) = *(text+i);
    }

    return newt;
}

void words(void){
    char** storage = NULL;
    printf("\n Kerem a szavakat (EOF-ig)\n");

    int i = 0;

    char word[BUFFER];
    while(read_string(word) != NULL){

        if(i % GROW == 0){
            char** temp = realloc(storage, (i+GROW)*sizeof(*storage));
            if(temp == NULL){
                printf("Realloc ERROR!\n");
                return;
            }else{
                printf("Realloc Siker! Uj kap: %d \t (%p)\n", (i+GROW), (void*)temp);
            }

            storage = temp;
        }

        storage[i] = (char*)malloc(strlen(word)+1);
        if(storage[i] == NULL){
        printf("Malloc ERROR!\n");
        return;
        }
        strcpy(storage[i], word);
        i++;
    }
    printf("Beolvasas vege! (%d bemenet)", i);

    for(int j=i-1; j>=0;j--){
        printf("Szo %d.: %s\n", j+1, storage[j]);
    }

    for(int j=0; j<i;++j){
        printf("\n Free %d.: %s\n", j+1, storage[j]);
        free(storage[j]);
    }
    free(storage);
    
}
