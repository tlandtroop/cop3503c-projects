#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <random>
#include <sstream>

using namespace std;

mt19937 random_mt;

class State
{
    string name;
    int perCapitaIncome;
    int population;
    int medHouseholdIncome;
    int numOfHouseholds;

public:
    State(string _name, int _perCapitaIncome, int _population, int _medHouseholdIncome, int _numOfHouseholds)
    {
        name = _name;
        perCapitaIncome = _perCapitaIncome;
        population = _population;
        medHouseholdIncome = _medHouseholdIncome;
        numOfHouseholds = _numOfHouseholds;
    }
    void Print()
    {
        cout << name << endl;
        cout << "Population: " << population << endl;
        cout << "Per Capita Income: " << perCapitaIncome << endl;
        cout << "Median Household Income: " << medHouseholdIncome << endl;
        cout << "Number of Households: " << numOfHouseholds << endl;
    }
};

int Random(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(random_mt);
}

void RollDice(int numberOfRolls, int numberOfSides)
{
    map<int, int> rolls;

    //  Initialize the values in the pairs to 0
    for (int i = 1; i < numberOfSides + 1; i++)
    {
        rolls[i] = 0;
    }

    // Generate a random number
    for (int i = 0; i < numberOfRolls; i++)
    {
        int random = Random(1, numberOfSides);
        rolls[random]++;
    }

    // Iterate through the map and print the values of the rolls
    map<int, int>::iterator iterator;
    for (iterator = rolls.begin(); iterator != rolls.end(); iterator++)
    {
        cout << iterator->first << ": " << iterator->second << endl;
    }
}

int main()
{
    cout << "1. Random Numbers\n";
    cout << "2. State Info\n";

    int option;
    cin >> option;

    if (option == 1)
    {
        int randomSeed, numberOfRolls, numberOfSides;
        cout << "Random seed value: ";
        cin >> randomSeed;
        random_mt.seed(randomSeed);

        cout << "Number of times to roll the die: ";
        // user input
        cin >> numberOfRolls;

        cout << "Number of sides on this die: ";
        // user input
        cin >> numberOfSides;

        // Roll Dice
        RollDice(numberOfRolls, numberOfSides);
    }
    else if (option == 2)
    {
        // Load the states
        map<string, State> states;
        string name;
        int perCapitaIncome;
        int population;
        int medianHouseholdIncome;
        int numberOfHouseholds;

        string row;

        ifstream File("states.csv");
        getline(File, row); // Reads the header

        while (getline(File, row)) // While not at the end of the csv file.
        {
            stringstream stream(row);
            string data;
            while (getline(stream, data, ','))
            {
                name = data;
                getline(stream, data, ',');
                perCapitaIncome = stoi(data);
                getline(stream, data, ',');
                population = stoi(data);
                getline(stream, data, ',');
                medianHouseholdIncome = stoi(data);
                getline(stream, data, ',');
                numberOfHouseholds = stoi(data);
                State state(name, perCapitaIncome, population, medianHouseholdIncome, numberOfHouseholds);
                states.emplace(name, state);
            }
        }
        int choice;
        cout << "1. Print all states" << endl;
        cout << "2. Search for a state" << endl;
        cin >> choice;

        if (choice == 1)
        {
            map<string, State>::iterator iterator;
            for (iterator = states.begin(); iterator != states.end(); iterator++)
            {
                iterator->second.Print();
            }
        }
        else if (choice == 2)
        {
            string name;
            cin >> name;

            if (states.find(name) == states.end())
            {
                cout << "No match found for " << name << endl;
            }
            else
            {
                states.find(name)->second.Print();
            }
        }
    }

    return 0;
}
