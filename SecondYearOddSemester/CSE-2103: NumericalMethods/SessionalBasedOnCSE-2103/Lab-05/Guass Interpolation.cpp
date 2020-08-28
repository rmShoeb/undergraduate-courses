#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

//void forward_interpolation()
//void backward_interpolation()

int main(void)
{
    int checker;
    int counter;
    int i,j;
    int temp;
    int mid;
    int keep_track;

    while(1)
    {
        printf("1. New input\n2. Exit\n   Enter your choice: ");
        scanf("%d",&checker);

        switch(checker)
        {
        case 1:
            printf("Enter size of your input: ");
            scanf("%d",%counter);                           ///to determine the size of the input
            vector<double>input;                            ///to store the values of y and differences
            cout<<"Enter your values in the form->"<<endl;
            cout<<"  x  |  y"<<endl;
            for(i=0;i<counter;i++)
            {
                cin>>temp;
                input.push_back(temp);
            }

            mid=counter/2;                                  ///to fix the middle index
            keep_track=0;                                   ///this is really necessary____i think
            for(i=counter;i>0;i--)                          ///to set how many differences there will be
            {
                for(j=0;j<i;j++)                            ///calculating the differences
                {
                    temp=input[keep_track+1]-input[keep_track];
                    input.push_back(temp);
                    keep_track++;
                }
            }
            break;

        case 2:
            return 0;                                       ///time to terminate the program

        default:
            printf("Wrong choice...\n");                    ///user has a nasty mind.....definitely
        }
    }
}
