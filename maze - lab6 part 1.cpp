#include <iostream>
#include <math.h> // This library lets us access random numbers
#include <ctime>  // This library lets us access the computer's clock
#include <stdlib.h>
using namespace std;

int room_exit = rand() % 10;
int player_room;
string direction;
char rooms[10];
int count;
int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        rooms[i] = 'O';
        cout << rooms[i];
    }
    rooms[room_exit] = 'E';

    cout << "Which room would you like to start in? (0-9): \n";
    cin >> player_room;

    if (player_room == room_exit)
    {
        room_exit = rand() % 10;
        rooms[room_exit] = 'E';
        rooms[player_room] = 'P';
    }
    else
    {
        rooms[player_room] = 'P';
    }

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
                rooms[player_room] = 'O';  
                player_room = player_room - 1;
                rooms[player_room] = 'P';
                for (int i = 0; i < 10; ++i)
                {
                    cout << rooms[i];
                }
                cout << endl;
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
                rooms[player_room] = 'O';  
                player_room = player_room - 1;
                rooms[player_room] = 'P';
                for (int i = 0; i < 10; ++i)
                {
                    cout << rooms[i];
                }
            }
            ++count;
            
        }
    } while (player_room != room_exit);
    cout << "Congratulations you found the exit in " << count << " moves!";
}