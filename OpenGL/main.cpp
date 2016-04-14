// main.cpp - Entry point to application

#include <iostream>
#include <GL\glut.h>

using namespace std;

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
	glEnd();
	glFlush();
}

void initialise()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv)
{
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("OpenGL");
	initialise();
	glutDisplayFunc(draw);
	glutMainLoop();

	return 0;
}