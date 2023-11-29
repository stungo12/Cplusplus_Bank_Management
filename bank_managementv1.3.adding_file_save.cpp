// Bank Management
// Project from the web for showing C++ skills
// Attempting to use STRUCTUREs to store info

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int menu(int& choice);
void new_account(int numAccount[], int arraySize);

int main()
{
    int choice;
    int const ROW = 10;

    // Array
    int numAccount[ROW];
    for (int i = 0; i < ROW; i++)
    {
        numAccount[i] = 0;
    }

        do
    {
        choice = -99;
        menu(choice);
        if (choice == 1) {new_account(numAccount, ROW);}
        //else if (choice == 2) {view_list();}
        //else if (choice == 3) {edit();}
        //else if (choice == 4) {transaction();}
        //else if (choice == 5) {erase();}
        //else if (choice == 6) {see();}
        //else if (choice == -99) {cout << "Good-bye\n";}
        //else {cout << "Wrong input, please try again.\n";}
        
    } while (choice != -99);

    cout << "\nYou have exited. good-bye";

    return 0;
}

int menu(int& choice)
{
    cout << "What would you like to do?\n";
    cout << "(1) - New Account\n";
    cout << "(2) - View list of customers\n";
    cout << "(3) - Edit an account\n";
    cout << "(4) - Create a transaction\n";
    cout << "(5) - Erase an account\n";
    cout << "(6) - See customer account\n";
    cout << "And -99 to quit\n\n";
    cout << "Please enter your choice: \n";

    cin >> choice;
    return choice;
}

void new_account(int numAccount[], int arraySize)
{
    int i = 0;
    int numberAccount;

    // Find the last open position in the array
    for (i; numAccount[i] != 0; i++);

    // Create a random account number
    srand(time(0));
        numberAccount = rand() % 100000;

    cout << "\nAccount Number: " << numberAccount << endl << endl;
    numAccount[i] = numberAccount;

    for (int j = 0; j < arraySize; j++)
        cout << "Account " << j << ": " << numAccount[j] << endl;

}