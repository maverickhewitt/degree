#include <windows.h>
#include <stdlib.h>
#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>
#include <math.h> 

#define SCREENWIDTH 500
#define SCREENHEIGHT 500
#define PI 3.1415926535897932384626433832795

void nGon(int x, int y, int r, int n) {
	double inc = (2 * PI) / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2d(x + r * cos(theta), y + r * sin(theta));
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);
	glLineWidth(4.0);

	nGon(SCREENWIDTH / 2, SCREENHEIGHT / 2, 50, 50);

	//	glBegin(GL_POLYGON);
	//		for(int i = 0; i<60; i++){
	//			glColor3ub(rand()%255,rand()%255,rand()%255);
	//			glVertex2i(rand()%SCREENWIDTH, rand()%SCREENHEIGHT);
	//		}
	glEnd();
	glFlush();
}

void initGL() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREENWIDTH, 0, SCREENHEIGHT);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(SCREENWIDTH, SCREENHEIGHT);
	glutCreateWindow("Test Window");
	glutDisplayFunc(display);

	initGL();

	glutMainLoop();

}