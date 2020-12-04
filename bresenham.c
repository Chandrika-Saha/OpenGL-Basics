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
	gluOrtho2D (-300.0, 300.0, -350.0, 350.0);
}


void bresenham()
{
	int x1,y1,x2,y2,dx,dy,p,dy2,dx2,i,yk,t;
	printf("Enter (start X,start Y) and (end X,end Y) : ");
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&x2,&y2);
	if(x1>x2)
	{
		t = y2;
		x2 = x1;
		x1 = t;
	}
	if(y1>y2)
	{
		t = y2;
		y2 = y1;
		y1 = t;
	}
	dx = x2-x1;
	dy = y2-y1;
	dx2 = 2*dx;
	dy2 = 2*dy;
	p = dy2-dx;
	yk = y1;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glPointSize(2.0f);		
	
	for(i=x1;i<=x2;i++)
	{
		if(p<0){
			glBegin(GL_POINTS);
				glVertex2i(i,yk);
			glEnd();
			p = p+2*dy;
		}
		else{
			glBegin(GL_POINTS);
				glVertex2i(i,yk+1);
			glEnd();
			p = p+dy2-dx2;
			yk = yk+1;
		}
	}
glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800,800);
	glutCreateWindow("Bresenham Line Drawing");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(bresenham);
	glutKeyboardFunc(handleKeypress);
	glutMainLoop();
	return 0;
}
