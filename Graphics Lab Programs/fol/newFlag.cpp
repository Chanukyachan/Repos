#if 1

///  Bezier Cubic Curve

#include <gl/glut.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include<iostream>
using namespace std;

double x0, y_0, x1, y_1 , x_v0 , y_v0 , x_v1 , y_v1;
double xc = 50,yc=145;

void plot(double x,double y)
{
	glBegin(GL_POINTS);
	glVertex2d(x +xc, y+yc);
	glEnd();

}

void display1(int r) 
{
	int x = 0;
	int y = r;
	float p = 5/4 -r;

	plot(x,y);

	while(y > x)
	{
		if(p<0)
		{
			x++;
			p += 2*x + 1;
		}
		else
		{
			y--;
			x++;
			p += 2*(x-y) + 1;
		}

		plot(x,y);
		plot(x,-y);
		plot(-x,y);
		plot(-x,-y);
		plot(y,x);
		plot(-y,x);
		plot(y,-x);
		plot(-y,-x);
	}

}

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-250.0, 250.0, -250.0, 250.0, -1.0, 1.0);
}


void draw_point(double x, double y) {
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
}


void space_curve() {	

	double u, x, y, f1, f2, f3, f4;

	draw_point(x0, y_0);
	draw_point(x1, y_1);
	draw_point(x_v0,y_v0);
	draw_point(x_v1,y_v1);

	for(u=0.01;u<=1;u+=0.001)
	{

		f1 = -u*u*u + 3*u*u - 3*u +1;
		f2 = 3*u*u*u - 6*u*u + 3*u;
		f3 = -3*u*u*u + 3*u*u;
		f4 = u*u*u;


		x = f1*x0 + f2*x1 + f3*x_v0 + f4*x_v1;
		y = f1*y_0 + f2*y_1 + f3*y_v0 + f4*y_v1;

		

		glColor3f(255/255, 153/255.0, 51/255.0);
		draw_point(x, y);
		for(int i=1;i<=30;i=i+1)
		{
			draw_point(x, y+i);
		}

		glColor3f(1, 1, 1);
		y =y+30;
		draw_point(x, y);
		for(int i=1;i<=30;i=i+1)
		{
			draw_point(x, y+i);
		}

		glColor3f(19/255.0, 136/255.0, 8/255.0);
		y=y+30;
		draw_point(x, y);
		for(int i=1;i<=30;i=i+1)
		{
			draw_point(x, y+i);
		}

	}
	glPointSize(2);
	glColor3f(1.0,0.0,0.0);
	display1(15);

	/*float ang = 360*24*3.14/180;
	float angx = 50;
	float angy = 145;
	for(int i=1;i<=24;i++)
	{
		glBegin(GL_LINES);
			glVertex2f(50,145);
			glVertex2f(angx*cos(ang*i),angy*(ang*i);
			
		glEnd();
	}*/

	for (int i = -500; i <= 500; i++)
	{
		draw_point(i, 0);
		draw_point(0, i);

	}


}

void myDisplay() {
	space_curve();
	glFlush();
}

void main(int argc, char **argv) {
	
	srand(time(0));

	//printf("Enter (x0, y0, x1, y1) \n");//,x_v0,y_v0,x_v1,y_v1)\n");

	//scanf("%d %d %d %d %d %d %d %d", &x0, &y0, &x1, &y1,&x_v0,&y_v0,&x_v1, &y_v1);

	//cin>>x0>>y_0>>x1>>y_1; //>>x_v0>>y_v0>>x_v1>>y_v1;

	double pi = 3.142857;

	x0 =20; //(rand()%(700) - 350 );
	y_0 =100; //(rand()%(700) - 350 );

	x1 =30; //(rand()%(700) -350);
	y_1 =110; //(rand()%(700) -350);
	
	x_v0 =70; //(rand()%(700) - 350 );
	y_v0 =90; //(rand()%(700) - 350 );

	x_v1 =80; //(rand()%(700) -350);
	y_v1 =100; //(rand()%(700) -350);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bezier Cubic Curve");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

#endif