#include <iostream>                                       //input output stream handling
#include <cstdio>                                         //standard input output handling
#include <cstdlib>                                        //standard library handling
#include <fstream>                                        //file stream handling
#include <vector>                                         //vector handling
using namespace std;

int main(void)
{
  ifstream read_file("input.txt");                        //for connecting to the file data
  vector <int> input;                                     //for storing file data
  int iterator;                                           //for iteration
  int INPUT_SIZE;                                         //for size of the input
  int temp;                                               //for temporary input
  int max;                                                //to store the maximum
  int min;                                                //to store the minimum
  double step_required;                                   //to store required steps

  cout << "Enter input size: ";
  cin >> INPUT_SIZE;

  for(iterator=0; iterator<INPUT_SIZE; iterator++)        //reading input
  {
    read_file >> temp;
    input.push_back(temp);
  }

  //let
  max = input[0];
  min = input[0];

  step_required = 0;
  for(iterator=1; iterator<INPUT_SIZE; iterator++)
  {
    if(input[iterator] > max)
      max = input[iterator];
    if(input[iterator] < min)
      min = input[iterator];
    step_required++;
  }

  cout << "Max = " << max << endl;
  cout << "Min = " << min << endl;

  cout << "Required steps = " << step_required << endl;
}
