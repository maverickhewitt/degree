#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glut.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define PI 3.1415926535897932384626433832795
#define FPS 30

int X = 0;
int Y = 0;
int dx = 25;
int dy = 20;

void rectangle(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}

void nGon(int x, int y, int r, int n) {
	double inc = (2 * PI) / n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2d(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();

}

void house(int x, int y, int w) {

	int h = (int)(0.667 * w);

	// body
	glColor3ub(200, 200, 230);
	rectangle(x, y, w, h);

	// door
	glColor3ub(80, 0, 50);
	rectangle(x + (w / 2) - (0.125 * w), y, 0.25 * w, 0.5 * h);

	// left window
	glColor3ub(100, 100, 0);
	rectangle(x + 0.10 * w, y + h / 2, 0.20 * w, 0.333 * h);

	// right window
	glColor3ub(100, 100, 0);
	rectangle(x + w - (0.10 * w) - 0.20 * w, y + h / 2, 0.20 * w, 0.333 * h);

	// roof
	glColor3ub(255, 140, 0);
	glBegin(GL_POLYGON);
	glVertex2i(x - 0.1 * w, y + h);
	glVertex2i(x + 1.1 * w, y + h);
	glVertex2i(x + w, y + h + h / 2);
	glVertex2i(x, y + h + h / 2);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);
	glLineWidth(10.0);

	//house(200, 300, 100);
	glColor3ub(255, 255, 255);
	nGon(X, Y, 30, 30);


	/*	for (int i = 0; i < 30; i++) {
			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
			rectangle(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, rand() % SCREEN_WIDTH / 3, rand() % SCREEN_HEIGHT / 3);
		}
		glBegin(GL_POLYGON);
			for (int i = 0; i < 6; i++) {
				glColor3ub(rand() % 255, rand() % 255, rand() % 255);
				glVertex2i(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
			}
		*/

	glEnd();
	glFlush();
	glutSwapBuffers();
}

void idle() {
	DWORD start = GetTickCount();
	while (GetTickCount() - start < 1000 / FPS);
	X += dx;
	Y += dy;

	if (X<0 || X>SCREEN_WIDTH) dx *= -1;
	if (Y<0 || Y>SCREEN_HEIGHT) dy *= -1;

	glutPostRedisplay();
}

void initGL() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Test");
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	initGL();

	glutMainLoop();
}