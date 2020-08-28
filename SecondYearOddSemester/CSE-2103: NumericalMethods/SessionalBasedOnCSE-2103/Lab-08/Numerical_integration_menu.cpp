#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<stdint.h>
using namespace std;

int main(void)
{
    double upper,lower,h;
    int steps;
    int i;
    int checker;
    double trap,trap_error;
    double simp_1_3,simp_1_3_error;
    double simp_3_8,simp_3_8_error;
    double calculated;

    while(1)
    {
        printf("1. Enter new value\n2. Try with new value of h\n0. Exit\n   Enter your choice: ");
        cin>>checker;

        switch(checker)
        {
        case 0:
            return 0;

        case 1:
            {
                printf("Enter upper-limit of the function: ");
                cin>>upper;
                printf("Enter lower-limit of the function: ");
                cin>>lower;
                xx:
                printf("Enter the value of h: ");
                cin>>h;

                steps=(int)(((upper-lower)/h)+1);
                double x[steps];
                double y[steps];

                calculated=log(1+upper)-log(1+lower);
                x[0]=lower;
                y[0]=1/(1+x[0]);
                for(i=1;i<steps;i++)
                {
                    x[i]=x[i-1]+h;
                    y[i]=1/(1+x[i]);
                }

                printf("\nTabulated values:\n   x   |   y\n");
                for(i=0;i<steps;i++)
                    printf("%0.5f|%0.5f\n",x[i],y[i]);

                ///trapezoidal_method
                trap=y[0]+y[steps-1];
                for(i=1;i<steps-1;i++)
                    trap+=(2*y[i]);
                trap*=(h/2);
                trap_error=abs(calculated-trap);
                printf("\nArea using Trapezoidal method: ");
                cout<<trap<<endl;
                printf("Absolute error: ");
                cout<<trap_error<<endl;

                ///Simpson's_1/3_rule
                simp_1_3=y[0]+y[steps-1];
                for(i=1;i<steps-1;i++)
                {
                    if(i%2==0)
                        simp_1_3+=(2*y[i]);
                    else
                        simp_1_3+=(4*y[i]);
                }
                simp_1_3*=(h/3);
                simp_1_3_error=abs(calculated-simp_1_3);
                printf("\nArea using Simpson's 1/3 rule: ");
                cout<<simp_1_3<<endl;
                printf("Absolute error: ");
                cout<<simp_1_3_error<<endl;

                ///Simpson's_3/8_rule
                simp_3_8=y[0]+y[steps-1];
                for(i=1;i<steps-1;i++)
                {
                    if(i%3==0)
                        simp_3_8+=(2*y[i]);
                    else
                        simp_3_8+=(3*y[i]);
                }
                simp_3_8*=(3*h/8);
                simp_3_8_error=abs(calculated-simp_3_8);
                printf("\nArea using Simpson's 3/8 rule: ");
                cout<<simp_3_8<<endl;
                printf("Absolute error: ");
                cout<<simp_3_8_error<<endl;

                if(trap_error<simp_1_3_error)
                {
                    if(trap_error<simp_3_8_error)
                        printf("\nTrapezoidal rule is the best.\n");
                    else
                        printf("\nSimpson's 3/8 rule is the best.\n");
                }
                else
                {
                    if(simp_1_3_error<simp_3_8_error)
                        printf("\nSimpson's 1/3 rule is the best.\n");
                    else
                        printf("\nSimpson's 3/8 rule is the best.\n");
                }
            }break;

        case 2:
            goto xx;
            break;

        default:
            printf("Wrong input...\n");
        }
    }
}
