#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <windows.h>

#include <stdio.h>

//driver code
int main()
{
    // gm is Graphics mode which is
    // a computer display mode that
    // generates image using pixels.
    // DETECT is a macro defined in
    // "graphics.h" header file

    int gd = DETECT, gm;

    // initgraph initializes the
    // graphics system by loading a
    // graphics driver from disk
    initgraph(&gd, &gm,"");

    // find the center point of the graphics window
    int x = getmaxx()/2;
    int y = getmaxy()/2;

    // color & circle function
    setcolor(2);
    circle(x, y, 10);
    setcolor(3);
    circle(x, y, 20);
    setcolor(4);
    circle(x, y, 30);
    setcolor(5);
    circle(x, y, 40);
    setcolor(6);
    circle(x, y, 50);
    setcolor(7);
    circle(x, y, 60);
    setcolor(8);
    circle(x, y, 70);
    setcolor(9);
    circle(x, y, 80);
    setcolor(10);
    circle(x, y, 90);
    setcolor(11);
    circle(x, y, 100);
    line(x, 0, x, getmaxy());
    line(0, y, getmaxx(), y);

    getch();

    // closegraph function closes the
    // graphics mode and deallocates
    // all memory allocated by
    // graphics system .
    closegraph();

    return 0;
}
