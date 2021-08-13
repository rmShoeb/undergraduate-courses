#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


//class definition
class MoneyStack
{
public:
    int StackWeight;
    int StackProfit;
};


//function definition
int MAXIMUM(int a, int b)
{
    return (a>b)? a:b;
}

int KnapsackDP(MoneyStack Stacks[], int NumberOfStacks, int CapacityOfBag)
{
    int iter;
    int weight;
    int TABLE[NumberOfStacks+1][CapacityOfBag+1];

    for(iter=0; iter<=NumberOfStacks; iter++)
    {
        for(weight=0; weight<=CapacityOfBag; weight++)
        {
            if(iter==0 || weight==0)
                TABLE[iter][weight] = 0;
            else if(Stacks[iter-1].StackWeight <= weight)
                TABLE[iter][weight] = MAXIMUM(Stacks[iter-1].StackProfit+TABLE[iter-1][weight-Stacks[iter-1].StackWeight], TABLE[iter-1][weight]);
            else
                TABLE[iter][weight] = TABLE[iter-1][weight];
        }
    }

    return TABLE[NumberOfStacks][CapacityOfBag];
}


//main function
int main(void)
{
    int CapacityOfBag;
    int NumberOfStacks;
    int iter;

    cout << "Enter the capacity of bag: ";
    cin >> CapacityOfBag;
    cout << "Enter the number of stacks: ";
    cin >> NumberOfStacks;

    MoneyStack Stacks[NumberOfStacks];

    cout << "Enter the stacks and their profits:" << endl;
    for(iter=0; iter<NumberOfStacks; iter++)
        cin >> Stacks[iter].StackWeight >> Stacks[iter].StackProfit;

    cout << "Maximum profit using Dynammic Programming: " << KnapsackDP(Stacks, NumberOfStacks, CapacityOfBag) << endl;
}
