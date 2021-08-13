#include<stdio.h>

int n = 4;
int arr[5];
int rear = -1;
int front = -1;
int x,y,option;
void enqueue()
{
    if(rear == n-1)
    {
        rear = -1;
        if(rear == front)
        {
            printf("Queue Is Full\n");
            rear = n-1;
        }
        else
        {
            printf("Enter the element to push : ");
            scanf("%d",&x);
            arr[rear] = x;
            printf("Pushed element is %d\n",x);
        }
    }
    else
    {
        if(rear + 1 == front)
        {
            printf("Queue is full\n");
        }
        else
        {
            printf("Enter the element to push: ");
            scanf("%d",&x);
            arr[++rear] = x;
            printf("Pushed element is %d\n",x);
        }
    }
}
void dequeue()
{
    if(rear == front)
    {
        printf("The queue is empty\n");
    }
    else
    {
        if(front == n - 1)
        {
            front = 0;
        }
        else
        {
            front++;
            x = arr[front];
            printf("Deleted element is %d\n",x);
        }
    }
}
void display()
{
    int i;
    if(rear==front)
        printf("Queue is empty.\n");
    else
    {
        for(i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
int menu()
{
    int q;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("  Choose an option : ");
    scanf("%d",&q);
    return q;
}
int main(void)
{
    while(1)
    {
        option = menu();
        if(option == 4)
            break;
        switch(option)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Wrong Choice.\n");
                break;
        }
    }
    return 0;
}
