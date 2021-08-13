#include<iostream>
#include<new>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int *p;
    try
    {
        p = new int; // allocate space for an int
    }
    catch (bad_alloc xa)
    {
        cout << "Allocation Failure\n";
        return 1;
    }

    *p = 100;
    cout << "At " << p << " ";
    cout << "is the value " << *p << "\n";
    delete p;
    cout<<"again "<<*p<<endl;           ///why_the_fuck_p_is_not_deleted???????/
    return 0;
}
