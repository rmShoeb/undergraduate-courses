#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<conio.h>
using namespace std;

/*int main(void)
{
    char s1[80], s2[80];

    gets(s1);
    gets(s2);
    //cin>>s1>>s2;          ///this doesn't work, don't know why.............

    printf("lengths: %d %d\n", strlen(s1), strlen(s2));
    if(!strcmp(s1, s2))
        printf("The strings are equal\n");
    strcat(s1, s2);
    printf("%s\n", s1);
    strcpy(s1, "This is a test.\n");
    printf(s1);
    if(strchr("hello", 'e'))
        printf("e is in hello\n");
    if(strstr("hi there", "hi"))
        printf("found hi");

    getch();
    return 0;
}*/


/*int main(void)
{
    //string s1,s2;
    char s1[20];
    char s2[20];

    //cin>>s1>>s2;
    gets(s1);
    gets(s2);

    if(!(strcmp(s1,s2)))
        cout<<"Same"<<endl;
    else
        cout<<strcat(s1,s2)<<endl;

    getch();
    return 0;
}*/


int main(void)
{
    char temp[10];
    sprintf(temp,"%d",9202410);
    cout<<temp[0]<<endl;
    getch();
    return 0;
}
