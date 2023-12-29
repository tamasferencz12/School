#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "constants.h"

char getNextDirection(char current, char *type)
{
    char *pos = strchr(type, current);
    int index = (int)(pos - type);
    index++;
    if (index == 4)
    {
        index = 0;
    }
    return type[index];
}

char getNextCwDirection(char current)
{
    return getNextDirection(current, DIRECTION_CW);
}

char getNextCCwDirection(char current)
{
    return getNextDirection(current, DIRECTION_CCW);
}

char getDirection(char current, int directionType)
{
    return (directionType == DIRECTION_CW_TYPE) ? getNextCwDirection(current) : getNextCCwDirection(current);
}

int getStartColumn(int dim, int directionType, char direction)
{
    if (dim % 2 != 0)
    {
        return dim / 2;
    }
    int mid = dim / 2;

    if (directionType == DIRECTION_CW_TYPE && (direction == DIRECTION_UP || direction == DIRECTION_RIGHT))
    {
        return mid - 1;
    }
    if (directionType == DIRECTION_CW_TYPE && (direction == DIRECTION_LEFT || direction == DIRECTION_DOWN))
    {
        return mid;
    }
    if (directionType == DIRECTION_CCW_TYPE && (direction == DIRECTION_UP || direction == DIRECTION_LEFT))
    {
        return mid;
    }
    if (directionType == DIRECTION_CCW_TYPE && (direction == DIRECTION_RIGHT || direction == DIRECTION_DOWN))
    {
        return mid - 1;
    }
    return dim;
}

int getStartRow(int dim, int directionType, char direction)
{
    if (dim % 2 != 0)
    {
        return dim / 2;
    }
    int mid = dim / 2;

    if (directionType == DIRECTION_CW_TYPE && (direction == DIRECTION_UP || direction == DIRECTION_LEFT))
    {
        return mid;
    }
    if (directionType == DIRECTION_CW_TYPE && (direction == DIRECTION_RIGHT || direction == DIRECTION_DOWN))
    {
        return mid - 1;
    }
    if (directionType == DIRECTION_CCW_TYPE && (direction == DIRECTION_UP || direction == DIRECTION_RIGHT))
    {
        return mid;
    }
    if (directionType == DIRECTION_CCW_TYPE && (direction == DIRECTION_LEFT || direction == DIRECTION_DOWN))
    {
        return mid - 1;
    }
    return dim;
}

int **generateSprial(int dimension, int directionType, char direction)
{
    int **matrix = (int **)malloc(dimension * sizeof(int *));
    for (int i = 0; i < dimension; i++)
    {
        matrix[i] = (int *)malloc(dimension * sizeof(int));
    }

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            matrix[i][j] = 0;
        }
    }
    int i = getStartRow(dimension, directionType, direction);
    int j = getStartColumn(dimension, directionType, direction);
    char currentDirection = direction;
    int current = 1;
    int size = dimension * dimension;
    do
    {
        // printf("[%d,%d], (%d,%d) = %d, %c\n", dimension, size, i, j, current, currentDirection);
        matrix[i][j] = current;
        if (current == size)
            break;

        switch (currentDirection)
        {
        case DIRECTION_UP:
            while (matrix[i - 1][j] != 0)
            {
                if (directionType == DIRECTION_CW_TYPE)
                {
                    j--;
                }
                else
                {
                    j++;
                }
                matrix[i][j] = ++current;
                if (current == size)
                    break;
            }
            i--;
            break;
        case DIRECTION_RIGHT:
            while (matrix[i][j + 1] != 0)
            {
                if (directionType == DIRECTION_CW_TYPE)
                {
                    i--;
                }
                else
                {
                    i++;
                }
                matrix[i][j] = ++current;
                if (current == size)
                    break;
            }
            j++;
            break;
        case DIRECTION_DOWN:
            while (matrix[i + 1][j] != 0)
            {
                if (directionType == DIRECTION_CW_TYPE)
                {
                    j++;
                }
                else
                {
                    j--;
                }
                matrix[i][j] = ++current;
                if (current == size)
                    break;
            }
            i++;
            break;
        case DIRECTION_LEFT:
            while (matrix[i][j - 1] != 0)
            {
                if (directionType == DIRECTION_CW_TYPE)
                {
                    i++;
                }
                else
                {
                    i--;
                }
                matrix[i][j] = ++current;
                if (current == size)
                    break;
            }
            j--;
            break;
        }

        current++;
        currentDirection = getDirection(currentDirection, directionType);
    } while (current <= size);

    printf(">>> Job Done! Spiral matrix generated!\n");

    return matrix;
}

int printMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d  ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf(">>> Job Done! Matrix printed!\n");
    printf("\n");
    return 0;
}

char *genericFilename(int dimension, int directionType, char direction)
{
    char *filename;

    int filenameLength = snprintf(NULL, 0, "spiral%d_%d_%c.txt", dimension, directionType, direction) + 1;

    filename = (char *)malloc(filenameLength * sizeof(char));

    sprintf(filename, "spiral%d_%d_%c.txt", dimension, directionType, direction);

    return filename;
}

int saveMatrix(int **matrix, int dimension, int directionType, char direction)
{
    if (matrix == NULL)
    {
        printf("No matrix generated, so I can't save it!\n");
        return 1;
    }

    char *filename = genericFilename(dimension, directionType, direction);
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Cannot open file for write!\n");
        return 0;
    }

    fprintf(file, "%d\n", dimension);

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            fprintf(file, "%2d  ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Job Done! Matrix saved to %s file!\n", filename);
    free(filename);

    return 0;
}

void freeMatrix(int **matrix, int rows)
{
    if (matrix != NULL)
    {
        for (int i = 0; i < rows; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
    }
}

int **loadMatrix(char *filename, int *length)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cannot open file for read!\n");
        return NULL;
    }

    fscanf(file, "%d", length);

    int **matrix = (int **)malloc(*length * sizeof(int *));
    for (int i = 0; i < *length; i++)
    {
        matrix[i] = (int *)malloc(*length * sizeof(int));
    }

    int row = 0;

    while (!feof(file))
    {
        for (int i = 0; i < *length; i++)
        {
            if (fscanf(file, "%d", &matrix[row][i]) == EOF)
            {
                break;
            }
        }
        row++;
    }

    fclose(file);

    printf("Job Done! Matrix loaded from %s file!\n", filename);

    return matrix;
}

void readMatrixData(int *dimension, int *directionType, char *direction)
{
    do
    {
        printf(">> Enter the matrix dimension [2-20]: ");
        scanf("%d", dimension);
    } while (*dimension < 2 || *dimension > 20);

    do
    {
        printf(">> Enter the matrix's rotation direction [0 - clockwise | 1 - counter clockwise]: ");
        scanf("%d", directionType);
    } while ((*directionType != 0) && (*directionType != 1));

    do
    {
        getchar();
        printf(">> Enter the matrix first move direction [U|R|D|L]: ");
        scanf("%c", direction);
        getchar();
    } while (strchr("URDL", *direction) == NULL);
}
