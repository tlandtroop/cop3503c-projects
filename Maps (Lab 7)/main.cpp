#include <iostream>
#include <fstream>
#include <map>
#include <random>
#include <ctime>
using namespace std;

mt19937 random_mt;

class State
{
public:
    string name;
    int perCapitaIncome;
    int population;
    int medHouseholdIncome;
    int numOfHouseholds;
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
    for (int i = 1; i < numberOfSides; i++)
    {
        rolls.emplace(i, 0);
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

        ifstream File("./states.csv");

        string row;
        getline(File, row); // Reads the header

        State state;
        while (!File.eof()) // While not at the end of the csv file.
        {
            getline(File, row); // Reads each line of the file.
        }

        // Get input for option 1 (show all states) or 2 (do a search for a particular state)
    }

    return 0;
}
