//COMSC-210 || LAB-29 || Akashdeep Singh
// Program: ER Simulation mockup
// Description: basic mockup, test of data structure and function calls

#include <iostream>
#include <map>
#include <array>
#include <list>
using namespace std;

// CONSTANTS
const int NUM_LISTS = 3;

// FUNCTION PROTOTYPES
void simulate(map<string, array<list<string>, NUM_LISTS>>& hospital);
void display(const map<string, array<list<string>, NUM_LISTS>>& hospital);

int main()
{
    // This is us creating the map
    map<string, array<list<string>, NUM_LISTS>> hospital;

    // Adding one dummy data element  
    // Department: ER
    // One patient in the waiting list
    hospital["ER"][0].push_back("John");

    // Show initial state
    cout << "INITIAL STATE:\n";
    display(hospital);

    // Call simulate function
    simulate(hospital);

    // Show final state
    cout << "\nFINAL STATE:\n";
    display(hospital);

    return 0;
}

// FUNCTION: display
void display(const map<string, array<list<string>, NUM_LISTS>>& hospital)
{
    // Loop through map
    for (auto pair : hospital)
    {
        cout << "\nDepartment: " << pair.first << endl;

        // Print the waiting list
        cout << "Waiting: ";
        for (auto name : pair.second[0])
            cout << name << " ";

        // Print treatment list
        cout << "\nTreatment: ";
        for (auto name : pair.second[1])
            cout << name << " ";

        // Print discharged list
        cout << "\nDischarged: ";
        for (auto name : pair.second[2])
            cout << name << " ";

        cout << endl;
    }
}

// FUNCTION: simulate
void simulate(map<string, array<list<string>, NUM_LISTS>>& hospital)
{
    cout << "\n--- Running Mock Simulation ---\n";

    // Access the ER department
    string patient;

    // Move patient from waiting to treatment
    if (!hospital["ER"][0].empty())
    {
        patient = hospital["ER"][0].front();
        hospital["ER"][0].pop_front();
        hospital["ER"][1].push_back(patient);

        cout << "Moved " << patient << " to treatment\n";
    }

    // Move patient from treatment to discharged
    if (!hospital["ER"][1].empty())
    {
        patient = hospital["ER"][1].front();
        hospital["ER"][1].pop_front();
        hospital["ER"][2].push_back(patient);

        cout << "Moved " << patient << " to discharged\n";
    }
}