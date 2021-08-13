/**
    this_code_is_the_implementation_of_stack_using_array
    editor_rmShoeb
    started_at_1445_1/5/2018
    finished_at_1515_1/5/2018
**/
#include<stdio.h>
#include<stdlib.h>
#define n 10

int stack[n];
int top=-1;

void push(void)
{
    int data;
    if(top<n-1)
    {
        top++;
        printf("Enter your data to insert: ");
        scanf("%d",&stack[top]);
    }
    else
        printf("Stack full...\n\n");
}

void pop(void)
{
    if(top<0)
        printf("Stack empty...\n\n");
    else
        top--;
}

void display(void)
{
    int i;
    if(top<0)
        printf("Stack empty...\n\n");
    else
    {
        for(i=0;i<=top;i++)
            printf("%d ",stack[i]);
        printf("\n\n");
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
            printf("Wrong input...\n\n");
        }
    }
}
