#include <GL/glut.h>
#include <stdio.h>

int x0 = 30, y0 = 100, x1 = 370, y1 = 100;

int xMin = 50, yMin = 50, xMax = 350, yMax = 350;

const int TOP = 8, BOTTOM = 4, RIGHT = 2, LEFT = 1, INSIDE = 0;

void init(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-639 * 2 * 0, 640 * 2, -359 * 2 * 0, 360 * 2);
    glFlush();
}

void drawWindow(int x0, int y0, int x1, int y1){
    glColor3f(0, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x0, y0);
    glVertex2i(x0, y1);
    glVertex2i(x1, y1);
    glVertex2i(x1, y0);
    glEnd();
}

int regionCode(int x, int y){
    int code = INSIDE;
    if(x < xMin){
        code |= LEFT;
    }else if(x > xMax){
        code |= RIGHT;
    }
    if(y < yMin){
        code |= BOTTOM;
    } else if(y > yMax){
        code |= TOP;
    }
    return code;
}

void drawLine(int x0, int y0, int x1, int y1){
    glColor3f(0.5, 0.7, 0.2);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(x0, y0);
    glVertex2i(x1, y1);
    glEnd();
}

void alg(){

    drawWindow(xMin, yMin, xMax, yMax);
    drawLine(x0, y0, x1, y1);
    int code0 = regionCode(x0, y0), code1 = regionCode(x1, y1), accept = 0;

    while(1){
        if(!(code0 | code1)){
            accept = 1;
            break;
        } else if(code1 & code0){
            break;
        } else{
            int code = code0 ? code0 : code1, x, y;
            float slope = (float)(y1 - y0) / (float)(x1 - x0);


            if(code & LEFT){
                x = xMin;
                y = slope * (xMin - x0) + y0;
            } else if(code  & RIGHT){
                x = xMax;
                y = slope * (xMax - x0) + y0;
            } else if(code & TOP){
                y = yMax;
                x = (yMax - y0) / slope + x0;
            } else if(code & BOTTOM){
                y = yMin;
                x = (yMin - y0) / slope + x0;
            }
            if(code  == code0){
                code = code1, x0 = x, y0 = y;
                code0 = regionCode(x0, y0); 
            } else{
                x1 = x, y1 = y;
                code1 = regionCode(x1, y1); 
            }
            
        }
    }
    drawWindow(xMin + 500, yMin, xMax + 500, yMax);
    if(accept){
        drawLine(x0 + 500, y0, x1 + 500, y1);
    }
    glFlush();
}



int main(int argc, char ** argv){
    printf("%d\n", (TOP | BOTTOM));
    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(320, 180);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(alg);
    glutMainLoop();
    return 0;
}