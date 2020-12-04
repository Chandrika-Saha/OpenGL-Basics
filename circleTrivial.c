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


void circleTrivial()
{
	int x,y,r,i;
	printf("Enter Radius: ");
	scanf("%d",&r);

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0f);

	for(i=0;i<=360;i++)
	{
		y = (int)(r*sin(i*1.0))+100;
		x = (int)(r*cos(i*1.0))+100;
		glBegin(GL_POINTS);
			glVertex2i(x,y);
		glEnd();

	}
glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,500);
	glutCreateWindow("Trivial Circle");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(circleTrivial);
	glutKeyboardFunc(handleKeypress);
	glutMainLoop();
	return 0;
}
