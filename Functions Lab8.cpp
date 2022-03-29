#include <iostream>
#include <math.h> // This library lets us access random numbers
#include <ctime>  // This library lets us access the computer's clock
#include <stdlib.h>
using namespace std;


struct empt // Struct in order to store if the value exists or not
{
    bool exist = true;
    int value;
};

void print(empt list[]) // This function prints all even numbers of the array
{
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (list[i].exist == true)
        {
            if (list[i].value % 2 == 0)
            {
                cout << list[i].value << endl;
            }
            else
            {
                cout << "ODD\n";
            }
            ++count;
        }
        else if (list[i].exist == false) {
            cout << "EMPTY\n";
        }
    }
    cout << "There are " << count << " valid entries in the array.\n";

}
int max(empt list[]) // This fuction computes the maximum value and tells you
{
    int largest = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (list[i].value > largest)
        {
            largest = list[i].value;
        }
    }
    return largest;
}
int lookup(empt list[], int lookupValue) // This fuction looks up your specified number and tells you how many times it appears
{
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (list[i].value == lookupValue)
        {
            ++count;
        }
    }
    return count;
}
void deletion(empt list[], int deleteNum) { // This function removes a value by making the boolean false
    int count = 0;
    for (int i=0; i < 10; ++i) {
        if (list[i].value == deleteNum) {
            list[i].exist = false;
            ++count;
        }
    }
    if (count == 0) {
        cout << "Number you entered is not in the array.\n";
    }
}
void addNum(empt list[], int add) { // This funciton adds a value to an empty slot created by removing a value
    bool found = false;
    for (int i = 0; i < 10; ++i) {
        if (list[i].exist == false) {
            list[i].value = add;
            found = true;
            list[i].exist = true;
            break;
        }
    }
    if (found == false) {
        cout << "There are no available slots to add in a new value.\n";
    }
    
}

int main()
{
    srand(time(NULL));
    int size = 10;
    empt list[size];
    for (int i = 0; i < size; ++i)
    {
        list[i].value = rand() % 11;
        cout << list[i].value << endl;
        list[i].exist = true;
    }
    int play = 1;
    int choice;
    do
    {
        cout << "||||||||||||||||||||||||||||||||||||||||\n";
        cout << "Select an option\n";
        cout << "(1) Print all even numbers in the array\n";
        cout << "(2) Get the maximum value in the array\n";
        cout << "(3) Lookup a value in the array\n";
        cout << "(4) Remove a value from the array\n";
        cout << "(5) Add a value to the array\n";
        cout << "(6) Quit\n";
        cout << "||||||||||||||||||||||||||||||||||||||||\n";
        cin >> choice;

        if (choice == 1) {
            print (list);
        }
        else if (choice == 2) {
            cout << "The maximum value in the array is " << max(list) << endl;
        }
        else if (choice == 3) {
            int lookupNum;
            cout << "Which number would you like to look up?: \n";
            cin >> lookupNum;
            cout << "The number you requested appeared " << lookup(list,lookupNum) << " times.\n";
        }
        else if (choice == 4) {
            int del;
            cout <<  "Which number would you like to delete?: \n";
            cin >> del;
            deletion(list,del);
        }
        else if (choice == 5) {
            int add;
            cout << "Enter a value you would like to add to the array: \n";
            cin >> add;
            addNum(list,add);
        }
        else if (choice == 6) {
            break;
        }
    } while (play = 1);
    


}
