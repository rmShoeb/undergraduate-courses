#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
    vector<int>v={5,7,4,9,6,8};                 ///vector of 6 elements
    //vector<string>philosopher={"Plato","Hume"}; ///vector of 2 strings
    //vector<int>v(6);                            ///vector of 6 integers and initialized to 0
    //vector<string>v(4);                         ///vector of 4 strings and initialized to empty string
    //v[7] ///error
    ///traversing a vector
    cout<<v.size();        ///size() is a member function of the vector class
    //for(int i=0;i<v.size();++i)
      //  cout<<v[i];
    ///range [0-v.size()]
    ///first element v[0]
    ///last element v[v.size()-1]
    //for(int x:v)                              ///for each x->v
      //  cout<<x;                              ///range for-loop
    ///line 13 and line 18 means same
    ///how to grow a vector?
    ///push_back(parameter) method*/
    //vector<double>v;        ///size of v is now 0
    //v.push_back(5.1);
    //cout<<v[0]<<endl;
    //v.push_back(1);
    //cout<<v[1]<<endl;
    //v.push_back(x);
    //cout<<v[2]<<endl;
    vector<double>temps;
    int i=0;
    for(double temp;cin>>temp/*condition part*/;)
    {
        temps.push_back(temp);
        cout<<temps[i]<<endl;
        i++;
    }
}
