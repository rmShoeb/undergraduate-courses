/**
    editor_rmShoeb
    started_at_1305_1/6/2018
    finished_at_1345_1/6/2018
**/
#include<stdio.h>
#include<stdlib.h>
#define n 10

int q[n];
int front=-1;
int rear=-1;

int isEmpty(void)
{
    if(front==-1&&rear==-1)
        return 1;
    else
        return 0;
}

void enqueue(void)
{
    if((rear+1)%n==front)
        printf("Memory Full...\n");
    else
    {
        if(isEmpty())
            front=rear=0;
        else
            rear=(++rear)%n;

        printf("Enter your data: ");
        scanf("%d",&q[rear]);
    }
}

void dequeue(void)
{
    if(isEmpty())
        printf("Memory Empty...\n");
    else if(front==rear)
        front=rear=-1;
    else
        front=(++front)%n;
}

void display(void)
{
    if(isEmpty())
        printf("Memory Empty...\n\n");
    else
    {
        int i=front;
        while(i!=rear)
        {
            printf("%d ",q[i]);
            i++;
            i%=n;
        }
        printf("%d\n\n",q[i]);
    }
}

int main(void)
{
    int ck;

    while(1)
    {
        printf("1. Insert Data\n2. Delete Data\n3. Display Data\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ck);

        switch(ck)
        {
        case 1:
            enqueue();
            printf("\n");
            break;

        case 2:
            dequeue();
            printf("\n");
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Wrong Choice...\n\n");
        }
    }
}
