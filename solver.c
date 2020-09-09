/*
 * CSC A48 - Exercise 11 - Sudoku Solver
 * 
 * Your goal in this exercise is to practice recursion and
 * to see how a properly written recursive solution can
 * take care of fairly complicated tasks with a few lines
 * of (well thought out) code.
 * 
 * We will be solving Sudoku puzzles. In case you have never
 * solved or seen a Sudoku, you can learn more about them
 * here:
 * 
 * https://en.wikipedia.org/wiki/Sudoku
 * 
 * Your task if to write a function that takes an input
 * Sudoku in the form of a 9x9 array of integers. the
 * array will have a few entries filled with numbers in
 * [1, 9], and the remaining entries set to zero.
 * 
 * For the example in the wiki, the input array will
 * be
 * 
 * 5 3 0 0 7 0 0 0 0
 * 6 0 0 1 9 5 0 0 0
 * 0 9 8 0 0 0 0 6 0
 * 8 0 0 0 6 0 0 0 3
 * 4 0 0 8 0 3 0 0 1
 * 7 0 0 0 2 0 0 0 6
 * 0 6 0 0 0 0 2 8 0 
 * 0 0 0 4 1 9 0 0 5
 * 0 0 0 0 8 0 0 7 9
 * 
 * Your code should find the values that correctly
 * complete the Sudoku. 
 * 
 * As a brief reminder, a correctly solved Sudoku is
 * one in which there are no repeated digits in any
 * row, any column, or any of the 3x3 sub-arrays that
 * make up the large 9x9 grid. Another way to think
 * about it is, every row, column, and 3x3 subgrid
 * uses all of the different digits.
 * 
 * How to solve this?
 * 
 * * RECURSIVELY!
 * 
 * (hint) - Solving a Sudoku with N unknown values
 * may involve trying something, then solving an
 * easier Sudoku problem.
 * 
 * * How to approach this?
 * 
 * - As noted in class:
 * 	a) Determine the base case(s)
 * 	b) Figure out the recursive case
 * 	c) Determine what needs to happen to
 * 	   the solution for the entire problem
 * 	   is returned once the recursion hits
 * 	   the base case(s)
 * 
 * - Conditions on the input Sudoku
 * 	- It will have AT LEAST ONE DIGIT in each
 * 	  3x3 subgrid. Likely there will be several
 * 	  3x3 subgrids with several digits already
 * 	  set to some value.
 * 
 * - Conditions on your solution
 * 	- It should return a solution if there
 * 	  exists one.
 * 	- If no solution can be found, return the
 * 	  original input array
 * 	- If multiple solutions exist, any one of
 *        them is valid
 * 
 * - Can I use helper functions?
 * 	- Yes, by all means!
 * 
 * - Can I add extra libraries?
 * 	- No, they won't be needed.
 * 
 * - Can I change the 'print_sudoku()' function?
 * 	- Please don't, we may need it for testing!
 * 
 * (c) F. Estrada, March 2019
 */

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

/*int check_sudoku(int sudoku[9][9])
{
    /*
   *  This function checks whether a Sudoku is properly
   * solved. That means that each row, column, and
   * 3x3 subgrid uses each digit only once.
   * 
   *  If *ignores* zeros, so you can use it to check
   * that a partial solution is valid
   */

/*****
   * TO DO:
   * Complete this function
   *   -- BUT ONLY IF YOU WANT TO!
   * Our testing script only checks your Sudoku
   * solution, if you want to solve it without
   * using this function, or if you want to write
   * your own helper functions, that's ok!
   * *****/
/*return 0;
}
*/

int solved(int sudoku[9][9])
{
    /*
   * This function checks whether a given Sudoku is
   * completely solved (it has no zeros, all digits
   * are used once per row, column, and sub-grid.
   * It returns 1 if the Sudoku is solved, zero
   * otherwise
   */

    /*****
   * TO DO
   * Complete this function
   * BUT ONLY IF YOU WANT TO!
   *   You can solve the Sudoku without using this function,
   * or you can write a different helper function, whatever
   * makes more sense to yoU! our checker won't look at this
   * function, 
   * ****/

    return 0;
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

void hello()
{
    printf("Hello\n");
}

#ifndef __testing

int main()
{
    // We'll provide you with the same test case
    // from the Wiki, so you can check your output.
    // But as always, be aware we will test your
    // solution on different Sudoku puzzles.

    // int Sudoku[9][9]={{5, 3, 0, 0, 7, 0, 0, 0, 0},
    // 	     {6, 0, 0, 1, 9, 5, 0, 0, 0},
    // 	     {0, 9, 8, 0, 0, 0, 0, 6, 0},
    // 	     {8, 0, 0, 0, 6, 0, 0, 0, 3},
    // 	     {4, 0, 0, 8, 0, 3, 0, 0, 1},
    // 	     {7, 0, 0, 0, 2, 0, 0, 0, 6},
    // 	     {0, 6, 0, 0, 0, 0, 2, 8, 0},
    // 	     {0, 0, 0, 4, 1, 9, 0, 0, 5},
    // 	     {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    int Sudoku[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 3, 0, 8, 5},
                        {0, 0, 1, 0, 2, 0, 0, 0, 0},
                        {0, 0, 0, 5, 0, 7, 0, 0, 0},
                        {0, 0, 4, 0, 0, 0, 1, 0, 0},
                        {0, 9, 0, 0, 0, 0, 0, 0, 0},
                        {5, 0, 0, 0, 0, 0, 0, 7, 3},
                        {0, 0, 2, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 4, 0, 0, 0, 9}};

    /*int Sudoku[9][9]={{1, 2, 3, 4, 5, 6, 7, 8, 0},
		     {0, 0, 0, 0, 0, 0, 0, 0, 2},
		     {0, 0, 0, 0, 0, 0, 0, 0, 3},
		     {0, 0, 0, 0, 0, 0, 0, 0, 4},
		     {0, 0, 0, 0, 0, 0, 0, 0, 5},
		     {0, 0, 0, 0, 0, 0, 0, 0, 6},
		     {0, 0, 0, 0, 0, 0, 0, 0, 7},
		     {0, 0, 0, 0, 0, 0, 0, 0, 8},
		     {0, 0, 0, 0, 0, 0, 0, 0, 9}};
  
*/
    printf("Input puzzle is:\n");
    print_sudoku(Sudoku);

    solve_sudoku(Sudoku, 0);

    printf("Solution is:\n");
    print_sudoku(Sudoku);
}

#endif