#include<iostream>
using namespace std;
int main(void)
{
    /*int x(17);
    int y(42);
    int *p1(&x);
    cout<<"p1-&y="<<(int)(p1-&y)<<endl;
    cout<<"p1= "<<hex<<(int)p1<<", *p1= "<<dec<<(int)*p1<<endl;
    //--p1;
    cout<<"p1= "<<hex<<(int)p1<<", *p1= "<<dec<<(int)*p1<<endl;
    cout<<"&y= "<<hex<<(int)&y<<", y= "<<dec<<(int)y<<endl;
    (*p1)++;
    cout<<"p1= "<<hex<<(int)p1<<", *p1= "<<dec<<(int)*p1<<endl;
    cout<<"&x= "<<hex<<(int)&x<<", x= "<<dec<<(int)x<<endl;*/
    const int arr[]={1,2,3,4,5,6,7,8};
    const int *p(arr);
    for(int i=0;i<8;i++)
        cout<<*p++<<endl;
}
