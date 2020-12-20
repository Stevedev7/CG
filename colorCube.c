#include <GL/glut.h>

float vertices[][3] = {
	{-1, -1, -1},
	{1, -1, -1},
	{1, 1, -1},
	{-1, 1, -1},
	{-1, -1, 1},
	{1, -1, 1},
	{1, 1, 1},
	{-1, 1, 1}
}, colors[][3] = {
	{0, 0, 0},
	{0, 0, 1},
	{0, 1, 0},
	{0, 1, 1},
	{1, 0, 0},
	{1, 0, 1},
	{1, 1, 0},
	{1, 1, 1}
}, theta[] = {0, 0, 0};

int axis = 2;

void init(){
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
}

void polygon(int a, int b, int c, int d){
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	glColor3fv(colors[b]);
	glVertex3fv(vertices[b]);
	glColor3fv(colors[c]);
	glVertex3fv(vertices[c]);
	glColor3fv(colors[d]);
	glVertex3fv(vertices[d]);
	glEnd();
}

void colorCube(){
	polygon(0, 1, 2, 3);
	polygon(4, 5, 6, 7);
	polygon(0, 4, 5, 1);
	polygon(1, 5, 6, 2);
	polygon(2, 6, 7, 3);
	polygon(0, 4, 7, 3);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1, 0, 0);
	glRotatef(theta[1], 0, 1, 0);
	glRotatef(theta[2], 0, 0, 1);
	colorCube();
	glFlush();
}

void spin (){
	theta[axis] += 0.1;
	if(theta[axis] > 360){
		theta[axis] = -360;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		axis = 0;
	}
	if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN){
		axis = 1;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		axis = 2;
	}
}

void reshape(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(w <= h){
		glOrtho(-2, 2, -2 * h / w, 2 * h / w, -2, 2);
	} else{
		glOrtho(-2 *  w/ h, 2 * w / h, -2, 2, -2, 2);
	}
	glMatrixMode(GL_MODELVIEW);
}


int  main(int argc,char *argv[]) {
    glutInit(&argc,argv);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(360, 180);\
    glutCreateWindow("CUBE");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(spin);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutMainLoop();
return 0;
}