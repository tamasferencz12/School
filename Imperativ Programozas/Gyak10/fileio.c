#include <stdio.h>
#include <ctype.h>

#define FBUFFER 256

void file_read(void){
    FILE* fin;
    char filename[] = "gyumolcsok.txt";
    fin = fopen(filename, "r");
    if(fin == NULL){
        printf("Nem talalhato a file!\n");
        return;
    }

    char row[FBUFFER];

    while (fgets(row, FBUFFER, fin) != NULL)
    {
        int i = 0;
        while (row[i]!='0')
        {
            row[i] = toupper(row[i]);
            i++;
        }
        printf("%s", row);
    }

    fclose(fin);
    
}

void file_rw(void){
    FILE* fin;
    FILE* fout;

    char filename[] = "gyumolcsok.txt";
    char filename2[] = "gyumolcsok_nagy.txt";
    fin = fopen(filename, "r");
    if(fin == NULL){
        printf("Nem talalhato a file!\n");
        return;
    }

    fout = fopen(filename2, "w"); //fajl elejere irunk, ures allomannyal dolgozik
    //fout = fopen(filename2, "a"); //fajl utolso karakteretol (EOF) dolgozik

    char row[FBUFFER];

    while (fgets(row, FBUFFER, fin) != NULL)
    {
        int i = 0;
        while (row[i]!='0')
        {
            row[i] = toupper(row[i]);
            i++;
        }
        fprintf(fout, "%s", row);
    }

    printf("A %s-t sikeresen feltotottuk!\n", filename2);

    fclose(fin);
    fclose(fout);
}
