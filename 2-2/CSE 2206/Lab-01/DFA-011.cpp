#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iterator>
using namespace std;

int main(void)
{
  string input_string;
  int string_length;
  int string_iterator;
  string state;
  vector <string> path;
  vector <string>::iterator path_iterator;

  cout << "Enter string: ";
  cin >> input_string;

  cout << "Transition table:\n\
       || 0  | 1\n\
  ===============\n\
  ->q0 || q1 | q0\n\
  _______________\n\
    q1 || q1 | q2\n\
  _______________\n\
    q2 || q1 | q3\n\
  _______________\n\
   *q3 || q3 | q3" << endl;

  state = "q0";
  path.push_back(state);

  string_length = input_string.size();

  for(string_iterator=0; string_iterator<string_length; string_iterator++)
  {
    if(state == "q0")
    {
      if(input_string[string_iterator] == '0')
        state = "q1";
      else
        state = "q0";
    }
    else if(state == "q1")
    {
      if(input_string[string_iterator] == '0')
        state = "q1";
      else
        state = "q2";
    }
    else if(state == "q2")
    {
      if(input_string[string_iterator] == '0')
        state = "q1";
      else
        state = "q3";
    }
    else
      state = "q3";
    path.push_back(state);
  }

  if(state == "q3")
    cout << "Accepted" << endl;
  else
    cout << "Not accepted" << endl;

  cout << "Path->";
    for(path_iterator=path.begin(); path_iterator!=path.end(); path_iterator++)
    cout << "->" <<*path_iterator;
  cout << endl;
}
