#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "matrix.h"

// gcc -o main -W -Wall -Wextra -pedantic main.c menu.c matrix.c
int main(void)
{
    int menu;
    int dimension;
    int directionType;
    char direction;

    char filename[20];
    int **matrix = NULL;

    do
    {
        menu = showMainMenu();
        switch (menu)
        {
        case 0:
            freeMatrix(matrix, dimension);
            printf(">> EXITED!\n");
            return 0;
            break;
        case 1:
            userGuide();
            break;
        case 2:
            freeMatrix(matrix, dimension);
            readMatrixData(&dimension, &directionType, &direction);
            matrix = generateSprial(dimension, directionType, direction);
            break;
        case 3:
            saveMatrix(matrix, dimension, directionType, direction);
            break;
        case 4:
            freeMatrix(matrix, dimension);

            printf(">> Enter the matrix's filename: ");
            scanf("%s", filename);
            matrix = loadMatrix(filename, &dimension);
            break;
        case 5:
            printMatrix(matrix, dimension);
            break;

        default:
            printf("\n");
            printf(">>Thers no such task as (%d), try: 0 - 5, or press 1 to see the User Guide!\n", menu);
            printf("\n");
            break;
        }
    } while (menu != 0);
}
