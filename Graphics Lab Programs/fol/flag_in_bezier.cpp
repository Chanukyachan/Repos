#if 0

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

#define PI 3.1416

GLsizei winWidth = 600, winHeight = 600;
GLfloat xwcMin = 0.0, xwcMax = 130.0;//Ortho 2D
GLfloat ywcMin = 0.0, ywcMax = 130.0;//Ortho 2D


void plot(double x,double y)
{
	glBegin(GL_POINTS);
	glVertex2d(x,y);
	glEnd();

}

void display1(double xx, double yy) 
{
	glPointSize(1);
	glColor3f(1.0,0.0,0.0);
	int r = 15;
	int x = 0 + xx;
	int y = r + yy;

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

	glColor3f(1, 1, 1);
	glPointSize(5);
}

typedef struct wcPt3D
{
		GLfloat x, y, z;
};
void bino(GLint n, GLint *C)
{
		GLint k, j;
		for(k=0;k<=n;k++)
		{
			C[k]=1;
				for(j=n;j>=k+1; j--)
					C[k]*=j;
						for(j=n-k;j>=2;j--)
							C[k]/=j;
		}
}
void computeBezPt(GLfloat u, wcPt3D *bezPt, GLint nCtrlPts, wcPt3D *ctrlPts, GLint *C)
{
		GLint k, n=nCtrlPts-1;
		GLfloat bezBlendFcn;
		bezPt ->x =bezPt ->y = bezPt->z=0.0;
		for(k=0; k< nCtrlPts; k++)
		{
			bezBlendFcn = C[k] * pow(u, k) * pow( 1-u, n-k);
			bezPt ->x += ctrlPts[k].x * bezBlendFcn;
			bezPt ->y += ctrlPts[k].y * bezBlendFcn;
			bezPt ->z += ctrlPts[k].z * bezBlendFcn;
		}
}
void bezier(wcPt3D *ctrlPts, GLint nCtrlPts, GLint nBezCurvePts)
{
		wcPt3D bezCurvePt;
		GLfloat u;
		GLint *C, k;
		C= new GLint[nCtrlPts];
		//C[0] = 1;C[1] = 3;C[2] = 3;
		bino(nCtrlPts-1, C);

		int newON = nCtrlPts -1;

		glBegin(GL_LINE_STRIP);
			for(k=0; k<=nBezCurvePts; k++)
			{
					u=GLfloat(k)/GLfloat(nBezCurvePts);

					computeBezPt(u, &bezCurvePt, nCtrlPts, ctrlPts, C);

					glVertex2f(bezCurvePt.x, bezCurvePt.y);

					//display1(bezCurvePt.x,bezCurvePt.y);
			}
		glEnd();
		delete[]C;
}
void displayFcn()
{
		GLint nCtrlPts = 4, nBezCurvePts =30;
		static float theta = 0;
		wcPt3D ctrlPts[4] = {
							{20, 100, 0},
							{30, 110, 0},
							{50, 90, 0},
							{60, 100, 0}};

		ctrlPts[1].x +=10*sin(theta * PI/180.0);
		ctrlPts[1].y +=5*sin(theta * PI/180.0);

		ctrlPts[2].x -= 10*sin((theta+30) * PI/180.0);
		ctrlPts[2].y -= 10*sin((theta+30) * PI/180.0);

		ctrlPts[3].x-= 4*sin((theta) * PI/180.0);
		ctrlPts[3].y += sin((theta-30) * PI/180.0);

		theta+=0.1;
		//cout<<theta<<endl;

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0, 1.0, 1.0);
		glPointSize(5);
		glPushMatrix();
		glLineWidth(5);
		glColor3f(255/255, 153/255.0, 51/255.0); //Orange

		for(int i=0;i<8;i++)
		{
			glTranslatef(0, -0.8, 0);
			bezier(ctrlPts, nCtrlPts, nBezCurvePts);
		}

		glColor3f(1, 1, 1); //White
		for(int i=0;i<8;i++)
		{
			glTranslatef(0, -0.8, 0);
			bezier(ctrlPts, nCtrlPts, nBezCurvePts);
		}

		glColor3f(19/255.0, 136/255.0, 8/255.0); //Green
		for(int i=0;i<8;i++)
		{
			glTranslatef(0, -0.8, 0);
			bezier(ctrlPts, nCtrlPts, nBezCurvePts);
		}

		glPopMatrix();
		glColor3f(0.7, 0.5,0.3);
		glLineWidth(5);
		glBegin(GL_LINES);
				glVertex2f(20,100);
				glVertex2f(20,40);
		glEnd();
		glFlush();
		glutPostRedisplay();
		glutSwapBuffers();

}
void winReshapeFun(GLint newWidth, GLint newHeight)
{
		glViewport(0, 0, newWidth, newHeight);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xwcMin, xwcMax, ywcMin, ywcMax);
		glClear(GL_COLOR_BUFFER_BIT);
}
void main(int argc, char **argv)
{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowPosition(50, 50);
		glutInitWindowSize(winWidth, winHeight);
		glutCreateWindow("Bezier Curve Flag");
		glutDisplayFunc(displayFcn);
		glutReshapeFunc(winReshapeFun);
		glutMainLoop();
}


#endif