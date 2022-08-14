#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <cmath>

using namespace std;

double** mat_mul(double aMatrix[][3], double bMatrix[][3]){
    double** product = 0;
    product = new double*[3];
    for(int i=0; i<3; i++){
        product[i] = new double[3];
        for(int j=0; j<3; j++)
            product[i][j] = 0;
    }

    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            for(int inner=0; inner<3; inner++) {
                product[row][col] += aMatrix[row][inner]*bMatrix[inner][col];
            }
        }
    }
    return product;
}

void translation(double points[][3]){
    double tx{0};
    double ty{0};
    cout << "Enter tx ty: ";
    cin >> tx >> ty;

    double t_v[3][3] = {
        {1,0,tx},
        {0,1,ty},
        {1,0,1}
    };

    double** result;
    result = mat_mul(t_v, points);

    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    line((int)points[0][0], (int)points[1][0], (int)points[0][1], (int)points[1][1]);
    line((int)points[0][0], (int)points[1][0], (int)points[0][2], (int)points[1][2]);
    line((int)points[0][1], (int)points[1][1], (int)points[0][2], (int)points[1][2]);
    // translated object
    line((int)result[0][0], (int)result[1][0], (int)result[0][1], (int)result[1][1]);
    line((int)result[0][0], (int)result[1][0], (int)result[0][2], (int)result[1][2]);
    line((int)result[0][1], (int)result[1][1], (int)result[0][2], (int)result[1][2]);

    getch();
    closegraph();
}

void rotation(double points[][3]){
    int theta{0};
    cout << "Enter rotation angle (theta): ";
    cin >> theta;

    double r_t[3][3] = {
        {cos(theta), -sin(theta), 0},
        {sin(theta), cos(theta), 0},
        {0,0,1}
    };

    double** result;
    result = mat_mul(r_t, points);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }


    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    line((int)points[0][0], (int)points[1][0], (int)points[0][1], (int)points[1][1]);
    line((int)points[0][0], (int)points[1][0], (int)points[0][2], (int)points[1][2]);
    line((int)points[0][1], (int)points[1][1], (int)points[0][2], (int)points[1][2]);
    // translated object
    line((int)result[0][0], (int)result[1][0], (int)result[0][1], (int)result[1][1]);
    line((int)result[0][0], (int)result[1][0], (int)result[0][2], (int)result[1][2]);
    line((int)result[0][1], (int)result[1][1], (int)result[0][2], (int)result[1][2]);

    getch();
    closegraph();
}

void scaling(double points[][3]){
    double sx{0};
    double sy{0};
    cout << "Enter sx sy: ";
    cin >> sx >> sy;

    double s_xy[3][3] = {
        {sx,0,0},
        {0,sy,0},
        {0,0,1}
    };

    double** result;
    result = mat_mul(s_xy, points);

    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    line((int)points[0][0], (int)points[1][0], (int)points[0][1], (int)points[1][1]);
    line((int)points[0][0], (int)points[1][0], (int)points[0][2], (int)points[1][2]);
    line((int)points[0][1], (int)points[1][1], (int)points[0][2], (int)points[1][2]);
    // translated object
    line((int)result[0][0], (int)result[1][0], (int)result[0][1], (int)result[1][1]);
    line((int)result[0][0], (int)result[1][0], (int)result[0][2], (int)result[1][2]);
    line((int)result[0][1], (int)result[1][1], (int)result[0][2], (int)result[1][2]);

    getch();
    closegraph();
}


int main()
{
    double points[3][3] = {
        {100,0,100},
        {0,100,100},
        {1,1,1}
    };

    //translation(points);
    //rotation(points);
    scaling(points);

    return 0;
}

