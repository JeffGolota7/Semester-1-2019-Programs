#include <iostream>
#include <math.h> // This library lets us access random numbers
#include <ctime>  // This library lets us access the computer's clock
#include <stdlib.h>
using namespace std;

/* Card Shark Game
Intro to Programming
Author: Jeff Golota */


int main()
{
    srand(time(NULL));

    int card1, card2, bet, rounds;
    int wallet = 100;
    string wager;
    int i = 1;
    
    cout << "Welcome to Card Shark!" << endl;
    cout << "How many rounds would you like to play? " << endl;
    cin >> rounds;

    while (rounds >= i)
    {
    
        card1 = rand() % 20; // Generates a random number between 0 and 20
        cout << "--------------------------------------" << endl;
        cout << "This is the current card: " << card1 << endl;
        cout << "You currently have " << wallet << "$" << endl;
        cout << "--------------------------------------" << endl;

        cout << "How much money would you like to bet?: " << endl;
        cin >> bet;
        // If you have enough money for the bet, then the game will start.
        if (bet <= wallet)
        {
            cout << "Do you think the next card will be higher or lower?: " << endl;
            cin >> wager;

            card2 = rand() % 20;
            cout << "The new card is: " << card2 << endl;
   
            if (card1 > card2)
            {
                if ((wager == "lower") || (wager == "Lower"))
                {
                    cout << "Congratulations, you guessed correctly! You win " << bet << "$." << endl;
                    wallet = wallet + bet;
                    cout << "You now have " << wallet << "$." << endl;
                }
                else if ((wager == "higher") || (wager == "Higher"))
                {
                    cout << "You did not guess correctly. You lost " << bet << "$." << endl;
                    wallet = wallet - bet;
                    cout << "You now have " << wallet << "$." << endl;
                }
            }
            else if (card1 < card2)
            {
                if ((wager == "higher") || (wager == "Higher"))
                {
                    cout << "Congratulations, you guessed correctly! You win " << bet << "$." << endl;
                    wallet = wallet + bet;
                    cout << "You now have " << wallet << "$." << endl;
                }
                else if ((wager == "lower") || (wager == "Lower"))
                {
                    cout << "You did not guess correctly. You lost " << bet << "$." << endl;
                    wallet = wallet - bet;
                    cout << "You now have " << wallet << "$." << endl;
                        if (wallet == 0)
                        {
                            cout << "Sorry you are out of money. Game over.";
                            return 0;
                        }
                }
            }
            else if (card2 == card1)
            {
                cout << "The new card is the same as the last one. You do not win or lose any money." << endl;
            }
            i++;
        }
        // If you don't have enough money then the game will tell you that you can't play.
        else if (wallet < bet)
        {
            cout << "Sorry you do not have enough money for that bet." << endl;
        }
        // If you are out of money the game tells you that you are broke.
        else if (wallet == 0)
        {
            cout << "Sorry you are broke. Better luck next time." << endl;
        }
    }




    return 0;
}