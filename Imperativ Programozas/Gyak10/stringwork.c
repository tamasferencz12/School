#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "shared.h"

void read_string(char text[]){
    fgets(text, BUFFER, stdin);

    if (strchr(text, '\n') != NULL)
    {
        *strchr(text, '\n') = '\0'; // felulirom \0-val az ENTERt
    }else{
        int c;
        while ((c=getchar()!=EOF && c!='\n'));
    }
    
    printf("%s -> meret: %zu\n", text, strlen(text));
}

void counter(char text[], int* c, int* w, int mode){
    if(mode != 0){
        char* p = text;
        while (*p != '\0')
        {
            p++;
        }
        
        *c = p - text;
    }else{
        *c = strlen(text);
    }

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isspace(text[i]) && (isspace(text[i+1]) || text[i+1]== '\0'))
        {
            (*w)++;
        }
    }
}

void mod_str(void){
    char t[] = "1 - Tomb string";
    char* p = "2 - Pointer string";

    printf("%s\n",t);
    printf("%s\n\n",p);

    //tomb verzio
    t[0] = 'A';
    t[9] = 'S';
    printf("%s\n",t);

    //pointeres verzio
    printf("%c %c\n",*(p+0), *(p+12));
    //*(p+0) = 'B'; //segmentation fault
    //*(p+12) = 'S'; // stringegek immutabilisek
    printf("%s\n",p);
}
