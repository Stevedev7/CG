#include <GL/glut.h>
#include <stdio.h>

int x00, y00, x01, y01;

void init(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 1280, 0, 720);
    glFlush();
}

void writepixel(int x, int y){
    glPointSize(3);
    glBegin(GL_POINTS);       //WRITE PIXEL
    glColor3f(0, 0, 0);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

void display(){
 float dx = x01 - x00; 
    float dy = y01 - y00; 
    float d = 2 * dy - dx;
    float E = dy;
    float NE = dy - dx;
  
    int x = x00;
    int y = y00;
     
    writepixel(x, y);

    while(x < x01){
        if(d <= 0){
 	          d += 2 * E;
        } else{
            d += 2 * NE;
            y++;
        }
        x++;
        writepixel(x, y);
    }
}

int main(int argc, char *argv[]){
  
    printf("Enter the values \n");
    printf("x0 = "); 
    scanf("%d", &x00);
    printf("y0 = "); 
    scanf("%d", &y00);
    printf("x1 = "); 
    scanf("%d", &x01);
    printf("y1 = "); 
    scanf("%d", &y01);
  
    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(320, 180);
    glutCreateWindow("MIDPOINT LINE ALGORITHM");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
