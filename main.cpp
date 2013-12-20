#include <Windows.h>
#include <stdio.h>
#include <GL\GL.H>
#include <GL\glu.h>
#include <GL\glut.h>
#include <math.h>
int mouseDownX=0;
int mouseDownY=0;
float angle=0;
void init()
{
	glClearColor(0,0,0,0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluPerspective(90,1,0,1);
	gluLookAt(0,0,5,0,0,0,0,-1,0);
	glShadeModel(GL_FLAT);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(1,0,0);
	glScalef(4,1,1);
	//¥Û±€
	glutWireCube(0.5);
	glLoadIdentity();
	if(abs(angle)>120) return;
	if(angle>0)
	{
		glTranslatef(0,0.25,0);
		glRotatef(angle,0,0,-1);
		glTranslatef(-1,-0.25,0);
	}else
	{
		glTranslatef(0,-0.25,0);
		glRotatef(angle,0,0,-1);
		glTranslatef(-1,0.25,0);
	}
	glScalef(4,1,1);
	//–°±€
	glutWireCube(0.5);
	glLoadIdentity();
	float w=0.5*sin(angle/180*3.14159265/2)*2;
	if(angle>0)
	{
		glTranslatef(0,-0.25,0);
		glRotatef(angle/2,0,0,-1);
		glTranslatef(-w/2,0,0);
	}else
	{
		glTranslatef(0,0.25,0);
		glRotatef(angle/2,0,0,-1);
		glTranslatef(w/2,0,0);
	}
	glBegin(GL_POLYGON);
	glVertex3f(w/2,0,0.25);
	glVertex3f(w/2,0,-0.25);
	glVertex3f(-w/2,0,-0.25);
	glVertex3f(-w/2,0,0.25);
	glEnd();
	glFlush();
	glutSwapBuffers();
}
void reShape(int w,int h)
{
	
}
void mouse(int button,int state,int x,int y)
{
	mouseDownX=x;
	mouseDownY=y;
}
void mouseMotion(int x,int y)
{
	angle+=(y-mouseDownY);
	mouseDownY=y;
	display();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow(" ÷±€");
	glutReshapeFunc(reShape);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return EXIT_SUCCESS;
}
