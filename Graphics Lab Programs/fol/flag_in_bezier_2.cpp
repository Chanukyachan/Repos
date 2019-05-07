#if 1

#include <gl/glut.h>
#include <stdio.h>


double XMat[4][4] = {{ 100, 220, 240, 260},
					{105, 225, 235, 205 },
					{105, 225, 235, 270},
					{100, 220, 240, 260}};
double YMat[4][4] = {{200, 220, 220, 40},
					{230,250,250,100},
					{280,260,260,100},
					{300,320,340,500}};
double ZMat[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(000.0, 500.0, 0.0, 500.0);
}

void draw_pixel(int x, int y,float r, float g, float b ) {
	glBegin(GL_POINTS);
	glColor3f(r,g,b);
	glVertex2i(x, y);
	glEnd();
}


void draw_curve() {	
	//drawP();
	double u,w;
	
	double x,y;
	double A[1][4],B[4][1];
	for(u=0;u<=0.5;u=u+0.001)
	{
		for(w=0;w<=0.5;w=w+0.001)
		{
			A[0][0] = (1-u)*(1-u)*(1-u);
			A[0][1] = 3*u*(1-u)*(1-u);
			A[0][2] = 3*u*u*(1-u);
			A[0][3] = u*u*u;

			B[0][0] = (1-w)*(1-w)*(1-w);
			B[1][0] = 3*w*(1-w)*(1-w);
			B[2][0] = 3*w*w*(1-w);
			B[3][0] = 3*w*w*w;

			x = (A[0][0] * XMat[0][0] + A[0][1] * XMat[1][0] + A[0][2] * XMat[2][0] + A[0][3] * XMat[3][0]) * B[0][0] + (A[0][0] * XMat[0][1] + A[0][1] * XMat[1][1] + A[0][2] * XMat[2][1] + A[0][3] * XMat[3][1]) * B[1][0] + (A[0][0] * XMat[0][2] + A[0][1] * XMat[1][2] + A[0][2] * XMat[2][2] + A[0][3] * XMat[3][2]) * B[2][0] + (A[0][0] * XMat[0][3] + A[0][1] * XMat[1][3] + A[0][2] * XMat[2][3] + A[0][3] * XMat[3][3]) * B[3][0];
			y = (A[0][0] * YMat[0][0] + A[0][1] * YMat[1][0] + A[0][2] * YMat[2][0] + A[0][3] * YMat[3][0]) * B[0][0] + (A[0][0] * YMat[0][1] + A[0][1] * YMat[1][1] + A[0][2] * YMat[2][1] + A[0][3] * YMat[3][1]) * B[1][0] + (A[0][0] * YMat[0][2] + A[0][1] * YMat[1][2] + A[0][2] * YMat[2][2] + A[0][3] * YMat[3][2]) * B[2][0] + (A[0][0] * YMat[0][3] + A[0][1] * YMat[1][3] + A[0][2] * YMat[2][3] + A[0][3] * YMat[3][3]) * B[3][0];
			
			if(u<0.17)
				draw_pixel(x, y,0,1,0);
			else if(u>=0.17 && u<0.34)
				draw_pixel(x, y,1,1,1);
			else
				draw_pixel(x, y,1,0.5,0.15);
		}
	}
	
}

void myDisplay() {
	draw_curve();
	glFlush();
}

void main(int argc, char **argv) {

	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Flag");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

#endif