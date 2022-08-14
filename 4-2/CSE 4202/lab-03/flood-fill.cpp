#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <cmath>

using namespace std;

void flood_fill_4_conn(int x, int y, int fill_color, int original_color)
{
    if(getpixel(x, y) == original_color){
        putpixel(x, y, fill_color);
        flood_fill_4_conn(x+1, y, fill_color, original_color);
        flood_fill_4_conn(x-1, y, fill_color, original_color);
        flood_fill_4_conn(x, y+1, fill_color, original_color);
        flood_fill_4_conn(x, y-1, fill_color, original_color);
    }
}

void flood_fill_8_conn(int x, int y, int fill_color, int original_color)
{
    if(getpixel(x, y) == original_color){
        putpixel(x, y, fill_color);
        flood_fill_8_conn(x-1, y-1, fill_color, original_color);
        flood_fill_8_conn(x, y-1, fill_color, original_color);
        flood_fill_8_conn(x+1, y-1, fill_color, original_color);
        flood_fill_8_conn(x-1, y, fill_color, original_color);
        flood_fill_8_conn(x+1, y, fill_color, original_color);
        flood_fill_8_conn(x-1, y+1, fill_color, original_color);
        flood_fill_8_conn(x, y+1, fill_color, original_color);
        flood_fill_8_conn(x+1, y+1, fill_color, original_color);
    }
}


int main()
{
    int r{0};
    int center_x{0};
    int center_y{0};
    int fill_color{15};
    int original_color{0};

    cout << "Enter center (x, y): ";
    cin >> center_x >> center_y;
    cout << "Enter radius: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    circle(center_x, center_y, r);
    // flood_fill_4_conn(center_x, center_y, fill_color, original_color);
    flood_fill_8_conn(center_x, center_y, fill_color, original_color);

    getch();
    closegraph();

    return 0;
}
