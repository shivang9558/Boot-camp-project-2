#include<iostream>
using namespace std;

void inputSudoku(short sudoku[9][9])
{
    char ch;
    do
    {
        short grid,row,col;
        short value;
        cout << "enter the grid number, respective row & column : ";
        cin >> grid >> row >> col;

        cout << "Enter the value : ";
        cin >> value;

        sudoku[ ((grid-1)/3)*3 + row-1][ ((grid-1)%3)*3 + col-1 ] = value;

        cout << "Do you want to enter more numbers Y/N : ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}

void printSudoku(short sudoku[9][9])
{
    for(short i=0;i<9;i++)
    {
        if (i == 3 || i == 6)
        {
            for(short k=0;k<23;k++)
                cout << "-";
            cout << endl;
        }
        for(short j=0;j<9;j++)
        {
            if (j == 3 || j == 6)
                cout << "| ";
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(short r,short c, short sudoku[9][9], short value)
{
    /** To check is value matches with either same row or column*/
    for(short i = 0; i < 9 ;i++)
        if(sudoku[r][i] == value || sudoku[i][c] == value)
            return false;

    /** To check in the sub matrix*/
    for(short i = 0; i < 3; i++)
    {
        for(short j = 0; j < 3;j++)
            if( sudoku[r/3 * 3 +i][c/3 * 3 + j] == value)
                return false;
    }
    return true;
}

bool solveSudoku(short sudoku[9][9],short i,short j)
{
    if(i == 8 && j == 9)
        return true;

    if(j == 9)
    {
        i++;    j = 0;
    }
    if(sudoku[i][j] != 0)
        return solveSudoku(sudoku,i,j+1);

    for(short value=1 ; value<=9; value++)
    {
        if(isSafe(i,j,sudoku,value))
        {
            sudoku[i][j] = value;

            if (solveSudoku(sudoku,i,j + 1))
                return true;
        }
        sudoku[i][j] = 0;
    }
    return false;
}

int main()
{
    short sudoku[9][9]={ { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
                         { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
                         { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
                         { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
                         { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
                         { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
                         { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
                         { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
                         { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };

    //inputSudoku(sudoku);
    printSudoku(sudoku);

    cout << "\n\nSolved sudoku\n";

    if(solveSudoku(sudoku,0,0))
        printSudoku(sudoku);
    else
        cout << "Not solved";

    cout << "\ndone\n";

    return 0;
}
