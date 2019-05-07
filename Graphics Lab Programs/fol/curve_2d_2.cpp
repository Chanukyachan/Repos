#if 0

#include <gl/glut.h>
#include <stdio.h>
#include <time.h>

int x1, y1, x2, y2 , x3 , y3 , x4 , y4;

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-250.0, 250.0, -250.0, 250.0, -1.0, 1.0);
}


void draw_point(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}


void space_curve() {	

	double u,x,y,f1,f2,f3,f4;

	draw_point(x1, y1);
	draw_point(x3, y3);

	for(u=0.01;u<=1;u+=0.001)
	{

		f1 = -9*u*u*u/2 + 9*u*u - 11*u/2 + 1;
		f2 = 27*u*u*u/2 - 45*u*u/2 + 9*u;
		f3 = -27*u*u*u/2 + 18*u*u - 9*u/2;
		f4 = 9*u*u*u/2 - 9*u*u/2 + u;


		x = f1*x1 + f2*x2 + f3*x3 + f4*x4;
		y = f1*y1 + f2*y2 + f3*y3 + f4*y4;

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
	/*printf("Enter (x1, y1, x2, y2,x3,y3)\n");
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2,&x3,&y3,&x4, &y4);*/

	x1 = rand()%(300);
	y1 = rand()%(300);

	x2 = rand()%(300);
	y2 = rand()%(300);

	x3 = rand()%(300);
	y3 = rand()%(300);

	x4 = rand()%(300);
	y4 = rand()%(300);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Space Curve");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

#endif