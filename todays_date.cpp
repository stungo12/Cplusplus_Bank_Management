// Program Name
// Program Description

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    const int size = 11;

    time_t rawtime;
    struct tm * timeinfo;
    char depositDate[size];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(depositDate, size, "%m-%d-%Y", timeinfo);
    

    //cout << depositDate << endl;

    string dateDeposite = "";

    for (int i = 0; i < size; i++) {
        dateDeposite += depositDate[i];
    }

    cout << dateDeposite;

    return 0;
}