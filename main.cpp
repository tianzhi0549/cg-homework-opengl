#include <Windows.h>
#include <stdio.h>
#include <GL\GL.H>
#include <GL\glu.h>
#include <GL\glut.h>
float angleX=0;
float angleY=0;
int mouseDownX=0;
int mouseDownY=0;
void init()
{
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,1,0,1);
	gluLookAt(0,0,-2,0,0,0,0,1,0);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(angleX,0,1,0);
	glRotatef(-angleY,1,0,0);
	glutWireCube(1);
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
	angleX+=(GLfloat)(x-mouseDownX)/2/3.14159265;
	angleY+=(GLfloat)(y-mouseDownY)/2/3.14159265;
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
	//glutIdleFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return EXIT_SUCCESS;
}
