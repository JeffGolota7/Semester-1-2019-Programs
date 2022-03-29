#include <iostream>
#include <math.h> // This library lets us access random numbers
#include <ctime>  // This library lets us access the computer's clock
#include <stdlib.h>
using namespace std;
/* This program will draw a random card from a deck and tell you what suit and type of card it is.
Author: Jeff Golota */
int randcard, randtype;
char play = 'y';

int main()
{
    string suit[4] {"Diamonds", "Spades", "Hearts", "Clubs"};
    string cardtype[13] {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
    srand(time(NULL)); // This sets up the random number chosen.
    do
    {
        randtype = rand() % 4;
        randcard = rand() % 14;

        cout << "The card that has been drawn is a " << cardtype[randcard] << " of " << suit[randtype] << endl;
        
        //This asks the user if they would like to keep going.
        cout << "Would you like another card? (y/n)\n";
        cin >> play;
    } while ((play == 'y') || (play == 'Y'));
}