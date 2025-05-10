#include <iostream>

using namespace std;

int chessBoard[9][9];
bool constQueen[9] = {false};

bool isAvailable(int m, int n)
{
    for (int i = 0; i < 8; i++)
    {
        if (i != m && chessBoard[n][i])
            return false;
        if (i != n && chessBoard[i][m])
            return false;
    }
    for (int i = 1; n - i >= 0 && m - i >= 0; i++)
        if (chessBoard[n - i][m - i])
            return false;
    for (int i = 1; n + i < 8 && m - i >= 0; i++)
        if (chessBoard[n + i][m - i])
            return false;
    for (int i = 1; n - i >= 0 && m + i < 8; i++)
        if (chessBoard[n - i][m + i])
            return false;
    for (int i = 1; n + i < 8 && m + i < 8; i++)
        if (chessBoard[n + i][m + i])
            return false;
    return true;
}

int DFS(int n)
{
    if (n == 8)
        return 1;
    if (constQueen[n])
        return DFS(n + 1);
    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        if (isAvailable(i, n))
        {
            chessBoard[n][i] = 1;
            result += DFS(n + 1);
            chessBoard[n][i] = 0;
        }
    }
    return result;
}

int main()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            cin >> chessBoard[i][j];
            if (chessBoard[i][j])
                constQueen[i] = true;
        }
    cout << DFS(0);
    return 0;
}