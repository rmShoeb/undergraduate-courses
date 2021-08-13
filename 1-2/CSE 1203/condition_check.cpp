#include<iostream>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    if(n%4==(1||3)||n%2==0)      /*ami bhabchilam n mod 4 equals 1 or 3 hoiche kina ta check
                                 korar jonno ei system e likhle kaj korbe. well, although there
                                 is no compilation error, it has logical error.
                                 which means, the compiler will check if the mod is equal to 1 or
                                 not, but ignores 3.
                                 so the code will be
                                 if(n%4==1||n%4==3||n%2==0)*/
        cout<<"get lost"<<endl;
    else
        cout<<"get out"<<endl;
}
