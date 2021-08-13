#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(void)
{
    //char a[100];
    string a;
    fstream file("zozo.txt");
    file<<"Dunia_bohut_khrap_hoye_geche";
    file>>a;
    //puts(a);
    cout<<a<<endl;
    file.close();
}
