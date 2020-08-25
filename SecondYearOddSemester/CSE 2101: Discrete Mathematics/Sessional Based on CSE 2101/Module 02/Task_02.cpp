#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(void)
{
    char a[100];
    char b[100];
    int i,j;

    printf("Enter set a: ");
    cin>>a;
    printf("Enter set b: ");
    cin>>b;

    printf("\nCartesian product of the given sets: {");
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!='{'&&a[i]!=','&&a[i]!='}')
        {
            for(j=0;b[j]!='\0';j++)
            {
                if(b[j]!='{'&&b[j]!=','&&b[j]!='}')
                    printf("(%c,%c),",a[i],b[j]);
            }
        }
    }
    printf("}\n\n");
}
