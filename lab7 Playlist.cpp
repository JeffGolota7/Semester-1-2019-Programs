#include <iostream>
#include <math.h> // This library lets us access random numbers
#include <ctime>  // This library lets us access the computer's clock
#include <stdlib.h>
using namespace std;

struct Song
{
    int length;
    bool empty;
    string songName;
    bool shuffle = false;
};
int main()
{
    int size = 0;
    int action, add, compare, numremove;
    int totalLength = 0;
    int minutes = 0;
    int seconds = 0;
    int count = 0;
    int num = 1;
    srand(time(NULL));
    string remove;
    Song playlist[10];

    for (int i = 0; i < 10; ++i)
    {
        playlist[i].empty = true;
    }

    do
    {
        cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
        cout << "(1) Play the playlist\n";
        cout << "(2) Print summary\n";
        cout << "(3) Add to playlist\n";
        cout << "(4) Delete from playlist\n";
        cout << "(5) Quit\n";
        cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
        cout << "What would you like to do with your playlist?\n";
        cin >> action;

        if (action == 1)
        {
            if (size == 0)
            {
                cout << "You do not have any songs in the playlist. Add some with option 3.\n";
            }
            else
            {
                for (int i = 0; i < 10; ++i)
                {
                    if (playlist[i].empty == false)
                    {
                        cout << playlist[i].songName << endl;
                    }
                }
            }
        }
        else if (action == 2)
        {
            if (size == 0)
            {
                cout << "There are currently 0 songs in the playlist. Add some with option 3.\n";
            }
            else
            {
                totalLength = 0;
                for (int i = 0; i < 10; ++i)
                {
                    if (playlist[i].empty == false)
                    {
                        totalLength = totalLength + playlist[i].length;
                    }
                }
                minutes = totalLength / 60;
                seconds = totalLength % 60;
                cout << "There are " << size << " songs in the playlist.\n";
                cout << "Total run time: " << minutes << " Minutes " << seconds << " Seconds" << endl;
            }
        }
        else if (action == 3)
        {
            if (size == 10)
            {
                cout << "You have the maximum number of songs allowed. You cannot add any more.\n"; // Won't let you add more than the 10 songs allowed
            }
            else
            {
                do
                {

                    cout << "How many songs would you like to add?:\n"; // Asks you how many songs you want to add
                    cin >> add;
                } while ((add + size) > 10);
                for (int i = 0; i < add; ++i)
                {
                    cout << "Song name: ";
                    cin >> playlist[i].songName;
                    cout << endl;
                    cout << "Length (write minutes then seconds separated by space): ";
                    cin >> minutes >> seconds;
                    playlist[i].length = (minutes * 60) + seconds;
                    cout << endl;
                    playlist[i].empty = false;
                    playlist[i].shuffle = false;
                }
                size = size + add;
            }
        }

        else if (action == 4)
        {
            if (size == 0)
            {
                cout << "Your playlist is empty. Can't delete any songs.\n"; // Doesn't let you remove a song if the playlist is empty
            }
            else
            {
                cout << "How many songs do you want to remove?: "; // Asks the number of songs you would like to remove
                cin >> numremove;

                for (int j = 0; j < numremove; ++j) // Launches a for loop for the amount of songs you want to remove
                {
                    cout << "Which song do you want to remove?: "; // Asks you which song you want to remove
                    cin >> remove;
                    cout << endl;
                    for (int i = 0; i < 10; ++i)
                    {
                        if (playlist[i].songName == remove) // Compares the current song name in the array with the one you wanted to remove
                        {
                            playlist[i].empty = true; // If the song is found then the boolean is set to true and the size is decreased
                            size = size - 1;
                            break;
                        }
                    }
                }
            }
        }
    } while (action != 5);

    return 0;
}
