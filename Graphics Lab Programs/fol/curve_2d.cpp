#if 0

#include <gl/glut.h>
#include <stdio.h>
#include <time.h>

float x1, y1, x2, y2,x3,y3;

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-250.0, 250.0, -250.0, 250.0, -1.0, 1.0);
}

void draw_point(double x, double y) {
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
}

void plane_curve() {	

	double u,x,y,fn1,fn2,fn3;
	draw_point(x1, y1);
	draw_point(x3, y3);

	for(u=0.01;u<=1;u+=0.001)
	{
		fn1 = 2*u*u - 3*u + 1;
		fn2 = -4*u*u + 4*u ;
		fn3 = 2*u*u - u;

		x = fn1*x1 + fn2*x2 + fn3*x3;
		y = fn1*y1 + fn2*y2 + fn3*y3;
		draw_point(x, y);
	}

	
	for (int i = -500; i <= 500; i++)
	{
		draw_point(i, 0);
		draw_point(0, i); 

	}

}

void myDisplay() {
	plane_curve();
	glFlush();
}

void main(int argc, char **argv) {

	srand(time(0));
	/*printf("Enter (x1, y1) , (x2, y2) , (x3,y3) \n");
	scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2,&x3,&y3);*/

	x1 = rand() % (300);
	y1 = rand() % (300);
	x2 = rand() % (300);
	y2 = rand() % (300);
	x3 = rand() % (300);
	y3 = rand() % (300);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Curve_Plane");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

#endif