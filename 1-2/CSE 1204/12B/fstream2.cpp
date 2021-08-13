#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
int main(void)
{
    srand(time(0));
    ofstream out("D:\\1st year even sem\\foo.temp",ios::app/*,0644*/);  ///apend
    out<<"A random number: "<<rand()<<endl;
    out.close();
}
