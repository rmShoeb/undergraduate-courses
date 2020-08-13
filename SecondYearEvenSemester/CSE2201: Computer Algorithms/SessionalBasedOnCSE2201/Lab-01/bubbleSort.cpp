#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;

int main(void)
{
  ifstream read_file("input.txt");                  //for reading from the file
  int input[40000];                                   //to store the inputs
  int i, j;                                         //for the use of iteration
  int temp;
  int n = 40000;                                      //number of elements in the array
  double start;                                     //to save the time of starting
  double stop;                                      //to save the time of stopping

  if(read_file.is_open())                           //to check if the file is open or not
  {
    for(i=0; i<n && !read_file.eof(); i++)          //eof() ensures that the file is not at end
    {
      read_file >> input[i];                        //reading from the file
    }
    read_file.close();                              //closing the file
  }
  else
    cout << "Failed to open input file" << endl;

  start = clock();
  for(i=0; i<n; i++)
  {
    for(j=i; j<n; j++)
    {
      if(input[i] > input[j])
      {
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
      }
    }
  }
  stop = clock();

  for(i=0; i<n; i++)
    cout << input[i] << endl;
  cout << (stop - start);
}
/*
*2000->30
*5000->90
*10000->273
*20000->938
*30000->1894
*40000->3189
*50000->4866
*/
