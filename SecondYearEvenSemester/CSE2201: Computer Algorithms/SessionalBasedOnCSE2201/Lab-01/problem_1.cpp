#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

int main(void)
{
  ofstream input_file("input.txt");                 //for storing input data
  int n,i;                                          //for saving the number of inputs

  srand(time(0));                                   //
  cout << "Enter the number of input: ";
  cin >> n;

  if(input_file.is_open())                          //checking if the file is open or not
  {
    for(i=0; i<n; i++)
      input_file << ((rand()%2000)-1000) << "\n";                 //taking input to the file randomly

    input_file.close();                             //closing the file
  }
  else                                              //the file coud not be opened
    cout << "Failed to open file to write" << endl;
}
