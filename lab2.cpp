#include <iostream>
using namespace std;

string firstName, lastInitial;
int quarters, dimes, nickels, pennies, decision, dollars, twnts, tns, fvs, ones;
double money, fee, change;

int main ()
{
    cout << "Enter your first name and last initial: ";
    cin >> firstName >> lastInitial;
    cout << "Enter the number of quarters, dimes, nickels, and pennies you have (in that order): ";
    cin >> quarters >> dimes >> nickels >> pennies;
    money = (0.25 * quarters) + (0.1 * dimes) + (0.05 * nickels) + (0.01 * pennies);
    cout << "The total amount of money you put in is: " << "$" << money << endl;

    cout << "You have three redemption options to choose from:" << endl;
    cout << "(1) Donate to Charity" << endl;
    cout << "(2) Store Gift Card" << endl;
    cout << "(3) Get Cash" << endl;
    cout << "Which option would you like to choose? (1, 2, or 3): ";
    cin >> decision;
    
    if (decision == 1)
    {
        cout << "Thank you for your donation, " << firstName << " " << lastInitial << ", in the amount of $" << money;
    }
    if (decision == 2)
    {
        fee = money * 0.95;
        cout << "Thank you for choosing Coinstar, " << firstName << " " << lastInitial << ". " << "Your gift card in the amount of $" << fee << " is being dispensed.";
    }
    if (decision == 3)
    {
        dollars = money / 1;
        change = money - dollars;
        cout << "Your change is: " << change << endl;

        twnts = dollars / 20;
        dollars = dollars - (twnts * 20);
        tns = dollars / 10;
        dollars = dollars - (tns * 10);
        fvs = dollars / 5;
        dollars = dollars - (fvs * 5);
        ones = dollars / 1;

        cout << "Thank you for choosing Coinstar, " << firstName << " " << lastInitial << ". Look below for your cash, which is " << twnts << " 20's, " << tns << " 10's, " << fvs << " 5's, and " << ones << " 1's.";
    }
return 0;
}