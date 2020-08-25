#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

int main(void)
{
    int n;
    vector<int>input;
    int i;
    int maximum;
    int temp;

    printf("Enter the size of your input: ");
    cin>>n;
    printf("Enter the data:\n");
    for(i=0;i<n;i++)
    {
        cin>>temp;
        input.push_back(temp);
    }

    maximum=input[0];
    for(i=1;i<n;i++)
    {
        if(input[i]>maximum)
            maximum=input[i];
    }

    printf("The largest number is: ");
    cout<<maximum<<endl;
}
