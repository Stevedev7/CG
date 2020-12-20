#include <GL/glut.h>

int spacing = 50, margin = 50;
int xMax = 10, yMax = 10;

void init(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,1280,0,720);
    glColor3f(0,0,0);
}

void display(){
	int i, j;
	for(i = 0; i < xMax; i ++){
		for(j = 0; j < yMax; j ++){
			glBegin(GL_LINE_LOOP);
			glVertex2i((i * spacing + margin), (j * spacing + margin));
			glVertex2i((i * spacing + margin), ((j + 1) * spacing + margin));
			glVertex2i(((i + 1) * spacing + margin), ((j + 1) * spacing + margin));
			glVertex2i(((i + 1 )* spacing + margin), (j * spacing + margin));
			glEnd();
		}
	}
	glFlush();
}

int main(int argc, char ** argv){
	glutInit(&argc,argv);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(360, 1800);
    glutCreateWindow("Rectangular Mesh");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}