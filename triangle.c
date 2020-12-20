#include <GL/glut.h>
#include <stdio.h>
int n;

void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1280, 0, 720);
}

void triangle(float *a, float *b, float *c){
    glVertex2f(a[0], a[1]);
    glVertex2f(b[0], b[1]);
    glVertex2f(c[0], c[1]);
}

void drawTriangle(float *a, float *b, float *c, int k){
	float ab[2],ac[2],bc[2];
	int i;
	if(k > 0){
	  for(i=0;i<2;i++){
		ab[i]=(a[i]+b[i])/2;
		ac[i]=(a[i]+c[i])/2;
		bc[i]=(b[i]+c[i])/2;
	}
	drawTriangle(a,ab,ac,k-1);
	drawTriangle(b,bc,ab,k-1);
	drawTriangle(c,ac,bc,k-1);
	} else{
        triangle(a,b,c);
	}
}

void display(){
    float a[]={100,100}, b[]={600,100}, c[]={350,500};

    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    drawTriangle(a,b,c,n);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    printf("enter n value");
    scanf("%d",&n);
    glutInit(&argc,argv);
    glutInitWindowSize(1280,720);
    glutCreateWindow("Sierpinski Gasket");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}