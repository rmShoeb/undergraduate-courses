#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

double func_val(double x)
{
    //return ((x * x * x) - (2 * x) - 5);
    return (pow(x,sin(2)))-4;
}

double diff_func_val(double x)
{
    //return ((3*x*x)-2);
    return (cos(2)*pow(x,sin(2)-1));
}

int main(void)
{
    double x0, x;
    int n = 1;

    cout << "Enter an approximate value: ";
    cin >> x0;

    printf("n|    x_n-1   |    x_n     |  f(x_n-1)   |   f(x_n)\n");
    printf("-------------------------------------------------------\n");

    while (1)
    {
        x = x0 - (func_val(x0) / diff_func_val(x0));
        printf("%d|%3.10f|%3.10f|%3.10f|%3.10f\n", n, x0, x, func_val(x0), diff_func_val(x0));
        printf("-------------------------------------------------------\n");
        n++;

        if (abs(x0 - x) <= 0.000001)
            break;
        else
            x0 = x;
    }

    printf("\nAnswer: ");
    cout << x << endl;
}
