#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct customer
{
    string first_name, last_name;
    int accountNum;
    float accountBal;
    bool exist;
};

int main()
{
    customer list[10];
    ifstream inputfile;
    ifstream logfile;
    ifstream log2file;
    ofstream output;
    inputfile.open("accounts.txt");
    int entries;

    inputfile >> entries;
    for (int i = 0; i < entries; ++i)
    {
        inputfile >> list[i].first_name >> list[i].last_name >> list[i].accountNum >> list[i].accountBal;
        list[i].exist = true;
    }

    logfile.open("log1.txt");
    logfile >> entries;
    int current_account, num;
    string action;
    for (int i = 0; i < entries; ++i)
    {
        logfile >> current_account >> action;
        if (action != "Balance") {
            logfile >> num;
        }
    
        for (int j = 0; j < entries; ++j)
        {
            if (current_account == list[j].accountNum)
            {
                if (action == "Deposit")
                {
                    list[j].accountBal = list[j].accountBal + num;
                    cout << setw(10) << setfill('-') << endl;
                    cout << "Deposit Successful\n";
                    cout << list[j].first_name << " " << list[j].last_name << endl;
                    cout << "Account Number: " << list[j].accountNum << endl;
                    cout << "Balance: " << list[j].accountBal << endl;
                    cout << setw(10) << setfill('-') << endl;
                }
                else if (action == "Withdraw")
                {
                    if (num <= list[j].accountBal)
                    {
                        list[j].accountBal = list[j].accountBal - num;
                        cout << setw(10) << setfill('-') << endl;
                        cout << "Withdrawl Successful\n";
                        cout << list[j].first_name << " " << list[j].last_name << endl;
                        cout << "Account Number: " << list[j].accountNum << endl;
                        cout << "Balance: " << list[j].accountBal << endl;
                        cout << setw(10) << setfill('-') << endl;
                    }
                    else if (num > list[j].accountBal) {
                        cout << setw(10) << setfill('-') << endl;
                        cout << "Withdrawl failed\n";
                        cout << "Insufficient funds.\n";
                        cout << setw(10) << setfill('-') << endl;
                    }
                }
                else if (action == "Balance")
                {
                    cout << setw(10) << setfill('-') << endl;
                    cout << "Balance Requested\n";
                    cout << list[j].first_name << " " << list[j].last_name << endl;
                    cout << "Account Number: " << list[j].accountNum << endl;
                    cout << "Balance: " << list[j].accountBal << endl;
                    cout << setw(10) << setfill('-') << endl;
                }
            }
        }
    }
    cout << "Transaction log finished.\n";
    cout << setw(10) << setfill('-') << endl;
    logfile.close();



    output.open("report.txt");
    output << setw(17) << left << "Account Details" << "|" << setw(15) << left << "Amount" << endl;
    output << "-----------------|-----------------------\n";
    for (int i= 0; i < 5; ++i) {

        output << setw(17) << left << (list[i].first_name + " " + list[i].last_name) << "|" << endl;
        output << setw(17) << left << "{Account Number " << "|" << list[i].accountNum << endl;
        output << setw(17) << left << "{Account Balance " << "|" << list[i].accountBal << endl;
    }
}
