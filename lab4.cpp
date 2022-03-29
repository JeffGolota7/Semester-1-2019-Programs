#include <iostream>
#include <math.h> // This library lets us access random numbers
#include <ctime>  // This library lets us access the computer's clock
#include <stdlib.h>
using namespace std;
/* Hot/Cold guessing game
   Author: Jeff Golota */
int main()
{
    srand(time(NULL));
    int magic_number, guess, previous_guess;
    int round = 0;
    char play = 'y';
randcard = (rand() % 52) + 1;
    magic_number = rand() % 50 + 1;

    cout << "--------------------------------------------------------\n"; // These lines introduce the game and tell you how to play.
    cout << "Welcome to the Hot/Cold Guessing game\n";
    cout << "A random number between 0 and 50 has been selected\n";
    cout << "Make a guess and it will tell you if you are hot or cold\n";
    cout << "--------------------------------------------------------\n";

    previous_guess = 0;
    do
    {
        cout << "Guess your first number(0-50): \n";
        cin >> previous_guess;
    } while((previous_guess > 50) || (previous_guess < 0));

    do // Compares the guess to the previous guess and tells you if you're hot or cold.
    {
            do
            {
                cout << "Guess a number(0-50): \n";
                cin >> guess;
            } while((guess > 50) || (guess < 0));

            if (magic_number == guess)
            {
                ++round;
                cout << "You guessed the number in " << round << " guesses.\n";
                break;
            }
            else if ((abs(magic_number - guess)) > (abs(magic_number - previous_guess)))
            {
                cout << "Getting colder.\n";
            }
            else if ((abs(magic_number - guess)) < (abs(magic_number - previous_guess)))
            {
                cout << "Getting warmer.\n";
            }
            cout << "Would you like to keep playing? (y/n): \n";
            cin >> play;

            previous_guess = guess;
            ++round;

        } while (play == 'y');
        cout << "Thanks for playing!\n";
    }