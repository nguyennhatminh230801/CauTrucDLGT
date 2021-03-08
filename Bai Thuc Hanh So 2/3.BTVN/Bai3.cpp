#include <bits/stdc++.h>
using namespace std;

int board[8][8];

bool isSafe(int row, int col)
{
    for(int i = 0 ; i < col ; i++)
    {
        if(board[row][i] == 1)
        {
            return false;
        }
    }

    for(int i = row, j = col; i >= 0 && j >= 0 ; i--, j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    for(int i = row, j = col; j >= 0 && i < 8 ; i++, j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

bool Backtrack(int column)
{
    if(column >= 8)
    {
        return true;
    }

    for(int row = 0 ; row < 8 ; row++)
    {
        if(isSafe(row, column) == true)
        {
            board[row][column] = 1;

            if(Backtrack(column + 1) == true)
            {
                return true;
            }
            else{
                board[row][column] = 0;
            }
        }
    }
    return false;
}

int main()
{
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            board[i][j] = 0;
        }
    }
    
    bool check = Backtrack(0);
    
    if(check == true)
    {
        cout << "KET QUA LA: " << endl;
        
        for(int i = 0 ; i < 8 ; i++)
        {
            for(int j = 0 ; j < 8 ; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "Khong co ket qua" << endl;
    }
}