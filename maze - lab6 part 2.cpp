#include <iostream>
#include <math.h> // This library lets us access random numbers
#include <ctime>  // This library lets us access the computer's clock
#include <stdlib.h>
using namespace std;

string rooms[10][10];
int dragonx, dragony, keyx, keyy, exitx, exity, swordx, swordy, dragon_movement;
int playerx, playery;
int key = 0;
int sword = 0;
int play = 1;
bool dragDead = false;
string direction;
int main()
{
    cout << "Welcome to the trapped room game. You will be presented with a room and an exit and you need to find a key in order to unlock the exit all while avoiding traps.\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    srand(time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            rooms[i][j] = "[] ";
        }
        cout << endl;
    }
    dragonx = rand() % 10;
    dragony = rand() % 10;
    exitx = rand() % 10;
    exity = rand() % 10;
    swordx = rand() % 10;
    swordy = rand() % 10;
    keyx = rand() % 10;
    keyy = rand() % 10;

    rooms[dragonx][dragony] = " D ";
    rooms[0][0] = " P ";
    rooms[exitx][exity] = " E ";
    rooms[swordx][swordy] = " S ";
    rooms[keyx][keyy] = " * ";

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << rooms[i][j];
        }
        cout << endl;
    }
    rooms[0][0] = " P ";
    playerx = 0;
    playery = 0;

    do
    {
        cout << "Which way would you like to move? (w, a, s, d): \n";
        cin >> direction;
        if ((direction == "a") || (direction == "A"))
        {
            if (playery == 0)
            {
                cout << "Invalid movement please pick another direction.\n";
            }
            else if (rooms[playerx][playery] == " O ")
            {
                cout << "You can't step on the same position twice. You lose.\n";
                break;
            }
            else
            {
                rooms[playerx][playery] = " O ";
                playery = playery - 1;
                if (rooms[playerx][playery] == " O ")
                {
                    cout << "You can't step on the same position twice. You lose.\n";
                    break;
                }
                else
                {
                    rooms[playerx][playery] = " P ";
                }
                if ((playerx == keyx) && (playery == keyy))
                {
                    cout << "You have acquired the key to the exit!\n";
                    key = 1;
                }
                else if ((playerx == swordx) && (playery == swordy))
                {
                    cout << "You have found the sword!\n";
                    sword = 1;
                }
                else if ((playerx == dragonx) && (playery == dragony))
                {
                    if (sword == 1)
                    {
                        cout << "You have killed the dragon!\n";
                        dragDead == true;
                    }
                    else if (sword == 0)
                    {
                        cout << "The dragon has killed you. You lose.\n";
                        break;
                    }
                }
                else if ((playerx == exitx) && (playery == exity))
                {
                    if (key == 1)
                    {
                        cout << "Congratulations for making it out of the room.\n";
                        break;
                    }
                    else if (key == 0)
                    {
                        cout << "You have not found the key yet!\n";
                    }
                }
            }
        }
        if ((direction == "w") || (direction == "W"))
        {
            if (playerx == 0)
            {
                cout << "Invalid movement please pick another direction.\n";
            }
            else
            {
                rooms[playerx][playery] = " O ";
                playerx = playerx - 1;
                if (rooms[playerx][playery] == " O ")
                {
                    cout << "You can't step on the same position twice. You lose.\n";
                    break;
                }
                else
                {
                    rooms[playerx][playery] = " P ";
                }
                if ((playerx == keyx) && (playery == keyy))
                {
                    cout << "You have acquired the key to the exit!\n";
                    key = 1;
                }
                else if ((playerx == swordx) && (playery == swordy))
                {
                    cout << "You have found the sword!\n";
                    sword = 1;
                }
                else if ((playerx == dragonx) && (playery == dragony))
                {
                    if (sword == 1)
                    {
                        cout << "You have killed the dragon!\n";
                        dragDead == true;
                    }
                    else if (sword == 0)
                    {
                        cout << "The dragon has killed you. You lose.\n";
                        break;
                    }
                }
                else if ((playerx == exitx) && (playery == exity))
                {
                    if (key == 1)
                    {
                        cout << "Congratulations for making it out of the room.\n";
                        break;
                    }
                    else if (key == 0)
                    {
                        cout << "You have not found the key yet!\n";
                    }
                }
            }
        }
        if ((direction == "d") || (direction == "D"))
        {
            if (playery == 9)
            {
                cout << "Invalid movement please pick another direction.\n";
            }
            else
            {
                rooms[playerx][playery] = " O ";
                playery = playery + 1;
                if (rooms[playerx][playery] == " O ")
                {
                    cout << "You can't step on the same position twice. You lose.\n";
                    break;
                }
                else
                {
                    rooms[playerx][playery] = " P ";
                }
                if ((playerx == keyx) && (playery == keyy))
                {
                    cout << "You have acquired the key to the exit!\n";
                    key = 1;
                }
                else if ((playerx == swordx) && (playery == swordy))
                {
                    cout << "You have found the sword!\n";
                    sword = 1;
                }
                else if ((playerx == dragonx) && (playery == dragony))
                {
                    if (sword == 1)
                    {
                        cout << "You have killed the dragon!\n";
                        dragDead == true;
                    }
                    else if (sword == 0)
                    {
                        cout << "The dragon has killed you. You lose.\n";
                        break;
                    }
                }
                else if ((playerx == exitx) && (playery == exity))
                {
                    if (key == 1)
                    {
                        cout << "Congratulations for making it out of the room.\n";
                        break;
                    }
                    else if (key == 0)
                    {
                        cout << "You have not found the key yet!\n";
                    }
                }
            }
        }
        if ((direction == "s") || (direction == "S"))
        {
            if (playerx == 9)
            {
                cout << "Invalid movement please pick another direction.\n";
            }
            else
            {
                rooms[playerx][playery] = " O ";
                playerx = playerx + 1;
                if (rooms[playerx][playery] == " O ")
                {
                    cout << "You can't step on the same position twice. You lose.\n";
                    break;
                }
                else
                {
                    rooms[playerx][playery] = " P ";
                }
                if ((playerx == keyx) && (playery == keyy))
                {
                    cout << "You have acquired the key to the exit!\n";
                    key = 1;
                }
                else if ((playerx == swordx) && (playery == swordy))
                {
                    cout << "You have found the sword!\n";
                    sword = 1;
                }
                else if ((playerx == dragonx) && (playery == dragony))
                {
                    if (sword == 1)
                    {
                        cout << "You have killed the dragon!\n";
                        dragDead == true;
                    }
                    else if (sword == 0)
                    {
                        cout << "The dragon has killed you. You lose.\n";
                        break;
                    }
                }
                else if ((playerx == exitx) && (playery == exity))
                {
                    if (key == 1)
                    {
                        cout << "Congratulations for making it out of the room.\n";
                        break;
                    }
                    else if (key == 0)
                    {
                        cout << "You have not found the key yet! You lose.\n";
                        break;
                    }
                }
            }
        }
        rooms[exitx][exity] = " E ";
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                cout << rooms[i][j];
            }
            cout << endl;
        }
    } while (play == 1);
    cout << "Thanks for playing!\n";
}
