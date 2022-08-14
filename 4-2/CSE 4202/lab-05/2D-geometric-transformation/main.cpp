#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

// matrices
double points[3][3] = {
    {-0.5, 0.5, 0},
    {-0.25, -0.25, 0.25},
    {1,1,1}
};

/*double t_v[3][3] = {
    {}
}*/
/*void mulMat(int mat1[][], int mat2[][]) {
    int rslt[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            rslt[i][j] = 0;
            for (int k=0; k<3; k++) {
                rslt[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
}*/

void display(){
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 1.0, 1.0);
        //glVertex2f(points[0][0],points[1][0]);
        glVertex2d(points[0][0],points[1][0]);
        //glColor3f(1.0, 0.0, 0.0);
        //glVertex2f(points[0][1],points[1][1]);
        glVertex2d(points[0][1],points[1][1]);
        //glColor3f(0.0, 1.0, 0.0);
        //glVertex2f(points[0][2],points[1][2]);
        glVertex2d(points[0][2],points[1][2]);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(500,0);
    glutCreateWindow("Lab-1, Code-1: Creating a triangle and displaying it.");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
