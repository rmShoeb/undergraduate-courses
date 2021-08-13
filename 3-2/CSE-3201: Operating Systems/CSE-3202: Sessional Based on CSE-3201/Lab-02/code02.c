#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int a=10;
    int id;
    
    id=fork();
    
    if(id==0)
    {
        //child
        a=200;
        printf("Inside child with PID %d and a=%d\n", (int)getpid(), a);
    }
    if(id>0)
    {
        //parent
        printf("Inside parent with PID %d and a=%d\n", (int)getpid(), a);
        a=420;
    }
    //fork fail korle -1 return kore
    printf("PID %d and a=%d\n", (int)getpid(), a);
    return 0;
}
