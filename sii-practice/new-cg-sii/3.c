#include <GL/glut.h>
#include <stdlib.h>

float rotate1 = 0.0; // Angle for sun's rotation
float rotate2 = 0.0; // Angle for earth's rotation
float rotate3 = 0.0; // Angle for moon's rotation

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Sun
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for sun
    glRotatef(rotate1, 0, 0, 1); // Rotation along its own axis
    glutWireSphere(0.4, 25, 25); // Draw the sun
    glPopMatrix();

    // Earth
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color for earth
    glRotatef(rotate2, 0, 0, 1); // Rotation along its own axis
    glTranslatef(0.4, 0.4, 0); // Translation to orbit around the sun
    glRotatef(rotate2, 0, 0, 1); // Rotation around the sun
    glutWireSphere(.1, 20, 20); // Draw the earth
    glPopMatrix();

    // Moon
    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f); // Grey color for moon
    glRotatef(rotate3, 0, 0, 1); // Rotation along its own axis
    glTranslatef(0.4, 0.4, 0); // Translation to Earth's position
    glRotatef(rotate2 * 12, 0, 0, 1); // Rotation around Earth
    glTranslatef(0.1, 0.0, 0.0); // Translation to the moon's orbit
    glutWireSphere(.05, 10, 10); // Draw the moon
    glPopMatrix();

    glutSwapBuffers();
}

void timer(int value) {
    rotate1 += 0.5; // Sun's rotation speed
    rotate2 += 0.2; // Earth's rotation speed
    rotate3 += 1.0; // Moon's rotation speed

    glutPostRedisplay(); // Trigger redraw
    glutTimerFunc(16, timer, 0); // Update every 16 milliseconds for ~60 FPS
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Solar System Simulation");

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Black background

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0); // Start timer

    glutMainLoop();
    return 0;
}
