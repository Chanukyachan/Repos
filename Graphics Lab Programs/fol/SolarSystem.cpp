#if 0
#include <math.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <string.h>
using namespace std;

float x[9], the[9] = { 0 }, speed[9] = { 0.001, 0.0002, 0.0005, 0.0004, 0.0003, 0.00025, 0.0002, 0.0004, 0.0009 }, size[9] = { 5, 9, 10, 6, 15, 14, 12, 11,3  };
float colour[9][3] = { { 0.5, 0.5, 0.5 }, { 0.94, 0.9, 0.54 }, { 0.03, 0.11, 0.537 }, { 0.756, 0.266, 0.054 }, { 0.705, 0.654, 0.619 }, { 0.886, 0.749, 0.49 }, { 0.384, 0.682, 0.905 }, { 0.168, 0.215, 0.545 }, { 0.494, 0.505, 0.643 } };
float f1 = 0.0f, mthe = 0; 
float l[500], m[500], n[500];

void orbit(int xc,int yc,int r)
{
	glColor3f(0.807, 0.721, 0.721);
	glBegin(GL_POINTS);
	
	int p = 1 - r;
	int x, y;
	
	x = 0;
	y = r;
	
	while (x<y)
	{
		if (p<0)
		{
			x = x + 1;
			p = p + 2 * x + 1;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			p = p + 2 * x + 1 - 2 * y;
		}
		glVertex3f(x + xc,0, y + yc);
		glVertex3f(y + xc,0, x + yc);
		glVertex3f(-x + xc,0, y + yc);
		glVertex3f(x + xc,0, -y + yc);
		glVertex3f(y + xc, 0,-x + yc);
		glVertex3f(-y + xc, 0,x + yc);
		glVertex3f(-x + xc,0, -y + yc);
		glVertex3f(-y + xc, 0,-x + yc);
	}
	glEnd();
}

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		100.0f, 800.0f, 400.0f,
		0.0f, 0.0f, -500.0f,
		0.0f, 1.0f, 0.0f);
	
	glBegin(GL_POINTS);
	for (int t = 0; t < 500; t++)
	{
		glVertex3f(l[t],m[t],n[t]);
	}glEnd();

	for (int k = 0; k < 9; k++)
	{
		orbit(0,-500,90 + 60 * k);
	}

	glTranslatef(0.0f, 0.0f, -500.0f);
	glColor3f(0.9, 0.3, 0.2);
	glutSolidSphere(50, 20, 20);

	int x=0, z=0,xp=0,zp=0;
	
	for (int i = 0; i < 9; i++)
	{
		if (i == 2)
		{
			glColor3f(colour[i][0], colour[i][1], colour[i][2]);
			glPushMatrix();
			glTranslatef((90 + 60 * i) * cos(the[i]), 0.0f, (90 + 60 * i)* sin(the[i]));
			glutSolidSphere(size[i], 20, 20);
			glColor3f(1,1,1);
			glTranslatef(20 *  cos(mthe), 0.0f, 20 * sin(mthe));
			glutSolidSphere(3, 20, 20);
			glPopMatrix();
			continue;
		}
		if (i == 6)
		{
			glColor3f(colour[i][0], colour[i][1], colour[i][2]);
			glPushMatrix();
			glTranslatef((90 + 60 * i)  * cos(the[i]), 0.0f, (90 + 60 * i)* sin(the[i]));
			glutSolidSphere(size[i], 20, 20);
			for (int t = 13; t < 20; t++)
			{
				orbit(0,0,t);
			}
			glPopMatrix();
			continue;
		}
		glColor3f(colour[i][0], colour[i][1], colour[i][2]);
		glPushMatrix();
		glTranslatef((90 + 60 * i) * cos(the[i]), 0.0f, (90 + 60 * i) * sin(the[i]));
		glutSolidSphere(size[i], 20, 20);
		glPopMatrix();
	}
	glutSwapBuffers();
}

void idle()
{
	
	for (int i = 0; i < 9; i++)
	{
		the[i] += speed[i];
	}
	mthe += 0.005;
	
	glutPostRedisplay();
}

void Resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (double)w / (double)h, 1.0, 5000.0);
}

void init(int ac, char *av[])
{
	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(0, 0);
	
	glutCreateWindow("Solar System");

	glEnable(GL_DEPTH_TEST);
	for (int i = 0; i < 9; i++)
	{
		the[i] = rand() % 360;
	}
	for (int k = 0; k < 500; k++)
	{
		l[k] = rand() % 1000-500;
		m[k] = rand() % 1000-500;
		n[k] = rand() % 1000-500;

	}
	glutDisplayFunc(draw);
	glutReshapeFunc(Resize);
	glutIdleFunc(idle);
	glutMainLoop();
}

int  main(int ac, char *av[])
{
	init(ac, av);
	
		return 0;
}
#endif