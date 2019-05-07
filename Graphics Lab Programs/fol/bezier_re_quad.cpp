#if 0

///  Bezier Quadratic Curve

#include <gl/glut.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include<iostream>
using namespace std;

double x0, y_0, x1, y_1 , x_v0 , y_v0;

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);
}


void draw_point(double x, double y) {
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
}


void space_curve() {	

	double u, x, y, f1, f2, f3;

	draw_point(x0, y_0);
	draw_point(x1, y_1);
	draw_point(x_v0,y_v0);

	for(u=0.01;u<=1;u+=0.001)
	{

		f1 = u*u -2*u + 1;
		f2 = -2*u*u + 2*u;
		f3 = u*u;

		x = f1*x0 + f2*x1 + f3*x_v0 ;
		y = f1*y_0 + f2*y_1 + f3*y_v0 ;

		draw_point(x, y);
	}

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

	x0 = (rand()%(700) - 350 );
	y_0 =(rand()%(700) - 350 );

	x1 = (rand()%(700) -350);
	y_1 = (rand()%(700) -350);
	
	x_v0 = (rand()%(700) - 350 );
	y_v0 =(rand()%(700) - 350 );
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bezier Quadratic Curve");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

#endif