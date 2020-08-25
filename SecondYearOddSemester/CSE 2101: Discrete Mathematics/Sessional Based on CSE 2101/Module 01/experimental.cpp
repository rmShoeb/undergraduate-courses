/**
    edited_by rmShoeb_CSE_16_RUET
    this program takes a string as input, evaluates the expression and shows result after calculation
    have fun :)
**/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int temp_stack[20];
int position=-1;

void push(int x)
{
    if(position<20)
    {
        position++;
        temp_stack[position]=x;
    }
}

int pop(void)
{
    int temp;
    if(position>=0)
    {
        temp=temp_stack[position];
        position--;
        return temp;
    }
}

int main(void)
{
    char expression[20];
    int len;
    int i;
    int temp;
    int p,q,ans;
    int ck;

    while(1)
    {
        printf("1.Evaluate in Postfix\n2.Evaluate in Prefix\n3.Evaluate in Infix\n4.Exit\n");
        cout<<"  Enter your choice: ";
        cin>>ck;

        switch(ck)
        {
        case 1:
            {
                cout<<"Enter your expression in Postfix: ";
                cin>>expression;

                len=strlen(expression);
                for(i=0;i<len;i++)
                {
                    if(expression[i]=='+')
                    {
                        q=pop();
                        p=pop();
                        ans=p+q;
                        push(ans);
                    }
                    else if(expression[i]=='-')
                    {
                        q=pop();
                        p=pop();
                        ans=p-q;
                        push(ans);
                    }
                    else if(expression[i]=='*')
                    {
                        q=pop();
                        p=pop();
                        ans=p*q;
                        push(ans);
                    }
                    else if(expression[i]=='/')
                    {
                        q=pop();
                        p=pop();
                        ans=p/q;
                        push(ans);
                    }
                    else
                    {
                        temp=expression[i]-48;
                        push(temp);
                    }
                }
                cout<<pop()<<endl;
                break;
            }

        case 2:
            {
                cout<<"Enter your expression in prefix: ";
                cin>>expression;

                len=strlen(expression)-1;
                for(i=len;i>=0;i--)
                {
                    if(expression[i]=='+')
                    {
                        p=pop();
                        q=pop();
                        ans=p+q;
                        push(ans);
                    }
                    else if(expression[i]=='-')
                    {
                        p=pop();
                        q=pop();
                        ans=p-q;
                        push(ans);
                    }
                    else if(expression[i]=='*')
                    {
                        p=pop();
                        q=pop();
                        ans=p*q;
                        push(ans);
                    }
                    else if(expression[i]=='/')
                    {
                        p=pop();
                        q=pop();
                        ans=p/q;
                        push(ans);
                    }
                    else
                    {
                        temp=expression[i]-48;
                        push(temp);
                    }
                }
                cout<<pop()<<endl;
                break;
            }

        case 3:
            {
                cout<<"update coming soon..."<<endl;
                break;
            }

        case 4:
            return 0;

        default:
            cout<<"Are you an idiot??? Why the heck you entered a wrong choice???\n";
            cout<<"Try again you dickhead"<<endl;
        }
    }
}
