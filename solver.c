#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prints the Sudoku on the console
void print_sudoku(int sudoku[9][9])
{
    printf("The Sudoku contains:\n");
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            printf("%d  ", sudoku[j][i]);
        }
        printf("\n");
    }
}

//Checks whether or not the sudoku has been solved or not
int not_solved(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == 0)
                return 1;
        }
    }
    return 0;
}

//Checks if a number has already been used in the coloumn
int check_col(int sudoku[9][9], int coloumn, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][coloumn] == num && num != 0)
            return 1;
    }
    return 0;
}

//Checks if a number has already been used in the row
int check_row(int sudoku[9][9], int row, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == num && num != 0)
            return 1;
    }
    return 0;
}

//Checks if a number has already been used in the square (3X3)
int check_square(int sudoku[9][9], int row, int coloumn, int num)
{
    int start_row = (row / 3) * 3;
    int start_col = (coloumn / 3) * 3;
    for (int i = start_row; i < start_row + 3; i++)
    {
        for (int j = start_col; j < start_col + 3; j++)
        {
            if (sudoku[i][j] == num && num != 0)
                return 1;
        }
    }
    return 0;
}

//Checks if the row inputted has duplicates or not
int check_duplicates(int arr[9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (arr[i] == arr[j] && arr[i] != 0)
                return 1;
        }
    }
    return 0;
}

//checks whether or not the inputted sudoku is valid or not
int is_valid(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] >= 10 || sudoku[i][j] < 0)
                return 1;
        }
    }
    int temp[9];
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            temp[col] = sudoku[row][col];
        }
        if (check_duplicates(temp) == 1)
            return 1;
    }

    for (int col = 0; col < 9; col++)
    {
        for (int row = 0; row < 9; row++)
        {
            temp[row] = sudoku[row][col];
        }
        if (check_duplicates(temp) == 1)
            return 1;
    }
    return 0;
}

//Solves the sudoku
void solve_sudoku(int sudoku[9][9], int depth)
{
    if (is_valid(sudoku) == 1)
        return;
    else
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (sudoku[row][col] == 0)
                {
                    for (int value = 9; value > 0; value--)
                    {
                        if (check_col(sudoku, col, value) == 0)
                        {
                            if (check_row(sudoku, row, value) == 0)
                            {
                                if (check_square(sudoku, row, col, value) == 0)
                                {
                                    sudoku[row][col] = value;
                                    solve_sudoku(sudoku, depth);
                                    if (not_solved(sudoku) == 1)
                                    {
                                        sudoku[row][col] = 0;
                                    }
                                }
                            }
                        }
                    }
                    return;
                }
            }
        }
    }
}