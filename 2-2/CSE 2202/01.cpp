#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  ifstream read_file("input.txt");
  int iterator;
  int INPUT_SIZE;
  int temp;
  vector <int> data;
  int left_index;
  int right_index;

  cout << "Enter input size: ";
  cin >> INPUT_SIZE;

  if(read_file.is_open())
  {
    for(iterator=0; iterator<INPUT_SIZE; iterator++)
    {
      read_file >> temp;
      data.push_back(temp);
    }
    read_file.close();
  }
  else
    cout << "Failed to open file" << endl;

  sort(data.begin(), data.end());

  for(iterator=0; iterator<INPUT_SIZE-2; iterator++)
  {
    left_index = iterator+1;
    right_index = INPUT_SIZE-1;

    while(left_index < right_index)
    {
      if((data[iterator] + data[left_index] + data[right_index]) == 0)
      {
        cout << data[iterator] << " + " << data[left_index] << " + " << data[right_index] << " = 0" << endl;
        left_index++;
        right_index--;
      }
      else if((data[iterator] + data[left_index] + data[right_index]) < 0)
        left_index++;
      else
        right_index--;
    }
  }
}
