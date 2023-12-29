#include <stdio.h>

int showMainMenu(void)
{
    int menu = -1;
    printf("+------------------------+\n");
    printf("| Spiral Matrix Program  |\n");
    printf("+------------------------+\n");
    printf("| 1 - User Guide         |\n");
    printf("| 2 - Matrix Generation  |\n");
    printf("| 3 - Save matrix        |\n");
    printf("| 4 - Load matrix        |\n");
    printf("| 5 - Print matrix       |\n");
    printf("| 0 - Exit               |\n");
    printf("+------------------------+\n");

    printf("\n");
    printf(">> Please enter the number of the task you want to run: ");
    scanf("%d", &menu);
    getchar();
    printf("\n");
    return menu;
}
void userGuide(void)
{
    printf(">>This program can generate spiral matrixes. It's saveable, readable, printable! \n");
    printf(">>Task description for each one of them: \n");
    printf(" 1. task -> You can get the description of the program! \n");
    printf(" 2. task -> You can generate a matrix! \n");
    printf(" 3. task -> You can save a matrix to a file! \n");
    printf(" 4. task -> You can load a matrix from a file! \n");
    printf(" 5. task -> You can print the matrix to terminal! \n");
    printf(" 0. task -> You can exit the program! \n");
    printf("\n");
}
