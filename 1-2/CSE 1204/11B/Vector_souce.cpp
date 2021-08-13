#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
using namespace std;
int main(void)
{
    /*vector<int>v={5,7,9,4,6,8};
    cout<<v.size()<<endl;
    cout<<v[0]<<" "<<v[1]<<endl;
    vector<double>u={1.2,2.3,3.4};
    u[0]=v[0];
    cout<<u[0]<<endl;
    for(int x:v)
        cout<<x<<ends;
    cout<<endl;*/

    vector<int>lit;
    for(int temp;cin>>temp;)
        lit.push_back(temp);
    for(int x:lit)
        cout<<x<<ends;
    cout<<endl;
    int number;
    cin>>number;
    cout<<number<<endl;
    vector<string>vs;
    for(string temp;cin>>temp;)
        vs.push_back(temp);
    for(string x:vs)
        cout<<x<<ends;
    cout<<endl;
    /*vector<int>vi(6);
    cout<<vi.size()<<endl;
    cout<<vi[0]<<" "<<vi[1]<<endl;

    vector<double>age;
    cout<<age.size()<<endl;
    age.push_back(20.0);
    cout<<age.size()<<endl;

    vector<string>name={"Plato","Aristotle"};
    cout<<name.size()<<endl;*/
}
