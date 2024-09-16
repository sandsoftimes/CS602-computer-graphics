#include <GL/glut.h>

float angle = 0.0f; // Initialize rotation angle

void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity(); // Load the identity matrix

    glTranslatef(0.0f, 0.0f, 0.0f); // Translate to the origin (optional)
    glRotatef(angle, 0.0f, 1.0f, 0.0f); // Rotate around the y-axis

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

    glFlush();
}

void timer(int value)
{
    angle += 1.0f; // Increment rotation angle
    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(16, timer, 0); // 16ms delay between frames (60fps)
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Rotating Polygon");
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0); // Start the timer
    glutMainLoop();
    return 0;
}
