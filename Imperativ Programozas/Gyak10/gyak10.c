#include <stdio.h>
#include <stdlib.h>  //atoi()
#include <string.h>  //strcmp()

#include "shared.h"
#include "stringwork.h"
#include "fileio.h"

int main(int argc, char *argv[]){

    printf(">> Koszonti Ont a %s program\n", argv[0]);
    printf(">> A kapott parameterek szama: %d\n", argc);

    int menu;
    int mode = 0;

    //ellenorzes
    if(argc <= 1){
        printf(">> Kerem adja meg a futtatni kivant feladat szamat: ");
        scanf("%d", &menu);
        getchar();
    }else{
        if (argc >= 2) menu = atoi(argv[1]);
        if (argc > 2) menu = atoi(argv[2]);
    }
    printf(">> %d feladat inditasa (%s modban)\n\n", menu, (mode==0)?"beepitett":"sajat");

    char input[BUFFER];
    char input2[BUFFER];

    switch (menu)
    {
    case 1:
        printf("Kerek egy mondatot: \n");
        read_string(input);

        int chars = 0;
        int words = 0;
        counter(input, &chars, &words, mode);
        printf("A karakterek: %d - a szavak: %d\n\n", chars, words);
        break;
    case 2:
        printf("Elso szo: \n");
        read_string(input);
        printf("Masodik szo: \n");
        read_string(input2);

        int result = strcmp(input, input2);
        printf("Cmp: %d\n", result);
        break;
    case 3:
        /* code */
        break;
    case 4:
        mod_str();
        break;
    case 5:
        file_read();
        break;
    case 6:
        file_rw();
        break;
    
    default:
        printf("Nem letezo feladat! (%d) Lehetoseg: 1 - 6", menu);
        break;
    }

    printf(">> Viszontlatasra!\n");

    return 0;
}
