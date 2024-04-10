#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "shared.h"

void clear_stream(void){
    int c;
    while ((c=getchar()!=EOF && c!='\n'));
}

char* read_string(char text[]){
   char* c = fgets(text, BUFFER, stdin);
   if(c == NULL) return c;

    if (strchr(text, '\n') != NULL)
    {
        *strchr(text, '\n') = '\0'; // felulirom \0-val az ENTERt
    }else{
        clear_stream();
    }
    
    printf("%s -> meret: %zu\n", text, strlen(text));

    return c;
}
