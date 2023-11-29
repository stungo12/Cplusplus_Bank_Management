// Bank Management
// Project from the web for showing C++ skills
// Attempting to use STRUCTUREs to store info

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int const ROW = 10;

struct {
    int numAccount[ROW];
    string firstName[ROW];
    string lastName[ROW];
    int ssn[ROW];
    string homeAddress[ROW];
    string phoneNumber[ROW];
    string typeAccount[ROW];
    double depositAccount[ROW];
    int customerAge[ROW];
    string ageDate[ROW];
    string whenDeposited[ROW];
} customer;

int menu(int& choice);
// Add date functions here
void birthday(int i);
void depositDate(int i);
//
void array_display();

void new_account();

void view_list();

int main()
{
    int choice;


    for (int i = 0; i < ROW; i++)
    {
        customer.numAccount[i] = 0;
        customer.firstName[i], customer.lastName[i], customer.homeAddress[i], customer.phoneNumber[i], customer.typeAccount[i], customer.ageDate[i], customer.whenDeposited[i] = "";
        customer.ssn[i], customer.customerAge[i] = 0;
        customer.depositAccount[i] = 0;
    }

        do
    {
        choice = -99;
        menu(choice);
        if (choice == 1) {new_account();}
        else if (choice == 2) {view_list();}
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

void array_display()
{
        for (int i = 0; i < ROW; i++)
    {
        cout << "Account Number: " << customer.numAccount[i];
        cout << ", Name: " << customer.firstName[i] << " " << customer.lastName[i];
        cout << ", DOB: " << customer.ageDate[i];
        cout << ", Customer's Age: " << customer.customerAge[i];
        cout << ", Social Security Number: " << customer.ssn[i];
        cout << ", Home Address: " << customer.homeAddress[i];
        cout << ", Phone Number: " << customer.phoneNumber[i];
        cout << ", Type of Account: " << customer.typeAccount[i];
        cout << ", Amount Deposited: " << customer.depositAccount[i];
        cout << ", Date Deposited: " << customer.whenDeposited[i] << endl << endl;

    }
}

// New Functions
void birthday(int i)
{
    int day, month, year;
    struct tm date = {0};
    cout << "\nPlease enter what month the customer was born in (mm): ";
    cin >> month;
    cout << "\nNow the day of their birth (dd): ";
    cin >> day;
    cout << "\nAnd finally, enter in which year they were born (yyyy): ";
    cin >> year;

    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    time_t normal = mktime(&date);
    time_t current;
    time(&current);
    int age = (difftime(current, normal) + 86400L/2) / 86400L;

    age = age / 365;

    string birthDate = to_string(month) + "-" + to_string(day) + "-" + to_string(year);

    cout << "Customer's age: " << age << endl;

    // Input out put into age array
    customer.customerAge[i] = age;
    customer.ageDate[i] = birthDate;
}

void depositDate(int i)
{
    const int SIZE = 11;
   string date = "";
   
   time_t rawtime;
   struct tm * timeinfo;
   char dateDeposit[SIZE];

   time(&rawtime);
   timeinfo = localtime(&rawtime);

   strftime(dateDeposit, SIZE, "%m-%d-%Y", timeinfo);

   for (int i = 0; i < SIZE; i++)
   {
    date += dateDeposit[i];
   }

    cout << "\nThis deposit was made today (" + date + ")" << endl << endl;

    customer.whenDeposited[i] = date;
}
// End of said functions

void new_account(int arraySize)
{
    int i = 0;
    int numberAccount;
    int accountChoice;

    // Find the last open position in the array
    for (i; customer.numAccount[i] != 0; i++);

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
    customer.numAccount[i] = numberAccount;
    cout << "\n\nFirst Name: ";
    cin >> customer.firstName[i];
    cout << "\nLast Name: ";
    cin >> customer.lastName[i];

    // New age function
    birthday(i);
    //

    cout << "\nSocial Security Number: " << social;
    customer.ssn[i] = social;
    cout << "\n\nHome Address: ";
    cin.ignore();
    getline(cin, customer.homeAddress[i]);
    cout << "\nPhone Number: " << phoneNum;
    customer.phoneNumber[i] = phoneNum;
    cout << "\n\nWhat type of account do they wish to open? ";
        cout << "\n1 - Savings";
        cout << "\n2 - Checking";
        cout << "\n3 - CD\n";

        cin >> accountChoice;

        switch (accountChoice)
        {
        case 1:
            customer.typeAccount[i] = "Savings";
            break;
        case 2:
            customer.typeAccount[i] = "Checking";
            break;
        case 3:
            customer.typeAccount[i] = "CD";
            break;
        
        default:
            cout << "Wrong input";
            break;
        }
        
    cout << "\nHow much is being deposited: $";
    cin >> customer.depositAccount[i];

    // New date function
    depositDate(i);
    //

    array_display();

}

void view_list()
{
    cout << "\t\tView List\n\n";
    for (int i = 0; i < ROW; i++)
    {
        cout << (i + 1) << ": ";
        cout << "Customer's name: " << customer.firstName[i] << " " << customer.lastName[i];
        cout << ", Customer's Age: " << customer.ageDate[i];
        cout << ", Account Number: " << customer.numAccount[i] << endl << endl;
    }

    int customer = 0;
    int choice = 0;
    int repeat = 0;

    cout << "What customer would you like to look into (please enter their number): ";
    cin >> customer;

    cout << "\n\nWhat would you like to do about this customer's information: \n";
    cout << "(1) - Edit an account\n";
    cout << "(2) - Create a transaction\n";
    cout << "(3) - Erase an account\n";
    cout << "(4) - See customer account\n";
    cout << "And -99 to quit\n\n";
    cout << "Please enter your choice: \n";
    cin >> choice;

    do
    {
        switch (choice)
        {
        case 1:
            //edit(customer);
            break;
        case 2:
            //transaction(customer);
            break;
        case 3:
            //erase(customer);
            break;
        case 4:
            //see(customer);
            break;
        case -99:
            cout << "\nExiting \"View List\"\n\n";
            break;
        default:
            cout << "\nInvalid input, please try again." << endl;
            repeat = 1;
            break;
    }
    } while (repeat == 1);
}