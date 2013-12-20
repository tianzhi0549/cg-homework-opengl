#include <Windows.h>
#include <stdio.h>
#include <GL\GL.H>
#include <GL\glu.h>
#include <GL\glut.h>

int mouseDownX=0;
int mouseDownY=0;
int curState=-1;
void init()
{
	glClearColor(0,0,0,0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluPerspective(90,1,0,1);
	gluLookAt(0,1,-5,0,0,0,0,1,0);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(2,0.5,0.5);
	glutWireCube(1);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
void reShape(int w,int h)
{
	
}
void mouse(int button,int state,int x,int y)
{
	if(state==GLUT_DOWN)
	{
		curState=button;
		mouseDownX=x;
		mouseDownY=y;
	}else
	{
		curState=-1;
	}
}
void mouseMotion(int x,int y)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(curState==1)
	{
		static float angleX=0;
		static float angleY=0;
		angleX+=(GLfloat)(x-mouseDownX)/2/3.14159265;
		angleY+=(GLfloat)(y-mouseDownY)/2/3.14159265;
		glRotatef(angleX,0,1,0);
		glRotatef(-angleY,1,0,0);
	}else if(curState==0)
	{
		static float _x=0,_y=0;
		_x-=(x-mouseDownX)/100.;
		_y-=(y-mouseDownY)/100.;
		glTranslatef(_x,_y,0);
	}
	mouseDownX=x;
	mouseDownY=y;
	display();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("CG");
	glutReshapeFunc(reShape);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return EXIT_SUCCESS;
}
