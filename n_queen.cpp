#include <bits/stdc++.h>
#define max 100
using namespace std;
void printSol(int board[], int n, int &count)
{
    count++;
    cout << "Solution " << count << ":\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i] == j)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(int board[], int row, int col)
{
    for (int i = 1; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}
void solveNqueen(int board[], int row, int n, int &count)

{
    for (int col = 1; col <= n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;

            if (row == n)
            {
                printSol(board, n, count);
            }
            else
            {
                solveNqueen(board, row + 1, n, count);
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter the size of board:";

    cin >> n;

    int board[max], count = 0;
    solveNqueen(board, 1, n, count);
    return 0;
}