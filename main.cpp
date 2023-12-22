#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int n = 0x7C;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);
    if (n & 1)
    {
        // A
        glVertex2f(-2.0, 5.0);
        glVertex2f(-2.0, 4.5);
        glVertex2f(2.0, 4.5);
        glVertex2f(2.0, 5.0);
    }
    if (n >> 1 & 1)
    {
        // B
        glVertex2f(2.2, 4.5);
        glVertex2f(2.7, 4.5);
        glVertex2f(2.7, 0.5);
        glVertex2f(2.2, 0.5);
    }
    if (n >> 2 & 1)
    {
        // C
        glVertex2f(2.2, 0.0);
        glVertex2f(2.2, -4.0);
        glVertex2f(2.7, -4.0);
        glVertex2f(2.7, 0.0);
    }
    if (n >> 3 & 1)
    {
        // D
        glVertex2f(-2.0, -4.0);
        glVertex2f(-2.0, -4.5);
        glVertex2f(2.0, -4.5);
        glVertex2f(2.0, -4.0);
    }
    if (n >> 4 & 1)
    {
        // E
        glVertex2f(-2.7, 0.0);
        glVertex2f(-2.7, -4.0);
        glVertex2f(-2.2, -4.0);
        glVertex2f(-2.2, 0.0);
    }
    if (n >> 5 & 1)
    {
        // F
        glVertex2f(-2.7, 4.5);
        glVertex2f(-2.2, 4.5);
        glVertex2f(-2.2, 0.5);
        glVertex2f(-2.7, 0.5);
    }
    if (n >> 6 & 1)
    {
        // G
        glVertex2f(-2.0, 0.5);
        glVertex2f(-2.0, 0.0);
        glVertex2f(2.0, 0.0);
        glVertex2f(2.0, 0.5);
    }

    glEnd();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Affichage 7 Segments");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}
