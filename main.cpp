#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "segment.hpp"

Segment segments[7] = {Segment('a'), Segment('b'), Segment('c'), Segment('d'), Segment('e'), Segment('f'), Segment('g')};

int current = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);

    for (Segment s : segments)
    {
        if (s.isContained(nombre[current]))
        {
            s.turnOn();
            s.afficher();
        }
        else s.turnOff();
    }

    glEnd();
    
    current = (current + 1) % 16;

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);

}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Affichage 7 Segments");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor4f(1.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}


// g++ -o my_program main.cpp segment.cpp -lGL -lGLU -lglut