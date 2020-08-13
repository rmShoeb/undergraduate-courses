#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


//global variables
vector <int> GivenNumbers;


//function definition
bool is_possible(int RequiredNumber)
{
    int NumberOfInputs = GivenNumbers.size();
    int row_iter;
    int column_iter;
    bool POSSIBLE[NumberOfInputs+1][RequiredNumber+1];

    for(row_iter=0; row_iter<=NumberOfInputs; row_iter++)
    {
        for(column_iter=0; column_iter<=RequiredNumber; column_iter++)
        {
            if(column_iter == 0)
                POSSIBLE[row_iter][column_iter] = true;
            else if(row_iter == 0)
                POSSIBLE[row_iter][column_iter] = false;
            else if(column_iter <= GivenNumbers[row_iter-1])
                POSSIBLE[row_iter][column_iter] = ((true && POSSIBLE[row_iter-1][column_iter - GivenNumbers[row_iter-1]]) || POSSIBLE[row_iter-1][column_iter]);
            else
                POSSIBLE[row_iter][column_iter] = POSSIBLE[row_iter-1][column_iter];
        }
    }

    return POSSIBLE[NumberOfInputs][RequiredNumber];
}


//main function
int main(void)
{
    int NumberOfInputs;
    int RequiredNumber;
    int temp;
    int iter;

    cout << "Enter the number of inputs: ";
    cin >> NumberOfInputs;
    cout << "Enter the numbers: ";
    for(iter=0; iter<NumberOfInputs; iter++)
    {
        cin >> temp;
        GivenNumbers.push_back(temp);
    }
    cout << "Enter the expected number: ";
    cin >> RequiredNumber;

    if(is_possible(RequiredNumber))
        cout << "POSSIBLE" << endl;
    else
        cout << "NOT POSSIBLE" << endl;
}
