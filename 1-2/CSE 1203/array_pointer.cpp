#include<iostream>
using namespace std;

int main(void)
{
    int *p, i[10];
    p = i;
    p[5] = 100; /* assign using index */
    cout<<p[5]<<endl;
    *(p+5) = 100; /* assign using pointer arithmetic */
    cout<<*(p+5)<<endl;
}
