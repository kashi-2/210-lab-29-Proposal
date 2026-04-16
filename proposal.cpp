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
