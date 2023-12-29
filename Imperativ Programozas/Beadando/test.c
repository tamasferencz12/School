#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "constants.h"
#include "matrix.h"

int main()
{

    // Test driven programming
    // getNextCwDirection TESTS
    char i = DIRECTION_UP;
    char k = getNextCwDirection(i);
    printf("CW: %c -> %c, %d\n", i, k, k == DIRECTION_RIGHT);

    i = DIRECTION_RIGHT;
    k = getNextCwDirection(i);
    printf("CW: %c -> %c, %d\n", i, k, k == DIRECTION_DOWN);

    i = DIRECTION_DOWN;
    k = getNextCwDirection(i);
    printf("CW: %c -> %c, %d\n", i, k, k == DIRECTION_LEFT);

    i = DIRECTION_LEFT;
    k = getNextCwDirection(i);
    printf("CW: %c -> %c, %d\n", i, k, k == DIRECTION_UP);

    // getNextCCwDirection TESTS

    i = DIRECTION_DOWN;
    k = getNextCCwDirection(i);
    printf("CCW: %c -> %c, %d\n", i, k, k == DIRECTION_RIGHT);

    i = DIRECTION_RIGHT;
    k = getNextCCwDirection(i);
    printf("CCW: %c -> %c, %d\n", i, k, k == DIRECTION_UP);

    i = DIRECTION_UP;
    k = getNextCCwDirection(i);
    printf("CCW: %c -> %c, %d\n", i, k, k == DIRECTION_LEFT);

    i = DIRECTION_LEFT;
    k = getNextCCwDirection(i);
    printf("CCW: %c -> %c, %d\n", i, k, k == DIRECTION_DOWN);

    // getStartRow tests
    int dim = 3;
    int directionType = DIRECTION_CW_TYPE;
    char direction = DIRECTION_UP;
    int r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 5;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_UP;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 2);

    dim = 7;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_UP;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 3);

    dim = 19;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_UP;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 9);

    dim = 2;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_UP;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 2;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_LEFT;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 2;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_RIGHT;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 0);

    dim = 2;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_DOWN;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 0);

    dim = 4;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_UP;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 2);

    dim = 4;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_LEFT;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 2);

    dim = 4;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_RIGHT;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 4;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_DOWN;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 2;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_UP;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 2;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_LEFT;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 0);

    dim = 2;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_RIGHT;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 2;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_DOWN;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 0);

    dim = 4;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_UP;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 2);

    dim = 4;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_LEFT;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 4;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_RIGHT;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 2);

    dim = 4;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_DOWN;
    r = getStartRow(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    // getStartColumn tests
    dim = 3;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_UP;
    r = getStartColumn(dim, directionType, direction);
    printf("START ROW: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 5;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_UP;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 2);

    dim = 7;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_UP;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 3);

    dim = 19;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_UP;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 9);

    dim = 2;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_UP;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 0);

    dim = 2;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_LEFT;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 2;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_RIGHT;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 0);

    dim = 2;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_DOWN;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 4;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_UP;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 4;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_LEFT;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 2);

    dim = 4;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_RIGHT;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 4;
    directionType = DIRECTION_CW_TYPE;
    direction = DIRECTION_DOWN;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 2);

    dim = 2;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_UP;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 2;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_LEFT;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 2;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_RIGHT;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 0);

    dim = 2;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_DOWN;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 0);

    dim = 4;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_UP;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 2);

    dim = 4;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_LEFT;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 2);

    dim = 4;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_RIGHT;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);

    dim = 4;
    directionType = DIRECTION_CCW_TYPE;
    direction = DIRECTION_DOWN;
    r = getStartColumn(dim, directionType, direction);
    printf("START COL: %d, %d, %c -> %d, %d\n", dim, directionType, direction, r, r == 1);
    return 0;
}