#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    vector<string> names;
    vector<int> dataPoints;
    string column1, column2;
    string input;
    // Input for table title and column headers
    string title;
    cout << "Enter a title for the data:" << endl;
    getline(cin, title);
    cout << "You entered: " << title << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, column1);
    cout << "You entered: " << column1 << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, column2);
    cout << "You entered: " << column2 << endl;

    while (true)
    {
        int commaCount = 0;

        // Collects data for table and histogram
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, input);
        // If -1 entered, then break out of while loop
        if (input == "-1")
        {
            break;
        }

        try
        {
            for (int i = 0; i < input.size(); i++)
            {
                if (input.at(i) == ',')
                {
                    commaCount++;
                }
            }
            // If no commas entered, throw error
            if (commaCount == 0)
            {
                cout << "Error: No comma in string." << endl;
                continue;
            }
            // If too many commas entered, throw error
            if (commaCount > 1)
            {
                cout << "Error: Too many commas in input." << endl;
            }
            // If one comma entered, cut input into a string and an integer for name and data point
            else
            {
                string firstString = input.substr(0, input.find(','));
                string secondInt = input.substr(input.find(',') + 1, input.length() - 1);
                secondInt.erase(0, secondInt.find_first_not_of(' '));

                int numNumbers = 0;

                for (char i : secondInt)
                {
                    if (i >= '0' && i <= '9')
                    {
                        numNumbers++;
                    }
                }
                // If all works, add name substring to names and integer to datapoints
                if (numNumbers == secondInt.length())
                {
                    names.push_back(firstString);
                    dataPoints.push_back(stoi(secondInt));

                    cout << "Data string: " << firstString << endl;
                    cout << "Data integer: " << secondInt << endl;
                }
                // If there is no integer after comma, throw an error
                else
                {
                    cout << "Error: Comma not followed by an integer." << endl;
                }
            }
        }
        // Catches any errors in the input
        catch (invalid_argument ex)
        {
            cout << ex.what() << endl;
        }
    }
    cout << endl;

    // Printing the data in a formatted table
    cout << setw(33) << title << endl;
    cout << left << setw(20) << column1 << "|" << right << setw(23) << column2 << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < names.size(); i++)
    {
        cout << left << setw(20) << names[i] << "|" << right << setw(23) << dataPoints[i] << endl;
    }
    cout << endl;

    // Printing the Histogram
    for (int i = 0; i < names.size(); i++)
    {
        cout << setw(20) << names[i] << " ";

        for (int j = 0; j < dataPoints[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
