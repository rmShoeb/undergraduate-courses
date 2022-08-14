#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <cmath>

using namespace std;

void put_circle_points(int x, int y, int center_x, int center_y){
    putpixel(center_x+x, center_y+y, 10);
    putpixel(center_x-x, center_y+y, 10);
    putpixel(center_x+x, center_y-y, 10);
    putpixel(center_x-x, center_y-y, 10);
    putpixel(center_x+y, center_y+x, 10);
    putpixel(center_x-y, center_y+x, 10);
    putpixel(center_x+y, center_y-x, 10);
    putpixel(center_x-y, center_y-x, 10);
}

int main()
{
    int r{0};

    cout << "Enter radius: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    int center_x = getmaxx()/2;
    int center_y = getmaxy()/2;

    int x{0};
    int y{0};
    int x_limit = r/sqrt(2);

    while(x<=x_limit){
        y = sqrt(r*r - x*x);
        put_circle_points(x, y, center_x, center_y);
        x++;
    }

    getch();
    closegraph();

    return 0;
}

