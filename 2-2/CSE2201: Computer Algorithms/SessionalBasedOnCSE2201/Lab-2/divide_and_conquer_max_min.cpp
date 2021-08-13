#include <iostream>                                           //input output stream handling
#include <cstdio>                                             //standard input output handling
#include <cstdlib>                                            //standard library handling
#include <fstream>                                            //file stream handling
using namespace std;

//global variables
int step_required = 0;                                        //to count the the number of steps required

//used-defined variable
struct couple
{
  int max;
  int min;
};

//user-defined functions
struct couple MAX_MIN(int data[], int left, int right)
{
  struct couple max_min;

  //case_1:
  if(left == right)                                           //the array or subarray has one element
  {
    max_min.max = max_min.min = data[left];
    return max_min;
  }
  //case_2:
  /*else if((left+1) == right)                                  //the array or subarray has two elements
  {
    if(data[left] > data[right])
    {
      max_min.max = data[left];
      max_min.min = data[right];
    }
    else
    {
      max_min.max = data[right];
      max_min.max = data[left];
    }
    return max_min;
  }*/
  //case_3:
  else                                                        //the array or subarray has more than two elements
  {
    struct couple right_subarray;
    struct couple left_subarray;
    int mid;

    mid = (left + right)/2;

    //recursion is happening here
    left_subarray = MAX_MIN(data, left, mid);
    right_subarray = MAX_MIN(data, mid+1, right);

    if(left_subarray.max > right_subarray.max)
      max_min.max = left_subarray.max;
    else
      max_min.max = right_subarray.max;

    if(left_subarray.min < right_subarray.min)
      max_min.min = left_subarray.min;
    else
      max_min.min = right_subarray.min;

    step_required++;

    return max_min;
  }
}


//main function
int main(void)
{
  ifstream read_file("input.txt");
  int INPUT_SIZE;
  int iterator;
  struct couple max_min;

  cout << "Enter input size: ";
  cin >> INPUT_SIZE;

  int input[INPUT_SIZE];

  for(iterator=0; iterator<INPUT_SIZE; iterator++)
    read_file >> input[iterator];

  max_min = MAX_MIN(input, 0, INPUT_SIZE-1);

  cout << "Max = " << max_min.max << endl;
  cout << "Min = " << max_min.min << endl;

  cout << "Required steps = " << step_required << endl;
}
