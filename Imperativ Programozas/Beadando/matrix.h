#ifndef MATRIX_H
#define MATRIX_H

char getNextDirection(char current, char *type);
char getNextCwDirection(char current);
char getNextCCwDirection(char current);
char getDirection(char current, int directionType);

int getStartRow(int dim, int directionType, char direction);
int getStartColumn(int dim, int directionType, char direction);

void readMatrixData(int *dimension, int *directionType, char *direction);
int **generateSprial(int dimension, int directionType, char direction);
int printMatrix(int **matrix, int n);
int saveMatrix(int **matrix, int dimension, int directionType, char direction);

int **loadMatrix(char *filename, int *length);
char *genericFilename(int n, char mDir[], char rDir[]);
void freeMatrix(int **matrix, int rows);
#endif // MATRIX_H
