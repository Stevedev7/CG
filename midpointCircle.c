#include <GL/glut.h>
#include <stdio.h>

int x, y, r;

void init(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-640, 639, -360, 359);
    glFlush();
}

void writePixel(int x, int y){
    glBegin(GL_POINTS);
    glPointSize(3);
    glColor3f(0, 0, 0);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}
void drawCircle(){
    x = 0, y = r;
    double d = 5.0 / 4.0 - r;

    while(x < y){
        if(d < 0){
            d = d + 2.0 * x + 3.0;
        } else{
            d = d + 2.0 * (x - y) + 5.0;
            y --;
        }
        x ++;
        writePixel(x, y);
        writePixel(-x, y);
        writePixel(-x, -y);
        writePixel(x, -y);
        writePixel(y, x);
        writePixel(-y, x);
        writePixel(-y, -x);
        writePixel(y, -x);

    }
}

int main(int argc, char ** argv){
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(320, 180);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(drawCircle);
    glutMainLoop();
    return 0;
}