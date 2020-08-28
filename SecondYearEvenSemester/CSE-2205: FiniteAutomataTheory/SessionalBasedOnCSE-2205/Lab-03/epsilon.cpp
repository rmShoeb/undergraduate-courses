#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    int NUMBEROF_INPUT_SYMBOL;
    int NUMBEROF_STATES;
    int i, j;
    char START_STATE;
    char ACCEPTING_STATE;

    cout << "Enter the number of Input symbol: ";
    cin >> NUMBEROF_INPUT_SYMBOL;
    char INPUT_SYMBOL[NUMBEROF_INPUT_SYMBOL];

    cout << "Enter the input symbols:" << endl;
    for(i=0; i<NUMBEROF_INPUT_SYMBOL; i++)
        cin >> INPUT_SYMBOL[i];

    cout << "Enter the number of states: ";
    cin >> NUMBEROF_STATES;
    char STATES[NUMBEROF_STATES];

    cout << "Enter the states:" << endl;
    for(i=0; i<NUMBEROF_STATES; i++)
        cin >> STATES[i];

    char TABLE[NUMBEROF_STATES][NUMBEROF_INPUT_SYMBOL];
    cout << "Enter the transition table (type 0 for empty set):" << endl;
    for(i=0; i<NUMBEROF_STATES; i++)
    {
        cout << "Enter transition for " << STATES[i] << endl;
        for(j=0; j<=NUMBEROF_INPUT_SYMBOL; j++)
            cin >> TABLE[i][j];
    }

    /*cout << "Enter start state: " << endl;
    cin >> START_STATE;
    cout << "Enter accepting state: " << endl;
    cin >> ACCEPTING_STATE;*/

    //e-closure()
    cout << "e-closure of each state:\n";
    for(i=0; i<NUMBEROF_STATES; i++)
    {
        cout << "e-close(" << STATES[i] << ") = {" << STATES[i];
        if(TABLE[i][0] != '0')
            cout << ", " << TABLE[i][0];
        for(j=0; j<NUMBEROF_STATES; j++)
        {
            if(TABLE[i][0] == STATES[j])
                break;
        }
        if(TABLE[j][0] != '0' && j<NUMBEROF_STATES)
            cout << ", " << TABLE[j][0];
        cout << "}" << endl;
    }

    //generate strings accepted by automation
}
