#include<stdio.h>
#include<stdlib.h>


void create(int n);
void push(void);
void pop(void);
void disp(void);


struct node
{
    int data;
    struct node *next;
}*h,*p,*q;


void create(int n)
{
    int i,x;
    h=0;
    q=0;
    for(i=0;i<n;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        printf("Enter x: ");
        scanf("%d",&x);
        ///printf("Address of this data: %x\n",p);
        p->data=x;
        if(h==0)
        {
            h=p;
        }
        if(q!=0)
        {
            q->next=p;
        }
        q=p;
    }
    q->next=0;
}


void push(void)
{
    int x,y;
    q=h;
    printf("Enter y: ");
    scanf("%d",&y);
    while(q!=0)
    {
        if(q->data==y)
        {
            p=(struct node*)malloc(sizeof(struct node));
            printf("Enter element: ");
            scanf("%d",&x);
            p->data=x;
            p->next=q->next;
            q->next=p;
        }
    }
}


void pop(void)
{
    int y;
    q=h;
    p=0;
    printf("Enter y: ");
    scanf("%d",&y);
    if(q!=0)
    {

    }
}


void disp(void)
{
    p=h;
    while(p!=0)
    {
        printf("%x %d %x\n", p,p->data,p->next);
        p=p->next;
    }
}


int main(void)
{
    int ck;
    int i,n;
    printf("Enter initial value: ");
    scanf("%d",&n);
    create(n);
    while(1)
    {
        printf("1. Enter data\n2. Delete data\n3. Display data\n4. Exit\n   Enter your choice: ");
        scanf("%d",&ck);
        switch(ck)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            disp();
            break;
        case 4:
            return 0;
        default:
            printf("Wrong Choice.\n");
        }
    }
}
