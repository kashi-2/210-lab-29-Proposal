//COMSC-210 || LAB-29 || Akashdeep Singh
// Program: ER Simulation
// Description: Discrete-event simulation using map, array, and lists

#include <iostream>
#include <map>
#include <array>
#include <list>
#include <fstream>
using namespace std;

// CONSTANTS
const int NUM_LISTS = 3; // waiting, treatment, discharged
const int TIME_STEPS = 25;

// FUNCTION PROTOTYPES
void simulate(map<string, array<list<string>, NUM_LISTS>>& hospital);
void display(const map<string, array<list<string>, NUM_LISTS>>& hospital);

int main ()
{
    //PSEDUOCODE:
    //Creat map<string, array<list<string>, 3>>
    map<string, array<list<string>, NUM_LISTS>> hospital;

    ifstream fin("patients.txt");

    if (!fin)
    {
        cout << "Error opening file.\n";
        return 1;
    }

    string dept, name;
    while (fin >> dept >> name)
    { 
        hospital[dept][0].push_back(name);
}

fin.close();

cout << "INITIAL STATE:\n";
display(hospital);

cout << "\nFINAL STATE:\n";
    display(hospital);

    return 0;
}

void display(const map<string, array<list<string>, NUM_LISTS>>& hospital)
{
    // Loop through each department
    for (auto pair : hospital)
    {
        cout << "\nDepartment: " << pair.first << endl;

        // Show all 3 lists
        cout << "Waiting: ";
        for (auto p : pair.second[0])
            cout << p << " ";

        cout << "\nTreatment: ";
        for (auto p : pair.second[1])
            cout << p << " ";

        cout << "\nDischarged: ";
        for (auto p : pair.second[2])
            cout << p << " ";

        cout << endl;
    }
}