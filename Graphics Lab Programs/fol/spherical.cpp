#if 0

#include<Windows.h>
#include<GL\glut.h>
#include<GL\freeglut.h>
#include<math.h>
#include<iostream>
using namespace std;

#define pi 3.1429
#define ro 1.7
double len,hei;

void mytwisted_value(int i,int j)
{
	float xc,yc,r;
	xc=-30;
	yc=-40;
	r=50;
	float D = (i-xc)*(i-xc) + (j-yc)*(j-yc);
	double dis = sqrt(D);

	float newx = i-xc;
	float newy = j-yc;
	//if(dis<r)
	//{
		float x = i + ro*(1-(dis/r))*(newx/r);
		float y = j + ro*(1-(dis/r))*(newy/r);
		glVertex2f(x,y);
	//}
	/*else
	{
		glVertex2f(i,j);
	}*/
	
}

void draw_rectangle_twisted(int l,int h)
{
	len =l;
	hei =h;
	glBegin(GL_POINTS);
		for(int k=0;k<8;k++)
		{
			if(k==0)
				glColor3f(1,1,0.5);
			else if(k==1)
				glColor3f(0.5,0.5,1);
			else if(k==2)
				glColor3f(0.5,0.8,1);
			else if(k==3)
				glColor3f(1,0,0);
			else if(k==4)
				glColor3f(0,1,0);
			else if(k==5)
				glColor3f(0,0,1);
			else if(k==6)
				glColor3f(1,1,0);
			else
				glColor3f(0,1,1);

			for(int i = -l+k*2*l/8;i<=-l+(k+1)*2*l/8;i = i+2)
			{
				for(int j = - h;j <= h;j++)
				{
					mytwisted_value(i,j);
				}
			}
		}
		glEnd();
		glFlush();
}

void myInit()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-780,780,-420,420,-1,1);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(0.5,1,0.5);
	for(int i=-300;i<=300;i++)
	{
		glVertex2d(i,0);
		glVertex2d(0,i);
	}
	glEnd();
	glFlush();
	draw_rectangle_twisted(300,100);
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1200,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("spherize");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
}

#endif