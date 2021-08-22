#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
    int INPUT_SIZE;
    int i, j;
    int START_NODE;
    queue <int> NODE;
    int QUEUE_FRONT;

    cout << "Enter the size of the input: ";
    cin >> INPUT_SIZE;

    bool QUEUED[INPUT_SIZE];
    bool ADJACENT[INPUT_SIZE][INPUT_SIZE];

    cout << "Enter adjacency matrix (simple graph only): " << endl;
    for(i=0; i<INPUT_SIZE; i++)
    {
        for(j=0; j<INPUT_SIZE; j++)
            cin >> ADJACENT[i][j];
    }

    //the BFS
    for(i=0; i<INPUT_SIZE; i++)
        QUEUED[i] = false;

    cout << "Enter index of the start node: ";
    cin >> START_NODE;

    NODE.push(START_NODE);
    QUEUED[START_NODE] = true;
    while(!NODE.empty())
    {
        QUEUE_FRONT = NODE.front();                 //getting front element of the queue
        cout << QUEUE_FRONT << " ";
        NODE.pop();                                 //popping the front element
        for(i=0; i<INPUT_SIZE; i++)
        {
            if((ADJACENT[QUEUE_FRONT][i]) && (!QUEUED[i]))
            {
                NODE.push(i);                       //pushing new element in the stack
                QUEUED[i] = true;                   //the element is now pushed
            }
        }
    }
    cout << endl;

    if(ADJACENT[QUEUE_FRONT][START_NODE])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
