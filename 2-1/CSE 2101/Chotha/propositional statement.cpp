#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;
#define nt 51
#define nd 50
#define orr 49
#define imp 48
void infix_postfix(char infix[20],char postfix[20]);
bool post_value(string str,bool T1,bool T2);
void justify_stm(char infix[],bool truth_table[]);
void equivalent_stm(char infix1[],char infix2[],bool truth_table[]);
int main()
{
    bool truth_table[] = {false,false,false,true,true,false,true,true};
    int select;
    char infix[20],infix1[20],infix2[20],postfix[20];
    while(true)
    {
        cout<<"\n1 : Justify\n2 : Equivalent  :";
        cin>>select;
        //gets(infix);
        switch(select)
        {
        case 1:
            cout<<"\nEnter one statement :";
            cin>>infix;
            justify_stm(infix,truth_table);
            break;
        case 2:
            cout<<"\nEnter first statement :";
            cin>>infix1;
            cout<<"\nEnter second Statement : ";
            cin>>infix2;
            equivalent_stm(infix1,infix2,truth_table);
            break;
        case 0:
            exit(0);
            break;
        }


    }
}
void equivalent_stm(char infix1[],char infix2[],bool truth_table[])
{
    strupr(infix1);
    strupr(infix2);
    bool result1[10],result2[10];
    char postfix1[50],postfix2[50],FLAG=true;
    int top=-1;
    infix_postfix(infix1,postfix1);
    infix_postfix(infix2,postfix2);
    for(int K=0; K<4; K++)
    {
        result1[K] = post_value(postfix1,truth_table[++top],truth_table[++top]);
        result2[K] = post_value(postfix2,truth_table[top-1],truth_table[top]);
        // cout<<result1[K]<<" "<<result2[K];
        if(result1[K] != result2[K])
        {
            FLAG = false;
            //cout<<postfix1;
            break;
        }
    }
    if(FLAG)
        cout<<"\nThey are Equivalent ...";
    else cout<<"\n They are not Equivalen !!";
}
void justify_stm(char infix[],bool truth_table[])
{
    strupr(infix);
    bool result[10];
    char postfix[50];
    int top=-1;
    char FLAG=true;
    infix_postfix(infix,postfix);
    cout<<"\nfor combination (F-F,F-T,T-F,T-T -->output : ";
    for(int K=0; K<4; K++)
    {
        result[K] = post_value(postfix,truth_table[++top],truth_table[++top]);
        cout<<result[K]<<" ";
    }
    for(int K= 1; K<4; K++)
    {
        if(result[0]!=result[K])
        {
            FLAG = false;
            break;
        }

    }
    if(FLAG)
    {
        if(result[0])
            cout<<"\n\tThis statement is a taughtology";
        else
            cout<<"\n\tThis statement is a contradiction";
    }
    else
        cout<<"\n\tThis is a contigency";
}


void infix_postfix(char infix[20],char postfix[20])
{
    char temp[20],c,ff=0;
    int k,m,top,ttop,n;
    strupr(infix);
    n=strlen(infix);
    infix[n]=')';
    temp[0]='(';
    top=-1;
    ttop=0;
    for(k=0; k<=n; k++)
    {
        c = infix[k];
        // cout<<"C = "<<c;
        if(c>='A' && c<='Z')
        {
            if(ff == 0)
                ff = c;
            if(c==ff)
                postfix[++top]='T';
            else postfix[++top] = 'F';
        }

        else if(c=='(')
            temp[++ttop]=c;
        else if(c==')')
        {
            //cout<<temp[0]<<temp[1]<<temp[2];
            while(5)
            {
                //cout<<" *";
                if(temp[ttop]=='(')
                {
                    ttop--;
                    break;
                }
                else
                    postfix[++top]=temp[ttop];
                ttop--;
            }
        }
        else //if(c=='-')
        {

            switch(c)
            {
            case '!':
                c=nt;
                break;
            case '^':
                c=nd;
                break;
            case '|':
                c = orr;
                break;
            case '~':
                c = imp;
                break;

            }

            while(5)
            {

                if(temp[ttop]!='(' && temp[ttop]>=c)
                {
                    postfix[++top] =temp[ttop--];
                }
                else break;
            }
            temp[++ttop] = c;
        }
    }

    postfix[++top]='\0';

}
bool post_value(string str,bool T1,bool T2)
{
    int size = str.length();
    char c;
    bool p,q;
    stack<bool>value;
    for(int K=0; K<size; K++)
    {
        c=str[K];
        if(c=='T' )
            value.push(T1);
        else if(c == 'F')
            value.push(T2);
        else
        {
            if(value.size()!=0)
            {
                q = value.top();
                value.pop();
            }
            if(value.size()!=0)
            {
                p = value.top();
                value.pop();
            }

            switch(c)
            {
            case nt:
                value.push(p);
                value.push(!q);
                //cout<<p<<q;
                break;
            case nd:
                value.push(p&&q);
                break;
            case orr:
                value.push(p||q);
                break;
            case imp:
                //cout<<p<<"*"<<q;
                if(q && !p)
                    value.push(false);
                else value.push(true);
            }
        }
    }
    return value.top();
}

