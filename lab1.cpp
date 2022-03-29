#include <iostream>
using namespace std;

int main()
{
    /* This program will calculate your average grade for four exam scores.
    Programmer: Jeff Golota */
    int x1,x2,x3,x4;
    double average;
    double sum;
    
    cout << "Welcome to this Grade Calculator!";
    cout << endl;
    cout << "Please enter your first exam score: ";
    cin >> x1;
    cout << endl;
    cout << "Please enter your second exam score: ";
    cin >> x2;
    cout << endl;
    cout << "Please enter your third exam score: ";
    cin >> x3;
    cout << endl;
    cout << "Please enter your fouth exam score: ";
    cin >> x4;
    cout << endl;
    sum = x1 + x2 + x3 + x4;
    average = sum / 4.0;
    cout << "Your grade average is: " << average << endl;

return 0;
}