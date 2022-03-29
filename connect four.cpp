#include <iostream>
using namespace std;

struct slot
{
    bool occupied;
    string value;
};

void drop(slot grid[6][8], int player, int column)
{
    
    int count = 0;
    if ((column >= 1) && (column <= 7))
    {
        if (grid[0][column].occupied == false)
        {
            if (player == 1)
            {
                for (int i = 1; i < 7; ++i)
                {
                    if (grid[i][column].occupied == true)
                    {
                        grid[i - 1][column].value = "|X|";
                        grid[i - 1][column].occupied = true;
                        break;
                    }
                    else if ((i == 5) && (grid[5][column].occupied == false))
                    {
                        grid[i][column].value = "|X|";
                        grid[i][column].occupied = true;
                    }
                }
            }
            else if (player == 2)
            {
                for (int i = 1; i < 7; ++i)
                {
                    if (grid[i][column].occupied == true)
                    {
                        grid[i - 1][column].value = "|O|";
                        grid[i - 1][column].occupied = true;
                        break;
                    }
                    else if ((i == 5) && (grid[5][column].occupied == false))
                    {
                        grid[i][column].value = "|O|";
                        grid[i][column].occupied = true;
                    }
                }
            }
        }
    }
}
void clear(slot grid[6][8])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j < 8; j++)
        {
            grid[i][j].value = "| |";
            grid[i][j].occupied = false;
        }
    }
}

void print(slot grid[6][8])
{
    cout << "Here's what the game looks like now:\n";
    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j < 8; j++)
        {
            cout << grid[i][j].value << " ";
        }
        cout << endl;
    }
}

int checkWinner(slot grid[6][8])
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 1; j < 8; ++j)
        {
            if(grid[i][j].value == "|X|") {
                if ((grid[i][j].value == grid[i][j + 1].value) && (grid[i][j+1].value == grid[i][j + 2].value) && (grid[i][j+2].value == grid[i][j + 3].value)) {
                    return 1;
                }
                else if ((grid[i][j].value == grid[i+1][j].value) && (grid[i+1][j].value == grid[i+2][j].value) && (grid[i+2][j].value == grid[i+3][j].value)) {
                    return 1;
                }
            }
            else if(grid[i][j].value == "|O|") {
                if ((grid[i][j].value == grid[i][j + 1].value) && (grid[i][j+1].value == grid[i][j + 2].value) && (grid[i][j+2].value == grid[i][j + 3].value)) {
                    return 2;
                }
                else if ((grid[i][j].value == grid[i+1][j].value) && (grid[i+1][j].value == grid[i+2][j].value) && (grid[i+2][j].value == grid[i+3][j].value)) {
                    return 2;
                }
            }
            
        }
    }
}

