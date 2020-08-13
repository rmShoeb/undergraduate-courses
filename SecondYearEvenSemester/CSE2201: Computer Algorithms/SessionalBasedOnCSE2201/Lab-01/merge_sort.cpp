#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>                                  //for calculating time using clock()
#include <fstream>                                //for file handling
#include <algorithm>
using namespace std;

//user-defined functions
void merge(int input[], int l, int m, int r)
{
  int i, j, k;                                    //for the use of iteration
  int n1 = m-l+1;                                 //denotes the number of element in the left subarray
  int n2 = r-m;                                   //denotes the number of element in the right subarray
  int L[n1];                                      //the left subarray
  int R[n2];                                      //the right subarray

  for (i=0; i<n1; i++)                            //dividing into left subarray
    L[i] = input[l+i];
  for (j=0; j<n2; j++)                            //dividing into right subarray
    R[j] = input[m+1+j];

  i = 0;                                          // Initial index of first subarray
  j = 0;                                          // Initial index of second subarray
  k = l;                                          // Initial index of merged subarray

  //the sorting part
  while(i<n1 && j<n2)
  {
    if(L[i] <= R[j])
    {
      input[k] = L[i];
      i++;
    }
    else
    {
      input[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1)                                   //copying the data left in the left subarray, if any
  {
    input[k] = L[i];
    i++;
    k++;
  }

  while(j < n2)                                     //copying the data left in the right subarray, if any
  {
    input[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int input[], int l, int r)
{
  int m;                                           //for middle index of subarray

  if(l<r)
  {
    m = (l+r-1)/2;
    mergeSort(input, l, m);                        //sorting the left subarray
    mergeSort(input, m+1, r);                      //sorting the right subarray
    merge(input, l, m, r);                           //merging the subarrays
  }
}


//main function
int main(void)
{
  ifstream read_file("input.txt");                  //for reading from the file
  int input[400];                                   //to store the inputs
  int i, j;                                         //for the use of iteration
  int n = 400;                                      //number of elements in the array
  //clock_t start;                                     //to save the time of starting
  //clock_t stop;                                      //to save the time of stopping
  clock_t time_needed;

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

  //start = clock();
  time_needed = clock();
  mergeSort(input, 0, n-1);                         //calling the mergeSort function
  //stop = clock();
  time_needed = clock() - time_needed;

  for(i=0; i<n; i++)
    cout << input[i] << endl;
  //cout << (stop - start);
  cout << "Clock cycles:" << time_needed << endl;
}
/*
*2000->~0
*5000->9
*10000->
*20000->
*30000->
*50000->10
*/
