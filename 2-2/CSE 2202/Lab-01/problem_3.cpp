#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

int main(void)
{
  ifstream read_file("input.txt");                  //for reading from the file
  int input[200];                                   //to store the inputs
  int i, j, k, n = 200;
  double start;                                     //to store the time of starting
  double stop;                                      //to store the time of stopping

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
  start = clock();                                  //start time in ms
  for(i=0; i<n-2; i++)
    for(j=i+1; j<n-1; j++)
      for(k=j+1; k<n; k++)
        if(input[i] + input[j] + input[k] == 0)
          cout << input[i] << " " << input[j] << " " << input[k] << endl;
  stop = clock();                                   //stop time in ms

  cout << (stop - start)/1000;
}
/**
*time count
*100->0.074second
*200->0.666second
*500->9.732second
*1000->43.979second
*2000->333.149second
*/
