/**
    editor_rmShoeb
    started_at_1530_1/5/2018
    finished_at_
**/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*h;

void create(void)
{
    h=0;
}

void push(void)
{
    struct node* p;
    int data;

    p=(struct node*)malloc(sizeof(struct node));

    printf("Enter data to insert: ");
    scanf("%d",&data);

    p->data=data;
    p->next=h;
    h=p;
}

void pop(void)
{
    struct node* p;
    p=h;

    if(p!=0)
    {
        h=p->next;
    }
    else
        printf("Stack empty...\n\n");
}

void display(void)
{
    struct node* p;
    p=h;

    if(p!=0)
    {
        while(p!=0)
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }
    else
        printf("Stack Empty...");
    printf("\n\n");
}


int main(void)
{
    int ck;
    printf("Creating space for you...\n\n");
    create();

    while(1)
    {
        printf("1. Insert data\n2. Delete data\n3. Display data\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ck);

        switch(ck)
        {
        case 1:
            push();
            printf("\n");
            break;

        case 2:
            pop();
            printf("\n");
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Wrong choice...\n\n");
        }
    }
}
