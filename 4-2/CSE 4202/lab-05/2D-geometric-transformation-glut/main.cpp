#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;

double points[3][3] = {
    {-0.3, 0.3, 0},
    {-0.15, -0.15, 0.15},
    {1, 1, 1}
};

void mat_mul(double aMatrix[][3]){
    double product[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            for(int inner=0; inner<3; inner++) {
                product[row][col] += aMatrix[row][inner]*points[inner][col];
            }
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            points[i][j] = product[i][j];
        }
    }
}

void translation(double tx, double ty){
    double t_v[3][3] = {
        {1,0,tx},
        {0,1,ty},
        {1,0,1}
    };
    mat_mul(t_v);
}

void rotation(double theta){
    double r_t[3][3] = {
        {cos(theta), -sin(theta), 0},
        {sin(theta), cos(theta), 0},
        {0,0,1}
    };
    mat_mul(r_t);
}

void scaling(double sx, double sy){
    double s_xy[3][3] = {
        {sx,0,0},
        {0,sy,0},
        {0,0,1}
    };

    mat_mul(s_xy);
}

void view_object(){
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(points[0][0], points[1][0]);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(points[0][1], points[1][1]);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(points[0][2], points[1][2]);
    glEnd();

    glFlush();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    view_object();
    //translation(0.5, 0.5);
    rotation(45);
    //scaling(2,0.5);
    view_object();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(500,0);
    glutCreateWindow("2D Geometric Transformation");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
