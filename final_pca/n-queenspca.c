#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define n 8

bool issafe(int board[][n], int row, int col)
{
    int row1 = row;
    int col1 = col;

    while (row1 >= 0 && col1 >= 0)
    {
        if (board[row1][col1] == 1)
        {
            return false;
        }
        row1--;
        col1--;
    }

    col1 = col;
    row1 = row;
    while (col1 >= 0)
    {
        if (board[row1][col1] == 1)
        {
            return false;
        }
        col1--;
    }

    col1 = col;
    row1 = row;
    while (col1 >= 0 && row1 < n)
    {
        if (board[row1][col1] == 1)
        {
            return false;
        }
        col1--;
        row1++;
    }

    return true;
}

bool nqueen(int board[][n], int *solution_num, int col)
{
    if (col >= n)
    {
        (*solution_num)++;
        return true;
    }
    bool res = false;
    for (int row = 0; row < n; row++)
    {
        if (issafe(board, row, col) == true)
        {
            board[row][col] = 1;
            
            res = nqueen(board, solution_num, col + 1) || res;

            board[row][col] = 0;
        }
    }

    return res;
}

int main()
{
    int board[n][n] = {0};
    int solutionnum = 0;
    if (nqueen(board, &solutionnum, 0) == true)
    {
        printf("\nThe number of solution possiable :-%d", solutionnum);
    }

    return 0;
}