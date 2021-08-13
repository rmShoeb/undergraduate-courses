#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <algorithm>
using namespace std;

int main(void)
{
    int INPUT_SIZE;
    int i, j;
    int START_NODE;
    int FIND_NODE;
    stack <int> NODE;
    int STACK_TOP;
    bool POSSIBLE = false;

    cout << "Enter the size of the input: ";
    cin >> INPUT_SIZE;

    bool PUSHED[INPUT_SIZE];
    bool ADJACENT[INPUT_SIZE][INPUT_SIZE];

    cout << "Enter adjacency matrix (simple graph only): " << endl;
    for(i=0; i<INPUT_SIZE; i++)
    {
        for(j=0; j<INPUT_SIZE; j++)
            cin >> ADJACENT[i][j];
    }

    //the DFS
    for(i=0; i<INPUT_SIZE; i++)
        PUSHED[i] = false;

    cout << "Enter index of the start node: ";
    cin >> START_NODE;
    cout << "Enter index of the required node: ";
    cin >> FIND_NODE;

    NODE.push(START_NODE);
    PUSHED[START_NODE] = true;
    while(!NODE.empty())
    {
        STACK_TOP = NODE.top();                     //getting top element of the stack
        cout << STACK_TOP << " ";
        NODE.pop();                                 //popping the top element
        if(ADJACENT[STACK_TOP][FIND_NODE])
        {
            POSSIBLE = true;
            break;
        }
        for(i=0; i<INPUT_SIZE; i++)
        {
            if((ADJACENT[STACK_TOP][i]) && (!PUSHED[i]))
            {
                NODE.push(i);                       //pushing new element in the stack
                PUSHED[i] = true;                   //the element is now pushed
            }
        }
    }
    cout << endl;

    if(POSSIBLE)
        cout << "POSSIBLE" << endl;
    else
        cout << "NOT POSSIBLE" << endl;

    /*if(ADJACENT[STACK_TOP][START_NODE])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;*/
}
