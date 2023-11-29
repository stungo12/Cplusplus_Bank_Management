// Bank Management
// Project from the web for showing C++ skills
// Attempting to use STRUCTUREs to store info

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int menu(int& choice);
// Add date functions here
void birthday(int customerAge, string ageDate[], int i);
void depositDate(string depositDate[], int i);
//
void array_display(int arraySize, int numAccount[], string firstName[], string lastName[], int ssn[], 
                    string homeAddress[], string phoneNumber[], string typeAccount[], 
                    double depositAccount[], int customerAge[], string ageDate[], string whenDeposited[]);

void new_account(int arraySize, int numAccount[], string firstName[], string lastName[], int ssn[], 
                    string homeAddress[], string phoneNumber[], string typeAccount[], 
                    double depositAccount[], int customerAge[], string ageDate[], string whenDeposited[]);

void view_list(int arraySize, int numAccount[], string firstName[], string lastName[], string ageDate[]);

void edit();
void edit(int& customers);

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
    // Age arrays
    int age[ROW];
    string ageDate[ROW];
    string depositDate[ROW];
    for (int i = 0; i < ROW; i++)
    {
        numAccount[i] = 0;
        firstName[i], lastName[i], homeAddress[i], phoneNumber[i], typeAccount[i], ageDate[i], depositDate[i] = "";
        ssn[i], age[i] = 0;
        depositAccount[i] = 0;
    }

        do
    {
        choice = -99;
        menu(choice);
        if (choice == 1) {new_account(ROW, numAccount, firstName, lastName, ssn, homeAddress, phoneNumber, 
                                        typeAccount, depositAccount, age, ageDate, depositDate);}
        else if (choice == 2) {view_list(ROW, numAccount, firstName, lastName, ageDate);}
        else if (choice == 3) {edit();}
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
                    double depositAccount[], int customerAge[], string ageDate[], string whenDeposited[])
{
        for (int i = 0; i < arraySize; i++)
    {
        cout << "Account Number: " << numAccount[i];
        cout << ", Name: " << firstName[i] << " " << lastName[i];
        cout << ", DOB: " << ageDate[i];
        cout << ", Customer's Age: " << customerAge[i];
        cout << ", Social Security Number: " << ssn[i];
        cout << ", Home Address: " << homeAddress[i];
        cout << ", Phone Number: " << phoneNumber[i];
        cout << ", Type of Account: " << typeAccount[i];
        cout << ", Amount Deposited: " << depositAccount[i];
        cout << ", Date Deposited: " << whenDeposited[i] << endl << endl;

    }
}

// New Functions
void birthday(int customerAge[], string ageDate[], int i)
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
    customerAge[i] = age;
    ageDate[i] = birthDate;
}

void depositDate(string depositDate[], int i)
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

    depositDate[i] = date;
}
// End of said functions



void new_account(int arraySize, int numAccount[], string firstName[], string lastName[], int ssn[], 
                    string homeAddress[], string phoneNumber[], string typeAccount[], double depositAccount[], 
                    int customerAge[], string ageDate[], string whenDeposited[])
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
    cout << "\n\nFirst Name: ";
    cin >> firstName[i];
    cout << "\nLast Name: ";
    cin >> lastName[i];

    // New age function
    birthday(customerAge, ageDate, i);
    //

    cout << "\nSocial Security Number: " << social;
    ssn[i] = social;
    cout << "\n\nHome Address: ";
    cin.ignore();
    getline(cin, homeAddress[i]);
    cout << "\nPhone Number: " << phoneNum;
    phoneNumber[i] = phoneNum;
    cout << "\n\nWhat type of account do they wish to open? ";
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

    // New date function
    depositDate(whenDeposited, i);
    //

    array_display(arraySize, numAccount, firstName, lastName, ssn, homeAddress, phoneNumber, typeAccount, 
                    depositAccount, customerAge, ageDate, whenDeposited);

}

void view_list(int arraySize, int numAccount[], string firstName[], string lastName[], string ageDate[])
{
    cout << "\t\tView List\n\n";
    for (int i = 0; i < arraySize; i++)
    {
        cout << (i + 1) << ": ";
        cout << "Customer's name: " << firstName[i] << " " << lastName[i];
        cout << ", Customer's Age: " << ageDate[i];
        cout << ", Account Number: " << numAccount[i] << endl << endl;
    }

    int customer = 0;
    int choice = 0;
    int repeat = 0;

    cout << "What customer would you like to look into (please enter their number): ";
    customer -= 1;
    cout << "\nYou have chosen: " << firstName[customer] << " " << lastName[customer] << endl;
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
            edit(customer);
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

void edit()
{

}
void edit(int& customers)
{

}