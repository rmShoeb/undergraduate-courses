/**
    this_code_is_the_implementation_of_single_linear)linked)list
    editor_rmShoeb
    started_at_1400_1/4//2018
    finished_at_2230_1/4/2018
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
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    h=p;
    p->next=0;
}

void insert(int n)
{
    struct node* p;
    p=h;
    while(p->next!=0)   ///traversing to find the last node
    {
        p=p->next;
    }
    p->data=n;
    p->next=(struct node*)malloc(sizeof(struct node));
    p=p->next;
    p->next=0;
}

void insertp(int pos, int data)
{
    int i;
    struct node *p;
    struct node *temp;
    p=h;
    temp=(struct node*)malloc(sizeof(struct node));

    if(pos==1)
    {
        temp->data=data;
        temp->next=h;
        h=temp;
    }
    else
    {
        for(i=1;i<pos-1;i++)
            p=p->next;

        temp->data=data;
        temp->next=p->next;
        p->next=temp;
    }
}

void del(int pos)
{
    struct node* p;
    struct node* temp;
    int i;
    p=h;

    if(pos==1)
        h=p->next;
    else
    {
        for(i=1;i<pos-1;i++)
            p=p->next;

        temp=p->next;
        p->next=temp->next;
    }
    free(temp);
}

void reverse(void)
{
    struct node* p;
    struct node* prev;
    struct node* next;
    p=h;

    prev=(struct node*)malloc(sizeof(struct node));
    prev.next=0;
    next=p->next;
    while(next!=0)
}

void display (void)
{
    struct node* p;
    p=h;
    while(p->next!=0)   ///printing the elements
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(void)
{
    int ck;
    int data;
    int in;
    int pos;

    printf("Creating space for your work......\n");
    create();

    while(1)
    {
        printf("1. Insert Data\n2. Delete data\n3. Display data\n4. Reverse\n5. Exit\n");
        printf("   Enter your choice: ");
        scanf("%d",&ck);

        switch(ck)
        {
        case 1:
            printf("1. Insert data at the end\n2. Insert Data at a particular position\n");
            printf("   Enter your choice: ");
            scanf("%d",&in);
            switch(in)
            {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                insert(data);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d",&pos);
                printf("Enter data: ");
                scanf("%d",&data);
                insertp(pos, data);
                break;

            default:
                printf("Wrong input.....\n");
            }
            break;

        case 2:
            printf("enter the position of the number you want to delete: ");
            scanf("%d",&pos);
            del(pos);
            break;

        case 3:
            display();
            break;

        case 4:
            reverse();
            break;

        case 5:
            return 0;

        default:
            printf("Wrong input.....\n");
        }
    }
}
