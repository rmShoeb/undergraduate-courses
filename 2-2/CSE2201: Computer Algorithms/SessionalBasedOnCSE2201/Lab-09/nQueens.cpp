#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;


//global variables
vector <int> RESULT;
int BoardSize;


//function defintion
void printRESULT(void)
{
    int iter;

    for(iter=0; iter<BoardSize; iter++)
        cout << RESULT[iter] << " ";
    cout << endl;
}


bool is_safe(int row, int column)
{
    int SOLVED = RESULT.size();
    int iter;

    for(iter=0; iter<SOLVED; iter++)
    {
        if(RESULT[iter] == row)                             //to check if they are in the same row
            return false;
        else if(iter == column)                             //to check if they are in the same column
            return false;
        else if(abs(RESULT[iter]-iter) == abs(row-column))  //to check if they are diagonal
            return false;
    }
    return true;
}


void BackTrack(void)
{
    bool FOUND = false;
    int i;

    while(!FOUND)
    {
        i = RESULT[RESULT.size()-1]+1;
        RESULT.pop_back();

        for(; i<BoardSize; i++)
        {
            if(is_safe(i, RESULT.size()))
            {
                FOUND = true;
                RESULT.push_back(i);
                //cout << i << endl;
                break;
            }
        }
    }
}


void NQueen(void)
{
    int currentColumn;
    int iter;
    bool FOUND;
    int temp;

    while(RESULT.size() != BoardSize)
    {
        currentColumn = RESULT.size();
        FOUND = false;
        for(iter=0; iter<BoardSize; iter++)
        {
            if(is_safe(iter, currentColumn))
            {
                RESULT.push_back(iter);
                FOUND = true;
                //cout << iter << " ";
                break;
            }
        }
        if(!FOUND)
            BackTrack();
    }
    //cout << endl;

    printRESULT();
    //cout << "1 3 0 2" << endl;
}


//main function
int main(void)
{
    cout << "Enter the size of the board: ";
    cin >> BoardSize;

    NQueen();
}
