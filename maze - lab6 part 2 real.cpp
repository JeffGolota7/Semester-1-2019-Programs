#include <iostream>
#include <math.h> // This library lets us access random numbers
#include <ctime>  // This library lets us access the computer's clock
#include <stdlib.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int room_exit = rand() % 10;
    int key = rand() % 10;
    while (room_exit == key)
    {
        room_exit = rand() % 10;
        key = rand() % 10;
    }
    int player_room;
    int play = 1;
    int key_possession = 0;
    string direction;
    string rooms[10];
    int count = 0;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        rooms[i] = " O ";
    }
    rooms[room_exit] = " E ";
    rooms[key] = " * ";

    do
    {
        cout << "Which room would you like to start in? (0-9): \n";
        cin >> player_room;
        player_room = player_room - 1;

        while (player_room == room_exit)
        {
            rooms[room_exit] = " O ";
            room_exit = rand() % 10;
            rooms[room_exit] = " E ";
            rooms[player_room] = " P ";
        }
        if (player_room == key)
        {
            rooms[key] = " O ";
            key = rand() % 10;
            rooms[key] = " * ";
            rooms[player_room] = " P ";
        }
        else
        {
            rooms[player_room] = " P ";
        }
    } while (player_room > 9);

    for (int i = 0; i < 10; ++i)
    {
        cout << rooms[i];
    }
    cout << endl;
    do
    {
        cout << "Which direction would you like to move? (Left(L) or Right(R)): \n";
        cin >> direction;

        if ((direction == "l") || (direction == "L"))
        {
            if (player_room == 0)
            {
                cout << "Invalid movement please choose another movement. \n";
            }
            else if (player_room != 0)
            {
                rooms[player_room] = " O ";
                player_room = player_room - 1;
                rooms[player_room] = " P ";
                if (player_room == key)
                {
                    if (key_possession == 0)
                    {
                        cout << "You have acquired the key!\n";
                        key_possession = 1;
                    }
                }
                else if ((key_possession == 1) && (player_room == room_exit))
                {
                    break;
                }
                else if ((key_possession == 0) && (player_room == room_exit))
                {
                    cout << "You have to find the key first.\n";
                }
            }
            ++count;
        }
        else if ((direction == "r") || (direction == "R"))
        {
            if (player_room == 9)
            {
                cout << "Invalid movement please choose another movement. \n";
            }
            else if (player_room != 9)
            {

                rooms[player_room] = " O ";
                player_room = player_room + 1;
                rooms[player_room] = " P ";
                if (player_room == key)
                {
                    cout << "You have acquired the key!\n";
                    key_possession = 1;
                }
                else if ((key_possession == 1) && (player_room == room_exit))
                {
                    break;
                }
                else if ((key_possession == 0) && (player_room == room_exit))
                {
                    cout << "You have to find the key first.\n";
                }
            }
            count++;
        }
        if (player_room == room_exit) {
            rooms[room_exit] = " P ";
        }
        else {
            rooms[room_exit] = " E ";
        }
        for (int i = 0; i < 10; ++i)
        {
            cout << rooms[i];
        }
        cout << endl;
    } while (play = 1);
    if (count <= 5)
    {
        cout << "Congratulations you found the exit in " << count << " moves! You win.\n";
    }
    else if (count > 5)
    {
        cout << "Sorry it took you " << count << " moves to find the exit. You lose.\n";
    }
}