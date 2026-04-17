//COMSC-210 || LAB-31 || Akashdeep Singh
// Program: ER Simulation (Beta version)
// Description: Full simulation with file input and 25 time steps

#include <iostream>
#include <map>
#include <array>
#include <list>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// CONSTANTS
const int NUM_LISTS = 3;
const int TIME_STEPS = 25;
// FUNCTION PROTOTYPES
void simulate(map<string, array<list<string>, NUM_LISTS>>& hospital);
void display(const map<string, array<list<string>, NUM_LISTS>>& hospital);

int main()
{
    // This is us creating the map
    map<string, array<list<string>, NUM_LISTS>> hospital;

    // Open file
    ifstream fin("patients.txt");

    if (!fin)
    {
        cout << "Error opening file.\n";
        return 1;
    }

    // Read file data
    string dept, name;
    while (fin >> dept >> name)
    {
        hospital[dept][0].push_back(name); // put in waiting list
    }

    fin.close();
    
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
    for (const auto& pair : hospital) // made this change to avoid unnecessary copying
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
    for (int t = 1; t <= TIME_STEPS; t++)
    {
        cout << "\n--- Time Step " << t << " ---\n";

        for (auto& pair : hospital)
        {
            string dept = pair.first;
            string patient;

            // waiting -> treatment
            if (!pair.second[0].empty())
            {
                patient = pair.second[0].front();
                pair.second[0].pop_front();
                pair.second[1].push_back(patient);

                cout << patient << " moved to treatment in " << dept << endl;
            }

            // treatment -> discharged
            if (!pair.second[1].empty())
            {
                patient = pair.second[1].front();
                pair.second[1].pop_front();
                pair.second[2].push_back(patient);

                cout << patient << " discharged from " << dept << endl;
            }

            //Random new patient arrival, doing this to improve the simulation
            if (rand() % 4 == 0) // 25% chance
            {
                string newPatient = "Patient_" + to_string(rand() % 1000);
                pair.second[0].push_back(newPatient);

                cout << newPatient << " arrived at " << dept << endl;
            }
        }
    }
}