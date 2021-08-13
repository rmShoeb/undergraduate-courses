#include <cstdio>                                       //for standard input output handling
#include <iostream>                                     //for input output stream handling
#include <cstdlib>                                      //for standard libray handling......srand()
#include <ctime>                                        //time()
using namespace std;


//user-defined function
void swap(int* a, int* b)                               //to swap two numbers
{
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

int FindPosition(int array[], int first, int last)      //find position of pivot
{
  int pivot = array[first];
  int position = last+1;                                //let's guess, the pivot is in the last position
  int iterator;

  for(iterator=last; iterator>first; iterator--)
  {
    if(pivot <= array[iterator])
    {
      position--;
      swap(&array[iterator], &array[position]);
    }
  }
  swap(&array[first], &array[position-1]);
  return position;
}


//main function
int main(void)
{
  int INPUT_SIZE;
  int iterator;
  int PIVOT_POSITION;

  cout << "Enter size of the input: ";
  cin>>INPUT_SIZE;
  int data[INPUT_SIZE];

  srand(time(0));

  for(iterator=0; iterator<INPUT_SIZE; iterator++)
  {
    data[iterator]= rand()%1001;
    cout << data[iterator] << endl;
  }

  PIVOT_POSITION = FindPosition(data, 0, INPUT_SIZE-1);

  cout<<"Position: "<< PIVOT_POSITION << endl;
  for(iterator=0; iterator<INPUT_SIZE; iterator++)
    cout << data[iterator] << endl;
}
