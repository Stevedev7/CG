#include<stdio.h>
#include<GL/glut.h>
#include <math.h>

float square[9][3]={
	{200,200, 1},
	{300,200, 1},
	{300,300, 1},
	{200,300, 1},
	{250,400, 1},
	{225,200, 1},
	{275,200, 1},
	{275,250, 1},
	{225,250, 1}
}, rotationMatrix[3][3], result[9][3], m, n, theta;

float tx, ty;

void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0,1280,0,720);
	glFlush();
}

void multiply (){
	int i, j, k;

	for(i = 0; i < 9; i++){
		for(j = 0; j < 3; j++){
			result[i][j] = 0;
			for(k = 0; k < 3; k++){
				result[i][j] = result[i][j] + square[i][k] * rotationMatrix[k][j];
			}
		}
	}
}

void rotate(){
	m = (-tx * cos(theta)) + (ty * sin(theta)) + tx;
	n = (-tx * sin(theta)) - (ty * cos(theta)) + ty;
	rotationMatrix[0][0] = cos(theta);
	rotationMatrix[0][1] = sin(theta);
	rotationMatrix[0][2] = 0;
	rotationMatrix[1][0] = -sin(theta);
	rotationMatrix[1][1] = cos(theta);
	rotationMatrix[1][2] = 0;
	rotationMatrix[2][0] = m;
	rotationMatrix[2][1] = n;
	rotationMatrix[2][2] = 1;
	multiply();
}

void drawHouse(){
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);
	glVertex2f(square[0][0], square[0][1]);
	glVertex2f(square[1][0], square[1][1]);
	glVertex2f(square[2][0], square[2][1]);
	glVertex2f(square[3][0], square[3][1]);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);
	glVertex2f(square[2][0], square[2][1]);
	glVertex2f(square[3][0], square[3][1]);
	glVertex2f(square[4][0], square[4][1]);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);
	glVertex2f(square[5][0], square[5][1]);
	glVertex2f(square[6][0], square[6][1]);
	glVertex2f(square[7][0], square[7][1]);
	glVertex2f(square[8][0], square[8][1]);
	glEnd();
}

void drawFinalHouse(){
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 1);
	glVertex2f(result[0][0], result[0][1]);
	glVertex2f(result[1][0], result[1][1]);
	glVertex2f(result[2][0], result[2][1]);
	glVertex2f(result[3][0], result[3][1]);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 1);
	glVertex2f(result[2][0], result[2][1]);
	glVertex2f(result[3][0], result[3][1]);
	glVertex2f(result[4][0], result[4][1]);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 1);
	glVertex2f(result[5][0], result[5][1]);
	glVertex2f(result[6][0], result[6][1]);
	glVertex2f(result[7][0], result[7][1]);
	glVertex2f(result[8][0], result[8][1]);
	glEnd();
}

void display(){
    drawHouse();
	rotate();
	drawFinalHouse();
	glFlush();
}
int main(int argc,char **argv){

	printf("Enter theta: "); scanf("%f", &theta);
	theta = (theta * 3.14) / 180;
	printf("enter x and y\n"); scanf("%f%f", &tx, &ty);
	glutInit(&argc,argv);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(320, 180);
	glutCreateWindow("House");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}