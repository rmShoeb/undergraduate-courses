#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int x1{0};
    int y1{0};
    int x2{0};
    int y2{0};

    cout << "Enter coordinates: ";
    cin >> x1 >> y1 >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    double m = (y2-y1)/(double)(x2-x1);
    int b = y1-m*x1;

    int x{0};
    int y{0};
    int max_x{0};
    int max_y{0};

    if(abs(m)<=1)
    {
        if(x1<x2)
        {
            x=x1;
            y=y1;
            max_x=x2;
        }
        else
        {
            x=x2;
            y=y2;
            max_x=x1;
        }
        putpixel(x, y, 11);
        while(x<=max_x)
        {
            x++;
            y = m*x+b;
            putpixel(x, y, 11);
        }
    }
    else
    {
        if(y1<y2)
        {
            x=x1;
            y=y1;
            max_y=y2;
        }
        else
        {
            x=x2;
            y=y2;
            max_y=y1;
        }
        putpixel(x, y, 11);
        while(y<=max_y)
        {
            y++;
            x = (y-b)/m;
            putpixel(x, y, 11);
        }
    }

    getch();
    closegraph();

    return 0;
}
