// main.cpp - Entry point to application

#include <iostream>
#include <GL\glut.h>

using namespace std;

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Set material properties
	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0};
	GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0};
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);	

	// Draw square with many little squares
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
	const GLfloat kqDelta = 0.01;

	for (int i = -90; i < 90; ++i)
	{
		for (int j = -90; j < 90; ++j)
		{
			glVertex3f(j * kqDelta, i * kqDelta, -0.2);
			glVertex3f((j+1) * kqDelta, i * kqDelta, -0.2);
			glVertex3f((j+1) * kqDelta, (i+1) * kqDelta, -0.2);
			glVertex3f(j * kqDelta, (i+1) * kqDelta, -0.2);
		}
	}
	
	glEnd();
		glFlush();
}

void initialise()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	// Lighting set up
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0};
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	GLfloat qaLightPosition[] = { 0.5, 0.5, 0.0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}

int main(int iArgc, char** cppArgv)
{
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1080, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL");
	initialise();
	glutDisplayFunc(draw);
	glutMainLoop();

	return 0;
}