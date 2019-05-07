#if 1

#include <GL/glut.h>
#include<iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int pointX[4],pointY[4];
int countNum = -1;
int flagVal = 0;

int factorial(int N)
{
	int result = 1;
	
	for (int j = 2; j <= N; j++)
		result = result * j;

	return result;
}

int NCr(int N, int r)
{
	return factorial(N) / (factorial(r) * factorial(N - r));
}

void DisplayClear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void display()
{
	double X, Y, U;
	cout << "Point Change detected" << endl;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 1.0);
	glLineWidth(1.0);
	glBegin(GL_POINTS);
	X = 0; Y = 0;

	for (U = 0; U <= 1.0; U += 0.001)
	{
		X = 0; Y = 0;
		for (int i = 0; i < 4; i++)
		{
			X = X + (pow(U, i)*pow(1 - U, 4 - i)*(NCr(4, i)))*pointX[i];
			Y = Y + (pow(U, i)*pow(1 - U, 4 - i)*(NCr(4, i)))*pointY[i];
		}
		glVertex2d(X, Y);

	}
	glEnd();
	glFlush();
}
void myinit()
{
	glClearColor(0.0, 0.1, 0.0, 1);
	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000.0, 0, 1000);
	glPointSize(1.5);

}

void MouseXY(int button, int state, int X, int Y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (flagVal == 0)
		{
			countNum++;
			pointX[countNum] = 1000 - X;
			pointY[countNum] = 1000 - Y;
			cout<< countNum << "  " << X << " " << Y << endl;
		}
		else
		{
			pointX[1] = 1000 - X;
			pointY[1] = 1000 - Y;
			display();
		}
		if (countNum == 3 && flagVal == 0)
		{
			flagVal = 1;
			display();
		}
	}

}
int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Bezier Curve With Mouse Click");
	cout << "Please select four points with left mouse button click" << endl;
	glutMouseFunc(MouseXY);
	glutDisplayFunc(DisplayClear);
	myinit();
	glutMainLoop();
	return 0;

}
#endif
