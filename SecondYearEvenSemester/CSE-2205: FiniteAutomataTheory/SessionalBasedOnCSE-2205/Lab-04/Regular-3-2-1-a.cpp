#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    int NumberOfInputSymbols;
    int NumberOfStates;
    bool Epsilon;
    bool EmptySET;
    int i, j, k;

    cout << "Enter number of input symbols: ";
    cin >> NumberOfInputSymbols;

    char InputSymbols[NumberOfInputSymbols];

    cout << "Enter the input symbols: ";
    for(i=0; i<NumberOfInputSymbols; i++)
        cin >> InputSymbols[i];
    cout << "Enter the number of states: ";
    cin >> NumberOfStates;

    int TransitionTable[NumberOfStates][NumberOfInputSymbols];

    cout << "Enter the indices of the transition table:" << endl;
    for(i=0; i<NumberOfStates; i++)
    {
        for(j=0; j<NumberOfInputSymbols; j++)
            cin >> TransitionTable[i][j];
    }

    //generating regular expression for Rij(0)
    //char RegularExpression0[NumberOfStates][NumberOfStates];
    cout << "Regular expression for Rij(0):" << endl;
    cout << "(e denotes epsilon)" << endl;
    for(i=0; i<NumberOfStates; i++)
    {
        for(j=0; j<NumberOfStates; j++)
        {
            Epsilon = false;
            EmptySET = true;
            printf("R%d%d(0): ", i+1, j+1);
            if(i == j)
            {
                cout << "e";
                Epsilon = true;
                EmptySET = false;
            }
            for(k=0; k<NumberOfInputSymbols; k++)
            {
                if(TransitionTable[i][k] == (j+1))
                {
                    if(Epsilon)
                        cout << "+";
                    cout << InputSymbols[k];
                    EmptySET = false;
                }
            }
            if(EmptySET)
                cout << "empty";
            cout << endl;
        }
    }
}
