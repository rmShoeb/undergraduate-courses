#include <iostream>                                               //for stream input output
#include <cstdio>                                                 //for standard input output
#include <cstdlib>                                                //rand() & srand()
#include <ctime>                                                  //time()
#include <vector>                                                 //STL........vector
#include <utility>
using namespace std;

//my variables
class MoneyStack
{
public:
  int weight;
  int profit;
  int position;
};


//main function
int main(void)
{
  int INPUT_SIZE;
  int iterator;
  int BagCapacity;
  int WeightLifted;
  int ProfitLifted;
  int weight;
  int profit;
  int j;
  int temp;
  double time_taken;

  cout << "Enter the size of the input: ";
  cin >> INPUT_SIZE;

  MoneyStack InputData[INPUT_SIZE];
  BagCapacity = 0;
  srand(time(0));

  for(iterator=0; iterator<INPUT_SIZE; iterator++)
  {
    weight = (rand()%25)+1;
    profit = (rand()%1000)+1;
    BagCapacity += weight;
    InputData[iterator].weight = weight;
    InputData[iterator].profit = profit;
    InputData[iterator].position = iterator+1;
  }
  BagCapacity = (BagCapacity*7)/10;

  cout << "Money stacks\nWeight Profit" << endl;
  for(iterator=0; iterator<INPUT_SIZE; iterator++)
    cout << InputData[iterator].weight << " " << InputData[iterator].profit << endl;
  cout << "Capacity of Bag=" << BagCapacity << endl;

  //brute force approch
  /*cout << "Brute Force Approach" << endl;
  for(iterator=0; iterator<INPUT_SIZE; iterator++)
  {
    //have to do something that will generate power set
  }*/

  //greedy approach
  cout << "Greedy Approach" << endl;
  for(iterator=0; iterator<INPUT_SIZE; iterator++)
  {
    for(j=iterator+1; j<INPUT_SIZE; j++)
    {
      if(InputData[iterator].profit < InputData[j].profit)
      {
        //profit swap
        temp = InputData[iterator].profit;
        InputData[iterator].profit = InputData[j].profit;
        InputData[j].profit = temp;
        //weight swap
        temp = InputData[iterator].weight;
        InputData[iterator].weight = InputData[j].weight;
        InputData[j].weight = temp;
        //position swap
        temp = InputData[iterator].position;
        InputData[iterator].position = InputData[j].position;
        InputData[j].position = temp;
      }
    }
  }

  time_taken = clock();
  cout << "Stacks taken: ";
  WeightLifted = InputData[0].weight;
  ProfitLifted = InputData[0].profit;
  cout << InputData[0].position << " ";
  for(iterator=1; iterator<INPUT_SIZE; iterator++)
  {
    if((WeightLifted+InputData[iterator].weight) <= BagCapacity)
    {
      WeightLifted += InputData[iterator].weight;
      ProfitLifted += InputData[iterator].profit;
      cout << InputData[iterator].position << " ";
    }
  }
  cout << endl;
  time_taken = (clock() - time_taken);

  cout << "Weight Lifted= " << WeightLifted << endl;
  cout << "Profit Lifted= " << ProfitLifted << endl;
  cout << "Time taken= " << time_taken << "ms" << endl;
}
