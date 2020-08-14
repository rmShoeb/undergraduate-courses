#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int main(void)
{
    FILE *fp;
    fp=fopen("file.txt","r");
    int i;  ///looping variable
    //int arr;
    int temp;
    int x; ///variable to save the expecting data
    printf("Enter data to check: ");
    scanf("%d",&x);
    clock_t start=clock();
    for(i=0;i<10000;i++)
    {
        fscanf(fp,"%d",&temp);
        if(temp==x)
            printf("Data is found at position %d\n",i+1);
    }
    clock_t stop=clock();
    printf("%f",(stop-start));
    fclose(fp);
    getch();
    return 0;
}
