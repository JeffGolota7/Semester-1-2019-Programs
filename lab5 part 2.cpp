#include <iostream>
#include <math.h> // This library lets us access random numbers
#include <ctime>  // This library lets us access the computer's clock
#include <stdlib.h>
using namespace std;

int count, previous, num, repeat, i, average;
/* Loop program
Author: Jeff Golota */

int main()
{
    srand(time(NULL));
    previous = 0;
    repeat = 0;
    cout << "Enter an amount of times you would like this program to run.\n"; //Asks the user how many times they want the loop to run.
    cin >> count;
    previous = rand() % 4;
    cout << "The first number is " << num << endl;
    for (i = 0; i < count; ++i)
    {
        num = rand() % 4;
        cout << "The new number is " << num << endl;
        average = average + num;
        if (num == previous) // Evaluates if the new number is the same as the last number
        {
            ++repeat;
            cout << "This is the same as the last number! That's " << repeat << " in a row!\n";
        }
        else if (num > previous) //Evaluates if the new number is greater than the last number
        {
            cout << "This is HIGHER than the last number.\n";
        }
        else if (num < previous) //Evaluates if the new number is lower than the last number
        {
            cout << "This is LOWER than the last number.\n";
        }
        previous = num;
    }
    cout << "The average value in your loop was " << (average / count) << endl; //Calculates and displays the average.
}