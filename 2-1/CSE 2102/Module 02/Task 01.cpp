#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<cstring>
#include<ctype.h>
#include<algorithm>
using namespace std;

void aUb(char a[],char b[])
{
    int i=0;
    int j=0;
    vector<char>Union;

    while(a[i]!='\0'&&b[j]!='\0')
    {
        if(a[i]==b[j])
        {
            Union.push_back(a[i]);
        }
        else if(a[i]>b[j])
        {
            Union.push_back(b[j]);
            Union.push_back(',');
            Union.push_back(a[i]);
        }
        else
        {
            Union.push_back(a[j]);
            Union.push_back(',');
            Union.push_back(b[i]);
        }
        i++;
        j++;
    }
    while(a[i]!='}'||a[i]!='\0')
    {
        Union.push_back(a[i]);
        i++;
    }
    while(b[j]!='\0')
    {
        Union.push_back(b[j]);
        j++;
    }
    Union.push_back('\0');

    for(i=0;Union[i]!='\0';i++)
        cout<<Union[i];
    cout<<endl;
}


int main(void)
{
    char set_a[100];
    char set_b[100];

    cout<<"Enter Set A: ";
    cin>>set_a;
    cout<<"Enter Set B: ";
    cin>>set_b;

    aUb(set_a, set_b);
}
