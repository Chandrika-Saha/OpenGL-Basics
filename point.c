#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <GL/glut.h>

void handleKeypress(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 27:
		case 32:
		exit(0);
	}
}
void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}


//void initRendering()
//{
//	glEnable(GL_DEPTH_TEST);
	//glViewport(0,0,400,400);
//}


void drawPoint()
{


	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	//glPointSize(20.0f);
	glBegin(GL_POINTS);
	for(int i = 0; i < 10; i++)
	{
		glVertex2i(10+5*i,110);
		//glVertex2i(10+5*i,110);
	}
		//glVertex3f(1.0f,1.0f,0.0f);
		//glVertex3f(100.0f,100.0f,0.0f);
	glEnd();


	//glBegin(GL_LINES);
	//	glVertex2i(10.0f,10.0f);
	//	glVertex2i(100.0f,100.0f);
	//glEnd();

	//glBegin(GL_QUADS);
	//	glVertex2i(0,0);
	//	glVertex2i(10,0);
	//	glVertex2i(30,40);
	//	glVertex2i(10,40);
	//glEnd();
glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400,400);
	glutCreateWindow("two points");
	//initRendering();
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(drawPoint);
	//glutKeyboardFunc(handleKeypress);
	glutMainLoop();
	return 0;
}
