#include<iostream>
#include<thread>
#include<conio.h>
using namespace std;
void hello(void)
{
    for(int i=0;i<10;i++)
        cout<<"Hello concurrent world!!!"<<endl;
    for(int i=0;i<1000;i++);
}
void hi(void)
{
    for(int i=0;i<10;i++)
    cout<<"this is another thread!!!"<<endl;
}
void again(void)
{
    cout<<"third thread"<<endl;
}
int main(void) ///a thread gets started here               ///this thread is default
{
    thread t(hello);///input is the function name
                    ///another thread  i.e. thread 2 gets called and as an argument a function is called
    t.join();
    thread t2(hi);
    t2.join();
    getch();
    return 0;
}
