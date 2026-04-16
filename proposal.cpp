//COMSC-210 || LAB-29 || Akashdeep Singh
// Program: ER Simulation
// Description: Discrete-event simulation using map, array, and lists

#include <iostream>
#include <map>
#include <array>
#include <list>
#include <fstream>
#include <string>
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
    
    //Open external file
    ifstream fin("patients.txt");

    // Check file error
    if (!fin)
    {
        cout << "Error opening file.\n";
        return 1;
    }

    // Reads file and than populates map
    //Each line: department patientName
    string dept, name;
    while (fin >> dept >> name)
    { 
        // Insert patient into the waiting list (index 0)
        hospital[dept][0].push_back(name);
}

fin.close();

//Displays initial state
cout << "INITIAL STATE:\n";
display(hospital);

// Run simulation
simulate(hospital);

//Display final state
cout << "\nFINAL STATE:\n";
    display(hospital);

    return 0;
}

//Function: display
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


void simulate(map<string, array<list<string>, NUM_LISTS>>& hospital)
{
    
    for (int t = 1; t <= TIME_STEPS; t++)
    {
        cout << "\n--- Time Step " << t << " ---\n";

        for (auto& pair : hospital)
        {
            string dept = pair.first;


           

            if (!pair.second[0].empty())
            {
                string patient = pair.second[0].front();
                pair.second[0].pop_front();
                pair.second[1].push_back(patient);

                cout << patient << " moved to treatment in " << dept << endl;
            }

            // If treatment list is not empty than move one patient to discharged

            if (!pair.second[1].empty())
            {
                string patient = pair.second[1].front();
                pair.second[1].pop_front();
                pair.second[2].push_back(patient);

                cout << patient << " discharged from " << dept << endl;
            }

            // Optional: random new patient arrival, (mockup version just adds a dummy name occasionally)

            if (t % 5 == 0)
            {
                string newPatient = "NewPatient" + to_string(t);
                pair.second[0].push_back(newPatient);

                cout << newPatient << " arrived at " << dept << endl;
            }
        }
    }
}