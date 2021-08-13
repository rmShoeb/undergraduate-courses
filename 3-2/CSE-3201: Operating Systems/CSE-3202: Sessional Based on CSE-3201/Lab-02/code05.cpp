#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<iostream>
#include<sys/wait.h>
#include<sys/types.h>
#include<cstring>
using namespace std;

int main()
{
    char* args[3];
    string fileLocation="/media/rmshoeb/Porashuna/3rd_year_even_sem/CSE_3202/lab_02/./code03";
    
    args[0] = (char*)fileLocation.c_str();
    args[1]=NULL;
    
    int id = fork();
    
    if(id==0)
    {
        cout << "child id: " << getpid() << endl;
        if(execvp(args[0], args) == -1)//execvp takes an array of pointer to char and loops though the second parameter args as long as null is found
        {
            cout << "error" << endl;
        }
    }
    if(id>0)
    {
        //parent
        cout << "parent id: " << getpid() << endl;
    }
    
    return 0;
}
