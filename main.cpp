#include <bits/stdc++.h>

using namespace std;

char s[3][3];
string player1, player2;

void resetB()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            s[i][j] = ' ';
        }
    }
    cout << endl;
}

void printBoard()
{
    cout << "\t " << s[0][0] << " | " << s[0][1] << " | " << s[0][2] << " " << endl;
    cout << "\t---|---|---" << endl;
    cout << "\t " << s[1][0] << " | " << s[1][1] << " | " << s[1][2] << " " << endl;
    cout << "\t---|---|---" << endl;
    cout << "\t " << s[2][0] << " | " << s[2][1] << " | " << s[2][2] << " " << endl;
}

int checkspaces()
{
    int space = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (s[i][j] != ' ')
                space--;
        }
    }
    return space;
}

void player1move()
{
    int x, y;
    cout << "Enter the row no. " << player1 << " : ";
    cin >> x;
    cout << "Enter the column no. " << player1 << " : ";
    cin >> y;
    if (s[x - 1][y - 1] != ' ' || (x > 3 && y > 3))
    {
        cout << "Invalid move" << endl;
        player1move();
    }
    else
    {
        s[x - 1][y - 1] = 'X';
    }
}

void player2move()
{
    int x, y;
    cout << "Enter the row no. " << player2 << " : ";
    cin >> x;
    cout << "Enter the column no. " << player2 << " : ";
    cin >> y;
    if (s[x - 1][y - 1] != ' ' || (x > 3 && y > 3))
    {
        cout << "Invalid move" << endl;
        player2move();
    }
    else
    {
        s[x - 1][y - 1] = 'O';
    }
}

char checkwinner()
{
    // rows
    for (int i = 0; i < 3; i++)
    {
        if (s[i][0] == s[i][1] && s[i][0] == s[i][2])
            return s[i][0];
    }
    // columns
    for (int i = 0; i < 3; i++)
    {
        if (s[0][i] == s[1][i] && s[0][i] == s[2][i])
            return s[0][i];
    }
    // diagonals
    if (s[0][0] == s[1][1] && s[1][1] == s[2][2])
    {
        return s[0][0];
    }
    if (s[0][2] == s[1][1] && s[1][1] == s[2][0])
    {
        return s[0][2];
    }
    return ' ';
}

int main()
{
    int c = 0;
    cout << "TIC TAC TOE" << endl;
    char win = ' ';
    cout << "Enter the name of First player  : ";
    cin >> player1;
    cout << "Enter the name of Second player : ";
    cin >> player2;
    cout << player1 << " is the first player so he/she will play first \n";
    resetB();
    while (win == ' ' && checkspaces() != 0)
    {
        printBoard();
        if (c % 2 == 0)
            player1move();
        else
            player2move();
        c++;
        win = checkwinner();

        if (win != ' ' || checkspaces() == 0)
        {
            break;
        }
    }

    if (win == 'X')
    {
        cout << endl
             << player1 << " wins" << endl;
        printBoard();
    }
    else if (win == 'O')
    {
        cout << endl
             << player2 << " wins" << endl;
        printBoard();
    }
    else
    {
        cout << endl
             << "Draw" << endl;
        printBoard();
    }
    cout << endl
         << "Thanks for playing." << endl;
}