int checkWinDiag(slot grid[6][8])
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 1; j < 8; ++j)
        {
            if (grid[i][j].value == "|X|")
            {
                if ((grid[i][j].value == grid[i + 1][j + 1].value) && (grid[i + 1][j + 1].value == grid[i + 2][j + 2].value) && (grid[i + 2][j + 2].value == grid[i + 3][j + 3].value))
                {
                    return 1;
                }
                else if ((grid[i][j].value == grid[i - 1][j - 1].value) && (grid[i - 1][j - 1].value == grid[i - 2][j - 2].value) && (grid[i - 2][j - 2].value == grid[i - 3][j - 3].value))
                {
                    return 1;
                }
                else if ((grid[i][j].value == grid[i - 1][j + 1].value) && (grid[i - 1][j + 1].value == grid[i - 2][j + 2].value) && (grid[i - 2][j + 2].value == grid[i - 3][j + 3].value))
                {
                    return 1;
                }
                else if ((grid[i][j].value == grid[i + 1][j - 1].value) && (grid[i + 1][j - 1].value == grid[i + 2][j - 2].value) && (grid[i + 2][j - 2].value == grid[i + 3][j - 3].value))
                {
                    return 1;
                }
                else if ((grid[i][j].value == grid[i+1][j-1].value) && (grid[i][j].value == grid[i-1][j+1].value) && (grid[i-1][j+1].value == grid[i-2][j+2].value)) {
                    return 1;
                }
                else if ((grid[i][j].value == grid[i+1][j+1].value) && (grid[i][j].value == grid[i-1][j-1].value) && (grid[i-1][j-1].value == grid[i-2][j-2].value)) {
                    return 1;
                }
                else if ((grid[i][j].value == grid[i-1][j-1].value) && (grid[i][j].value == grid[i+1][j+1].value) && (grid[i+1][j+1].value == grid[i+2][j+2].value)) {
                    return 1;
                }
                else if ((grid[i][j].value == grid[i-1][j+1].value) && (grid[i][j].value == grid[i+1][j-1].value) && (grid[i+1][j-1].value == grid[i+2][j-2].value)) {
                    return 1;
                }
            }
            else if (grid[i][j].value == "|O|")
            {
                if ((grid[i][j].value == grid[i + 1][j + 1].value) && (grid[i + 1][j + 1].value == grid[i + 2][j + 2].value) && (grid[i + 2][j + 2].value == grid[i + 3][j + 3].value))
                {
                    return 2;
                }
                else if ((grid[i][j].value == grid[i - 1][j - 1].value) && (grid[i - 1][j - 1].value == grid[i - 2][j - 2].value) && (grid[i - 2][j - 2].value == grid[i - 3][j - 3].value))
                {
                    return 2;
                }
                else if ((grid[i][j].value == grid[i - 1][j + 1].value) && (grid[i - 1][j + 1].value == grid[i - 2][j + 2].value) && (grid[i - 2][j + 2].value == grid[i - 3][j + 3].value))
                {
                    return 2;
                }
                else if ((grid[i][j].value == grid[i + 1][j - 1].value) && (grid[i + 1][j - 1].value == grid[i + 2][j - 2].value) && (grid[i + 2][j - 2].value == grid[i + 3][j - 3].value))
                {
                    return 2;
                }
                else if ((grid[i][j].value == grid[i+1][j-1].value) && (grid[i][j].value == grid[i-1][j+1].value) && (grid[i-1][j+1].value == grid[i-2][j+2].value)) {
                    return 2;
                }
                else if ((grid[i][j].value == grid[i+1][j+1].value) && (grid[i][j].value == grid[i-1][j-1].value) && (grid[i-1][j-1].value == grid[i-2][j-2].value)) {
                    return 2;
                }
                else if ((grid[i][j].value == grid[i-1][j-1].value) && (grid[i][j].value == grid[i+1][j+1].value) && (grid[i+1][j+1].value == grid[i+2][j+2].value)) {
                    return 2;
                }
                else if ((grid[i][j].value == grid[i-1][j+1].value) && (grid[i][j].value == grid[i+1][j-1].value) && (grid[i+1][j-1].value == grid[i+2][j-2].value)) {
                    return 2;
                }
            }
        }
    }
}

int main()
{
    slot grid[6][8];
    int column;
    bool win = false;
    int player = 1;
    clear(grid);
    print(grid);

    for (int i = 0; i < 7; ++i) {
        grid[i][0].occupied = true;
    }

    do
    {
        cout << "Welcome to Connect Four. Player 1 please choose a column that you would like to place your chip into: ";
        cin >> column;
        drop(grid, player, column);
        print(grid);
    } while (((column > 7) || (column < 1)) || (grid[0][column].occupied == true));

    do
    {
        ++player;
        do
        {
            cout << "Next player please choose which column you want to drop your chip into: ";
            cin >> column;
        } while (((column > 7) || (column < 1)) || (grid[0][column].occupied == true));

        drop(grid, player, column);
        print(grid);
        checkWinner(grid);

        if ((checkWinner(grid) == 1) || (checkWinDiag(grid) == 1))
        {
            cout << "Game over. Congratulations Player 1 for winning.\n";
            break;
        }
        else if ((checkWinner(grid) == 2) || (checkWinDiag(grid) == 2))
        {
            cout << "Game over. Congratulations Player 2 for winning.\n";
            break;
        }

        --player;
        do
        {
            cout << "Next player please choose which column you want to drop your chip into: ";
            cin >> column;
        } while (((column > 7) || (column < 1)) || (grid[0][column].occupied == true));

        drop(grid, player, column);
        print(grid);
        checkWinner(grid);

        if ((checkWinner(grid) == 1) || (checkWinDiag(grid) == 1))
        {
            cout << "Game over. Congratulations Player 1 for winning.\n";
            break;
        }
        else if ((checkWinner(grid) == 2) || (checkWinDiag(grid) == 2))
        {
            cout << "Game over. Congratulations Player 2 for winning.\n";
            break;
        }

    } while (win == false);
    return 0;
}