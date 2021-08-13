#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

double func_value(double x, double y)
{
    return (y - x);
}

int second_order(void)
{
    double temp;
    double h;
    int choice, i;
    double x_check;

    while (1)
    {
        vector<double> x;
        vector<double> y;
        printf("1. New value\n2. New h\n0. Terminate\n   Enter choice: ");
        cin >> choice;

        switch (choice)
        {
        case 0:
            return 1;

        case 1:
            printf("Enter initial value of x: ");
            cin >> temp;
            x.push_back(temp);
            printf("Enter initial value of y: ");
            cin >> temp;
            y.push_back(temp);
        xx:
            printf("Enter value of h: ");
            cin >> h;
            printf("Enter the value of x to find y: ");
            cin >> x_check;

            i = 0;
            while (x[i] <= x_check)
            {
                temp = x[i] + h;
                x.push_back(temp);
                temp = y[i] + (h / 2) * (func_value(x[i], y[i]) + func_value(x[i + 1], y[i] + h * func_value(x[i], y[i])));
                y.push_back(temp);
                i++;
            }
            cout << "y(" << x_check << ")=" << y[i] << endl;
            break;

        case 2:
            goto xx;
            break;

        default:
            printf("Wrong input.\n");
        }
    }
}

int forth_order(void)
{
    double temp;
    double h;
    int choice, i;
    double x_check;
    double k1, k2, k3, k4;

    while (1)
    {
        vector<double> x;
        vector<double> y;
        printf("1. New value\n2. New h\n0. Terminate\n   Enter choice: ");
        cin >> choice;

        switch (choice)
        {
        case 0:
            return 1;
            break;

        case 1:
            printf("Enter initial value of x: ");
            cin >> temp;
            x.push_back(temp);
            printf("Enter initial value of y: ");
            cin >> temp;
            y.push_back(temp);
        xx:
            printf("Enter value of h: ");
            cin >> h;
            printf("Enter the value of x to find y: ");
            cin >> x_check;

            i = 0;
            while (x[i] <= x_check)
            {
                temp = x[i] + h;
                x.push_back(temp);
                k1 = h * func_value(x[i], y[i]);
                k2 = h * func_value(x[i] + (h / 2), y[i] + (k1 / 2));
                k3 = h * func_value(x[i] + (h / 2), y[i] + (k2 / 2));
                k4 = h * func_value(x[i + 1], y[i] + k3);
                temp = y[i] + ((k1 + 2 * k2 + 2 * k3 + k4) / 6);
                y.push_back(temp);
                i++;
            }
            cout << "y(" << x_check << ")=" << y[i] << endl;
            break;

        case 2:
            goto xx;
            break;

        default:
            printf("Wrong input.\n");
        }
    }
}

int main(void)
{
    int order;
    int temp;
    while (1)
    {
        printf("1. 2nd order\n2. 4th order\n0. Exit program\n   Enter your choice: ");
        cin >> order;
        switch (order)
        {
        case 0:
            return 0;

        case 1:
            temp = second_order();
            break;

        case 2:
            temp = forth_order();
            break;

        default:
            printf("Wrong input.\n");
        }
    }
}
