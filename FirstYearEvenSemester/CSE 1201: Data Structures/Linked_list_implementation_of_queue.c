/**
    editor_rmShoeb
    started_at_1445_1/6/2018
    finished_at_
**/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*front,*rear;

void create(void)
{
    front=(struct node*)malloc(sizeof(struct node));
    rear=front;
    rear->next=0;
}

void enqueue(void)
{
    int data;
    printf("Enter your data: ");
    scanf("%d",&data);

    rear->data=data;
    rear->next=(struct node*)malloc(sizeof(struct node));
    rear=rear->next;
    rear->next=0;
}

void dequeue(void)
{
    if(front==rear)
        printf("Memory empty...\n");
    else
    {
        front=front->next;
    }
}

void display(void)
{
    if(front==rear)
        printf("Memory empty\n\n");
    else
    {
        struct node* temp;
        temp=front;
        while(temp!=rear)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n\n");
    }
}

int main(void)
{
    int ck;
    printf("Creating space for you...\n\n");
    create();

    while(1)
    {
        printf("1. Insert Data\n2. Delete data\n3. Display data\n4. Exit\n\n");
        printf("   Enter your choice: ");
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
            printf("Wrong input...\n\n");
        }
    }
}
