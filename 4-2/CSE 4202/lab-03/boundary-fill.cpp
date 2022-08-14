#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <cmath>

using namespace std;

void boundary_fill_4_conn(int x, int y, int fill_color, int boundary_color)
{
    int color = getpixel(x, y);
    if(color!=boundary_color && color!=fill_color){
        delay(1);
        putpixel(x, y, fill_color);
        boundary_fill_4_conn(x+1, y, fill_color, boundary_color);
        boundary_fill_4_conn(x-1, y, fill_color, boundary_color);
        boundary_fill_4_conn(x, y+1, fill_color, boundary_color);
        boundary_fill_4_conn(x, y-1, fill_color, boundary_color);
    }
}

void boundary_fill_8_conn(int x, int y, int fill_color, int boundary_color)
{
    int color = getpixel(x, y);
    if(color!=boundary_color && color!=fill_color){
        putpixel(x, y, fill_color);
        boundary_fill_8_conn(x-1, y-1, fill_color, boundary_color);
        boundary_fill_8_conn(x, y-1, fill_color, boundary_color);
        boundary_fill_8_conn(x+1, y-1, fill_color, boundary_color);
        boundary_fill_8_conn(x-1, y, fill_color, boundary_color);
        boundary_fill_8_conn(x+1, y, fill_color, boundary_color);
        boundary_fill_8_conn(x-1, y+1, fill_color, boundary_color);
        boundary_fill_8_conn(x, y+1, fill_color, boundary_color);
        boundary_fill_8_conn(x+1, y+1, fill_color, boundary_color);
    }
}


int main()
{
    int r{0};
    int center_x{0};
    int center_y{0};
    int fill_color{15};
    int boundary_color{5};

    cout << "Enter center (x, y): ";
    cin >> center_x >> center_y;
    cout << "Enter radius: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    circle(center_x, center_y, r);
    boundary_fill_4_conn(center_x, center_y, fill_color, boundary_color);
    // boundary_fill_8_conn(center_x, center_y, fill_color, boundary_color);

    getch();
    closegraph();

    return 0;
}

