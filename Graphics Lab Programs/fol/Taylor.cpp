
#if 0

///  Bezier cubic Curve - Faster

#include <gl/glut.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include<iostream>
using namespace std;

double x0, y_0, x1, y_1 , x_v0 , y_v0 , x_v1 , y_v1;

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
	double ax,bx,cx,dx;
	double ay,by,cy,dy;
	double fx,dfx,ddfx,dddfx,fy,dfy,ddfy,dddfy,dt = 0.001;

	ax = -x0 + 3*x1 - 3*x_v0 + x_v1;
	bx = 3*x0 - 6*x1 + 3*x_v0;
	cx = -3*x0 + 3*x1;
	dx = x0;

	ay = -y_0 + 3*y_1 - 3*y_v0 + y_v1;
	by = 3*y_0 - 6*y_1 + 3*y_v0;
	cy = -3*y_0 + 3*y_1;
	dy = y_0;

	fx = dx;
	fy = dy;

	dfx = cx*dt + bx*dt*dt + ax*dt*dt*dt;
	dfy = cy*dt + by*dt*dt + ay*dt*dt*dt;

	ddfx = 2*bx*dt*dt + 6*ax*dt*dt*dt;
	ddfy = 2*by*dt*dt + 6*ay*dt*dt*dt;

	dddfx = 6*ax*dt*dt*dt;
	dddfy = 6*ay*dt*dt*dt;

	for(u=0;u<=1;u=u+dt)
	{

		draw_point(fx, fy);

		fx = fx + dfx;
		fy = fy + dfy;

		dfx = dfx + ddfx;
		dfy = dfy + ddfy;

		ddfx = ddfx + dddfx;
		ddfy = ddfy + dddfy;
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

	x_v1 = (rand()%(700) -350);
	y_v1 = (rand()%(700) -350);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bezier Cubic Curve - Faster");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}


#endif

