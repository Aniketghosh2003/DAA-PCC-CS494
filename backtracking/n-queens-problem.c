#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int n = 4;

void printboard(int board[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j])
			{
				printf(" Q ");
			}

			else
			{
				printf(" . ");
			}
		}
		printf("\n");
	}
}

bool issafe(int board[n][n], int row, int col)
{
	int row1 = row;
	int col1 = col;

	while (row1 >= 0 && col1 >= 0)
	{
		if (board[row1][col1] == 1)
			return false;
		row1--;
		col1--;
	}

	row1 = row;
	col1 = col;

	while (col1 >= 0)
	{
		if (board[row1][col1] == 1)
			return false;

		col1--;
	}

	row1 = row;
	col1 = col;

	while (row1 < n && col1 >= 0)
	{
		if (board[row1][col1] == 1)
			return false;
		row1++;
		col1--;
	}

	return true;
}

bool solveNQ(int board[n][n], int col)
{
	if (col >= n)
		return true;

	for (int row = 0; row < n; row++)
	{
		if (issafe(board, row, col))
		{
			board[row][col] = 1;
			if (solveNQ(board, col + 1))
			{
				return true;
			}

			board[row][col] = 0;
		}
	}
	return false;
}

int main()
{
	int board[4][4] = {{0, 0, 0, 0},
					   {0, 0, 0, 0},
					   {0, 0, 0, 0},
					   {0, 0, 0, 0}};

	if (solveNQ(board, 0) == true)
	{
		printboard(board);
	}
	else
	{
		printf("\nWrong input!!!");
	}

	return 0;
}