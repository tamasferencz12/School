#include <stdio.h>
#include <stdbool.h>

#define HEIGHT 10
#define WIDTH 10
#define BOATS_NUM 10

void init(int board[HEIGHT][WIDTH], int boats[6]){

    for (size_t i = 1; i <= 10; i++)
    {
        for (size_t j = 1; j <= 10; j++)
        {
            board[i][j]= 0;
        }
    }
    
    for (size_t i = 1; i <=5 ; i++)
    {
        boats[i]= 0;
    }
    
}

void print_table(int board[HEIGHT][WIDTH]){
    for (size_t i = 1; i <= 10; i++)
    {
        for (size_t j = 1; j <= 10; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isTheAreaClear(int board[HEIGHT][WIDTH], int x, int y){
    bool felt = true;

    for (int i = x-1; i <= x+1; i++)
    {
        for (int j = y-1; j <= y+1; j++)
        {
            if (board[i][j] == 1) 
            {
                return false;
            }
        }
        
    }
    return felt;
}

void submit(int board[HEIGHT][WIDTH], int boats[BOATS_NUM],char startingPoint1, int startinPoint2, int boatLenght, char direction){

    int startingPoint1ToNum;
    bool help=true;

    switch (startingPoint1)
    {
    case 'A':
        startingPoint1ToNum = 1;
        break;
    case 'B':
        startingPoint1ToNum = 2;
        break;
    case 'C':
        startingPoint1ToNum = 3;
        break;
    case 'D':
        startingPoint1ToNum = 4;
        break;
    case 'E':
        startingPoint1ToNum = 5;
        break;
    case 'F':
        startingPoint1ToNum = 6;
        break;
    case 'G':
        startingPoint1ToNum = 7;
        break;
    case 'H':
        startingPoint1ToNum = 8;
        break;
    case 'I':
        startingPoint1ToNum = 9;
        break;
    case 'J':
        startingPoint1ToNum = 10;
        break;
    }

    if (direction == '|')
    {
        for (int  i = startingPoint1ToNum; i <= (startingPoint1ToNum + boatLenght-1); i++)
        {
            for (int  i = startingPoint1ToNum; i <= (startingPoint1ToNum + boatLenght-1); i++)
            {
                if (((boatLenght >=1) && (boatLenght <=5)) && !isTheAreaClear(board, i, startingPoint1ToNum))
                {
                    help=false;
                }
            }
        }

        if (help)
        {
            for (int  i = startingPoint1ToNum; i <= (startingPoint1ToNum + boatLenght-1); i++)
            {
                for (int  i = startingPoint1ToNum; i <= (startingPoint1ToNum + boatLenght-1); i++)
                {
                    board[i][startingPoint1ToNum]=1;
                }
            }
        }
        
    }else if (direction == '-')
    {
        for (int i = startingPoint1ToNum; i <= (startingPoint1ToNum + boatLenght -1); i++){
            if (((boatLenght >=1) && (boatLenght <=5)) && !isTheAreaClear(board, i, startingPoint1ToNum))
                {
                    help=false;
                }
        }

        if (help)
        {
            for (int i = startingPoint1ToNum; i <= (startingPoint1ToNum + boatLenght -1); i++){
                board[startingPoint1ToNum][i]=1;
            }
        }
    }
    
}

int main(void){

    int board[HEIGHT][WIDTH];
    int boats[6]={0,0,0,0,0};

    init(board, boats);
    //print_table(board);
    submit(board,boats,'E', 4, 3, '|');
    submit(board,boats,'E', 4, 2, '-');
    submit(board,boats,'C', 1, 3, '-');
    submit(board,boats,'C', 1, 2, '|');
    submit(board,boats,'G', 6, 4, '-');
    submit(board,boats,'G', 6, 2, '|');
    print_table(board);

    return 0;
}
