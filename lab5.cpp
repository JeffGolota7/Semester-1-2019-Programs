#include <iostream>
#include <math.h> // This library lets us access random numbers
#include <ctime>  // This library lets us access the computer's clock
#include <stdlib.h>
using namespace std;
/* This program will draw a random card from a deck and tell you what suit and type of card it is.
Author: Jeff Golota */
int randcard;
char play;

int main()
{
    srand(time(NULL)); // This sets up the random number chosen.
    do
    {
        randcard = (rand() % 52) + 1; // Picks the random card.
        cout << "This program will pick a random card and tell you what suit and card it is.\n";
        if ((randcard >= 1) && (randcard <= 13)) // Checks if the card is a Club
        {
            //These if and else if statements check what the value of the card is.
            if (randcard == 13)
            {
                cout << "The card that has been dealt is a King of Clubs.\n";
            }
            else if (randcard == 12)
            {
                cout << "The card that has been dealt is a Queen of Clubs.\n";
            }
            else if (randcard == 11)
            {
                cout << "The card that has been dealt is a Jack of Clubs.\n";
            }
            else if (randcard == 10)
            {
                cout << "The card that has been dealt is a 10 of Clubs.\n";
            }
            else if (randcard == 9)
            {
                cout << "The card that has been dealt is a 9 of Clubs.\n";
            }
            else if (randcard == 8)
            {
                cout << "The card that has been dealt is an 8 of Clubs.\n";
            }
            else if (randcard == 7)
            {
                cout << "The card that has been dealt is a 7 of Clubs.\n";
            }
            else if (randcard == 6)
            {
                cout << "The card that has been dealt is a 6 of Clubs.\n";
            }
            else if (randcard == 5)
            {
                cout << "The card that has been dealt is a 5 of Clubs.\n";
            }
            else if (randcard == 4)
            {
                cout << "The card that has been dealt is a 4 of Clubs.\n";
            }
            else if (randcard == 3)
            {
                cout << "The card that has been dealt is a 3 of Clubs.\n";
            }
            else if (randcard == 2)
            {
                cout << "The card that has been dealt is a 2 of Clubs.\n";
            }
            else if (randcard == 1)
            {
                cout << "The card that has been dealt is an ace of Clubs.\n";
            }
        }
        else if ((randcard >= 14) && (randcard <= 26)) //Checks if the card is a diamond.
        {
            //These statements check the calue again but for diamonds.
            if (randcard == 26)
            {
                cout << "The card that has been dealt is a King of Diamonds.\n";
            }
            else if (randcard == 25)
            {
                cout << "The card that has been dealt is a Queen of Diamonds.\n";
            }
            else if (randcard == 24)
            {
                cout << "The card that has been dealt is a Jack of Diamonds.\n";
            }
            else if (randcard == 23)
            {
                cout << "The card that has been dealt is a 10 of Diamonds.\n";
            }
            else if (randcard == 22)
            {
                cout << "The card that has been dealt is a 9 of Diamonds.\n";
            }
            else if (randcard == 21)
            {
                cout << "The card that has been dealt is an 8 of Diamonds.\n";
            }
            else if (randcard == 20)
            {
                cout << "The card that has been dealt is a 7 of Diamonds.\n";
            }
            else if (randcard == 19)
            {
                cout << "The card that has been dealt is a 6 of Diamonds.\n";
            }
            else if (randcard == 18)
            {
                cout << "The card that has been dealt is a 5 of Diamonds.\n";
            }
            else if (randcard == 17)
            {
                cout << "The card that has been dealt is a 4 of Diamonds.\n";
            }
            else if (randcard == 16)
            {
                cout << "The card that has been dealt is a 3 of Diamonds.\n";
            }
            else if (randcard == 15)
            {
                cout << "The card that has been dealt is a 2 of Diamonds.\n";
            }
            else if (randcard == 14)
            {
                cout << "The card that has been dealt is an ace of Diamonds.\n";
            }
        }
        else if ((randcard >= 27) && (randcard <= 39)) // Checks if the card is a heart.
        {
            //Checks the value of the card as a heart.
            if (randcard == 39)
            {
                cout << "The card that has been dealt is a King of Hearts.\n";
            }
            else if (randcard == 38)
            {
                cout << "The card that has been dealt is a Queen of Hearts.\n";
            }
            else if (randcard == 37)
            {
                cout << "The card that has been dealt is a Jack of Hearts.\n";
            }
            else if (randcard == 36)
            {
                cout << "The card that has been dealt is a 10 of Hearts.\n";
            }
            else if (randcard == 35)
            {
                cout << "The card that has been dealt is a 9 of Hearts.\n";
            }
            else if (randcard == 34)
            {
                cout << "The card that has been dealt is an 8 of Hearts.\n";
            }
            else if (randcard == 33)
            {
                cout << "The card that has been dealt is a 7 of Hearts.\n";
            }
            else if (randcard == 32)
            {
                cout << "The card that has been dealt is a 6 of Hearts.\n";
            }
            else if (randcard == 31)
            {
                cout << "The card that has been dealt is a 5 of Hearts.\n";
            }
            else if (randcard == 30)
            {
                cout << "The card that has been dealt is a 4 of Hearts.\n";
            }
            else if (randcard == 29)
            {
                cout << "The card that has been dealt is a 3 of Hearts.\n";
            }
            else if (randcard == 28)
            {
                cout << "The card that has been dealt is a 2 of Hearts.\n";
            }
            else if (randcard == 27)
            {
                cout << "The card that has been dealt is an ace of Hearts.\n";
            }
        }
        else if ((randcard >= 40) && (randcard <= 52)) // Checks if the card is a Spade.
        {
            // Checks the value of the card as a spade.
            if (randcard == 52)
            {
                cout << "The card that has been dealt is a King of Spades.\n";
            }
            else if (randcard == 51)
            {
                cout << "The card that has been dealt is a Queen of Spades.\n";
            }
            else if (randcard == 50)
            {
                cout << "The card that has been dealt is a Jack of Spades.\n";
            }
            else if (randcard == 49)
            {
                cout << "The card that has been dealt is a 10 of Spades.\n";
            }
            else if (randcard == 48)
            {
                cout << "The card that has been dealt is a 9 of Spades.\n";
            }
            else if (randcard == 47)
            {
                cout << "The card that has been dealt is an 8 of Spades.\n";
            }
            else if (randcard == 46)
            {
                cout << "The card that has been dealt is a 7 of Spades.\n";
            }
            else if (randcard == 45)
            {
                cout << "The card that has been dealt is a 6 of Spades.\n";
            }
            else if (randcard == 44)
            {
                cout << "The card that has been dealt is a 5 of Spades.\n";
            }
            else if (randcard == 43)
            {
                cout << "The card that has been dealt is a 4 of Spades.\n";
            }
            else if (randcard == 42)
            {
                cout << "The card that has been dealt is a 3 of Spades.\n";
            }
            else if (randcard == 41)
            {
                cout << "The card that has been dealt is a 2 of Spades.\n";
            }
            else if (randcard == 40)
            {
                cout << "The card that has been dealt is an ace of Spades.\n";
            }
        }

        //This asks the user if they would like to keep going.
        cout << "Would you like another card? (y/n)\n";
        cin >> play;
    } while ((play == 'y') || (play == 'Y'));
}