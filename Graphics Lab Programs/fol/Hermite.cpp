#if 0

#include <gl/glut.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include<iostream>
using namespace std;

double x0, y_0, x1, y_1 , x_v0 , y_v0 , x_v1 , y_v1;
double al_0,beta_0,gam_0,al_1,beta_1,gam_1;
double coal_0,coal_1,cobe_0,cobe_1;
double magn_0,magn_1;


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

	double u, x, y, f1, f2, f3, f4;

	draw_point(x0, y_0);
	draw_point(x1, y_1);

	for(u=0.01;u<=1;u+=0.001)
	{

		f1 = 2*u*u*u - 3*u*u + 1;
		f2 = -2*u*u*u + 3*u*u;
		f3 = u*u*u -2*u*u + u;
		f4 = u*u*u - u*u;


		x = f1*x0 + f2*x1 + f3*x_v0 + f4*x_v1;
		y = f1*y_0 + f2*y_1 + f3*y_v0 + f4*y_v1;

		draw_point(x, y);
	}

	for (int i = -250; i <= 250; i++)
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


	cout<<"Enter magnitude of v_0 and v_1 :"<<endl;
	cin>>magn_0>>magn_1;

	
	al_0 = rand()%(180);
	al_0 = al_0 * (pi);

	beta_0 = rand()%(180);
	beta_0 = beta_0 * (pi);

	/*cout<<"Enter alpha_0 and beta _0 :"<<endl;
	cin>>al_0>>beta_0;*/

	double res1 = 1 - (cos(al_0)*cos(al_0) + cos(beta_0)*cos(beta_0));
	double gam_0 = sqrt(res1);

	cout<<"Gamma_0 Value :"<<gam_0<<endl;

	/*cout<<"Enter alpha_1 and beta_1 :"<<endl;
	cin>>al_1>>beta_1;*/

	al_1 = rand()%(180);
	al_1 = al_1 * (pi);

	beta_1 = rand()%(180);
	beta_1 = beta_1 * (pi);

	double res2 = 1 - (cos(al_1)*cos(al_1) + cos(beta_1)*cos(beta_1));
	double gam_1 = sqrt(res2);

	cout<<"Gamma_1 Value :"<<gam_1<<endl;

	coal_0 = cos(al_0);
	coal_1 = cos(al_1);

	cobe_0 = cos(beta_0);
	cobe_1 = cos(beta_1);

	x_v0 = magn_0 * coal_0;
	y_v0 = magn_0 * cobe_0;

	x_v1 = magn_1 * coal_1;
	x_v1 = magn_1 * cobe_1;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Hermite Curve");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

#endif