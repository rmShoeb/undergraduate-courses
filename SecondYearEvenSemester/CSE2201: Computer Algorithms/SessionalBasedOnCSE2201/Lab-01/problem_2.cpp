#include <iostream>
#include <cstdlib>
#include <ctime>                                  //for calculating time using clock()
#include <fstream>                                //for file handling
#include <utility>                                //to use the "pair"
using namespace std;

//global variables
pair <bool, int> p;                               //to get the search result

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

  while(i < n1)                                     //copying the data left in the left subarray, if any
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

void search(int input[], int x, int left, int right) //to search the array
{
  int mid;

  p = make_pair(false, 0);                         //first guessing that the data is not there
  while (left <= right)
  {
    mid = (left+right)/2;
    if(input[mid] == x)
    {
      p = make_pair(true, input[mid]);              //true to denote that the data is found
      break;
    }
    else if(input[mid] > x)
      right = mid - 1;
    else
      left = mid + 1;
  }
}


//main function
int main(void)
{
  ifstream read_file("input.txt");                  //for reading from the file
  int input[2000];                                   //to store the inputs
  int i, j;                                         //for the use of iteration
  int n = 2000;                                      //number of elements in the array
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

  mergeSort(input, 0, n-1);                         //calling the mergeSort function

  start = clock();
  for(i=0; i<n-1; i++)
  {
    for(j=i+1; j<n; j++)
    {
      search(input, -input[i]-input[j], j, n-1);
      if(p.first)
        cout << input[i] << " " << input[j] << " " << p.second << endl;
    }
  }
  stop = clock();

  cout << (stop - start)/1000;
}
/**
*100->0.186
*200->1.413
*500->16.246
*1000->82.852
*2000->172.758
*/
