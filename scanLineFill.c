#include <GL/glut.h>

float x1, x2, x3, x4, y1, y2, y3, y4;

void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 1280, 0, 720);
    glFlush();
}

void edgeDetect(float x1, float y1, float x2, float y2, int * leftEdges, int * rightEdges){
    float slopeInverse, x, temp;
    int i;

    if(y2 < y1){
        temp = y1;
        y1 = y2;
        y2 = temp;

        temp = x1;  
        x1 = x2;
        x2 = temp;
    }

    if(y2 != y1){
        slopeInverse = (x2 - x1) / (y2 - y1);
    } else{
        slopeInverse = (x2 - x1);
    }
    x = x1;
    for ( i = y1; i <= y2; i++){
        
        if(x < leftEdges[i]){
            leftEdges[i] = x;
        }
        if(x > rightEdges[i]){
            rightEdges[i] = x;
        }
        x += slopeInverse;
    }
    
}

void drawPixel(int x, int y){
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void scanLineFill(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    int leftEdges[1280], rightEdges[1280], i, j;

    for(i = 0; i < 1280; i++){
        leftEdges[i] = 1280;
        rightEdges[i] = 0;
    }

    edgeDetect(x1, y1, x2, y2, leftEdges, rightEdges);
    edgeDetect(x2, y2, x3, y3, leftEdges, rightEdges);
    edgeDetect(x3, y3, x4, y4, leftEdges, rightEdges);
    edgeDetect(x4, y4, x1, y1, leftEdges, rightEdges);

    for (i = 0; i < 1280; i++){
        if(leftEdges[i] <= rightEdges[i]){
            for (j = leftEdges[i]; j < rightEdges[i]; j++){
                drawPixel(j, i);
            }
            
        }
    }
    
}

void display(){
    x1 = 640.0, x2 = 540.0, x3 = 640.0, x4 = 740.0;
    y1 = 260.0, y2 = 360.0, y3 = 460.0, y4 = 360.0;

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();

    scanLineFill(x1, y1, x2, y2, x3, y3, x4, y4);

    glFlush();
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(320, 180);
    glutCreateWindow("Scan-line fill");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}