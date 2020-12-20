#include <GL/glut.h>

void init(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 1280, 720, 0);
    glFlush();
}

void line(int x, int y){
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(x, y);
    glVertex2i(x + 100, y + 200);
    glEnd();
    glFlush();
}

void point(int x, int y){
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 1.0);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void square(int x, int y){
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(x, y);
    glVertex2f(x + 100, y);
    glVertex2f(x + 100, y + 100);
    glVertex2f(x, y + 100);
    glEnd();
    glFlush();
}

void triangle(int x, int y){
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(x, y);
    glVertex2f(x + 100, y);
    glVertex2f(x + 50, y - 86);
    glEnd();
    glFlush();
}


void pentagon(int x, int y){
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(x, y);
    glVertex2f(x + 100, y);
    glVertex2f(x + 100, y - 100);
    glVertex2f(x + 50, y - 170);
    glVertex2f(x, y - 100);
    glEnd();
    glFlush();
}


void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        point(x, y);
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        line(x, y);
    }
}

void keyboard(unsigned char key, int x, int y){
    if(key == 'p' || key == 'P'){
        pentagon(x, y);
    }
    if(key == 't' || key == 'T'){
        triangle(x, y);
    }
    if(key == 's' || key == 'S'){
        square(x, y);
    }
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("MOUSE KEYBOARD INTERACTION");
    init();
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}