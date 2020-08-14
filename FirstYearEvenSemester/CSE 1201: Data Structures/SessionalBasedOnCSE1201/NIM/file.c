#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    FILE *fp;
    fp=fopen("file.txt","w");
    int i;
    int temp;
    srand(time(0));
    for(i=0;i<10000;i++)
    {
        temp=rand()%1000;
        fprintf(fp,"%d ",temp);
    }
    fclose(fp);
    return 0;
}
