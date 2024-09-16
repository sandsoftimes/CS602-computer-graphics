#include <GL/glut.h>
#include <stdlib.h>

float angle1 = 0.0;
float angle2 = 0.0;

void drawCube() {
    // Drawing code for a cube
    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for object 1
    glVertex3f(-0.15f, -0.15f, 0.0f);
    glVertex3f(0.15f, -0.15f, 0.0f);
    glVertex3f(0.15f, 0.15f, 0.0f);
    glVertex3f(-0.15f, 0.15f, 0.0f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Object 1
    glPushMatrix();
    glColor3f(1.f, 0.f, 0.f); // Red color
    glTranslatef(-0.5f, 0.0f, 0.0f); // Move object 1 to the left
    glRotatef(angle1, 0.0f, 0.0f, 1.0f); // Rotate clockwise
    drawCube();
    glPopMatrix();

    // Object 2
    glPushMatrix();
    glColor3f(0.f, 1.f, 0.f); // Green color
    glTranslatef(0.5f, 0.0f, 0.0f); // Move object 2 to the right
    glRotatef(-angle2, 0.0f, 0.0f, 1.0f); // Rotate counter-clockwise
    drawCube();
    glPopMatrix();

    glutSwapBuffers();
}

void timer(int value) {
    angle1 += 2.0; // Clockwise rotation for object 1
    angle2 += 2.0; // Counter-clockwise rotation for object 2

    glutPostRedisplay(); // Trigger redraw
    glutTimerFunc(16, timer, 0); // Update every 16 milliseconds for ~60 FPS
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Parallel Rotations");

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Black background

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0); // Start timer

    glutMainLoop();
    return 0;
}
