// Bank Management
// Project from the web for showing C++ skills
// Attempting to use STRUCTUREs to store info

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int menu(int& choice);
void array_display(int arraySize, int numAccount[], string firstName[], string lastName[], int ssn[], 
                    string homeAddress[], string phoneNumber[], string typeAccount[], 
                    double depositAccount[], int customerAge[], string ageDate[], string whenDeposited[]);
// Add date functions here
void birthday(int customerAge, string ageDate[], int i);
void depositDate(string depositDate[], int i);
//
void new_account(int arraySize, int numAccount[], string firstName[], string lastName[], int ssn[], 
                    string homeAddress[], string phoneNumber[], string typeAccount[], 
                    double depositAccount[], int customerAge[], string ageDate[], string whenDeposited[]);

int main()
{
    int choice;
    int const ROW = 10;

    // Array
    int numAccount[ROW];
    string firstName[ROW];
    string lastName[ROW];
    int ssn[ROW];
    string homeAddress[ROW];
    string phoneNumber[ROW];
    string typeAccount[ROW];
    double depositAccount[ROW];
    for (int i = 0; i < ROW; i++)
    {
        numAccount[i] = 0;
    }

        do
    {
        choice = -99;
        menu(choice);
        if (choice == 1) {new_account(ROW, numAccount, firstName, lastName, ssn, homeAddress, phoneNumber, 
                                        typeAccount, depositAccount);}
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

void array_display(int arraySize, int numAccount[], string firstName[], string lastName[], int ssn[], 
                    string homeAddress[], string phoneNumber[], string typeAccount[], 
                    double depositAccount[])
{
        for (int i = 0; i < arraySize; i++)
    {
        cout << "Account Number: " << numAccount[i];
        cout << ", Name: " << firstName[i] << " " << lastName[i];
        cout << ", Social Security Number: " << ssn[i];
        cout << ", Home Address: " << homeAddress[i];
        cout << ", Phone Number: " << phoneNumber[i];
        cout << ", Type of Account: " << typeAccount[i];
        cout << ", Amount Deposited: " << depositAccount[i] << endl;
    }
}

void new_account(int arraySize, int numAccount[], string firstName[], string lastName[], int ssn[], 
                    string homeAddress[], string phoneNumber[], string typeAccount[], double depositAccount[])
{
    int i = 0;
    int numberAccount;
    int accountChoice;

    // Find the last open position in the array
    for (i; numAccount[i] != 0; i++);

    // Create a random account number
    srand(time(0));
        numberAccount = rand() % 100000;

    // Create a random social security number
    srand(time(0));
        int social = rand() % 100000000;

    // Create a random phone number
    srand(time(0));
        string phoneNum = to_string(rand() % 1000000000);


    cout << "Account Number: " << numberAccount;
    numAccount[i] = numberAccount;
    cout << "\nFirst Name: ";
    cin >> firstName[i];
    cout << "\nLast Name: ";
    cin >> lastName[i];
    cout << "\nSocial Security Number: " << social;
    ssn[i] = social;
    cout << "\nHome Address: ";
    cin.ignore();
    getline(cin, homeAddress[i]);
    cout << "\nPhone Number: " << phoneNum;
    phoneNumber[i] = phoneNum;
    cout << "\nWhat type of account do they wish to open? ";
        cout << "\n1 - Savings";
        cout << "\n2 - Checking";
        cout << "\n3 - CD\n";

        cin >> accountChoice;

        switch (accountChoice)
        {
        case 1:
            typeAccount[i] = "Savings";
            break;
        case 2:
            typeAccount[i] = "Checking";
            break;
        case 3:
            typeAccount[i] = "CD";
            break;
        
        default:
            cout << "Wrong input";
            break;
        }
        
    cout << "\nHow much is being deposited: $";
    cin >> depositAccount[i];

    array_display(arraySize, numAccount, firstName, lastName, ssn, homeAddress, phoneNumber, typeAccount, 
                    depositAccount);

}