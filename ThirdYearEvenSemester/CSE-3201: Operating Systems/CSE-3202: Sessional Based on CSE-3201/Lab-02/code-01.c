#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int a=100;
    
    fork();
    fork();
    
    printf("%d\n", a);
    
    return 0;
}
