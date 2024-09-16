/* gcc nu_hello.c -lGL -lglut -lGLU */
#include <GL/glut.h>
void display()
{
glClearColor(0.0, 0.0, 0.0, 0.0); //
glClear(GL_COLOR_BUFFER_BIT);
//
glColor3f(1.0, 0.0, 0.0);
//
glBegin(GL_POLYGON);
//
glVertex2f(-0.5, -0.5); //v1
//
glVertex2f( 0.5, -0.5); //v2
glVertex2f( 0.5, 0.5); //v3
glVertex3f(-0.5, 0.5,0.5); //v4
glVertex3f(-0.5, 0.5,-0.5);//v5
glEnd();
// glBegin(GL_TRIANGLES);
// //
// glVertex2f(-0.5, -0.5); //v1
// glVertex2f( 0.5, 0.5); //v3
// glVertex2f(-0.5, 0.5); //v4
// glEnd();
//
glFlush();
//
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitWindowSize(300, 300);
glutInitWindowPosition(300, 300);
glutCreateWindow("Simple Polygon");
glutDisplayFunc(display);
glutMainLoop();
}
